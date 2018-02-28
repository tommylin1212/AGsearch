#include "agent.h"
using namespace std;
Agent::Agent() {
	//nuthin to do
	AorG = false;
}

Agent::Agent(Problem * p) {
	m = p;
	AorG = false;
}




Node * Agent::Searches(std::string a) {
	Node* cur = new Node(NULL, a, 0,m->findh(a));
	f.add(cur,AorG);
	while (true) {
		if (f.isEmpty())return NULL;
		Node* test = f.next();
		if (test->getName() == "Bucharest")return test;
		exset.add(test);
		CityList temp = m->findNeighbors(test->getName());
		for (int i = 0; i < temp.size(); i++) {
			Node *child = new Node(test, temp[i].name, temp[i].dist, m->findh(temp[i].name));
			cout << "frontier:";
			f.print();
			cout << endl;
			if (!exset.check(child)) {
				f.add(child,AorG);
				cout << "frontier:";
				f.print();
				cout << endl;
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

void Agent::setsearch(char * n){
	if (n[0] == 'A' || n[0] == 'a') {
		AorG = true;
	}
	else {
		AorG = false;
	}
}
