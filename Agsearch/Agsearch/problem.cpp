#include "problem.h"
#include <fstream>
#include <iostream>
using namespace std;
Problem::Problem() {
	//nothing to do here
}

bool Problem::init(std::string fname, string fname1) {
	ifstream ifs(fname.c_str());
	if (ifs.fail()) {
		cout << "Invalid map file. Exiting.";
		return false;
	}
	string city1, city2;
	double weight, trash;
	char check;
	while (!ifs.eof()) {
		check = ifs.get();
		if (check == '#') {
			while (check != '\n') {
				check = ifs.get();
			}
		}
		else {
			ifs.putback(check);
			ifs >> city1 >> city2 >>trash>> weight;
			insert(CityLink(city1, city2, weight));
		}
	}
	ifs.close();
	ifs.open(fname1.c_str());
	if (ifs.fail()) {
		cout << "Invalid actf file. Exiting.";
		return false;
	}
	while (!ifs.eof()) {
		check = ifs.get();
		if (check == '#') {
			while (check != '\n') {
				check = ifs.get();
			}
		}
		else {
			ifs.putback(check);
			ifs >> city1 >>city2 >> weight;
			Hueristic temp;
			temp.name = city1;
			temp.weight = weight;
			inserth(temp);
		}
	}
	ifs.close();
	return true;
}

bool Problem::insert(CityLink temp) {
	for (int i = 0; i < cmap.size(); i++) {
		if (temp == cmap[i])return false;
	}
	cmap.push_back(temp);
	return true;
}
bool Problem::inserth(Hueristic temp) {
	hmap.push_back(temp);
	return true;
}

CityList Problem::findNeighbors(std::string temp) {
	string city1, city2;
	double weight;
	CityList cl;
	Neighbor n;
	for (int i = 0; i < cmap.size(); i++) {
		cmap[i].getVals(city1, city2, weight);
		if (city1 == temp) {
			n.name = city2;
			n.dist = weight;
			cl.push_back(n);
		}
		if (city2 == temp) {
			n.name = city1;
			n.dist = weight;
			cl.push_back(n);
		}
	}
	return cl;
}

void Problem::print() const {
	for (int i = 0; i < cmap.size(); i++) {
		cmap[i].print();
	}
}

double Problem::findh(std::string a){
	for (int i = 0; i < hmap.size(); i++){
		if (hmap[i].name == a) return hmap[i].weight;
	}
}

CityLink::CityLink(std::string city1, std::string city2, double weight) {
	a = city1;
	b = city2;
	cost = weight;
}

bool CityLink::operator==(const CityLink & city1) const {
	string a1, b1;
	double weight;
	city1.getVals(a1, b1, weight);
	if (((this->a == a1) && (this->b == b1)) ||
		((this->a == b1) && (this->b == a1))) {
		return true;
	}
	return false;
}

void CityLink::getVals(std::string & a1, std::string & b1, double & w) const {
	a1 = a;
	b1 = b;
	w = cost;
}

void CityLink::print()const {
	cout << a << " " << b << " " << cost << endl;
}
