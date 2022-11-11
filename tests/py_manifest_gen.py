#!/usr/bin/env python3

import os
import subprocess
import sys
import time

def main():
    fout = open('data/py_manifest_gen.txt', 'w')

    for (dirpath, _, filenames) in os.walk('../cpython/Lib'):
        if 'lib2to3/tests/data' in dirpath:
            continue

        for f in filenames:
            if not f.endswith('.py'):
                continue

            if f.startswith('bad_') or f.startswith('badsyntax_') or f.startswith('py2_'):
                continue

            if os.path.join(dirpath, f) == '../cpython/Lib/test/test_importlib/test_util.py':
                # U+FEFF
                continue

            ok = True
            with open(os.path.join(dirpath, f), 'r') as fin:
                try:
                    l = fin.readline()
                    if '-*- coding' in l and not 'utf-8' in l:
                        ok = False
                except UnicodeDecodeError:
                    ok = False

            if ok:
                fout.write('{}\n'.format(os.path.join(dirpath, f)))
                fout.flush()

    fout.close()

if __name__ == '__main__':
    main()
