#include <cstdlib>

//template <class type>
//class QueueItem
//{
//public:

//type val;
//};

//template <class type>
//class Queue{
//public:
//Queue():front(0),back(0){}
//~Queue();

//private:
//QueueItem<type> *front;
//QueueItem<type> *back;


//};



template <class type>
class Queue
{
public:
	Queue():front(0),back(0){}

private:
	class QueueItem
	{
	public:
		QueueItem(type val):Item(val), next(0){}
		type Item;
		QueueItem* next;
	};

	QueueItem *front, *back;

};

int main()
{

	return 0;
}
