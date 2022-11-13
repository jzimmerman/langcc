from pathlib import Path
import subprocess
import os

is_windows = os.name == "nt"
build_type = os.environ.get("BUILD_TYPE", "Debug")
build_dir = Path("build")


def run_command(command):
    if is_windows:
        command[0] = f"{command[0]}.exe"
        subprocess.check_call(command, shell=True)
    else:
        subprocess.check_call(command)


def build_target(target):
    run_command(
        ["cmake", "--build", "build", "--config", build_type, "--target", target]
    )


def generate_grammar(grammar_file):
    run_command([build_dir / "langcc", grammar_file, "gen"])


def main():
    build_target("langcc")
    generate_grammar("grammars/data.lang")
    generate_grammar("grammars/cc.lang")
    generate_grammar("grammars/meta.lang")
    subprocess.check_call(["git", "diff", "--exit-code", "gen"])


if __name__ == "__main__":
    main()
