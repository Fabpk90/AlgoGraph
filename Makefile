run: compile
	./graph

compile:
	gcc -g3 -Wall main.c Util/dijk.c Util/fileHandler.c Util/graph.c -o graph
