proj1:func1.o func2.o func3.o main.o
	gcc func1.o func2.o func3.o main.o -o proj1
func1.o:func1.c
	gcc func1.c -c
func2.o:func2.c
	gcc func2.c -c
func3.o:func3.c
	gcc func3.c -c
main.o:main.c
	gcc main.c -c
clean:
	rm -f *.o
