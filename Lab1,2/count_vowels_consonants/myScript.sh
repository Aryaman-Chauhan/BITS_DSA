gcc -c count_consonants.c
gcc -c master.c
gcc -o count_consonants_exe count_consonants.o master.o
rm *.o
./count_consonants_exe
