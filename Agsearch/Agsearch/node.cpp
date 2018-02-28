#include "node.h"

using namespace std;

Node::Node() {
}

Node::Node(Node * p, std::string state, double cost) {
	if (p != NULL) {
		parent = p;
		name = state;
		ucost = cost;
		pcost = p->pcost + cost;
	}
	else {
		parent=p;
		name = state;
		pcost = 0;
		cost = 0;
	}
}

string Node::getName() const {
	return name;
}

double Node::getcost() const {
	return ucost;
}
 
double Node::getpathcost() const{
	return pcost;
}

bool Node::operator==(const Node & n1) {
	return (name == n1.getName()&&pcost==n1.getpathcost());
}

bool Node::operator<(const Node & n1) {
	return (ucost < n1.getpathcost());
}

void Node::print() const {
	cout << name<<"("<<pcost<<")"<<" ";
}

void Node::traceBack(bool pc) {
	if (parent) {
		parent->traceBack(false);
		cout << "->";
	}
	cout << name<<"("<<ucost<<")";
	if (pc)cout << " total cost: " << pcost;
}
void Node::setcost(double a) {
	ucost = a;
}
