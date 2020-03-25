#pragma once
#include "node.h"


class Tree {
public:

	Node* root; // nodul radacina
	
	Tree();
	Tree(Node* root);
	~Tree();

	void insert(Node*& n, int x);  //insereaza un nod in copac
	void suchen(Node*& k, Node*& foundk, int x);  //cauta un nod in copac
	void deleteN(Node*& c, int k);  //sterge un nod din copac
	void cmmd(Node*& c, Node*& f);  //socoteste pe care dintre noduri il 
									//pune, in caz ca se sterge un nod important
									//(care are mai multe legaturi)
	void inorder(Node* k);  //parcurgerea stanga, radacina, dreapta
	void preorder(Node* k);  //parcurgerea radacina, stanga, dreapta
	void postorder(Node* k);  //parcurgerea stanga, dreapta, radacina

	int countNodes(Node* n, int count);  //numara nodurile din copac
	int countEdges(Node* n);  //numara legaturile dintre nodurile din copac
	int height(Node* node);  //socoteste inaltimea copacului
};
