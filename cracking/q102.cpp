#include <vector>
#include <map>
#include <cstddef>
using std::vector;
using std::map;

//class Person {
//public:

//private:
//string name;
//string desc;
//vector<Person*> friends;
//}

class Person {
public:
Person(int ID) {PersonID = ID;}
int GetID() {return PersonID;}
void AddFriend(int ID) {FriendIDs.push_back(ID);}

private:
int PersonID;
vector<int> FriendIDs;
};


class Server {
public:
Server(){}
Person* GetPersonWithID(int ID) {return persons[ID];}

private:
int ServerID;
map<int, Person*> persons;
};

class Service {
public:
Service(){}
Server* GetServerWithID(int ID) {
	map<int,Server*>::iterator it = servers.find(ID);
	if (it == servers.end()) return NULL;
	else return it->second;
}
int GetServerIDforUser(int ID) {return personToServer[ID];}
Person* GetPerson(int ID);

private:
map<int,int> personToServer;
map<int,Server*> servers;
};

Person* Service::GetPerson(int ID) {
	map<int,int>::iterator it_1;
	it_1 = personToServer.find(ID);
	if (it_1 == personToServer.end()) return NULL;

	Server* s;
	s = GetServerWithID(it_1->second);
	return s->GetPersonWithID(ID);
}

int main()
{


	return 0;
}
