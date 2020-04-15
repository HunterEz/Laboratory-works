#pragma once

struct Node;

Node* make_pointd();

Node* make_list(int n);

void print_list(int n, Node* beg);

Node* add_str(int n, Node* beg);