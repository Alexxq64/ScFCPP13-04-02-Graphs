#pragma once
#ifndef __GRAPH__
#define __GRAPH__

#define SIZE 10




class Graph {
public:
	Graph();
	// ���������� �������
	void addVertex(int vnumber);
	// ���������� �����
	void addEdge(int v1, int v2, int weight = 1);
	// �������� �������
	void delVertex(int vnumber);
	// �������� �����
	void delEdge(int v1, int v2);
	void showMatrix();

	void depthFirstSearch(int start);
	void recurDepth(int start, bool visited[]);
	void breadthFirstSearch(int start);
	//void recurBreadth(int start, bool visited[]);

	int findMinWayDFS(int v1, int v2);
	void findPathLength(int v1, int v2, bool visited[], int& length);

	int findPathCount(int from, int to);
	void findPathCountAll(int from, int to, bool visited[], int& count);

	//friend bool test(Graph& g);
private:
	bool edgeExists(int v1, int v2);
	bool vertexExists(int v);

	int matrix[SIZE][SIZE]; // ������� ���������

	int vertexes[SIZE]; // ��������� ������
	int vertexCount; // ���������� ����������� ������
};
#endif