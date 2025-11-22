nasm -f win64 convert.asm -o convert.o
gcc -c timer.c -o timer.o
gcc convert.o timer.o -o timer.exe
timer.exe