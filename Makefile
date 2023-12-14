build:
	gcc -o renderer -Wall -std=c99 ./src/*.c -IC:/SDL2/include -lSDL2main -lSDL2 -LC:/SDL2/lib/x64

run:
	./renderer.exe

clean:
	del renderer.exe
	