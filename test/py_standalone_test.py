#!/usr/bin/env python3

import ast
import os
import sys

def main():
	filenames = []
	with open('data/py_manifest_gen.txt') as fin:
		for l in fin:
			filenames.append(l.strip())

	assert len(sys.argv) == 2

	num_iter = int(sys.argv[1])

	for filename in filenames:
		for j in range(num_iter):
			with open(filename) as fin:
				contents = fin.read()

			try:
				ast.parse(contents)
			except:
				print('failed: ', filename)
				assert False

if __name__ == '__main__':
	main()
