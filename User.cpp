#include "User.h"
#include "Message.h"
#include <vector>
using namespace std;

User::User(string name, string login, string password){
	name_ = name;
	login_ = login;
	password_ = password;
}

User::~User(){}

string& User::getName() {
	return name_;
}

string& User::getLogin() {
	return login_;
}

string& User::getPassword() {
	return password_;
}













