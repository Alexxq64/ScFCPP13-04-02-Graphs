// ScFCPP13 04 02.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include "graph.h"
#include "task.h"
#include <iostream>
using namespace std;

int main() {
	Graph g;
	//g = new Graph();
	//cifr(g);
	//g.showMatrix();
	//g.addVertex(5);
	//g.addEdge(0, 5, 25);
	//g.showMatrix();
	//g.addVertex(7);
	//g.addEdge(0, 7, 35);
	//g.showMatrix();
	//cifr(g);
	//g.showMatrix();
	//g.delVertex(1);
	//g.showMatrix();

	g.addVertex(0);
	g.addVertex(1);
	g.addVertex(2);
	g.addVertex(3);
	g.addVertex(4);
	//g.addVertex(5);
	//g.addVertex(6);
	//g.addVertex(7);
	//g.addVertex(8);

	g.addEdge(0, 1, 10);
	g.addEdge(0, 2, 20);
	g.addEdge(0, 3, 15);
	g.addEdge(2, 3, 5);
	//g.addEdge(2, 5);
	g.addEdge(1, 4, 8);
	g.addEdge(4, 3, 11);
	//g.addEdge(5, 3);
	//g.addEdge(4, 7);
	//g.addEdge(3, 6);
	//g.addEdge(3, 7);
	//g.addEdge(3, 8);
	//g.addEdge(5, 8);
	//g.addEdge(8, 6);
	//g.addEdge(7, 6);
	g.showMatrix();

	g.depthFirstSearch(0);
	g.breadthFirstSearch(0);
	cout << "Path quantity " << g.findPathCount(0, 4) << endl;

	cout << "Min path: " << g.findMinWayDFS(0, 4);
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
