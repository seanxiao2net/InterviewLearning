#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main()
{
	ofstream outfile("outfile");
	ifstream infile("infile");

	int index;

	if(! infile)
	{
		cerr << "error: cannot input";
		return -1;
	}

	if (! outfile)
	{
		cerr << "error: cannot output";
		return -2;
	}

	string word;
	while ( infile >> word )
	{
		outfile << word << ' ';
	}

	for ( index = 0; index <10; ++index)
	{
		cout << index << endl;
	}

	return 0;
}
