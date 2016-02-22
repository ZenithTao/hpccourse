EXECS=mpi_hello_world
MPICC?=/usr/lib64/openmpi/bin/mpicc

all: ${EXECS}

mpi_hello_world: lab5.c
	${MPICC} -o lab lab5.c

clean:
	rm -f ${EXECS}
