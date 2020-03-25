#pragma once
class Node {
public:
	Node();
	~Node();
	

	Node* ln; // pointer la partea st/dr
	Node* rn;
	int val; // valoare nod

};