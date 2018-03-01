#include "frontier.h"
using namespace std;

Frontier::Frontier() {
	type = LIFO;
}

Frontier::~Frontier() {
	int size = fnodes.size();
	for (int i = 0; i < size; i++) {
		delete fnodes[size - i - 1];
	}
}

bool Frontier::add(Node * p,bool a_g) {
		if (fnodes.empty()) {
			fnodes.push_back(p);
			return true;
		}
		FrontierList::iterator it = fnodes.begin();
		for (; it < fnodes.end(); it++) {
			if (!a_g) {
				if (p->gethcost() < (*it)->gethcost()) {//greedy
					break;
				}
			}
			else{
				if (p->getpathcost()+p->gethcost() < (*it)->getpathcost()+(*it)->gethcost()) {
					break;
				}
			}
		}
		fnodes.insert(it, p);
		return true;
}

bool Frontier::check(Node * p) {
	for (int i = 0; i < fnodes.size(); i++) {
		if (p->getName() == fnodes[i]->getName())return true;
	}
	return false;
}
bool Frontier::checksame(Node * p) {
	for (int i = 0; i < fnodes.size(); i++) {
		if (*p==*fnodes[i])return true;
	}
	return false;
}

bool Frontier::isEmpty() {
	return fnodes.empty();
}

Node * Frontier::next() {
	if (type) {
		Node * temp = fnodes.back();//fifo
		fnodes.pop_back();
		return temp;
	}
	else {
		Node * temp = fnodes.front();
		fnodes.pop_front();
		return temp;
	}
}

void Frontier::setType(FrontierType f) {
	type = f;
}

void Frontier::print() const {
	for (int i = 0; i < fnodes.size(); i++) {
		fnodes[i]->print();
	}
}
Node* Frontier::get(string a) {
	for (int i = 0; i < fnodes.size(); i++){
		if (fnodes[i]->getName() == a) {
			return fnodes[i];
		}
	}
	return NULL;
}


