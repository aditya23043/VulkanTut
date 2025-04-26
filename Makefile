something: src/main.c
	gcc src/main.c -o bin/main

run: bin/main
	./bin/main
