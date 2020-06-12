#pragma once
#include <glut.h>
#include <stdio.h>
#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

int WinW;
int WinH;
const int maxSize = 20;

template<class T>

class Graph
{
	vector<T> vertList;
	int adjMatrix[maxSize][maxSize] = { 0 };
	vector<T> labelList;
	bool* visitedVerts = new bool[vertList.size()];
public:
	Graph();
	~Graph();
	void DrawGraph();
	void InsertEdge(const T& vertex1, const T& vertex2, int weight);
	void InsertVertex(const T& vertex);
	int GetVertPos(const T& vertex);
	bool IsEmpty();
	bool IsFull();
	int GetAmountVerts();
	int GetAmountEdges();
	int GetWeight(const T& vertex1, const T& vertex2);
	vector<T> GetNbrs(const T& vertex);
	void Print();
	void FillLabels(T& startVertex);
	int Dijkstra(T& startVertex);
	bool AllVisited(bool* visitedVerts);
};


int R;

struct vertCoord
{
	int x, y;
};
vertCoord vertC[20];

Graph<int> graph;

template<class T>
int Graph<T>::Dijkstra(T& startVertex)
{
	for (int i = 0; i < vertList.size(); i++)
		visitedVerts[i] = false;
	for (int i = 0; i < vertList.size(); i++)
		for (int j = 0; j < vertList.size(); j++)
			if (adjMatrix[i][j] < 0)
				return -1;
	if (GetVertPos(startVertex) == -1)
		return -2;
	T curSrc;
	int counter = 0;
	int minLabel = 1000000;
	vector<T> neighbors = GetNbrs(startVertex);
	for (int i = 0; i < neighbors.size(); ++i)
	{
		int startLabel = labelList[GetVertPos(startVertex)]; //метка текущей вершины
		int weight = GetWeight(startVertex, neighbors[i]);   //вес ребра до соседней вершины
		int nIndex = GetVertPos(neighbors[i]); //индекс соседней вершины
		int nextLabel = labelList[nIndex]; //метка соседней вершины
		if (startLabel + weight < nextLabel) //Если значение суммы текущей метки и веса ребра меньше значения соседней метки
			labelList[nIndex] = startLabel + weight; //Обновление соседней метки
		if (labelList[nIndex] < minLabel)
			minLabel = labelList[nIndex]; //Определение наименьшей метки у соседних вершин
	}

	for (int i = 0; i < neighbors.size(); ++i) //Все ли соседние вершины проверены
		if (labelList[GetVertPos(neighbors[i])] != 1000000)
			counter += 1;

	if (counter == neighbors.size()) //Текущая вершина помечается обработанной
		visitedVerts[GetVertPos(startVertex)] = true;

	for (int i = 0; i < neighbors.size(); ++i) //Поиск новой опорной вершины с наименьшей меткой
		if (labelList[GetVertPos(neighbors[i])] == minLabel)
			curSrc = neighbors[i];

	while (!AllVisited(visitedVerts)) //Пока все вершины не обработаны
	{
		neighbors = GetNbrs(curSrc); //Вектор соседей новой опорной вершины
		int count = 0;
		minLabel = 1000000;
		for (int i = 0; i < neighbors.size(); i++) //Обход соседних вершин
		{
			int curLabel = labelList[GetVertPos(curSrc)]; //Метка текущей опорной вершины
			int weight = GetWeight(curSrc, neighbors[i]); //Вес ребра до соседней вершины
			int nIndex = GetVertPos(neighbors[i]); //Индекс соседней вершины
			int nextLabel = labelList[nIndex]; //Метка соседней 

			if (curLabel + weight < nextLabel) //Если значение суммы текущей метки и веса ребра меньше значения соседней метки
				labelList[nIndex] = curLabel + weight; //Метка соседней вершины обновляется

			if (labelList[nIndex] < minLabel && visitedVerts[nIndex] != true) //Поиск минимальной метки среди не обработанных вершин
				minLabel = labelList[nIndex];

			count += 1; //Подсчёт посещённых соседей
		}
		if (count == neighbors.size()) //Если все соседи посещены
			visitedVerts[GetVertPos(curSrc)] = true; //Опорная вершина помечается обработанной

		for (int i = 0; i < neighbors.size(); ++i) //Поиск новой опорной вершины
			if (labelList[GetVertPos(neighbors[i])] == minLabel || visitedVerts[GetVertPos(neighbors[i])] != true)
				curSrc = neighbors[i];
	}

	for (int i = 0; i < GetVertPos(startVertex); ++i)
	{
		cout << "Кратчайшее расстояние от вершины " << startVertex << " до вершины " << vertList[i] << " равно " << labelList[GetVertPos(vertList[i])] << endl;
	}

	for (int i = GetVertPos(startVertex) + 1; i < vertList.size(); ++i)
	{
		cout << "Кратчайшее расстояние от вершины " << startVertex << " до вершины " << vertList[i] << " равно " << labelList[GetVertPos(vertList[i])] << endl;
	}
}

