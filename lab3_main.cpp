#include <iostream>
#include "node.cpp"
#include "tree.cpp"
using namespace std;


void einlesen(int& n, Node*& root, Tree& tree) {
	int x, ct = 0;
	cout << "Root: ";
	cin >> x;
	tree.insert(root, x, ct);
	cout << endl << "Inaltime copac: ";
	cin >> n;
	cout << endl << "Noduri: ";
	for (int i = 2; i <= n; i++) {
		cin >> x;
		tree.insert(root, x, ct);
	}
}

int main() {
	Tree tree;
	int x, y, z, t, n = 0;
	Node* nod2, * nodgol, * nod, * nod3, * nod4;
	nod = NULL;
	nodgol = NULL;
	einlesen(n, nod, tree);
	nod2 = nod;
	nod3 = nod;
	nod4 = nod;
	cout << "Nodul pe care vreti sa il cautati: ";
	cin >> x;
	tree.suchen(nod, nodgol, x);
	if (nodgol) {
		cout << "gefunden";
	}
	else {
		cout << "nicht gefunden";
	}
	cout << endl;
	cout << "Nodul pe care vreti sa il stergeti: " << endl;
	cin >> y;
	tree.deleteN(nod, y);
	cout << endl;
	nodgol = NULL;
	cout << "Nodul pe care vreti sa il cautati: ";
	cin >> z;
	cout << endl;
	tree.suchen(nod, nodgol, z);
	if (nodgol) {
		cout << "gefunden";
	}
	else {
		cout << "nicht gefunden";
	}
	cout << endl;
	cout << "Nodul pe care vreti sa il cautati: ";
	cin >> t;
	tree.suchen(nod, nodgol, t);
	if (nodgol) {
		cout << "gefunden";
	}
	else {
		cout << "nicht gefunden";
	}

	cout << endl;
	tree.inorder(nod);
	cout << endl;
	tree.preorder(nod);
	cout << endl;
	tree.postorder(nod);

	cout << endl << "Count nodes: " << endl;
	cout << tree.countNodes(nod, 1) << endl;
	cout << "Count edges: " << tree.countEdges(nod);
	cout << endl << tree.maxDepth(nod);
}
