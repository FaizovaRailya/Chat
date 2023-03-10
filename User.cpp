#include <iostream>
#include "User.h"
#include "Message.h"
using namespace std;

User::User(const string& name, const string& login, const string& password) :
	name_(name), login_(login),	password_(password){}

string& User::getName() { return name_; }
string& User::getLogin() { return login_; }
string& User::getPassword() { return password_; }