template <class T>
bool Graph<T>::AllVisited(bool* visitedVerts) //Проверка все ли вершины обработаны
{
	bool flag = true; //Изначально считается, что все вершины обработаны
	for (int i = 0; i < vertList.size(); i++)
		if (visitedVerts[i] != true)
			flag = false; //Если есть хотя бы одна необработанная вершина - флаг принимает значение false
	return flag; //Возвращается значение флага: true если все обработаны, false в ином случае
}


template<class T>
void Graph<T>::FillLabels(T& startVertex)
{
	for (int i = 0, size = vertList.size(); i < size; ++i)
	{
		labelList.push_back(1000000);
	}
	int pos = GetVertPos(startVertex);
	labelList[pos] = 0;
}


template<class T>
std::vector<T> Graph<T>::GetNbrs(const T& vertex) {
	std::vector<T> nbrsList; // создание списка соседей
	int vertPos = this->GetVertPos(vertex); // вычисление позиции vertex в матрице смежности
	if (vertPos != (-1)) {
		
			for (int i = 0, vertListSize = this->vertList.size(); i < vertListSize; ++i) {
				if (this->adjMatrix[vertPos][i] != 0 &&
					this->adjMatrix[i][vertPos] != 0) // вычисление соседей

					nbrsList.push_back(this->vertList[i]);

			}
	}
	return nbrsList;
}



template<class T>
void Graph<T>::InsertVertex(const T& vertex) {
	if (!this->IsFull()) {
		this->vertList.push_back(vertex);
	}
	else {
		cout << "Граф уже заполнен. Невозможно добавить новую вершину " << endl;
		return;
	}
}

template<class T>
int Graph<T>::GetAmountEdges() {
	int amount = 0; // обнуляем счетчик
	if (!this->IsEmpty()) { // проверяем, что граф не пуст
		for (int i = 0, vertListSize = this->vertList.size();
			i < vertListSize; ++i) {
			for (int j = 0; j < vertListSize; ++j) {
				if (this->adjMatrix[i][j] ==
					this->adjMatrix[j][i] &&
					this->adjMatrix[i][j] != 0) // находим рёбра
					amount += 1; // считаем количество рёбер
			}
		}
		return (amount / 2); // приводим счетчик к корректному результату и возвращаем его
	}
	else
		return 0; // если граф пуст, возвращаем 0
}

template<class T>
int Graph<T>::GetWeight(const T& vertex1, const T& vertex2) {
	if (!this->IsEmpty()) {
		int vertPos1 = GetVertPos(vertex1);
		int vertPos2 = GetVertPos(vertex2);
		return adjMatrix[vertPos1][vertPos2];
	}
	return 0;
}

template<class T>
int Graph<T>::GetAmountVerts() {
	return this->vertList.size();
}

template<class T>
bool Graph<T>::IsEmpty() {
	if (this->vertList.size() != 0)
		return false;
	else
		return true;
}

template<class T>
bool Graph<T>::IsFull() {
	return (vertList.size() == maxSize);
}

template <class T>
int Graph<T>::GetVertPos(const T& vertex) {
	for (int i = 0; i < this->vertList.size(); ++i) {
		if (this->vertList[i] == vertex)
			return i;
	}
	return -1;
}

template<class T>
Graph<T>::Graph() {
	for (int i = 0; i < maxSize; ++i)
	{
		for (int j = 0; j < maxSize; ++j)
		{
			this->adjMatrix[i][j] = 0;
		}
	}
}

template<class T>
Graph<T>::~Graph() {

}


