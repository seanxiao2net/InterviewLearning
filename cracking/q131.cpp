#include <string>
#include <iostream>
#include <fstream>

//using std::string;
//using std::cout;
//using std::endl;
//using std::ifstream;
using namespace std;

void PrintKLine(string &filename, int num) {
	ifstream myfile;
	string buffer[num];
	int sz = 0;

	myfile.open(filename.c_str());


	//if (myfile.fail()) return;

	while ((!myfile.fail())&&(!myfile.eof())) {
		getline(myfile, buffer[(sz++)%num]);
	}

	int begin = (sz < num) ? 0 : sz%num;
	int count = (sz < num) ? sz : num;

	for (int i = begin; i<count; ++i) {
		cout<< buffer[(i)%num] <<endl;
	}
}


int main() {

	string filename = "abc.txt";
	PrintKLine(filename, 4);

	return 0;
}
