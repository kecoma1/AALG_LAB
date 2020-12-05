#-----------------------
# IMPORTANTE: The values of the parameters for exercise?_test have to be conveniently adjusted.
# It is assumed that the name of the source files is exercise1.c, exercise2.c,...,exercise.h
#-----------------------

CC = gcc -O3 -ansi -pedantic -g
CFLAGS = -Wall
EXE = exercise1 exercise2

all : $(EXE) main.o main_exe

.PHONY : clean
clean :
	rm -f *.o core $(EXE)

$(EXE) : % : %.o sorting.o search.o times.o permutations.o
	@echo "#---------------------------"
	@echo "# Generating $@ "
	@echo "# Depepends on $^"
	@echo "# Has changed $<"
	$(CC) $(CFLAGS) -o $@ $@.o sorting.o search.o times.o permutations.o

permutations.o : permutations.c permutations.h
	@echo "#---------------------------"
	@echo "# Generating $@ "
	@echo "# Depepends on $^"
	@echo "# Has changed $<"
	$(CC) $(CFLAGS) -c $<

sorting.o : sorting.c sorting.h
	@echo "#---------------------------"
	@echo "# Generating $@ "
	@echo "# Depepends on $^"
	@echo "# Has changed $<"
	$(CC) $(CFLAGS) -c $<

search.o : search.c search.h
	@echo "#---------------------------"
	@echo "# Generating $@ "
	@echo "# Depepends on $^"
	@echo "# Has changed $<"
	$(CC) $(CFLAGS) -c $<

times.o : times.c times.h
	@echo "#---------------------------"
	@echo "# Generating $@ "
	@echo "# Depepends on $^"
	@echo "# Has changed $<"
	$(CC) $(CFLAGS) -c $<

main.o:
	$(CC) $(CFLAGS) -c main.c

main_exe:
	$(CC) $(CFLAGS) -o main main.o sorting.o search.o times.o permutations.o


exercise1_test:
	@echo Running exercise1
	@./exercise1 -size 15000 -key 12
	@echo Running exercise1 with valgrind
	@valgrind --leak-check=full ./exercise1 -size 15000 -key 5679

exercise2_test:
	@echo Running exercise2
	@./exercise2 -num_min 1000 -num_max 50000 -incr 100 -n_times 1 -outputFile exercise5.log
	@echo Running exercise2 with valgrind
	@valgrind --leak-check=full ./exercise2 -num_min 10 -num_max 1500 -incr 10 -n_times 1 -outputFile v_exercise5.log