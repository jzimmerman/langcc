
#
# Create test targets
#

# Unittests:
add_executable(unittest_lib
  unittest_lib_main.cpp
)
add_executable(unittest_lang
  unittest_lang_main.cpp
)

find_package(Threads REQUIRED)
target_link_libraries(unittest_lib PRIVATE Threads::Threads)
target_link_libraries(unittest_lang PRIVATE Threads::Threads langcclib datacclib)

# go_standalone_test
add_custom_command(
    COMMAND $<TARGET_FILE:langcc> ${CMAKE_CURRENT_SOURCE_DIR}/grammars/go.lang ${CMAKE_CURRENT_SOURCE_DIR}/gen
    DEPENDS langcc ${CMAKE_CURRENT_SOURCE_DIR}/grammars/go.lang
    OUTPUT ${CMAKE_SOURCE_DIR}/gen/go__gen.cpp
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
)
add_executable(go_standalone_test
  go_standalone_test.cpp
  ${CMAKE_SOURCE_DIR}/gen/go__gen.cpp
)
add_executable(go_standalone_bidir_test
  go_standalone_bidir_test.cpp
  ${CMAKE_SOURCE_DIR}/gen/go__gen.cpp
)

# py_standalone_test
add_custom_command(
    COMMAND $<TARGET_FILE:langcc> ${CMAKE_CURRENT_SOURCE_DIR}/grammars/py.lang ${CMAKE_CURRENT_SOURCE_DIR}/gen
    DEPENDS langcc ${CMAKE_CURRENT_SOURCE_DIR}/grammars/py.lang
    OUTPUT ${CMAKE_SOURCE_DIR}/gen/py__gen.cpp
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
)
add_executable(py_standalone_test
  py_standalone_test.cpp
  ${CMAKE_SOURCE_DIR}/gen/py__gen.cpp
)
add_executable(py_standalone_bidir_test
  py_standalone_bidir_test.cpp
  ${CMAKE_SOURCE_DIR}/gen/py__gen.cpp
)
