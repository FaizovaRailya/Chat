// Chat.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "User.h"
#include "Message.h"
#include <vector>
using namespace std;
int userLogin = 0;
vector<User>UserSpisok;   //список зарегистрированных пользователей

bool FindLogin(string login)					//Метод проверки логина
{
	bool j = false;
	for (int i = 0; i < UserSpisok.size(); i++) {
		if (UserSpisok[i].getLogin() == login) {
			j = true;

			return j;
			break;
		}
	}return j;
}
void NewUser() {									//метод создания нового пользователя

	string name;
	string login;
	string pass;
	cout << "----Введите данные для регистрации----\n";
	cout << "Имя: ";
	
	cin >> name;
	
	cout << "Логин: ";

	bool l = true;
	while (l) {
		cin >> login;
		if (FindLogin(login)) {
			cout << "Данный логин уже занят выберите другой!\n";
			cout << "----Введите----\nЛогин: ";
		}
		else {
			l = false;
		}
	}
	cout << "Пароль: ";
	cin >> pass;

	User U(name, login, pass);

	UserSpisok.push_back(U);
	cout << "Пользователь зарегистрирован!\n\n";
}

bool  UserSearch(string login, string password) {            //метод поиска пользователя по логину и паролю
	int i = 0;
	bool flag = false;
	while (i < UserSpisok.size()) {
		string l = UserSpisok[i].getLogin();
		string p = UserSpisok[i].getPassword();
		if (login == l && password == p) {

			cout << endl << "Пользователь: " << UserSpisok[i].getName() << endl << endl;
			userLogin = i;
			flag = true;
			return flag;
			break;
		}
		else {++i;}
	}
	if (flag == false) {
		cout << "\nНеверный логин или пароль!!!\n";
	}
	return flag;
}



void PrintNamesUsers() {							//метод получения списка зарегестрированных пользователей
	for (int i = 0; i < UserSpisok.size(); ++i) {
		cout << (i + 1) << ". " << UserSpisok[i].getName() << endl;
	}
}


int FindUserinUserSpisok(string name) {		//метод проверяет корректно ли введено имя
	for (int i = 0; i < UserSpisok.size(); ++i) {

		if (UserSpisok[i].getName() == name) {
			return i;
		}
	}return -1;
}






int main(){
	setlocale(LC_ALL, "Rus");
	
	while (true) {
		int a;

		cout << "----Введиде действие:----\n1 - вход\n2 - регистрация\n0 - выход\n";
		cin >> a;
		string log;
		string pas;
string message;
string inputName;
		switch (a)
		{
		case 1:								//вход по логину и паролю

			//bool inuser = false;
			std::cout << "----Введите----\nЛогин: ";
			cin >> log;
			std::cout << "Пароль: ";
			cin >> pas;
			if (UserSearch(log, pas)) {
				while (true) {

					
					//inuser = true;

					cout << "\n----Введите действиe:----\n ";
					cout << "1 - Прочитать сообщения\n";
					cout << "2 - Написать сообщение\n";

					cout << "0 - Выйти\n";
					int b = 0;
					cin >> b;
					

					switch (b) {

					case 1:						//прочитать сообщения

						break;
					case 2:						//написать сообщение
						cout << "\n----Введите действиe:----\n1 - Лично\n2 - Всем пользователям\n0 - Выход\n";
						int c;
						cin >> c;


						switch (c)
						{

						case 1:				//лично

							cout << "Введите имя кому отправить сообщение:\n ";
							PrintNamesUsers();   //выводим список пользователей

							cin >> inputName;
							int t = 0;
							t = FindUserinUserSpisok(inputName);
							if (t == -1) {
								cout << "Пользователь с данным именем не найден\n";
							}
							else {
								cout << "Введите текст сообщения: " << endl;
								cout << endl;
								getline(cin, message, '\n');
								getline(cin, message, '\n');

								//Message<string> mes(UserSpisok[user_islogin].GetName(), message);
								//UserSpisok[FindUserinUserSpisok(inputName)].setmessage(mes);
								cout << "Сообщение отправлено!" << endl;
							
 
							}
						case 2:				//всем пользователям
							break;
						case 0:
							break;

						default:
							break;
						}




					//case 0:					// выход
						
						
					default:
						cout << "Неверный ВВОД!" << endl;
						continue;
					}
				}
			}

		case 2:								// регистрация нового пользователя
			NewUser();						//вызываем метод добавления нового пользователя
			continue;
		case 0:
			break;

		default:
			cout << "Неверный ВВОД!" << endl;
			continue;

		}
		break;

	
	
	
	}
	return 0;
}