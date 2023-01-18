#pragma once
#include "User.h"
#include "Message.h"
#include <vector>
#include <exception>
#include <memory>

template <typename T> class Methods {
	vector<User> UserSpisok;				//список зарегистрированных пользователей
	vector<Message> messageList;			//создаем вектор, который хранит сообщения в чате
	shared_ptr<User> currentUser = nullptr; //указатель указывает на текущего пользователя

public:
	Methods() = default;
	~Methods() = default;
		
	int userLogin = 0;									// для индекса текущего логина
	shared_ptr<User>getCurrentUser();
	shared_ptr<User>getUserByLogin(string& login);


	bool FindName(T name);							    //проверка имени
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
	void currrenNull();
	/*void PrintMess();
	void clear();*/
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