Graph<int> makeGraph()
{
	Graph<int> graph; // создание графа, содержащего вершины с номерами целого типа
	int amountVerts, amountEdges, sourceVertex, targetVertex, edgeWeight; // создание необходимых для ввода графа переменных
	cout << "Введите количество вершин графа: "; cin >> amountVerts; cout << endl; // ввод количества рёбер графа в переменную amountVerts
	cout << "Введите количество ребер графа: "; cin >> amountEdges; cout << endl; // ввод количества рёбер графа в переменную amountEdges
	for (int i = 1; i <= amountVerts; ++i) {
		int* vertPtr = &i; // запоминаем адрес вершины с помощью указателя
		graph.InsertVertex(*vertPtr); //передаём ссылку на вершину в функцию InsertVertex; происходит вставка вершины в вектор вершин
	}

	for (int i = 0; i < amountEdges; ++i) {
		cout << "Исходная вершина: "; cin >> sourceVertex; cout << endl; // ввод исходной вершины
		int* sourceVertPtr = &sourceVertex; // запоминаем адрес исходной вершины
		cout << "Конечная вершина: "; cin >> targetVertex; cout << endl; // ввод вершины, до которой будет идти ребро от исходной вершины
		int* targetVertPtr = &targetVertex; // запоминаем адрес конечной вершины (до которой будет идти ребро от исходной вершины)

		cout << "Вес ребра: "; cin >> edgeWeight; cout << endl; // ввод числового значения веса ребра в переменную edgeWeight
		graph.InsertEdge(*sourceVertPtr, *targetVertPtr, edgeWeight); // вставка ребра весом edgeWeight между исходной и конечной вершинами
	}
	cout << endl;
	graph.Print();//печать матрицы смежности
	return graph;
}

template<class T>
void Graph<T>::InsertEdge(const T& vertex1, const T& vertex2, int weight) {
	if (this->GetVertPos(vertex1) != (-1) && this->GetVertPos(vertex2) != (-1)) {
		int vertPos1 = GetVertPos(vertex1);
		int vertPos2 = GetVertPos(vertex2);
		if (this->adjMatrix[vertPos1][vertPos2] != 0
			&& this->adjMatrix[vertPos2][vertPos1] != 0) {
			cout << "Ребро между вершинами уже есть" << endl;
			return;
		}
		else {
			this->adjMatrix[vertPos1][vertPos2] = weight;
			this->adjMatrix[vertPos2][vertPos1] = weight;
		}
	}
	else {
		cout << "Обеих вершин (или одной из них) нет в графе " << endl;
		return;
	}
}

template<class T>
void Graph<T>::Print() {
	if (!this->IsEmpty()) {
		cout << "Матрица смежности графа: " << endl;
		for (int i = 0, vertListSize = this->vertList.size(); i < vertListSize; ++i) {
			cout << this->vertList[i] << " ";
			for (int j = 0; j < vertListSize; ++j) {
				cout << " " << this->adjMatrix[i][j] << " ";
			}
			cout << endl;
		}
		T startVertex;
		cout << "Введите начальную вершину: ";
		cin >> startVertex;
		cout << endl;
		FillLabels(startVertex);
		Dijkstra(startVertex);
	}
	else {
		cout << "Граф пуст " << endl;
	}
}

void setCoord(int i, int n)
{
	int R_;

	int x0 = WinW / 2;
	int y0 = WinH / 2;
	if (WinW > WinH)
	{
		R = 5 * (WinH / 13) / n;
		R_ = WinH / 2 - R - 10;
	}
	else {
		R = 5 * (WinW / 13) / n;
		R_ = WinW / 2 - R - 10;
	}
	float theta = 2.0f * 3.1415926f * float(i) / float(n);
	float y1 = R_ * cos(theta) + y0;
	float x1 = R_ * sin(theta) + x0;

	vertC[i].x = x1;
	vertC[i].y = y1;
}

void drawCircle(int x, int y, int R) //рисуем круг в заданных координатах
{
	glColor3f(1.0, 1.0, 1.0);
	float x1, y1;
	glBegin(GL_POLYGON);
	for (int i = 0; i < 360; i++)
	{
		float theta = 2.0f * 3.1415926f * float(i) / float(360);
		y1 = R * cos(theta) + y;
		x1 = R * sin(theta) + x;;
		glVertex2f(x1, y1);
	}
	glEnd();

	glColor3f(0.0f, 0.0f, 0.0f);
	float x2, y2;
	glBegin(GL_LINE_LOOP);
	for (int i = 0; i < 360; i++)
	{
		float theta = 2.0f * 3.1415926f * float(i) / float(360);
		y2 = R * cos(theta) + y;
		x2 = R * sin(theta) + x;
		glVertex2f(x2, y2);
	}
	glEnd();
}

