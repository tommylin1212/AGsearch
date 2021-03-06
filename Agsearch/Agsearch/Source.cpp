#include "agent.h"
#include "frontier.h"
#include "exploredset.h"
#include "node.h"
#include "problem.h"
#include "Source.h"
using namespace std;

int main(int argc, char** argv) {
	char ding=7;
	if (argc < 5) {
		cout << "Usage: ./program [filename] [filename(actf)] [start] [A|G]";
		return 23;
	}
	else {
		Problem p;
		if (!p.init(argv[1],argv[2]))return 24;
		Agent a(&p);
		a.setsearch(argv[4]);
		Node * answer = a.Searches(argv[3]);
		if (answer) {
			cout<<"Found Route"<<ding<<endl;
			answer->traceBack(true);
			cout<<endl;
		}
		else {
			cout << "No Solution"<<endl;
		}
	}
	return 0;
}
