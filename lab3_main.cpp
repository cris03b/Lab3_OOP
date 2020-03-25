#include <iostream>
#include "node.cpp"
#include "tree.cpp"
using namespace std;


// citire binary tree de la tastatura

void einlesen(int& n, Node*& root, Tree& tree) {
	int x;
	cout << endl << "Root: ";
	cin >> x;
	tree.insert(root, x);
	cout << "Number of nodes: ";
	cin >> n;
	cout << "Nodes: ";
	for (int i = 2; i <= n; i++) {
		cin >> x;
		tree.insert(root, x);
	}
	cout << endl << "Great! you just created a binary search tree!" << endl;
}

int main() {
	Tree tree;
	int x, y, z, t, n = 0;
	Node* nod2, * nodgol, * nod, * nod3, * nod4;
	nod = NULL;
	nodgol = NULL;

	cout << "Hello! Welcome to the binary search tree app!" << endl << "Let's create a tree :D" << endl << "You need a root, a number of nodes (including the root) and the values" << endl;
	einlesen(n, nod, tree);

	cout << "You can now search for a node" << endl << endl << "Node: ";
	cin >> x;
	tree.suchen(nod, nodgol, x);
	if (nodgol) {
		cout << "Found! :D";
	}
	else {
		cout << "Not found... :(";
	}

	cout << endl << endl << "Now that you've searched for a node, you can delete one!" << endl << "Node: ";
	cin >> y;
	tree.deleteN(nod, y);

	cout << endl << endl << "Now it's time for some tree traversals!" << endl << "Trees can be traversed in different ways: " << endl << endl;
	cout << "Inorder: ";
	tree.inorder(nod);
	cout << endl << "Preorder: ";
	tree.preorder(nod);
	cout << endl << "Postorder: ";
	tree.postorder(nod);

	cout << endl << endl << "WOW! You've done a lot so far!" << endl << "Let's see how many nodes and edges are left and the height of your tree!" << endl;
	cout << endl << "Count nodes: " << tree.countNodes(nod, 1) << endl;
	cout << "Count edges: " << tree.countEdges(nod) << endl;
	cout << "Height: " << tree.height(nod);
}
