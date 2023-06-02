CycleTest: CycleTest.exe
	./CycleTest.exe
invertList: invertList.exe
	./invertList.exe
rotateList: rotateList.exe
	./rotateList.exe
rotateList.exe: rotateList.o LinkedFunctionsImplement.o
	gcc -o rotateList.exe rotateList.o LinkedFunctionsImplement.o
invertList.exe: invertList.o LinkedFunctionsImplement.o
	gcc -o invertList.exe invertList.o LinkedFunctionsImplement.o
CycleTest.exe: CycleTest.o LinkedFunctionsImplement.o
	gcc -o CycleTest.exe CycleTest.o LinkedFunctionsImplement.o
CycleTest.o: CycleTest.c
	gcc -c CycleTest.c
rotateList.o: rotateList.c
	gcc -c rotateList.c
invertList.o: invertList.c
	gcc -c invertList.c
LinkedFunctionsImplement.o: LinkedFunctionsImplement.c
	gcc -c LinkedFunctionsImplement.c
clean:
	rm *.o
	rm *.exe