void drawText(int nom, int x1, int y1)
{
	GLvoid* font = GLUT_BITMAP_HELVETICA_18;
	string s = to_string(nom);
	glRasterPos2i(x1 - 5, y1 - 5);
	for (int j = 0; j < s.length(); j++)
		glutBitmapCharacter(font, s[j]);
}

void drawVertex(int n)
{
	for (int i = 0; i < n; i++) {
		drawCircle(vertC[i].x, vertC[i].y, R);
		drawText(i + 1, vertC[i].x, vertC[i].y);
	}
}

void drawLine(int text, int x0, int y0, int x1, int y1) //ребро неориентированный взвешенный граф
{
	glColor3f(0.0f, 0.0f, 0.0f);
	glBegin(GL_LINES);
	glVertex2i(x0, y0);
	glVertex2i(x1, y1);
	glEnd();

	drawText(text, (x0 + x1) / 2 + 10, (y0 + y1) / 2 + 10);
}


template<class T>
void Graph<T>::DrawGraph()
{
	int n = vertList.size();
	for (int i = 0; i < n; i++)
	{
		setCoord(i, n);
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			int a = adjMatrix[i][j];
			if (a != 0)
			{
				drawLine(a, vertC[i].x, vertC[i].y, vertC[j].x, vertC[j].y);
			}
		}
	}
	drawVertex(n);
}

void reshape(int w, int h)
{
	WinW = w;
	WinH = h;
	glViewport(0, 0, (GLsizei)WinW, (GLsizei)WinH);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, (GLdouble)WinW, 0, (GLdouble)WinH);
	glutPostRedisplay();
}

void display()
{
	glShadeModel(GL_SMOOTH);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, WinW, 0, WinH); //ставим начало координат в левый нижний угол
	glViewport(0, 0, WinW, WinH);
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);

	graph.DrawGraph();

	glutSwapBuffers();
}


