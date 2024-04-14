GCC=gcc
STDFLAGS=-Wall -Werror -Wextra -std=c11
TARGET=libquadratic.a

libquadratic.a: quadratic_equation.o
	$(GCC) -c $(STDFLAGS) quadratic_equation.c
	ar rcs libquadratic.a quadratic_equation.o
	rm -rf quadratic_equation.o

check: $(TARGET) 
	$(GCC) $(STDFLAGS) ./test/test_quadratic_equation.c $(TARGET)  -o test_quadratic_equation -lcheck
	./test_quadratic_equation

rebuild: clean check

clean: 
	rm -rf test_quadratic_equation
	rm -rf libquadratic.a
