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

assert 0 "return 0;"
assert 42 "return 42;"
assert 21 "return  5 +20-4 ;"
assert 9 "return 1+0+10-2;"
assert 9 "return 1 + 2 - 3 +  4  +  5;"
assert 2 "return 1 + 3 - 2;"
assert 32 "return   3 * 6+2 * 7  ;"
assert 6 "return 4 * (2 + 1) / ((1 * 1) + 1);"
assert 6 "return -3 *-3 + (-6 / (1 + 1));"
assert 1 "return 10 == 10 ;"
assert 0 "return -10 != (-10);"
assert 1 "return 6 >= 6;"
assert 0 "return 6 < 6;"
assert 1 "return (1 + 3) ==4;"
assert 1 "return (((( 1 + 1 ) ) )  )  < (2 * 2 / 2 * 2);"
assert 3 "a=3; return a;"
assert 8 "aa = 3; zzz = 5; return aa + zzz;"
assert 1 "return 1; 2; 3;"
assert 2 "1; return 2; 3;"
assert 8 "foo123=3; bar=5; return foo123+bar;"
assert 3 "if (0) return 2; return 3;"
assert 3 "if (1-1) return 2; return 3;"
assert 2 "if (1) return 2; return 3;"
assert 2 "if (2 - 1) return 2; return 3;"
assert 10 "i = 0; while (i < 10) i= i + 1; return i;"


echo OK
