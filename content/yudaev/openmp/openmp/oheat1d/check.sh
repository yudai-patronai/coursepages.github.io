#!./roundup

gcc -O2 -o heat heat.c
gcc -O2 -fopenmp -o heat1 heat1.c
gcc -O2 -fopenmp -o heat2 heat2.c

it_check_N10P1() {
	./heat 10 0.1 > s.txt
	OMP_NUM_THREADS=1 ./heat1 10 0.1 > p.txt
	diff -q s.txt p.txt
}

it_check_N10P2() {
	./heat 10 0.1 > s.txt
	OMP_NUM_THREADS=2 ./heat1 10 0.1 > p.txt
	diff -q s.txt p.txt
}

it_check_N10P3() {
	./heat 10 0.1 > s.txt
	OMP_NUM_THREADS=3 ./heat1 10 0.1 > p.txt
	diff -q s.txt p.txt
}

it_check_N10P7() {
	./heat 10 0.1 > s.txt
	OMP_NUM_THREADS=7 ./heat1 10 0.1 > p.txt
	diff -q s.txt p.txt
}

it_check_N10P9() {
	./heat 10 0.1 > s.txt
	OMP_NUM_THREADS=9 ./heat1 10 0.1 > p.txt
	diff -q s.txt p.txt
}

it_check_N100P2() {
	./heat 100 0.1 > s.txt
	OMP_NUM_THREADS=2 ./heat1 100 0.1 > p.txt
	diff -q s.txt p.txt
}

it_check_N100P7() {
	./heat 100 0.1 > s.txt
	OMP_NUM_THREADS=7 ./heat1 100 0.1 > p.txt
	diff -q s.txt p.txt
}

it_check2_N10P1() {
	./heat 10 0.1 > s.txt
	OMP_NUM_THREADS=1 ./heat2 10 0.1 > p.txt
	diff -q s.txt p.txt
}

it_check2_N10P2() {
	./heat 10 0.1 > s.txt
	OMP_NUM_THREADS=2 ./heat2 10 0.1 > p.txt
	diff -q s.txt p.txt
}

it_check2_N10P3() {
	./heat 10 0.1 > s.txt
	OMP_NUM_THREADS=3 ./heat2 10 0.1 > p.txt
	diff -q s.txt p.txt
}

it_check2_N10P7() {
	./heat 10 0.1 > s.txt
	OMP_NUM_THREADS=7 ./heat2 10 0.1 > p.txt
	diff -q s.txt p.txt
}

it_check2_N10P9() {
	./heat 10 0.1 > s.txt
	OMP_NUM_THREADS=9 ./heat2 10 0.1 > p.txt
	diff -q s.txt p.txt
}

it_check2_N100P2() {
	./heat 100 0.1 > s.txt
	OMP_NUM_THREADS=2 ./heat2 100 0.1 > p.txt
	diff -q s.txt p.txt
}

it_check2_N100P7() {
	./heat 100 0.1 > s.txt
	OMP_NUM_THREADS=7 ./heat2 100 0.1 > p.txt
	diff -q s.txt p.txt
}
