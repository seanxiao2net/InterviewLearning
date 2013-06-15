#include <string>
#include <vector>

using std::string;
using std::vector;

class book {
public:
book(const char* str, int ID):title(str), bookID(ID), avaliable(true){}
~book(){}
void AddDesc(const char* desc) {description = desc;}
size_t FindBookBytitle(const char* str) {return title.find(str);}
void GetBook(){avaliable = false;}
void ReturnBook() {avaliable = true;}
bool isBorrowed() {return avaliable;}
private:
string title;
string description;
int bookID;
bool avaliable;
};

class display {
public:
display(book* b):myBook(b), Page(0){}
~display(){}
void GetPage();
void SetBook(book* b) {myBook = b; Page = 0;}
void PageUp(){++Page;}
void PageDown(){--Page;}

private:
book* myBook;
int Page;
};

class user {
public:
user(const char* n, int ID): name(n), UserID(ID), reading(NULL), myView(NULL){}
~user(){}
void getBook(book* b) {reading = b; b->GetBook(); myView.SetBook(b);}
book* getBookPtr() {return reading;}
void returnBook() {reading->ReturnBook(); reading = NULL;}
void readBook() {myView.GetPage();}
void readNextPage() {myView.PageUp(); myView.GetPage();}
void readPreVPage() {myView.PageDown(); myView.GetPage();}

private:
string name;
int UserID;
book* reading;
display myView;
};


class Library
{
public:
Library(){currID = 0;}
~Library(){}
void AddBooks(book &newbook){}
void DeleteBooks(int bookID);
book* SearchBookbyTitle(const char* str);
book* SearchBookbyDesc(const char* str);

private:
vector<book*> booklist;
static int currID;
};

class UserManager {
public:
UserManager(){currID = 0;}
~UserManager();
void AddUser(user &newuser);
void DeleteUser(int userID);
void UpdateInfo(const char *newname, int userID);
int SearchUserByName(const char* str);
string SearchUserByID(int ID);

private:
vector<user*> userlist;
static int currID;
};

class System {
public:
System(){}
~System(){}
UserManager* GetUserManager(){return &usermanagesys;}
Library* GetLibrary() {return &library;}

private:
UserManager usermanagesys;
Library library;
};

int main()
{


	return 0;
}
