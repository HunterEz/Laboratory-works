#pragma once

struct Node;

Node* make_pointq();

Node* push(Node*& plast, Node*& pfirst);

Node* createque(int n);

void show(Node* plast);

Node* add_str(Node* plast);