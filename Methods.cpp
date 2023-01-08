#include <iostream>
#include "Methods.h"
#include "User.h"
using namespace std;

int userLogin = 0;
bool Methods::FindLogin(string login) {						//Метод проверки логина
	bool j = false;
	for (int i = 0; i < UserSpisok.size(); i++) {
		if (UserSpisok[i].getLogin() == login) {
			j = true;
			return j;
			break;
		}
	}return j;
}

void Methods::NewUser() {									//метод создания нового пользователя
	string name;
	string login;
	string password;
	cout << "----Введите данные для регистрации----\n";
	cout << "Имя: ";
	cin >> name;
	cout << "Логин: ";

	bool l = true;
	while (l) {
		cin >> login;
		if (FindLogin(login)) {
			cout << "Данный логин уже занят выберите другой!\n";
			cout << "------ Введите ------\nЛогин: ";
		}
		else {
			l = false;
		}
	}
	cout << "Пароль: ";
	cin >> password;

	User U(name, login, password);				//создаем объект класа User
	UserSpisok.push_back(U);					// добавляем пользователя в массив
	cout << "Пользователь зарегистрирован!\n\n";
}

bool Methods::UserSearch(string login, string password) {	//метод поиска пользователя по логину и паролю	
	int i = 0;
	bool flag = false;
	while (i < UserSpisok.size()) {
		string l = UserSpisok[i].getLogin();
		string p = UserSpisok[i].getPassword();
		if (login == l && password == p) {
			cout << endl << "------ Пользователь: " << UserSpisok[i].getName() << " ------\n";
			userLogin = i;
			flag = true;
			return flag;
			break;
		}
		else { ++i; }
	}
	if (flag == false) {
		cout << "\nНеверный логин или пароль!!!\n";
	}
	return flag;
}

void Methods::PrintNamesUsers() {							//метод получения списка зарегестрированных пользователей
	for (int i = 0; i < UserSpisok.size(); ++i) {
		cout << UserSpisok[i].getName() << endl;
	}
}

int Methods::FindUserinUserSpisok(string name) {				//метод проверяет корректно ли введено имя
	for (int i = 0; i < UserSpisok.size(); ++i) {
		if (UserSpisok[i].getName() == name) {
			return i;
		}
	}return -1;
}

bool Methods::IsEmpty() {									//метод проверки наличия сообщений
	bool i = true;
	if (size(messageList) > 0) { i = false; }	return i;
}

void Methods::setShowChat() {								//метод чтения сообщений
	if (IsEmpty()) {
		cout << "У вас еще нет входящих сообщений!" << endl;
	}
	else {
		std::string from;
		std::string to;
		std::cout << "------Chat------" << std::endl;
		for (auto& mess : messageList) {
			if (UserSpisok[userLogin].getLogin() == mess.getFromMessage() || UserSpisok[userLogin].getLogin() == mess.getToMessage() || mess.getToMessage() == "all") {//если текущий пользователь
				from = (UserSpisok[userLogin].getLogin() == mess.getFromMessage()) ? "Меня" : mess.getFromMessage();
				if (mess.getToMessage() == "all") {			//сообщение всем пользователям
					to = "Всем";
				}
				else {
					to = (UserSpisok[userLogin].getLogin() == mess.getToMessage()) ? "Мне" : mess.getToMessage();
					//если текущее имя равно to, то отправляем сообщение самому себе, если нет, то получаем имя пользователя и присваиваем его значение полю to
				}
				std::cout << "Сообщение от " << from << " кому " << to << ": " << mess.getText() << endl;
			}
		}
		std::cout << "-------------------" << endl;
	}
}

void Methods::setAddMessage()								  //метод добавления сообщения в массив
{
	string inputName;
	string message;
	cout << "Введите имя кому отправить сообщение:\n ";
	PrintNamesUsers();									  //выводим список пользователей
	cout << "all - отправить всем\n";

	cin >> inputName;
	if (inputName == "all") {							  //отправка всем пользователям
		cout << "Введите текст сообщения: \n";
		cout << endl;
		getline(cin, message, '\n');
		getline(cin, message, '\n');
		messageList.push_back(Message(UserSpisok[userLogin].getName(), "all", message));
		cout << "Сообщение разослано всем пользователям!\n";
	}
	else {
		int t = -1;
		t = FindUserinUserSpisok(inputName);
		if (t == -1) {
			cout << "Пользователь с данным именем не найден\n";
		}
		else {
			cout << "Введите текст сообщения: \n";
			cout << endl;
			getline(cin, message, '\n');
			getline(cin, message, '\n');
			messageList.push_back(Message(UserSpisok[userLogin].getName(), inputName, message));
		}
	}
}

