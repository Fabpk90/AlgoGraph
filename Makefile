run: compile
	./graph

compile:
	gcc -Wall main.c Util/graph.c -O2 -o graph
