#ifndef NODE_H
#define NODE_H

#include "globals.h"
#include <iostream>
#include <string>

class Node {
public:
	Node();
	Node(Node*, std::string, double cost,double hcost);
	std::string getName() const;
	double getcost() const;
	bool operator==(const Node&);
	bool operator<(const Node&);
	void print() const;
	void traceBack(bool);
	void setcost(double a);
	double getpathcost() const;
	double gethcost() const;
private:
	Node* parent;
	std::string name;
	double ucost;
	double pcost;
	double hcost;
};

#endif