/*
int WinW;
int WinH;
const int maxSize = 20;

template<class T>

class Graph
{
	vector<T> vertList;
	int adjMatrix[maxSize][maxSize] = { 0 };
	vector<T> labelList;
	bool* visitedVerts = new bool[vertList.size()];
public:
	Graph();
	~Graph();
	void DrawGraph();
	void InsertEdge(const T& vertex1, const T& vertex2, int weight);
	void InsertVertex(const T& vertex);
	int GetVertPos(const T& vertex);
	bool IsEmpty();
	bool IsFull();
	int GetAmountVerts();
	int GetAmountEdges();
	int GetWeight(const T& vertex1, const T& vertex2);
	vector<T> GetNbrs(const T& vertex);
	void Print();
	void FillLabels(T& startVertex);
	int Dijkstra(T& startVertex);
	bool AllVisited(bool* visitedVerts);
};


int R;

struct vertCoord
{
	int x, y;
};
vertCoord vertC[20];

Graph<int> graph;

template<class T>
int Graph<T>::Dijkstra(T& startVertex)
{
	for (int i = 0; i < vertList.size(); i++)
		visitedVerts[i] = false;
	for (int i = 0; i < vertList.size(); i++)
		for (int j = 0; j < vertList.size(); j++)
			if (adjMatrix[i][j] < 0)
				return -1;
	if (GetVertPos(startVertex) == -1)
		return -2;
	T curSrc;
	int counter = 0;
	int minLabel = 1000000;
	vector<T> neighbors = GetNbrs(startVertex);
	for (int i = 0; i < neighbors.size(); ++i)
	{
		int startLabel = labelList[GetVertPos(startVertex)]; //метка текущей вершины
		int weight = GetWeight(startVertex, neighbors[i]);   //вес ребра до соседней вершины
		int nIndex = GetVertPos(neighbors[i]); //индекс соседней вершины
		int nextLabel = labelList[nIndex]; //метка соседней вершины
		if (startLabel + weight < nextLabel) //Если значение суммы текущей метки и веса ребра меньше значения соседней метки
			labelList[nIndex] = startLabel + weight; //Обновление соседней метки
		if (labelList[nIndex] < minLabel)
			minLabel = labelList[nIndex]; //Определение наименьшей метки у соседних вершин
	}

	for (int i = 0; i < neighbors.size(); ++i) //Все ли соседние вершины проверены
		if (labelList[GetVertPos(neighbors[i])] != 1000000)
			counter += 1;

	if (counter == neighbors.size()) //Текущая вершина помечается обработанной
		visitedVerts[GetVertPos(startVertex)] = true;

	for (int i = 0; i < neighbors.size(); ++i) //Поиск новой опорной вершины с наименьшей меткой
		if (labelList[GetVertPos(neighbors[i])] == minLabel)
			curSrc = neighbors[i];

	while (!AllVisited(visitedVerts)) //Пока все вершины не обработаны
	{
		neighbors = GetNbrs(curSrc); //Вектор соседей новой опорной вершины
		int count = 0;
		minLabel = 1000000;
		for (int i = 0; i < neighbors.size(); i++) //Обход соседних вершин
		{
			int curLabel = labelList[GetVertPos(curSrc)]; //Метка текущей опорной вершины
			int weight = GetWeight(curSrc, neighbors[i]); //Вес ребра до соседней вершины
			int nIndex = GetVertPos(neighbors[i]); //Индекс соседней вершины
			int nextLabel = labelList[nIndex]; //Метка соседней 

			if (curLabel + weight < nextLabel) //Если значение суммы текущей метки и веса ребра меньше значения соседней метки
				labelList[nIndex] = curLabel + weight; //Метка соседней вершины обновляется

			if (labelList[nIndex] < minLabel && visitedVerts[nIndex] != true) //Поиск минимальной метки среди не обработанных вершин
				minLabel = labelList[nIndex];

			count += 1; //Подсчёт посещённых соседей
		}
		if (count == neighbors.size()) //Если все соседи посещены
			visitedVerts[GetVertPos(curSrc)] = true; //Опорная вершина помечается обработанной

		for (int i = 0; i < neighbors.size(); ++i) //Поиск новой опорной вершины
			if (labelList[GetVertPos(neighbors[i])] == minLabel || visitedVerts[GetVertPos(neighbors[i])] != true)
				curSrc = neighbors[i];
	}

	for (int i = 0; i < GetVertPos(startVertex); ++i)
	{
		cout << "Кратчайшее расстояние от вершины " << startVertex << " до вершины " << vertList[i] << " равно " << labelList[GetVertPos(vertList[i])] << endl;
	}

	for (int i = GetVertPos(startVertex) + 1; i < vertList.size(); ++i)
	{
		cout << "Кратчайшее расстояние от вершины " << startVertex << " до вершины " << vertList[i] << " равно " << labelList[GetVertPos(vertList[i])] << endl;
	}
}

template <class T>
bool Graph<T>::AllVisited(bool* visitedVerts) //Проверка все ли вершины обработаны
{
	bool flag = true; //Изначально считается, что все вершины обработаны
	for (int i = 0; i < vertList.size(); i++)
		if (visitedVerts[i] != true)
			flag = false; //Если есть хотя бы одна необработанная вершина - флаг принимает значение false
	return flag; //Возвращается значение флага: true если все обработаны, false в ином случае
}


template<class T>
void Graph<T>::FillLabels(T& startVertex)
{
	for (int i = 0, size = vertList.size(); i < size; ++i)
	{
		labelList.push_back(1000000);
	}
	int pos = GetVertPos(startVertex);
	labelList[pos] = 0;
}


template<class T>
std::vector<T> Graph<T>::GetNbrs(const T& vertex) {
	std::vector<T> nbrsList; // создание списка соседей
	int pos = this->GetVertPos(vertex); 
	if (pos != (-1)) { 
		for (int i = 0, vertListSize = this->vertList.size(); i < vertListSize; ++i) {
			if (this->adjMatrix[pos][i] != 0)
				nbrsList.push_back(this->vertList[i]); 
		}
	}
	return nbrsList; // возврат списка соседей
}


template<class T>
void Graph<T>::InsertVertex(const T& vertex) {
	if (!this->IsFull()) {
		this->vertList.push_back(vertex);
	}
	else {
		cout << "Граф уже заполнен. Невозможно добавить новую вершину " << endl;
		return;
	}
}

template<class T>
int Graph<T>::GetAmountEdges() {
	int amount = 0; // обнуляем счетчик
	if (!this->IsEmpty()) { // проверяем, что граф не пуст
		for (int i = 0, vertListSize = this->vertList.size(); i < vertListSize; ++i) {
			for (int j = 0; j < vertListSize; ++j) {
				if (this->adjMatrix[i][j] == 1) // находим рёбра
					amount += 1; // считаем количество рёбер
			}
		}
		return amount; // возвращаем количество рёбер
	}
	else
		return 0; // если граф пуст, возвращаем 0
}

template<class T>
int Graph<T>::GetWeight(const T& vertex1, const T& vertex2) {
	if (!this->IsEmpty()) {
		int vertPos1 = GetVertPos(vertex1);
		int vertPos2 = GetVertPos(vertex2);
		return adjMatrix[vertPos1][vertPos2];
	}
	return 0;
}

template<class T>
int Graph<T>::GetAmountVerts() {
	return this->vertList.size();
}

template<class T>
bool Graph<T>::IsEmpty() {
	if (this->vertList.size() != 0)
		return false;
	else
		return true;
}

template<class T>
bool Graph<T>::IsFull() {
	return (vertList.size() == maxSize);
}

template <class T>
int Graph<T>::GetVertPos(const T& vertex) {
	for (int i = 0; i < this->vertList.size(); ++i) {
		if (this->vertList[i] == vertex)
			return i;
	}
	return -1;
}

template<class T> 
Graph<T>::Graph() { 
	for (int i = 0; i < maxSize; ++i)
	{
		for (int j = 0; j < maxSize; ++j) 
		{
			this->adjMatrix[i][j] = 0;
		}
	}
}

template<class T>
Graph<T>::~Graph() {

}


Graph<int> makeGraph()
{
	Graph<int> graph; // создание графа, содержащего вершины с номерами целого типа
	int amountVerts, amountEdges, sourceVertex, targetVertex, edgeWeight; // создание необходимых для ввода графа переменных
	cout << "Введите количество вершин графа: "; cin >> amountVerts; cout << endl; // ввод количества рёбер графа в переменную amountVerts
	cout << "Введите количество ребер графа: "; cin >> amountEdges; cout << endl; // ввод количества рёбер графа в переменную amountEdges
	for (int i = 1; i <= amountVerts; ++i) {
		int* vertPtr = &i; // запоминаем адрес вершины с помощью указателя
		graph.InsertVertex(*vertPtr); //передаём ссылку на вершину в функцию InsertVertex; происходит вставка вершины в вектор вершин
	}

	for (int i = 0; i < amountEdges; ++i) {
		cout << "Исходная вершина: "; cin >> sourceVertex; cout << endl; // ввод исходной вершины
		int* sourceVertPtr = &sourceVertex; // запоминаем адрес исходной вершины
		cout << "Конечная вершина: "; cin >> targetVertex; cout << endl; // ввод вершины, до которой будет идти ребро от исходной вершины
		int* targetVertPtr = &targetVertex; // запоминаем адрес конечной вершины (до которой будет идти ребро от исходной вершины)

		cout << "Вес ребра: "; cin >> edgeWeight; cout << endl; // ввод числового значения веса ребра в переменную edgeWeight
		graph.InsertEdge(*sourceVertPtr, *targetVertPtr, edgeWeight); // вставка ребра весом edgeWeight между исходной и конечной вершинами
	}
	cout << endl;
	graph.Print();//печать матрицы смежности
	return graph;
}

template<class T>
void Graph<T>::InsertEdge(const T& vertex1, const T& vertex2, int weight) {
	if (this->GetVertPos(vertex1) != (-1) && this->GetVertPos(vertex2) != (-1)) {
		int vertPos1 = GetVertPos(vertex1);
		int vertPos2 = GetVertPos(vertex2);
		if (this->adjMatrix[vertPos1][vertPos2] != 0) {
			cout << "Ребро между этими вершинами уже существует" << endl;
			return;
		}
		else {
			this->adjMatrix[vertPos1][vertPos2] = weight;
		}
	}
	else {
		cout << "Обеих вершин (или одной из них) нет в графе " << endl;
		return;
	}
}

template<class T>
void Graph<T>::Print() {
	if (!this->IsEmpty()) {
		cout << "Матрица смежности графа: " << endl;
		for (int i = 0, vertListSize = this->vertList.size(); i < vertListSize; ++i) {
			cout << this->vertList[i] << " ";
			for (int j = 0; j < vertListSize; ++j) {
				cout << " " << this->adjMatrix[i][j] << " ";
			}
			cout << endl;
		}
		T startVertex;
		cout << "Введите начальную вершину: ";
		cin >> startVertex;
		cout << endl;
		FillLabels(startVertex);
		Dijkstra(startVertex);
	}
	else {
		cout << "Граф пуст " << endl;
	}
}

void setCoord(int i, int n)
{
	int R_;
	
	int x0 = WinW / 2;
	int y0 = WinH / 2;
	if (WinW > WinH)
	{
		R = 5 * (WinH / 13) / n;
		R_ = WinH / 2 - R - 10;
	}
	else {
		R = 5 * (WinW / 13) / n;
		R_ = WinW / 2 - R - 10;
	}
	float theta = 2.0f * 3.1415926f * float(i) / float(n);
	float y1 = R_ * cos(theta) + y0;
	float x1 = R_ * sin(theta) + x0;

	vertC[i].x = x1;
	vertC[i].y = y1;
}

void drawCircle(int x, int y, int R) //рисуем круг в заданных координатах
{
	glColor3f(1.0, 1.0, 1.0);
	float x1, y1;
	glBegin(GL_POLYGON);
	for (int i = 0; i < 360; i++)
	{
		float theta = 2.0f * 3.1415926f * float(i) / float(360);
		y1 = R * cos(theta) + y;
		x1 = R * sin(theta) + x;;
		glVertex2f(x1, y1);
	}
	glEnd();

	glColor3f(0.0f, 0.0f, 0.0f);
	float x2, y2;	
	glBegin(GL_LINE_LOOP);
	for (int i = 0; i < 360; i++)
	{
		float theta = 2.0f * 3.1415926f * float(i) / float(360);
		y2 = R * cos(theta) + y;
		x2 = R * sin(theta) + x;
		glVertex2f(x2, y2);
	}
	glEnd();
}

void drawText(int nom, int x1, int y1)
{
	GLvoid* font = GLUT_BITMAP_HELVETICA_18;
	string s = to_string(nom);
	glRasterPos2i(x1 - 5, y1 - 5);
	for (int j = 0; j < s.length(); j++)
		glutBitmapCharacter(font, s[j]);
}

void drawVertex(int n)
{
	for (int i = 0; i < n; i++) {
		drawCircle(vertC[i].x, vertC[i].y, R);
		drawText(i + 1, vertC[i].x, vertC[i].y);
	}
}

void drawLine(int text, int x0, int y0, int x1, int y1) //ребро ориентированный взвешенный граф
{
	glColor3i(0, 0, 0);
	glBegin(GL_LINES);
	glVertex2i(x0, y0);
	glVertex2i(x1, y1);
	glEnd();
	drawText(text, (x0 + x1) / 2 + 10, (y0 + y1) / 2 + 10);

	float vx = x0 - x1;
	float vy = y0 - y1;
	float s = 1.0f / sqrt(vx * vx + vy * vy);
	vx *= s;
	vy *= s;
	x1 = x1 + R * vx;
	y1 = y1 + R * vy;

	glColor3i(0, 0, 0);
	glBegin(GL_TRIANGLES);
	glVertex2f(x1, y1);
	glVertex2f(x1 + 10 * (vx + vy), y1 + 10 * (vy - vx));
	glVertex2f(x1 + 10 * (vx - vy), y1 + 10 * (vy + vx));
	glEnd();
}

template<class T>
void Graph<T>::DrawGraph()
{
	int n = vertList.size();
	for (int i = 0; i < n; i++)
	{
		setCoord(i, n);
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int a = adjMatrix[i][j];
			if (a != 0)
			{
				drawLine(a, vertC[i].x, vertC[i].y, vertC[j].x, vertC[j].y);
			}
		}
	}
	drawVertex(n);
}

void reshape(int w, int h)
{
	WinW = w;
	WinH = h;
	glViewport(0, 0, (GLsizei)WinW, (GLsizei)WinH);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, (GLdouble)WinW, 0, (GLdouble)WinH);
	glutPostRedisplay();
}

void display()
{
	glShadeModel(GL_SMOOTH);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, WinW, 0, WinH); //ставим начало координат в левый нижний угол
	glViewport(0, 0, WinW, WinH);
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);

	graph.DrawGraph();

	glutSwapBuffers();
}

*/