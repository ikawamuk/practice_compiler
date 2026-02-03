#!/bin/bash

assert()
{
	expected="$1"
	input="$2"
	src=test.txt
	exe="b.out"

	echo "$2" > "$src"
	./ccc "$src"
	./"$exe"
	actual="$?"
	if [ "$actual" == "$expected" ]; then
		echo "$input => $actual"
	else
		echo "$input => $expected expected, but got $actual"
		rm "$src" "$exe"
		exit 1
	fi
	rm "$src" "$exe"
}

make re > /dev/null

assert 0 0
assert 42 42
assert 21 " 5 +20-4 "
assert 9 "1+0+10-2"
assert 9 "1 + 2 - 3 +  4  +  5"
assert 2 "1 + 3 - 2"
assert 32 "  3 * 6+2 * 7  "
assert 6 "4 * (2 + 1) / ((1 * 1) + 1)"
assert 6 "-3 *-3 + (-6 / (1 + 1))"
assert 1 "10 == 10 "
assert 0 "-10 != (-10)"
assert 1 "6 >= 6"
assert 0 "6 < 6"
assert 1 "(1 + 3) ==4"
assert 1 "(((( 1 + 1 ) ) )  )  < (2 * 2 / 2 * 2)"

echo OK
