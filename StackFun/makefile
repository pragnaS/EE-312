# target: dependencies
# <tab> rule

# make (without arguments) executes first rule in file
# Ideally, one target for every object file and a target for final binary. 

checker: stack_arr.o checker.o
	c99 -o checker stack_arr.o checker.o

stack_arr.o: stack_arr.c
	c99 -c stack_arr.c

checker.o: checker.c
	c99 -c checker.c


