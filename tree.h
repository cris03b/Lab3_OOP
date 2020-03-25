#pragma once
#include "node.h"


class Tree {
public:
	
	// int bin_tree[100]; // vector noduri din binary tree
	// int counter; // nr noduri

	Node* root; // nodul radacina
	Tree();
	Tree(Node* root);
	~Tree();

	void insert(Node*& n, int x, int& counter);
	void suchen(Node*& k, Node*& foundk, int x);
	void deleteN(Node*& c, int k);
	void cmmd(Node*& c, Node*& f);
	void inorder(Node* k);
	void preorder(Node* k);
	void postorder(Node* k);

	int countNodes(Node* n, int count);
	int countEdges(Node* n);
	int height(Node* node);
};