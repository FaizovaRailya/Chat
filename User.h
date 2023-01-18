#pragma once
#include<string>
#include"Message.h"
using namespace std;

class User {
	string name_;
	string login_;
	string password_;

public:
	User(const string& name, const string& login, const string& password);
	~User() = default;
	string& getName();
	string& getLogin();
	string& getPassword();
};