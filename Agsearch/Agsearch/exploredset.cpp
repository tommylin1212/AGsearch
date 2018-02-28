#include "exploredset.h"

ExploredSet::ExploredSet() {
}

ExploredSet::~ExploredSet() {
	int size = exset.size();
	for (int i = 0; i < size; i++) {
		delete exset[size - i - 1];
	}
}

bool ExploredSet::check(Node * n) {
	for (int i = 0; i < exset.size(); i++) {
		if (n->getName() == exset[i]->getName()) {
			return true;
		}
	}
	return false;
}

bool ExploredSet::checksame(Node * n) {
	for (int i = 0; i < exset.size(); i++) {
		if (n == exset[i]) {
			return true;
		}
	}
	return false;
}

bool ExploredSet::add(Node * n) {
	exset.push_back(n);
	return true;//sure
}

void ExploredSet::print() const {
	for (int i = 0; i < exset.size(); i++) {
		exset[i]->print();
	}
}
