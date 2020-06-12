
#define _USE_MATH_DEFINES 
#include <cmath>
#include "Tree.h"
#include <Windows.h>

using namespace std;

SGlutContextStruct glutContext;

template <class T>
void mouseMove(int x, int y) {
	btree<T>* tree = (btree<T>*)glutContext.tree;
	int R = glutContext.R;
	btree<T>* node = tree->getNodeByCoords(x, glutContext.window_height - y, R);
	if (node != NULL) {
		glutContext.x = x;
		glutContext.y = glutContext.window_height - y;
		glutContext.state = 1;
		glutPostRedisplay();
		
	}
	else {
		glutContext.state = 0;
		glutPostRedisplay();
	}
}

int getPos(int index, int width, int curLevel, int height)
{
	int x1 = 0;
	int x2 = pow(2, curLevel) - 1;
	int y1 = width / pow(2, curLevel + 1);
	int y2 = width - pow(2, height - curLevel);
	if (x1 == x2) return y1;
	double k = (y2 - y1) / (x2 - x1);
	double m = -x1 * k + y1;
	int y = (int)(k * index + m);
	return y;

}

template <class T>
void mouseClick(int btn, int stat, int x, int y) {
	btree<T>* temp = ((btree<T>*)glutContext.tree);

	if (stat == GLUT_DOWN) {
		int k;
		if (x > 10&& x < 145 && y > 10&& y < 30) {
			file_cabinet templ;
			templ.InsertData();
			temp->insert(templ);
		}
		if (x > 10&& x < 145 && y > 10 + 40 && y < 80) {
			cout << "Введите вершину: ";
			cin >> k;
			temp->postOrder(k);
		}
		if (x > 10&& x < 145 && y > 10 + 80 && y < 120)
		{
			cout << "Введите вершину: ";
			cin >> k;
			btree<file_cabinet>* temp2 = temp;
			temp2 = temp2->preOrder(k);
			cout << "Полное имя: " << temp2->key_value.fullname << endl;
			cout << "Номер телефона: " << temp2->key_value.number << endl;
			cout << "Время разговора: " << temp2->key_value.talktime << endl;
			cout << "Задолжность: " << temp2->key_value.arrears << endl;
		}
		if (x > 10 && x < 145 && y > 10 + 120 && y < 160)
		{
			btree<file_cabinet>* temp2 = temp;
			temp2->printAll(temp2);
		}
	}
	glutPostRedisplay();
}


template<class T>
void initWindow(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowSize(glutContext.window_width, glutContext.window_height);
	glutCreateWindow("Картотека абонентов");
	glutDisplayFunc(display<T>);
	glutReshapeFunc(reshape);
	glutPassiveMotionFunc(mouseMove<T>);
	glutMouseFunc(mouseClick<T>);
	glutMainLoop();
}

void reshape(int w, int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, (GLsizei)w, 0, (GLsizei)h);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glutContext.window_width = w;
	glutContext.window_height = h;
	glutPostRedisplay();
}

