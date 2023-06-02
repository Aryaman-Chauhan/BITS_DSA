runStackWithArray.exe: stackDriver.o stack_array.o heap_usage.o
	gcc -o runStackWithArray.exe stackDriver.o stack_array.o heap_usage.o
	./runStackWithArray.exe

runStackWithList.exe: stackDriver.o stack_ll.o linked_list.o heap_usage.o
	gcc -o runStackWithList.exe stackDriver.o stack_ll.o linked_list.o heap_usage.o
	./runStackWithList.exe

linked_list.o: linked_list.c
	gcc -c linked_list.c

stack_ll.o: stack_ll.c
	gcc -c stack_ll.c

heap_usage.o:heap_usage.c
	gcc -c heap_usage.c

stackDriver.o: stackDriver.c stack.h
	gcc -c stackDriver.c

stack_array.o: stack_array.c stack.h
	gcc -c stack_array.c
	
clean:
	rm -f *.o 
	rm *.exe