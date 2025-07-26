nasm HatsanPlayer.asm -o HatsanPlayer.o
gcc -c HatsanPlayerC.c
gcc -shared HatsanPlayer.o HatsanPlayerC.o -o HatsanPlayer.dll