### BEGIN ejudge auto-generated makefile ###
EJUDGE_PREFIX_DIR ?= /home/ejudge/inst-ejudge
EJUDGE_CONTESTS_HOME_DIR ?= /home/judges
EJUDGE_SERVER_BIN_PATH ?= /home/ejudge/inst-ejudge/bin

CC = gcc
CFLAGS = -Wall -g -O2 -std=gnu99 -Wno-pointer-sign
CLIBS = -lm

EXECUTE = ${EJUDGE_PREFIX_DIR}/bin/ejudge-execute
EXECUTE_FLAGS =  --use-stdin --use-stdout --test-pattern=%02d --corr-pattern=%02d.a

NORMALIZE = ${EJUDGE_SERVER_BIN_PATH}/ej-normalize
NORMALIZE_FLAGS = --workdir=tests --test-pattern=%02d --corr-pattern=%02d.a --type=nl

all : solutions/b_gcc
check_settings : all normalize



normalize :
	${NORMALIZE} ${NORMALIZE_FLAGS} --all-tests

solutions/b_gcc : solutions/b_gcc.c
	cd "solutions" && ${CC} -DEJUDGE ${CFLAGS} b_gcc.c -ob_gcc ${CLIBS}
clean :
	-rm -f *.o *.class *.exe *~ *.bak solutions/*.o solutions/b_gcc

### END ejudge auto-generated makefile ###
