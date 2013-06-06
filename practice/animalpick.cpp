#include <iostream>
#include <list>
#include <typeinfo>

using namespace std;

class Animal
{
public:
	Animal():name(""), order(0){}
	Animal(const char* str, int num=0): name(str), order(num){}
	void SetOrder(int num) {order = num;}
	int GetOrder() {return order;}
	void SetName(const char* str) {name = str;}
	const char* GetName() {return name.c_str();}
	virtual void print() = 0;
	virtual ~Animal(){}
protected:
	string name;
	int order;
};

class Cat: public Animal
{
public:
	Cat():Animal() {}
	Cat(Animal& rhs): Animal(rhs.GetName(), rhs.GetOrder()){}
	Cat(const char* str, int num): Animal(str, num){}
	virtual void print() {cout<<"This is cat, name is "<<name<<" order is "<<order<<endl;}
	virtual ~Cat(){}
};

class Dog: public Animal
{
public:
	Dog():Animal() {}
	Dog(Animal& rhs): Animal(rhs.GetName(), rhs.GetOrder()){}
	Dog(const char* str, int num): Animal(str, num){}
	virtual void print() {cout<<"This is dog, name is "<<name<<" order is "<<order<<endl;}
	virtual ~Dog(){}
};

class shelter
{
public:
	shelter(): count(0){};
	void enqueue(Animal& sth);
	Animal* dequeue();
	Cat* dequeueCat();
	Dog* dequeueDog();

private:
	int count;
	list<Animal*> catlist;
	list<Animal*> doglist;
};

void shelter::enqueue(Animal& sth)
{
	Animal* it;
	if (typeid(sth) == typeid(Cat))
	{
		it = new Cat(sth);
		it->SetOrder(count++);
		catlist.push_back(it);
	}
	else
	{
		it = new Dog(sth);
		it->SetOrder(count++);
		doglist.push_back(it);
	}
}

Cat* shelter::dequeueCat()
{
	if (catlist.empty())	return NULL;
	Cat* tmp;

	tmp = (Cat*)catlist.front();
	catlist.pop_front();
	return tmp;
}

Dog* shelter::dequeueDog()
{
	if (doglist.empty())	return NULL;
	Dog* tmp;

	tmp = (Dog*)doglist.front();
	doglist.pop_front();
	return tmp;
}

Animal* shelter::dequeue()
{
	Animal* it;
	if (catlist.empty()&&doglist.empty())	return NULL;
	else if (catlist.empty())
	{
		it = doglist.front();
		doglist.pop_front();
	}
	else if (doglist.empty())
	{
		it = catlist.front();
		catlist.pop_front();
	}
	else
	{
		if (catlist.front()->GetOrder() < doglist.front()->GetOrder())
		{
			it = catlist.front();
			catlist.pop_front();
		}
		else
		{
			it = doglist.front();
			doglist.pop_front();
		}
	}

	return it;
}


int main()
{
	shelter q;
	Cat newcat;
	Dog newdog;
	Cat* rtc;
	Dog* rtd;
	Animal* rt;
	

	newcat.SetName("jiemao");
	newdog.SetName("tidi");
	q.enqueue(newcat);
	q.enqueue(newdog);
	newcat.SetName("jiemao1");
	newdog.SetName("tidi1");
	q.enqueue(newcat);
	q.enqueue(newdog);
	newcat.SetName("jiemao2");
	newdog.SetName("tidi2");
	q.enqueue(newcat);
	q.enqueue(newdog);
	newcat.SetName("jiemao3");
	newdog.SetName("tidi3");
	q.enqueue(newcat);
	q.enqueue(newdog);

	rtc = q.dequeueCat();
//	rtd = q.dequeueDog();
	rtc->print();
	delete rtc;
	rtc = q.dequeueCat();
	rtc->print();
//	rtd->print();
	rt = q.dequeue();
	rt->print();

	delete rt;
	rt = q.dequeue();
	rt->print();
	delete rt;
	rt = q.dequeue();
	rt->print();
	delete rt;
	rt = q.dequeue();
	rt->print();
	delete rt;
	rt = q.dequeue();
	rt->print();
	

	return 0;
}
