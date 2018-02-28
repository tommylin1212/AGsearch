#ifndef PROBLEM_H
#define PROBLEM_H

#include <vector>
#include <string>

struct Neighbor {
	std::string name;
	double dist;
};
class CityLink;
typedef std::vector<Neighbor> CityList;
typedef std::vector<CityLink> CityLinks;
class CityLink {
public:
	CityLink(std::string, std::string, double);
	bool operator==(const CityLink&) const;
	void getVals(std::string&, std::string&, double&) const;  // get values
	void print() const;
private:
	std::string a;
	std::string b;
	double cost;
};
class Problem {
public:
	Problem();
	bool init(std::string);
	bool insert(CityLink);
	CityList findNeighbors(std::string);  // expand()
	void print()const;
private:
	CityLinks cmap;
};

#endif
