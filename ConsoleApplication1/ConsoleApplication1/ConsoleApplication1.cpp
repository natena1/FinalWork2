// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <queue>
using namespace std;

const int n = 6; // какой-то коэффициент
int dist[n] = { 0, 0, 0, 0, 0, 0 }; // массив меток посещённых вершин
									//матрица смежности графа
int graph[n][n] =
{
	{ 0, 2, 3, 0, 2, 1 },
	{ 2, 0, 0, 5, 0, 0 },
	{ 3, 0, 0, 0, 6, 0 },
	{ 0, 5, 0, 0, 0, 0 },
	{ 0, 0, 1, 0, 0, 0 },
	{ 1, 0, 0, 0, 0, 0 }
};

queue < int > q;

int main() {
	setlocale(LC_CTYPE, "rus");
	int i, x, v;
	for (i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << graph[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "Введите номер стартовой вершины" << "\n";
	x = 0;

	for (i = 0; i < n; i++) {
		dist[i] = 1000;
	}
	q.push(x);
	dist[x] = 0;
	while (!q.empty()) {
		v = q.front();
		q.pop();
		for (i = 0; i < n; i++) {
			if ((dist[i] > (dist[v] + graph[v][i])) && graph[v][i]) {
				q.push(i);
				dist[i] = dist[v] + graph[v][i];
			}
		}
	}
	cout << "Расстояния от вершины " << x << " до остальных" << "\n";
	for (i = 0; i < n; i++) {
		cout << dist[i] << " ";
	}
	system("pause");
	return 0;
}


