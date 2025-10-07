#!./roundup

gcc -O2 -o int int.c -lm
gcc -fopenmp -O2 -o tint1 tint1.c -lm
gcc -fopenmp -O2 -o tint2 tint2.c -lm

it_check_N10P1() {
	test `./int 10` "=" `OMP_NUM_THREADS=1 ./tint1 10`
}

it_check_N10P2() {
	test `./int 10` "=" `OMP_NUM_THREADS=2 ./tint1 10`
}

it_check_N10P3() {
	test `./int 10` "=" `OMP_NUM_THREADS=3 ./tint1 10`
}

it_check_N10P7() {
	test `./int 10` "=" `OMP_NUM_THREADS=7 ./tint1 10`
}

it_check_N10P9() {
	test `./int 10` "=" `OMP_NUM_THREADS=9 ./tint1 10`
}

it_check_N100P2() {
	test `./int 100` "=" `OMP_NUM_THREADS=2 ./tint1 100`
}

it_check_N100P7() {
	test `./int 100` "=" `OMP_NUM_THREADS=7 ./tint1 100`
}

it_check_N10P1() {
	test `./int 10` "=" `OMP_NUM_THREADS=1 ./tint2 10`
}

it_check_N10P2() {
	test `./int 10` "=" `OMP_NUM_THREADS=2 ./tint2 10`
}

it_check_N10P3() {
	test `./int 10` "=" `OMP_NUM_THREADS=3 ./tint2 10`
}

it_check_N10P7() {
	test `./int 10` "=" `OMP_NUM_THREADS=7 ./tint2 10`
}

it_check_N10P9() {
	test `./int 10` "=" `OMP_NUM_THREADS=9 ./tint2 10`
}

it_check_N100P2() {
	test `./int 100` "=" `OMP_NUM_THREADS=2 ./tint2 100`
}

it_check_N100P7() {
	test `./int 100` "=" `OMP_NUM_THREADS=7 ./tint2 100`
}
