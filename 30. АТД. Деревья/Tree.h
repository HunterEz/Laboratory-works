#pragma once
#include <iostream>
#include <glut.h>
#include <string>
#include <vector>

using namespace std;

struct file_cabinet
{
	int datanumber;
	string fullname;
	long number;
	int talktime;
	int arrears;

	file_cabinet()
	{
		 datanumber = 0;
		 fullname = ' ';
		 number = 0;
		 talktime = 0;
		 arrears = 0;
	}

	file_cabinet(int datanum, string name, int num, int time, int arr)
	{
		datanumber = datanum;
		fullname = name;
		talktime = time;
		number = num;
		arrears = arr;
	}

	void InsertData()
	{	
		cout << "Введите номер элемента: ";
		cin >> datanumber;
		cout << "Введите полное имя абонента: ";
		cin.get();
		getline(cin, fullname);
		cout << "Введите время разговора(минуты): ";
		cin >> talktime;
		cout << "Введите номер абонента: ";
		cin >> number;
		cout << "Введите задолжность абонента(рубли): ";
		cin >> arrears;
	}

	bool operator < (const file_cabinet& fc)
	{
		if (datanumber < fc.datanumber)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool operator > (const file_cabinet& fc)
	{
		 if (datanumber > fc.datanumber)
		 {
			 return true;
		 }
		 else
		 {
			 return false;
		 }
	}

	bool operator >= (const file_cabinet& fc)
	{
		if (datanumber >= fc.datanumber)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	bool operator <= (const file_cabinet& fc)
	{
		if (datanumber <= fc.datanumber)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool operator == (int key)
	{
		if (datanumber <= key)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool operator < (int key)
	{
		if (datanumber > key)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	file_cabinet& operator = (const file_cabinet& fc)
	{
		if (&fc == this)return *this;
		datanumber = fc.datanumber;
		fullname = fc.fullname;
		number = fc.number;
		talktime = fc.talktime;
		arrears = fc.arrears;
		return *this;
	}

	bool operator == (const file_cabinet& fc)
	{
		if (datanumber == fc.datanumber)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool operator != (const file_cabinet& fc)
	{
		if (datanumber != fc.datanumber)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	int operator() ()
	{
		return datanumber;
	}
};

struct SGlutContextStruct
{
	void* tree;
	int window_width, window_height, shift, k, R, x, y, state;
};

template <class T>
class btree
{
public:
	T key_value;
	btree* left;
	btree* right;
	btree* root;					

	int node_x;
	int node_y;
	int text_x;
	int text_y;

	btree(T);   
	btree();
	~btree();                           	

	void insert(T key);               	
	void insertLeft(int key);
	void insertRight(int key);
	btree<T>* search(T key);			
	void destroy_tree();               
	void destroy_tree(btree<T>* leaf);		
	btree<T>* search(T key, btree<T>* leaf);	
	void postOrder(int k);

	btree<T>* findElement(T);
	void deleteNode();
	btree<T>* next();
	btree<T>* findMin();

	void Add_Left_Tree(btree<T>* node)
	{ 
		left = node;
	}
	void Add_Right_Tree(btree<T>* node)
	{
		right = node;
	}

	void setCoordsForNode(int window_width, int window_height, int shift, 
		int tree_width, int tree_height, int x, int y, int R);
	btree<T>* getNodeByCoords(int x, int y, int R);
	void setCoordsForText(int k, int shift);

	
	void drawTree(
		int argc, char** argv,
		int window_width, int window_height,
		int shift, int k);
	
	int getHeight();

	btree<T>* preOrder(int k);

	void printAll(btree<T>* node);
	
	btree<T>* CopyTree();

	btree<T>* replaceNULLforEmpty();

	btree<T>* getLeft()
	{
		return left;
	}
	btree<T>* getRight()
	{
		return right;
	}
	btree<T>* getRoot()
	{
		return root;
	}

	int getData()
	{
			return key_value() ;
	}
	

	int getAmountOfNodes();

};

template<class T>
void initWindow(int argc, char** argv);

template <class T>
void display(void);

void reshape(int w, int h);

int getPos(int index, int width, int curLevel, int maxLevel);

extern SGlutContextStruct glutContext;

struct  pos
{
	int col;
	int str;
};


void btree<file_cabinet>::printAll(btree<file_cabinet> *node)
{
	if (node) {
		cout << "__________________________________________________" << endl;
		cout << "Номер элемента: " << node->key_value.datanumber << endl;
		cout << "Полное имя: " << node->key_value.fullname << endl;
		cout << "Номер телефона: " << node->key_value.number << endl;
		cout << "Время разговора: " << node->key_value.talktime << endl;
		cout << "Задолжность: " << node->key_value.arrears << endl;
		cout << "__________________________________________________" << endl;
		printAll(node->left);
		printAll(node->right);
	}
}

template <class T>
btree<T>* btree<T>::replaceNULLforEmpty()
{
	btree<T>* node = this->CopyTree();
	int h = node->getHeight();
	node = replace_help(node, h);
	return node;
}

template<class T>
btree<T>::btree(T key)
{
	this->key_value = key;
	left = nullptr;
	right = nullptr;
	root = nullptr;
}

template<class T>
btree<T>::btree()
{

}

template<class T>
btree<T>::~btree()
{
	destroy_tree(); 	
}

template<class T>
void btree<T>::destroy_tree(btree<T>* leaf)
{
	if (leaf != NULL)				
	{							
		destroy_tree(leaf->left);	
		destroy_tree(leaf->right);
		delete leaf;				
	}
}

template <class T>
btree<T>* btree<T>::preOrder(int key)
{
	if ((this == NULL) || (key == this->getData()))
		return this;
	if (key < this->getData()) return this->left->preOrder(key);
	else return this->right->preOrder(key);
}

template<class T>
void btree<T>::postOrder(int k)
{
	btree<T>* temp = preOrder(k);
	if (temp)
	{
		if (k == 3 || k == 4 || k == 5 || k == 7 || k == 8 || k==1 || k == 9)
		{
			cout << "Изначальные вершины удалить нельзя!\n";
		}
		else
		{
			temp->deleteNode();
		}
	}
	else
	{
		cout << "Вершина не найдена\n";
	}
}

template <class T>
btree<T>* btree<T>::findElement(T key)
{
	if ((this == NULL) || (key == this->key_value))
		return this;
	if (key < this->key_value) return this->left->findElement(key);
	else return this->right->findElement(key);
}

template <class T>
void btree<T>::insert(T key)
{
	btree<T>* tree = this;
	btree<T>* search = findElement(key);
	while (tree != NULL && !search)
	{
		if (key >= tree->key_value)
		{
			if (tree->right != NULL)
			{
				tree = tree->right;
			}
			else
			{
				btree<T>* t = new btree<T>(key);
				t->root = tree;
				tree->right = t;
				break;
			}
		}
		else if (key < tree->key_value)
		{
			if (tree->left != NULL)
			{
				tree = tree->left;
			}
			else
			{
				btree<T>* t = new btree<T>(key);
				t->root = tree;
				tree->left = t;
				break;
			}
		}
	}
	if (search)
	{
		cout << "Такой элемент уже существует\n";
	}
}

template <class T>
void btree<T>::insertLeft(int key)
{
	btree<T>* node = new btree<T>();
	if (this->left != NULL)
		this->left->root = node;
	node->left = this->left;
	this->left = node;
	node->root = this;
}

template<class T>
void btree<T>::insertRight(int key)
{
	btree<T>* node = new btree<T>();
	if (this->right != NULL)
		this->right->root = node;
	node->right = this->right;
	this->right = node;
	node->root = this;
}



template<class T>
void btree<T>::deleteNode()
{
	btree<T>* e = this;
	btree<T>* p = e->root;
	if ((e->left == NULL) && (e->right == NULL))
	{
		if (p->left == e) p->left = NULL;
		if (p->right == e) p->right = NULL;
	}
	else if ((e->left == NULL) || (e->right == NULL))
	{
		if (e->left == NULL)
		{
			if (p->left == e) p->left = e->right;
			else p->right = e->right;
			e->right->root = p;
		}
		else
		{
			if (p->left == e) p->left = e->left;
			else p->right = e->left;
			e->left->root = p;
		}
	}
	else
	{
		btree<T>* s = e->next();
		e->key_value = s->key_value;
		if (s->root->left == s)
		{
			s->root->left = s->right;
			if (s->right != NULL)
				s->right->root = s->root;
		}
		else
		{
			s->root->right = s->right;
			if (s->right != NULL)
				s->right->root = s->root;
		}
	}
}

template <class T>
btree<T>* btree<T>::next()
{
	btree<T>* tree = this;
	if (tree->right != NULL)
		return tree->right->findMin();
	btree<T>* t = tree->root;
	while ((t != NULL) && (tree == t->right))
	{
		tree = t;
		t = t->root;
	}
	return t;
}

template <class T>
btree<T>* btree<T>::findMin()
{
	if (this->left == NULL) return this;
	return this->left->findMin();
}
	
	void drawLine(int x1, int y1, int x2, int y2)
	{
		glBegin(GL_LINES);
		glColor3f(0, 0, 0);
		glVertex2i(x1, y1);
		glVertex2i(x2, y2);
		glEnd();
	}
	
	void drawFillCircle(int x, int y, int R)
	{
		glColor3f(0, 255, 0);
		float x1, y1;
		glBegin(GL_POINTS);
		for (int i = 0; i <= R; i++) {
			for (int t = 0; t <= 360; t++) {
				x1 = i * sin(t) + x;
				y1 = i * cos(t) + y;
				glVertex2f(x1, y1);
			}
		}
		glEnd();
		glColor3f(0.0, 0.0, 0.0);
		glBegin(GL_POINTS);
		for (int i = R - 1; i <= R; i++) {
			for (int t = 0; t <= 360; t++) {
				x1 = R * sin(t) + x;
				y1 = R * cos(t) + y;
				glVertex2f(x1, y1);
			}
		}
		glEnd();
	}

	void drawMenuText(string text, int x1, int y1)
	{
		GLvoid* font = GLUT_BITMAP_HELVETICA_18;
		string s = text;
		glRasterPos2i(x1 + 5, y1 - 20);
		for (int j = 0; j < s.length(); j++)
			glutBitmapCharacter(font, s[j]);
	}

	void drawMenu()
	{
		int shift = glutContext.shift;
		int height = glutContext.window_height;

		glColor3d(0.3, 0.3, 0.6);
		glBegin(GL_QUADS);
		glVertex2i(shift - 10, height);
		glVertex2i(shift + 145, height);
		glVertex2i(shift + 145, height - shift - 160);
		glVertex2i(shift - 10, height - shift - 160);
		glEnd();

		glColor3d(0, 0.3, 0.0);
		glBegin(GL_QUADS);
		glVertex2i(shift, height - shift - 30);
		glVertex2i(shift + 135, height - shift - 30);
		glVertex2i(shift + 135, height - shift);
		glVertex2i(shift, height - shift);
		glEnd();
		glColor3d(0.8, 1.0, 0.9);
		drawMenuText("Insert elements", shift, height - shift-2);

		glColor3d(0, 0.3, 0.0);
		glBegin(GL_QUADS);
		glVertex2i(shift, height - shift - 70);
		glVertex2i(shift + 135, height - shift - 70);
		glVertex2i(shift + 135, height - shift - 40);
		glVertex2i(shift, height - shift - 40);
		glEnd();
		glColor3d(0.8, 1.0, 0.9);
		drawMenuText("Delete element", shift, height - shift - 42);

		glColor3d(0, 0.3, 0.0);
		glBegin(GL_QUADS);
		glVertex2i(shift, height - shift - 110);
		glVertex2i(shift + 135, height - shift - 110);
		glVertex2i(shift + 135, height - shift - 80);
		glVertex2i(shift, height - shift - 80);
		glEnd();
		glColor3d(0.8, 1.0, 0.9);
		drawMenuText("Get information", shift, height - shift - 82);

		glColor3d(0, 0.3, 0.0);
		glBegin(GL_QUADS);
		glVertex2i(shift, height - shift - 150);
		glVertex2i(shift + 135, height - shift - 150);
		glVertex2i(shift + 135, height - shift - 120);
		glVertex2i(shift, height - shift - 120);
		glEnd();
		glColor3d(0.8, 1.0, 0.9);
		drawMenuText("All subscribers", shift, height - shift - 122);
	}

	void drawText(char text, void* font, int text_x, int text_y, int R, int k)
	{
		glColor3f(0, 0, 0);
		glPushMatrix();
		glTranslatef(text_x, text_y, 0.0);
		string s = to_string(text);
		char* s1 = new char[s.size() + 1];
		for (int i = 0; i < s.size(); i++) {
			s1[i] = s.at(i);
		}
		s1[s.size()] = 0;
		char* c;
		int max_char_width = 0;
		int char_width = 0;
		for (c = s1; *c != '\0'; c++) {
			char_width = glutStrokeWidth(font, *c);
			if (max_char_width < char_width) max_char_width = char_width;
		}
		float expand_x = (float)1.5 * R / (float)(k * max_char_width);
		float expand_y = (float)1.5 * R / (float)(k * 100);
		glScalef(expand_x, expand_y, 1.0);
		for (c = s1; *c != '\0'; c++)
			glutStrokeCharacter(font, *c);
		glPopMatrix();
	}
	

		

	template<class T>
	btree<T>* btree<T>::CopyTree()
	{
		btree<T>* tree = new btree<T>(this->key_value);
		if (this->root != NULL)
			tree->root = this->root;
		if (this->left != NULL)
			tree->left = this->left->CopyTree();
		if (this->right != NULL)
			tree->right = this->right->CopyTree();
		return tree;
	}

	template <class T>
	int btree<T>::getHeight()
	{
		int h1 = 0, h2 = 0, hadd = 0;
		if (this == NULL)return 0;
		if (this->left != NULL) h1 = this->left->getHeight();
		if (this->right != NULL) h2 = this->right->getHeight();
		if (h1 >= h2) return h1 + 1;
		else return h2 + 1;
	}

	template<class T>
	int btree<T>::getAmountOfNodes()
	{
		if (this == NULL)return 0;
		if ((this->left == NULL) && (this->right == NULL)) return 1;
		int l = 0;
		int r = 0;
		if (this->left != NULL) l = this->left->getAmountOfNodes();
		if (this->right != NULL) r = this->right->getAmountOfNodes();
		return (l + r + 1);
	}

		template<class T>
	btree<T>* get_help(btree<T>* node, int x, int y, int R)
	{
		if (pow(x - node->node_x, 2) + pow(y - node->node_y, 2) <= pow(R, 2))
			return node;
		btree<T>* temp = NULL;
		if (node->getLeft() != NULL)
			temp = get_help(node->getLeft(), x, y, R);
		if (temp != NULL)
			return temp;
		if (node->getRight() != NULL)
			temp = get_help(node->getRight(), x, y, R);
		return temp;
	}

	template<class T>
	void btree<T>::drawTree(int argc, char** argv,int window_width, 
		int window_height, int shift, int k)
	{
		btree<T>* temp = this->CopyTree();
		temp = temp->replaceNULLforEmpty();
		glutContext.tree = temp;
		glutContext.window_width = window_width;
		glutContext.window_height = window_height;
		glutContext.shift = shift;
		glutContext.k = k;
		initWindow<T>(argc, argv);
	}

	template<class T>
	btree<T>* btree<T>::getNodeByCoords(int x, int y, int R)
	{
		btree<T>* node = this;
		node = get_help(node, x, y, R);
		return node;
	}

	template <class T>
	void btree<T>::setCoordsForText(int k, int R)
	{

		text_x = node_x - 3 * R / 4;

		text_y = node_y - 3 * R / (4 * k);
	}

	template <class T>
	void btree<T>::setCoordsForNode(int window_width, int window_height, int shift, int tree_width, int tree_height, int x, int y, int R)
	{
		if (tree_width != tree_height)
		{
			int k_x = (window_width - 2 * (shift + R)) / (tree_width - 1);
			int k_y = (window_height - 2 * (shift + R)) / (tree_height - 1);
			node_x = node_x = k_x * x + shift + R;
			node_y = window_height - k_y * y - shift - R;
		}
		else
		{
			node_x = window_width / 2;
			node_y = window_height / 2;
		}
	}

	template <class T>
	void btree<T>::destroy_tree()
	{
		if (root != NULL)
		{
			destroy_tree(root->left);
			destroy_tree(root->right);
			delete root;
		}
	}

	template <class T>
	btree<T>* btree<T>::search(T key)	
	{
		if (root != NULL)	
		{
			if (key == root->key_value)
				return root;	
			if (key < root->key_value)	
			
				return search(key, root->left);	
			else							
				return search(key, root->right);	
		}
		else return NULL;				
	}

	template <class T>
	btree<T>* btree<T>::search(T key, btree<T>* leaf)	
	{
		if (leaf != NULL)	
		{
			if (key == leaf->key_value)
				return leaf;	
			if (key < leaf->key_value)	
			
				return search(key, leaf->left);	
			else							
				return search(key, leaf->right);	
		}
		else return NULL;					
	}

	template <class T>
	btree<T>* replace_help(btree<T>* node, int h)
	{
		int curLevel = getLevel(node);
		if ((node->getLeft() == NULL) && (curLevel != h - 1))
		{
			node->insertLeft(NULL);
		}
		if ((node->getRight() == NULL) && (curLevel != h - 1))
		{
			node->insertRight(NULL);
		}
		if (node->getLeft() != NULL) node->Add_Left_Tree(replace_help(node->getLeft(), h));
		if (node->getRight() != NULL) node->Add_Right_Tree(replace_help(node->getRight(), h));
		return node;
	}

	template<class T>
	int getLevel(btree<T>* node)
	{

		if (node->getRoot() == NULL)
		{
			return 0;
		}
		else
		{
			return getLevel(node->getRoot()) + 1;
		}
	}