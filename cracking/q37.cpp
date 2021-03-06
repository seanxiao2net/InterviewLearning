#include <queue>
#include <iostream>
#include <typeinfo>

using namespace std;

class Animal
{
friend class Cat;
friend class Dog;
public:
Animal(): order(0){}
Animal(const char* newname, int num =0): name(newname), order(num) {}
virtual ~Animal(){}
void SetName(const char* newname){name = newname;}
void SetOrder(int num){order = num;}
int GetOrder(){return order;}
virtual void print() = 0;

protected:
string name;
int order;
};


class Cat: public Animal
{
public:
Cat():Animal(){}
virtual ~Cat(){}
Cat(Animal &rhs):Animal(rhs.name.c_str(), rhs.order){}
virtual void print() {cout<<"This is cat, name is "<<name<<" id is "<<order<<endl;}
};

class Dog: public Animal
{
public:
Dog():Animal(){}
virtual ~Dog(){}
Dog(Animal &rhs):Animal(rhs.name.c_str(), rhs.order){}
virtual void print() {cout<<"This is dog, name is "<<name<<" id is "<<order<<endl;}
};

class shelter
{
public:
shelter():ID(0){}
void enqueue(Animal &newitem);
Dog* deQdog();
Cat* deQcat();
Animal* deQ();

private:
queue<Animal*> cat;
queue<Animal*> dog;
int ID;
};

void shelter::enqueue(Animal &newitem)
{
	if (typeid(newitem)==typeid(Cat))
	{
		Cat *newcat;
		newcat = new Cat(newitem);
		newcat->SetOrder(ID++);
		cat.push(newcat);
	}
	else
	{
		Dog *newdog;
		newdog = new Dog(newitem);
		newdog->SetOrder(ID++);
		dog.push(newdog);
	}
}

Dog* shelter::deQdog()
{
	if (dog.size() == 0)	return NULL;

	Dog* ret;

	ret = (Dog*)dog.front();
	dog.pop();

	return ret;
}

Cat* shelter::deQcat()
{
	if (cat.size() == 0)	return NULL;

	Cat* ret;

	ret = (Cat*)cat.front();
	cat.pop();

	return ret;
}

Animal* shelter::deQ()
{
	Animal* ret;
	if ((cat.size())&&(dog.size()))
	{
		if(cat.front()->GetOrder() < dog.front()->GetOrder())
		{
			ret = cat.front();
			cat.pop();
		}
		else
		{
			ret = dog.front();
			dog.pop();
		}

	}
	else if (cat.size())
	{
		ret = cat.front();
		cat.pop();
	}
	else if (dog.size())
	{
		ret = dog.front();
		dog.pop();
	}
	else
	{
		ret = NULL;
	}

	return ret;
}



int main()
{
	shelter q;
	Cat mycat;
	Dog mydog;
	Cat* ret_c;
	Dog* ret_d;
	Animal* ret;

	q.enqueue(mycat);
	q.enqueue(mydog);

	mycat.SetName("jemi1");
	q.enqueue(mycat);
	mycat.SetName("jemi2");
	q.enqueue(mycat);
	mycat.SetName("jemi3");
	q.enqueue(mycat);

	ret_c = q.deQcat();
	ret_d = q.deQdog();

	ret_c->print();
	ret_d->print();

	delete ret_c;
	ret_c = q.deQcat();
	ret_c->print();

	ret = q.deQ();
	ret->print();

	ret = q.deQ();
	ret->print();

	ret = q.deQ();
	if (ret != NULL)
	ret->print();


	return 0;
}
