#!/bin/bash
filename="${1%.*}"
gcc $1 -masm=intel -S -O0 -o "${filename}.s"