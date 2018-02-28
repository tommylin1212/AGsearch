#ifndef AGENT_H
#define AGENT_H

#include "frontier.h"
#include "exploredset.h"
#include "problem.h"

class Agent {
public:
	Agent();
	Agent(Problem*);
	Node* Searches(std::string a);
	void printExploredSet() const;
	void printFrontier() const;
	void setsearch(char* n);
private:
	ExploredSet exset;
	Frontier f;
	Problem* m;
	bool AorG;
};

#endif
