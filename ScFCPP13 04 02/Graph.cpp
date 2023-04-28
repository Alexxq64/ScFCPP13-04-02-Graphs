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
void Graph::addEdge(int v1, int v2, int weight)
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
void Graph::depthFirstSearch(int start) {
	bool visited[SIZE];
	for (size_t i = 0; i < SIZE; i++) {
		visited[i] = false;
	}
	recurDepth(start, visited);
	cout << endl;
}

void Graph::recurDepth(int current, bool visited[]) {
	cout << "v" << current << " -> ";
	visited[current] = true;
	for (size_t i = 0; i < SIZE; i++) {
		if (edgeExists(current, i) && !visited[i])
			recurDepth(i, visited);
	}
}

void Graph::breadthFirstSearch(int start) {
	int queue_to_visit[SIZE]; // очередь вершин для обхода
	int queueCount = 0;

	bool visited[SIZE]; // список посещенных вершин
	for (int i = 0; i < SIZE; i++)
		visited[i] = false;

	queue_to_visit[queueCount++] = start; // кладем в очередь начальную вершину
	while (queueCount > 0)
	{
		// взятие из очереди вершины
		int current = queue_to_visit[0];
		queueCount--;
		for (int i = 0; i < queueCount; i++)
		{
			queue_to_visit[i] = queue_to_visit[i + 1];
		}
		visited[current] = true;
		std::cout << "v" << current << " -> ";
		// поиск смежных вершин и добавление их в очередь
		for (int i = 0; i < SIZE; i++)
		{
			bool alreadyAdded = false;
			for (int j = 0; j < queueCount; j++)
				if (queue_to_visit[j] == i)
				{
					alreadyAdded = true;
					break;
				}
			if (!alreadyAdded && edgeExists(current, i) && !visited[i])
				queue_to_visit[queueCount++] = i;
		}
	}
	std::cout << std::endl;
}

//void Graph::recurBreadth(int current, bool visited[]) {
//	cout << "v" << current << " -> ";
//	visited[current] = true;
//	for (size_t i = 0; i < SIZE; i++) {
//		if (edgeExists(current, i) && !visited[i])
//			recurDepth(i, visited);
//	}
//	cout << "v" << current << " -> ";
//	visited[current] = true;
//	while (edgeExists);
//}

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

int length;
int pathDepth = 0;
int path[SIZE - 1];
int Graph::findPathCount(int from, int to) {
	pathDepth = 0;
	int count = 0;
	length = 0;
	bool visited[SIZE]; // список посещенных вершин
	for (int i = 0; i < SIZE; i++)
		visited[i] = false; // инициализируем как непосещенные
	findPathCountAll(from, to, visited, count); // запуск алгоритма  
	//std::cout << "Number of paths from " << from << " to " << to << " = " << count << std::endl;
	return count;
}


void Graph::findPathCountAll(int current, int to, bool visited[], int& count)
{
	//cout << "V" << current << "  N" << count << "  L" << length << "  ";
	if (current == to)
	{
		// если дошли до второй вершины, увеличиваем счётчик путей
		// и выходим
		for (size_t i = 0; i < pathDepth; i++) {
			cout << path[i] << " ";
		}
		cout << to << endl;
		count++;
		pathDepth--;
		return;
	}
	visited[current] = true; // отмечаем как посещенную
	for (int i = 0; i < SIZE; i++)
	{
		if (edgeExists(current, i) && !visited[i])
		{
			path[pathDepth++] = current;
			findPathCountAll(i, to, visited, count);
		}
	}
	// отмечаем, что путь уже не содержит эту вершину
	pathDepth--;
	visited[current] = false;
}

//void Graph::findPathCountAll(int from, int to, bool visited[], int& count)
//// !!!!!!!!!!!!!!! Show pathes
//{
//	//for (int i = 0; i < vertexCount; i++) {
//	//	if (i == to) {
//	//		++count;
//	//		cout << "V" << to << endl;
//	//	}
//	//	else
//	//		if (edgeExists(from, i) && !visited[i]) {
//	//			visited[from] = true; // помечаем как посещенную
//	//			cout << "V" << i << " -> ";
//	//			findPathCountAll(i, to, visited, count);
//	//		}
//	//	visited[from] = false;
//	//}
//
//	visited[from] = true; // помечаем как посещенную
//
//
//	for (int i = 0; i < vertexCount; i++)
//	{
//		if (edgeExists(from, i) && !visited[i])
//			if (i != to) {
//				cout << "V i " << i << "  V from " << from << "-> ";
//				findPathCountAll(i, to, visited, count);
//
//			}
//			else
//			{
//				++count;
//				cout << "V" << to << endl;
//			}
//
//	}
//	visited[from] = false;
//}

void Graph::findPathLength(int current, int to, bool visited[], int& length)
{
	//static int pathDepth = 0;
	//int path[SIZE - 1];
	int currentPath = 0;
	if (current == to)
	{
		// если дошли до второй вершины, увеличиваем счётчик путей
		// и выходим
		path[pathDepth] = current;
		for (size_t i = 0; i < pathDepth; i++) {
			//cout << " <V" << path[i] << ">  " << 1;
			//currentPath += 1;
			cout << " <V" << path[i] << "> " << matrix[path[i]][path[i + 1]];
			currentPath += matrix[path[i]][path[i + 1]];
		}
		cout << " <V" << to << "> ";
		length = (length == 0) ? currentPath : (currentPath < length) ? currentPath : length;
		cout << "   =   " << currentPath << endl;
		pathDepth--;
		return;
	}
	visited[current] = true; // отмечаем как посещенную
	for (int i = 0; i < SIZE; i++)
	{
		if (edgeExists(current, i) && !visited[i])
		{
			path[pathDepth++] = current;
			findPathLength(i, to, visited, length);
		}
	}
	// отмечаем, что путь уже не содержит эту вершину
	pathDepth--;
	visited[current] = false;
}

int Graph::findMinWayDFS(int v1, int v2)
{
	int length = 0;
	pathDepth = 0;
	bool visited[SIZE]; // список посещенных вершин
	for (int i = 0; i < SIZE; i++)
		visited[i] = false; // инициализируем как непосещенные
	findPathLength(v1, v2, visited, length); // запуск алгоритма  
	//std::cout << "Number of paths from " << from << " to " << to << " = " << length << std::endl;
	return length;
}

