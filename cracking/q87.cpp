#include <string>
#include <vector>
#include <list>

using std::string;
using std::vector;
using std::list;

enum Sex {male, female, unknown};
enum UserType {Normal, Moderator, SU};
enum MsgType {broadcast, pvt, sys};

class user;

class msg
{
public:
msg(MsgType t, string s, user* f = NULL, user* t = NULL): msgText(s), from(f), to(t), type (t) {}
void ShowMSG();
void SendMSG();
void DeleteMsg();
private:
string msgText;
user* from;
user* to;
MsgType type;
}

class user {
public:
user(int ID, Sex s = unknow, UserType type = Normal): UserID(ID), sex(s), accountType(type) {}
virtual ~user(){}
void SetName(const char* newname) {name = newname;}
void SetDesc(const char* str) {desc = str;}
void SetPasswd(const char* pw) {passwd = pw;}
void SetAccountType(UserType newtype) {accountType = newtype;}
bool isPasswdCorrect(string str) {if (str == passwd) return true; else return false;}
int GetID() {return UserID;}
string GetName() {return name;}
string GetDesc() {return desc;}
UserType GetAccountType() {return accountType;}
void ReadMSG();

private:
int UserID;
Sex sex;
string name;
string desc;
string passwd;
UserType accountType;
list<msg> receivedMsg;
};

//class NormalUser : public user {
//public:
//NormalUser(int ID, Sex s = unknow, UserType type = Normal): user(ID, s, type) {}
//virtual ~NormalUser(){}
//};

//class Moderator : public user {
//public:
//Moderator(int ID, Sex s = unknow, UserType type = Moderator): user(ID, s, type) {}
//virtual ~Moderator(){}
//};

//class SU : public user {
//public:
//SU(int ID, Sex s = unknow, UserType type = SU): user(ID, s, type) {}
//virtual ~SU(){}
//};

class UserList
{
public:
UserList(){NextID=0;}
void UserRegister();
void DeleteUser(int ID);
void KickUser(int ID);
void SetPriviledge(int ID, UserType type);
void UserOnline(int ID);
void UserOffline(int ID);
int FindUser(const char* str);
user* FindUser(int ID);
user* FindOnlineUser(int ID);

private:
static int NextID;
vector<user*> onlineList;
vector<user*> userData;
};

class ChatServer
{
public:
ChatServer(){}
~ChatServer(){}

private:
UserList userlist;
}

