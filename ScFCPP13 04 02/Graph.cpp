#include "graph.h"
#include <iostream>
#include <iomanip>
using namespace std;

Graph::Graph() {
	for (int i = 0; i < SIZE; i++)
		for (int j = 0; j < SIZE; j++)
			matrix[i][j] = 0;
	vertexCount = 0;
	for (size_t i = 0; i < SIZE; i++) {
		vertexes[i] = 0;
	}
}
// добавление вершины
void Graph::addVertex(int vnumber)
{
	vertexes[vertexCount] = vnumber;
	vertexCount++;
}
// добавление ребра
void Graph::addEdge(int v1, int v2, int weight = 1)
{
	matrix[v1][v2] = weight;
	matrix[v2][v1] = weight;
}
void Graph::delVertex(int vnumber)
{
	//vertexes[vertexCount] = vnumber;
	size_t number;
	for (number = 0; number < vertexCount; number++)
		if (vertexes[number] == vnumber) break;
	vertexCount--;
	for (; number < vertexCount; number++) {
		vertexes[number] = vertexes[number + 1];
	}
	for (size_t i = 0; i < SIZE; i++) {
		matrix[vnumber][i] = 0;
		matrix[i][vnumber] = 0;
	}
}
void Graph::delEdge(int v1, int v2)
{
	matrix[v1][v2] = 0;
	matrix[v2][v1] = 0;
}
void Graph::showMatrix() {
	for (size_t i = 0; i < SIZE; i++) {
		cout << setw(3) << vertexes[i] << " ";
	}
	cout << endl << "--------------------------------" << endl;
	for (size_t i = 0; i < SIZE; i++) {
		for (size_t j = 0; j < SIZE; j++) {
			cout << setw(3) << matrix[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}
// проверка существования ребра
bool Graph::edgeExists(int v1, int v2)
{
	return matrix[v1][v2] > 0;
}
// проверка существования вершины
bool Graph::vertexExists(int v)
{
	for (int i = 0; i < vertexCount; i++)
		if (vertexes[i] == v)
			return true;
	return false;
}
