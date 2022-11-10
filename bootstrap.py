import subprocess
import os


def build_target(target):
    build_type = os.environ.get("BUILD_TYPE", "Debug")
    subprocess.check_call(
        ["cmake", "--build", "build", "--config", build_type, "--target", target]
    )


def generate_grammar(grammar_file):
    subprocess.check_call("build/langcc", grammar_file, "gen")


def main():
    build_target("datacc")
    build_target("langcc")
    build_target("unittest_lang")
    generate_grammar("grammars/data.lang")
    generate_grammar("grammars/cc.lang")
    generate_grammar("grammars/meta.lang")

    build_target("clean")
    build_target("datacc")
    build_target("langcc")
    build_target("unittest_lang")
    subprocess.check_call("build/unittest_lang")
    build_target("go_standalone_test")
    subprocess.check_call("build/go_standalone_test", "1")
    build_target("py_standalone_test")
    subprocess.check_call("build/py_standalone_test", "1")
    build_target("go_standalone_bidir_test")
    subprocess.check_call("build/go_standalone_bidir_test", "1")
    build_target("py_standalone_bidir_test")
    subprocess.check_call("build/py_standalone_bidir_test", "1")


if __name__ == "__main__":
    main()
