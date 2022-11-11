package main

import (
	"bufio"
	"flag"
	"fmt"
	"go/parser"
	"go/token"
	"os"
	"runtime"
	"strconv"
)

func main() {
	runtime.GOMAXPROCS(1)

	var err error

	fs := token.NewFileSet()

	flag.Parse()
	args := flag.Args()

	n_iter := -1

	for arg_i, arg := range args {
		if arg_i == 0 {
			n_iter, err = strconv.Atoi(arg)
			if err != nil || n_iter < 0 {
				fmt.Println("Error in setting n_iter\n")
				os.Exit(1)
			}
			continue
		} else {
			fmt.Printf(" ===== Error: extra arguments\n")
			os.Exit(1)
		}
	}

	f, err := os.Open("data/golang_manifest_gen.txt")
	if err != nil {
		fmt.Printf(" ===== Error reading manifest\n")
		os.Exit(1)
	}
	defer f.Close()

	sc := bufio.NewScanner(f)

	for sc.Scan() {
		arg := sc.Text()

		for i := 0; i < n_iter; i += 1 {
			_, err = parser.ParseFile(fs, arg, nil, 0)

			if err != nil {
				fmt.Printf(" ==== Error: %v\n", arg)
				os.Exit(1)
			}
		}
	}

	os.Exit(0)
}
