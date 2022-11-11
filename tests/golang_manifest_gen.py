#!/usr/bin/env python3

import os
import subprocess
import sys
import time

def main():
    fout = open('data/golang_manifest_gen.txt', 'w')

    for (dirpath, _, filenames) in os.walk('../go/src'):
        for f in filenames:
            if not f.endswith('.go'):
                continue

            s = os.path.join(dirpath, f)
            if s == '../go/src/go/parser/testdata/issue42951/not_a_file.go/invalid.go':
                continue

            fout.write('{}\n'.format(s))
            fout.flush()

    fout.close()

if __name__ == '__main__':
    main()
