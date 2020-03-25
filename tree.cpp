// lab3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "node.h"
#include "tree.h"
#include <iostream>
#include <string>
using namespace std;

Tree::Tree() {
	this->root = NULL;
}

Tree::Tree(Node* root) {
	this->root = root;
}


Tree::~Tree() {
	delete this->root;
}


void Tree::insert(Node*& n, int x, int &counter) {
	//n = this->root
	if (n) {

		if (n->val == x) {
			cout << "Der Knoten existiert :D";
		}

		else if (x < n->val) {
			insert(n->ln, x, counter);
		}
		else {
			insert(n->rn, x, counter);
		}
	}
	else {
		n = new Node;
		n->val = x;
		n->ln = n->rn = NULL;
		counter++;
	}

}

void Tree::suchen(Node*& k, Node*& foundk, int x) {
	if (k) {
		if (k->val > x) {
			suchen(k->ln, foundk, x);
		}
		else if (k->val < x) {
			suchen(k->rn, foundk, x);
		}
		else {
			foundk = k;
		}
	}
	else {
		foundk = NULL;
	}
}

void Tree::cmmd(Node*& c, Node*& f) {
	Node* aux;
	if (f->rn)
		cmmd(c, f->rn);
	else {
		c->val = f->val;
		aux = f;
		f = f->ln;
		delete aux;
	}
}

void Tree::deleteN(Node*& c, int k) {
	Node* f;
	if (c) {
		if (c->val == k)
			if (c->ln == 0 && c->rn == 0) {
				free(c);
				c = NULL;
				cout << "Knoten " << k << " wurde geloscht";
				return;
			}
			else if (c->ln == 0) {
				f = c->rn;
				free(c);
				c = f;
				cout << "Knoten " << k << " wurde geloscht";
				return;
			}
			else if (c->rn == 0) {
				f = c->ln;
				free(c);
				c = f;
				cout << "Knoten " << k << " wurde geloscht";
				return;
			}
			else {
				cmmd(c, c->ln);

			}
		else if (c->val < k) {
			deleteN(c->rn, k);
		}
		else {
			deleteN(c->ln, k);
		}
	}
	else {
		cout << " Es gibt keine solche Zahl! ";
		return;
	}
}

void Tree::inorder(Node* k) {
	if (k != 0)
	{
		inorder(k->ln);
		cout << k->val << ' ';
		inorder(k->rn);
	}
}

void Tree::preorder(Node* k) {
	if (k != 0)
	{
		cout << k->val << ' ';
		preorder(k->ln);
		preorder(k->rn);
	}
}

void Tree::postorder(Node* k)
{
	if (k != 0)
	{
		postorder(k->ln);
		postorder(k->rn);
		cout << k->val << ' ';
	}
}

int Tree::countNodes(Node* n, int count) {
	if (n->ln == 0 && n->rn == 0) {
		return 1;
	}
	else if (n->ln == 0) {
		return count + countNodes(n->rn, count);
	}
	else if (n->rn == 0) {
		return count + countNodes(n->ln, count);
	}
	else {
		return count + countNodes(n->ln, count) + countNodes(n->rn, count);
	}
}

int Tree::countEdges(Node* n) {
	return countNodes(n, 1) - 1;

}

int Tree::height(Node* node)
{
	if (node == 0)
		return 0;
	else
	{
		
		int left = height(node->ln);
		int right = height(node->rn);

		
		if (left > right)
			return(left + 1);
		else return(right + 1);
	}
}

