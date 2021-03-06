#ifndef FRONTIER_H
#define FRONTIER_H

#include "node.h"
#include <deque>

enum FrontierType { LIFO, FIFO };

typedef std::deque<Node*> FrontierList;

class Frontier {
public:
	Frontier();
	~Frontier();
	bool add(Node*,bool);
	bool check(Node*);
	bool checksame(Node*);
	bool isEmpty();
	Node* next();
	void setType(FrontierType);
	void print() const;
	Node* get(std::string a);
	
private:
	FrontierType type;
	FrontierList fnodes;
};

#endif