template <class T>
void display(void) {
	btree<T>* tree = ((btree<T>*)glutContext.tree)->CopyTree();
	tree = tree->replaceNULLforEmpty();
	int k = glutContext.k;
	int window_width = glutContext.window_width;
	int window_height = glutContext.window_height;
	int shift = glutContext.shift;
	int height = tree->getHeight();
	int maxLeafs = pow(2, height - 1); 
	int width = 2 * maxLeafs - 1; 
	int curLevel = 0; 
	int index = 0;
	int factSpaces = getPos(index, width, curLevel, height - 1); 
	pos node;
	vector<btree<T>*> V;
	vector<pos> Vi;
	int R; 
	R = (window_width - 2 * shift) / (2 * width);
	if (2 * R * height > (window_height - 2 * shift)) R = (window_height - 2 * shift) / (2 * height);
	glutContext.R = R;
	tree->setCoordsForNode(window_width, window_height, shift, width, height, factSpaces, curLevel, R);
	V.push_back(tree);
	node.col = factSpaces;
	node.str = curLevel;
	Vi.push_back(node);

	glClearColor(0.6, 0.6, 0.6, 0.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glLineWidth(2);
	glEnable(GL_POINT_SMOOTH);
	for (int i = 0; i < tree->getAmountOfNodes(); i++) {
		if (pow(2, curLevel) <= index + 1) {
			index = 0;
			curLevel++;
		}
		if (V.at(i)->getLeft() != NULL) {
			V.push_back(V.at(i)->getLeft());
			factSpaces = getPos(index, width, curLevel, height - 1);
			node.col = factSpaces;
			node.str = curLevel;
			Vi.push_back(node);
			index++;
			V.at(i)->getLeft()->setCoordsForNode(window_width, window_height, shift, width, height, factSpaces, curLevel, R);
			if (V.at(i)->getLeft()->getData() != NULL) {
				int x1 = V.at(i)->node_x;
				int y1 = V.at(i)->node_y;
				int x2 = V.at(i)->getLeft()->node_x;
				int y2 = V.at(i)->getLeft()->node_y;
				drawLine(x1, y1, x2, y2);
			}
		}

		if (V.at(i)->getRight() != NULL) {
			V.push_back(V.at(i)->getRight());
			factSpaces = getPos(index, width, curLevel, height - 1);
			node.col = factSpaces;
			node.str = curLevel;
			Vi.push_back(node);
			index++;
			V.at(i)->getRight()->setCoordsForNode(window_width, window_height, shift, width, height, factSpaces, curLevel, R);
			if (V.at(i)->getRight()->getData() != NULL) {
				int x1 = V.at(i)->node_x;
				int y1 = V.at(i)->node_y;
				int x2 = V.at(i)->getRight()->node_x;
				int y2 = V.at(i)->getRight()->node_y;
				drawLine(x1, y1, x2, y2);
			}
		}

		if (V.at(i)->getData() != NULL) {
			if (glutContext.state == 0) {
				drawFillCircle(V.at(i)->node_x, V.at(i)->node_y, R);
			}
			else {
				drawFillCircle(V.at(i)->node_x, V.at(i)->node_y, R);
				if ((tree->getNodeByCoords(glutContext.x, glutContext.y, R)->node_x == V.at(i)->node_x)
					& (tree->getNodeByCoords(glutContext.x, glutContext.y, R)->node_y == V.at(i)->node_y))
					drawFillCircle(V.at(i)->node_x, V.at(i)->node_y, R);
			}
			V.at(i)->setCoordsForText(k, R);
			drawText(V.at(i)->getData(), GLUT_STROKE_ROMAN, V.at(i)->text_x, V.at(i)->text_y, R, k);
		}
	}
	drawMenu();
	glutSwapBuffers();
	glDisable(GL_POINT_SMOOTH); 
	
}


int main(int argc, char** argv)
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "rus");
	
	file_cabinet Medvedev(5, "Медведев Максим Аркадьевич", 7653412, 123, 15);
	file_cabinet Petrov(8, "Петров Вадим Андреевич", 2345434, 123, 15);
	file_cabinet Luchnikov(3, "Лучников Александр Валерьвич", 7653463, 123, 15);
	file_cabinet Kuzovkin(9, "Кузовкин Михаил Александровч", 2341265, 123, 15);
	file_cabinet Makarov(7, "Макаров Дмитрий Ильич", 3241243, 123, 15);
	file_cabinet Sidorov(4, "Сидоров Максим Романович", 4325467, 123, 15);
	file_cabinet Petuhov(1, "Петухов Василий Альбертович", 2348756, 123, 15);
	

	btree<file_cabinet>* tree = new btree<file_cabinet>(Medvedev);
	tree->insert(Petrov);
	tree->insert(Luchnikov);
	tree->insert(Kuzovkin);
	tree->insert(Makarov);
	tree->insert(Sidorov);
	tree->insert(Petuhov);
	
	tree->drawTree(argc, argv, 800, 600, 10, 2);
	return 0;
}