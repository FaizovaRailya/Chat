#pragma once
#include "User.h"
#include "Message.h"
#include <vector>
#include <exception>

template <typename T> class Methods {
	vector<User> UserSpisok;				//список зарегистрированных пользователей
	vector<Message> messageList;		//создаем вектор, который хранит сообщения в чате
	
public:
	int userLogin = 0;									// для индекса текущего логина
	bool FindLogin(T login);							//проверка логина
	void NewUser();										//создание нового пользователя
	bool UserSearch(T login, T password);				//поиск пользователя по логину и паролю
	void PrintNamesUsers();							    //получение списка зарегестрированных пользователей
	int FindUserinUserSpisok(string name);				//проверка корректно ли введено имя
	bool IsEmpty();										//проверка наличия сообщений
	void setPrivateShowChat();							//чтение личных сообщений
	void setAllShowChat();								//чтение общих сообщений
	void setAddMessage();								//добавление сообщения в массив
	int sizeUserSpisok();								//количество зарегистрированных пользователей
};

class LoginExp : public exception {			//исключение если введен логин "all"
public:
	const char* what() const noexcept override {
		return "ERROR: Логин занят!\n\n";
	}
};

class NameExp : public exception {			//исключение если введено имя "all"
public:
	const char* what()const noexcept override {
		return "ERROR: Имя пользователя занято!\n\n";
	}
};