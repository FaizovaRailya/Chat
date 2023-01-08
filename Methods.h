#pragma once
#include "User.h"
#include "Message.h"
#include <vector>

class Methods {
	vector<User>UserSpisok;				//список зарегистрированных пользователей
	vector<Message> messageList;		//создаем вектор, который хранит сообщения в чате

public:
	bool FindLogin(string login);						//метод проверки логина
	void NewUser();										//метод создания нового пользователя
	bool UserSearch(string login, string password);     //метод поиска пользователя по логину и паролю
	void PrintNamesUsers();							    //метод получения списка зарегестрированных пользователей
	int FindUserinUserSpisok(string name);				//метод проверяет корректно ли введено имя
	bool IsEmpty();										//метод проверки наличия сообщений
	void setShowChat();									//метод чтения сообщений
	void setAddMessage();								//метод добавления сообщения в массив
};
