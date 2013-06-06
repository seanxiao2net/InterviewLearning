#include <list>
#include <string>
#include <iostream>
#include <typeinfo>

using namespace std;

class cat;
class dog;

class animal
{
friend class cat;
friend class dog;
public:
	animal(const char* newName, int num): name(newName), order(num){}
	virtual ~animal(){};
	void SetOrder(int num) {order = num;}
	int GetOrder() {return order;}
	void SetName(const char* newName) {name = newName;}
	bool isOlderThan(animal& rhs) {return order < rhs.order;}
	virtual void Print() =0;
	
protected:
	string name;
	int order;
	//static int count;
};

//int animal::count = 0;

class cat: public animal
{
public:
	cat(const char* newName, int num) : animal(newName, num){}
	cat(animal& sth): animal(sth.name.c_str(), sth.order){};
	virtual void Print() {cout<<"This is cat "<<name<<" order"<<order<<endl;}
	virtual ~cat(){};
	
};

class dog: public animal
{
public:
	dog(const char* newName, int num) : animal(newName, num){}
	dog(animal& sth): animal(sth.name.c_str(), sth.order){};
	virtual void Print() {cout<<"This is dog "<<name<<" order"<<order<<endl;}
	//dog(animal& sth){};
	virtual ~dog(){};
	
};

//animal::operator cat()
//{
//	return cat(name.c_str(), order);
//}

//animal::operator dog()
//{
//	return dog(name.c_str(), order);
//}

class animalQ
{
public:
	animalQ():order(0){};
	void enqueue(animal& newanimal);
	animal* dequeueall();
	cat* dequeuecat();
	dog* dequeuedog();

private:
	int order;
	list<animal*> catlist;
	list<animal*> doglist;
};

void animalQ::enqueue(animal& newanimal)
{
	animal* newitem;

	if (typeid(newanimal) == typeid(cat))
	{
		newitem = new cat(newanimal);
		newitem->SetOrder(order++);
		catlist.push_back(newitem);
	}
	else
	{
		newitem = new dog(newanimal);
		newitem->SetOrder(order++);
		doglist.push_back(newitem);
	}
}

cat* animalQ::dequeuecat()
{
	cat* newcat =NULL;

	if (catlist.empty())	return NULL;

	newcat = (cat*)catlist.front();
	catlist.pop_front();

	return newcat;
}

dog* animalQ::dequeuedog()
{
	dog* newdog =NULL;

	if (doglist.empty())	return NULL;

	newdog = (dog*)doglist.front();
	doglist.pop_front();

	return newdog;
}

animal* animalQ::dequeueall()
{
	animal* newanimal = NULL;

	if (doglist.empty() && catlist.empty()) return NULL;
	else if (doglist.empty())
	{
		newanimal = catlist.front();
		catlist.pop_front();
	}
	else if (catlist.empty())
	{
		newanimal = doglist.front();
		doglist.pop_front();
	}
	else
	{
		if (doglist.front()->GetOrder() < catlist.front()->GetOrder())
		{
			newanimal = doglist.front();
			doglist.pop_front();
		}
		else
		{
			newanimal = catlist.front();
			catlist.pop_front();
		}
	}

	return newanimal;
}

//cat animalQ::dequeuecat()
//{
//	()
//}

int main()
{
	animalQ q;
	cat mycat("jemi",0);
	dog mydog("tidi",0);
	cat* ret_c;
	dog* ret_d;
	animal* ret;

	q.enqueue(mycat);
	q.enqueue(mydog);

	mycat.SetName("jemi1");
	q.enqueue(mycat);
	mycat.SetName("jemi2");
	q.enqueue(mycat);
	mycat.SetName("jemi3");
	q.enqueue(mycat);

	ret_c = q.dequeuecat();
	ret_d = q.dequeuedog();

	ret_c->Print();
	ret_d->Print();

	delete ret_c;
	ret_c = q.dequeuecat();
	ret_c->Print();

	ret = q.dequeueall();
	ret->Print();

	return 0;
}
