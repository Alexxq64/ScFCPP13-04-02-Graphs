#include "graph.h"
#include "task.h"

void cifr(Graph& g) {
	g.addVertex(0);
	g.addVertex(1);
	g.addVertex(2);
	g.addVertex(3);

	// добавляем ребра
	g.addEdge(0, 2, 4);
	g.addEdge(1, 2, 11);
	g.addEdge(0, 1, 5);
	g.addEdge(0, 3, 3);
	g.addEdge(2, 3, 9);
}