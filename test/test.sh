#!/bin/bash

assert()
{
	expected="$1"
	input="$2"
	src=test.txt
	exe="a.out"

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

assert 0 "int main(){return 0;}"
assert 42 "int main(){return 42;}"
assert 1 "int main(){return 1; 2; 3;}"
assert 2 "int main(){1; return 2; 3;}"

assert 21 "int main(){return  5 +20-4 ;}"
assert 9 "int main(){return 1+0+10-2;}"
assert 9 "int main(){return 1 + 2 - 3 +  4  +  5;}"
assert 2 "int main(){return 1 + 3 - 2;}"
assert 32 "int main(){return   3 * 6+2 * 7  ;}"
assert 6 "int main(){return 4 * (2 + 1) / ((1 * 1) + 1);}"
assert 6 "int main(){return -3 *-3 + (-6 / (1 + 1));}"
assert 9 "int main(){return 27%18;}"

assert 1 "int main(){return 10 == 10 ;}"
assert 0 "int main(){return -10 != (-10);}"
assert 1 "int main(){return 6 >= 6;}"
assert 0 "int main(){return 6 < 6;}"
assert 1 "int main(){return (1 + 3) ==4;}"
assert 1 "int main(){return (((( 1 + 1 ) ) )  )  < (2 * 2 / 2 * 2);}"

assert 3 "int main(){int a; a=3; return a;}"
assert 8 "int main(){int aa; aa = 3; int zzz; zzz = 5; return aa + zzz;}"
assert 8 "int main(){int foo123; foo123=3; int bar; bar=5; return foo123+bar;}"

assert 3 "int main(){if (0) return 2; return 3;}"
assert 3 "int main(){if (1-1) return 2; return 3;}"
assert 2 "int main(){if (1) return 2; return 3;}"
assert 2 "int main(){if (2 - 1) return 2; return 3;}"
assert 10 "int main(){int i; i = 0; while (i < 10) i= i + 1; return i;}"

assert 10 "int main(){return (rev10());} int rev10(){return (10);}"
assert 11 "int main(){return (add(1, 10));} int add(int a, int b){return (a + b);}"
assert 55 "int main(){return (fib(9));} int fib(int x){if(x<=1) return 1; return (fib(x-1)+fib(x-2));}"

assert 7 "int main(){int x; x=7; return *(&x);}"
assert 7 "int main(){int x; x=5; int y; y=&x; *y=7; return x;}"

echo OK
