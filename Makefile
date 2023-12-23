build:
	gcc -o renderer -Wall -std=c99 ./src/*.c -IC:/SDL2/include -lSDL2main -lSDL2 -lm -LC:/SDL2/lib/x64

build_mac:
	gcc -Wall -std=c99 ./src/*.c -I include -L lib -lSDL2 -lm -o renderer

run:
	./renderer.exe

run_mac:
	./renderer

clean:
	del renderer.exe
	
