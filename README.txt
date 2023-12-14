-------- WINDOWS --------

choco install mingw

choco install make

download SDL2, extract to C:\SDL2

include SDL2 in C extension path in VSCode

get the SDL2.dll from C:\SDL2\lib\x64 and put it in the same folder as the executable

the main method must have the following signature: int main(int argc, char* args[])

build with these args: gcc -o renderer -Wall -std=c99 ./src/*.c -IC:/SDL2/include -lSDL2main -lSDL2 -LC:/SDL2/lib/x64

run with ./renderer.exe
