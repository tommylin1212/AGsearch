#ifndef EXPLOREDSET_H
#define EXPLOREDSET_H

#include "node.h"
#include <vector>

typedef std::vector<Node*> ExploredNodes;

class ExploredSet {
public:
	ExploredSet();
	~ExploredSet();
	bool check(Node* n);
	bool checksame(Node* n);
	bool add(Node* n);
	void print() const;
private:
	struct NodeMatch {
		NodeMatch(Node *n) : toFind(n) {}
		bool operator() (const Node* n) {
			return (n->getName() == toFind->getName());
		}
		Node* toFind;
	};
	ExploredNodes exset;
};

#endif
