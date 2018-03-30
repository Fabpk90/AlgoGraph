run: compile
	./graph

compile:
	gcc main.c Util/graph.c -O2 -o graph
