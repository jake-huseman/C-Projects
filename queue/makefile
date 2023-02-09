queue : queue.c
	gcc queue.c -o queue
	#gcc -Wall -Werror - ggdb queue.c -o queue
#queue: main.o queue.o
	#gcc main.o queue.o -o queue
#main.o: main.c queue.h
	#gcc -Wall -Werror -ggdb main.c -c
#queue.o: queue.c queue.h
	#gcc -Wall -Werror -ggdb queue.c -c
clean:
	rm -f clean *~ core
	#rm -f queue.o main.o queue