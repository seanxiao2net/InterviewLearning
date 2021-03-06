#include <vector>
#include <iostream>

using std::vector;
using std::endl;
using std::cout;

struct Box {
	int height;
	int width;
	int depth;
	Box(int h=0, int w=0, int d=0): height(h), width(w), depth(d){}
	bool isSmaller(Box *rhs);
	void print() {cout<<"Height "<<height<<" Width "<<width<<" Depth "<<depth<<endl;}
};

bool Box::isSmaller(Box *rhs) {
	if (height<rhs->height && width<rhs->width && depth < rhs->depth)
		return true;
	else	return false;
}

int GetHeight(vector<Box*> &stacks) {
	if (stacks.empty()) return 0;
	int height = 0;
	vector<Box*>::iterator it;
	for (it = stacks.begin(); it!= stacks.end(); ++it)
		height+=(*it)->height;
	return height;
}

vector<Box*> MakeStack(vector<Box> &boxes, Box *bottom) {
	int MaxHeight=0, NewHeight;
	vector<Box*> MaxStack;

	vector<Box>::iterator it;
	for (it=boxes.begin(); it!= boxes.end(); ++it) {
		if ((bottom == NULL)||(it->isSmaller(bottom))) {
			vector<Box*> NewStack;
			NewStack = MakeStack(boxes, &(*it));
			NewHeight = GetHeight(NewStack);
			if (NewHeight > MaxHeight) {
				MaxHeight = NewHeight;
				MaxStack = NewStack;
			}
		}
	}
	if (bottom != NULL) {
		MaxHeight += bottom->height;
		MaxStack.push_back(bottom);
	}
	return MaxStack;
}

void printlist(vector<Box*> in) {
	vector<Box*>::iterator it;

	for (it = in.begin(); it != in.end(); ++it) {
		(*it)->print();
	}
}

int main() {
	vector<Box> boxes;
	vector<Box*> result;
	int height;

	boxes.push_back(Box(9,9,9));
	boxes.push_back(Box(9,8,8));
	boxes.push_back(Box(8,9,9));
	boxes.push_back(Box(8,8,8));
	boxes.push_back(Box(7,7,7));
	boxes.push_back(Box(6,3,3));
	boxes.push_back(Box(6,6,6));
	boxes.push_back(Box(5,5,5));
	boxes.push_back(Box(3,3,3));

	result = MakeStack(boxes, NULL);

	height = GetHeight(result);

	cout<<"height is: "<<height<<endl;
	printlist(result);
	
	return 0;
}
