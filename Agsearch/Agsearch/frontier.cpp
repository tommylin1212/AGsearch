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

bool Frontier::add(Node * p) {
	if (!check(p)) {
		if (fnodes.empty()) {
			fnodes.push_back(p);
			return true;
		}
		FrontierList::iterator it = fnodes.begin();
		for (; it < fnodes.end(); it++) {
			if (p->getpathcost() < (*it)->getpathcost()) {
				break;
			}
		}
		fnodes.insert(it, p);
		return true;
	}
	else {
		Node * other = get(p->getName());
		if (other->getpathcost() > p->getpathcost()) {
			replace(other->getName(), p);
		}
		return false;
	}
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

void Frontier::replace(string a, Node* b) {
	FrontierList::iterator it;
	for (it=fnodes.begin(); it < fnodes.end();it++) {
		if ((*it)->getName() == a) {
			break;
		}
	}
	fnodes.erase(it);
	add(b);
}
