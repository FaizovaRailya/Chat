#pragma once
#include<string>
using namespace std;

class User {
	string name_;
	string login_;
	string password_;
public:
	
	User(string name, string login, string password);
	~User();
	string& getName();  
	string& getLogin();
	string& getPassword();
	
};