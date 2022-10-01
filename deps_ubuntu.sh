#!/bin/bash
set -e
set -u
sudo apt update
sudo apt install make llvm-14-dev libunwind-dev libgoogle-perftools-dev
