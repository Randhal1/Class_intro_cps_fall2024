EXEC= Example2.1 Example3.2 Example3.3 Example3.5 Example3.6 Example4.1 \
      Example4.2 Example5.1 Example6.1 Example6.6 Example7.1 Example7.2 \
      Example7.3 Example7.4 Example7.5

all: $(EXEC)

Example2.1: Example2.1.c
	gcc -o Example2.1 Example2.1.c

Example3.2: Example3.2.c
	gcc -o Example3.2 Example3.2.c

Example3.3: Example3.3.c
	gcc -o Example3.3 Example3.3.c

Example3.5: Example3.5.c
	gcc -o Example3.5 Example3.5.c

Example3.6: Example3.6.c
	gcc -o Example3.6 Example3.6.c

Example4.1: Example4.1.c
	gcc -o Example4.1 Example4.1.c

Example4.2: Example4.2.c
	gcc -o Example4.2 Example4.2.c

Example5.1: Example5.1.c
	gcc -o Example5.1 Example5.1.c

Example6.1: Example6.1.c
	gcc -o Example6.1 Example6.1.c

Example6.6: Example6.6.c
	gcc -o Example6.6 Example6.6.c -lm

Example7.1: Example7.1.c
	gcc -o Example7.1 Example7.1.c -lblas

Example7.2: Example7.2.c
	gcc -o Example7.2 Example7.2.c -Wl,-Bstatic -llapacke -Wl,-Bdynamic -llapack -lblas

Example7.3: Example7.3.c
	gcc -o Example7.3 Example7.3.c -Wl,-Bstatic -llapacke -Wl,-Bdynamic -llapack -lblas

Example7.4: Example7.4.c
	gcc -o Example7.4 Example7.4.c -lfftw3 -lm

Example7.5: Example7.5.c
	gcc -o Example7.5 Example7.5.c -lm

clean: 
	-rm $(EXEC)
	-rm *~
	-rm *.dat
