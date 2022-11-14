include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        release-1.12.1
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)
enable_testing()
include(GoogleTest)

# Generate golang parser
add_custom_command(
    COMMAND $<TARGET_FILE:langcc> ${CMAKE_SOURCE_DIR}/grammars/go.lang ${CMAKE_SOURCE_DIR}/gen
    DEPENDS langcc ${CMAKE_SOURCE_DIR}/grammars/go.lang
    OUTPUT ${CMAKE_SOURCE_DIR}/gen/go__gen.cpp
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
)

# Generate python parser
add_custom_command(
    COMMAND $<TARGET_FILE:langcc> ${CMAKE_SOURCE_DIR}/grammars/py.lang ${CMAKE_SOURCE_DIR}/gen
    DEPENDS langcc ${CMAKE_SOURCE_DIR}/grammars/py.lang
    OUTPUT ${CMAKE_SOURCE_DIR}/gen/py__gen.cpp
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
)


add_compile_definitions(LANGCC_INCLUDE_PATH="${CMAKE_SOURCE_DIR}/src")

add_executable(unittest_lang unittest_lang.cpp)
target_link_libraries(unittest_lang GTest::gtest_main langcclib datacclib)
gtest_discover_tests(unittest_lang)

add_executable(unittest_lib unittest_lib.cpp)
target_link_libraries(unittest_lib GTest::gtest_main)
gtest_discover_tests(unittest_lib)

add_executable(py_standalone_test py_standalone_test.cpp
  ${CMAKE_SOURCE_DIR}/gen/py__gen.cpp
)
target_link_libraries(py_standalone_test GTest::gtest_main)
gtest_discover_tests(py_standalone_test)

add_executable(go_standalone_test go_standalone_test.cpp
  ${CMAKE_SOURCE_DIR}/gen/go__gen.cpp
)
target_link_libraries(go_standalone_test GTest::gtest_main)
gtest_discover_tests(go_standalone_test)


add_custom_target(build_tests)
add_dependencies(build_tests unittest_lang unittest_lib py_standalone_test go_standalone_test)
include(ProcessorCount)
ProcessorCount(N)
if(NOT N EQUAL 0)
  set(CTEST_PARALLEL_FLAG -j${N})
endif()
add_custom_target(tests
  COMMAND ${CMAKE_CTEST_COMMAND} ${CTEST_PARALLEL_FLAG} -C $<CONFIGURATION> --output-on-failure --output-junit ${CMAKE_SOURCE_DIR}/report.xml
  DEPENDS build_tests
  WORKING_DIRECTORY "${CMAKE_BINARY_DIR}"
)
