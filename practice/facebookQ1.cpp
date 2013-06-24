#include <string>
#include <iostream>
using std::string;
using std::cout;
using std::endl;

double solveForX(string s) {
	bool isLeft = true;
	bool isPos = true;
	int count_x = 0;
	int count_num = 0;
	string::iterator it;

	for (it = s.begin(); it != s.end(); ++it) {
		switch(*it) {
		case '+':
			isPos = true;
			break;
		case '-':
			isPos = false;
			break;
		case '=':
			isLeft = !isLeft;
			break;
		case 'x':
			if (!(isLeft^isPos)) {
				++count_x;
			} else {
				--count_x;
			}
			break;
		default:
			if ((isLeft^isPos)) {
				count_num += (*it - '0');
			} else {
				count_num -= (*it - '0');
			}
		}
	}
	cout<<count_x<<" "<<count_num<<endl;
		
	return (double)count_num/(double)count_x;
}


int main() {
	string in;
	double out=0;

	//in = "x+9-2-4+x=-x+5-1+3-x";
	//in = "x+9-1 = 0";
	in = "x+4=-3-x";

	out = solveForX(in);

	cout<<"in "<<in<<" output: x ="<<out<<endl;


	return 0;
}
