import subprocess
import os

is_windows = os.name == "nt"


def run_command(command):
    if is_windows:
        command[0] = f"{command[0]}.exe"
        subprocess.check_call(command, shell=True)
    else:
        subprocess.check_call(command)


def build_target(target):
    build_type = os.environ.get("BUILD_TYPE", "Debug")
    run_command(
        ["cmake", "--build", "build", "--config", build_type, "--target", target]
    )


def generate_grammar(grammar_file):
    run_command(["build/langcc", grammar_file, "gen"])


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
    run_command(["build/unittest_lang"])
    build_target("go_standalone_test")
    run_command(["build/go_standalone_test", "1"])
    build_target("py_standalone_test")
    run_command(["build/py_standalone_test", "1"])
    build_target("go_standalone_bidir_test")
    run_command(["build/go_standalone_bidir_test", "1"])
    build_target("py_standalone_bidir_test")
    run_command(["build/py_standalone_bidir_test", "1"])


if __name__ == "__main__":
    main()
