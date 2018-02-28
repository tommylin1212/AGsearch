#include "agent.h"
using namespace std;
Agent::Agent() {
	//nuthin to do
}

Agent::Agent(Problem * p) {
	m = p;
}

Node * Agent::bsearch(std::string a, std::string b) {
	Node* cur = new Node(NULL, a, 0);
	if (a == b) {
		return cur;
	}
	f.add(cur);
	while (true) {
		if (f.isEmpty())return NULL;
		Node* test = f.next();
		if (test->getName() == b)return test;
		exset.add(test);
		CityList temp = m->findNeighbors(test->getName());
		for (int i = 0; i < temp.size(); i++) {
			Node *child = new Node(test, temp[i].name, temp[i].dist);
			if (!f.checksame(child) && !exset.check(child)) {
				f.add(child);
			}
		}
	}
}

void Agent::printExploredSet() const {
	exset.print();
}

void Agent::printFrontier() const {
	f.print();
}
