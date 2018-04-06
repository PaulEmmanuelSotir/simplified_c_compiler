#!/bin/bash
gcc -c $1 -o file.o
gcc file.o -o $2
rm file.o
