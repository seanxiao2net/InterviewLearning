#include <time.h>
#include <vector>
using std::vector;

class vehicle;

class parkingslot
{
public:
parkingslot(int sz): size(sz),avaliable(true), thisvehicle(NULL){}
~parkingslot(){}
bool isAvaliable() {return avaliable;}
void setunAvaliable(vehicle *v) {avaliable = false; thisvehicle = v;}
void setAvaliable() {avaliable = true; thisvehicle = NULL;}
vehicle* getVehicleID() {return thisvehicle;}
private:
int size;
bool avaliable;
vehicle *thisvehicle;
};

class vehicle
{
public:
virtual ~vehicle(){}
virtual float fee() = 0;
int GetType() {return type;}
parkingslot* GetSlot() {return slot;}

protected:
vehicle(int t, parkingslot* s): type(t),slot(s) {time(&timer);}
int type;
time_t timer;
parkingslot* slot;
};

class motorcycle :public vehicle {
public:
motorcycle(parkingslot* s): vehicle(0, s) {}
virtual ~motorcycle(){}
virtual float fee();	//this function calculate the accumulated fees based on the type and time
private:
static const float rate = 1.0;
};

class car:public vehicle {
public:
car(parkingslot* s): vehicle(1, s) {}
virtual ~car(){}
virtual float fee();
private:
static const float rate = 2.0;
};

class truck:public vehicle {
public:
truck(parkingslot* s): vehicle(2, s) {}
virtual ~truck(){}
virtual float fee();
private:
static const float rate = 3.0;
};



class parkinglot
{
parkinglot(vector<int> &sz);
~parkinglot(){}
int assignSlot(vehicle* v);
float checkout(vehicle* v);
bool isFull(int t){return (max_sz[t] - occupied[t])>0;}

private:
vector<vector<parkingslot> > slots;
vector<int> max_sz;
vector<int> occupied;
};

int main()
{



	return 0;
}
