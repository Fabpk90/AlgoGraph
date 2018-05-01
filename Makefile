run: compile
	./graph

compile:
	gcc -g3 -Wall main.c Util/fileHandler.c Util/graph.c -O2 -o graph
