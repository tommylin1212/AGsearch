#ifndef AGENT_H
#define AGENT_H

#include "frontier.h"
#include "exploredset.h"
#include "problem.h"

class Agent {
public:
	Agent();
	Agent(Problem*);
	Node* bsearch(std::string, std::string);
	void printExploredSet() const;
	void printFrontier() const;
private:
	ExploredSet exset;
	Frontier f;
	Problem* m;
};

#endif
