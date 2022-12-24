// Chat.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "User.h"
#include "Message.h"
#include <vector>
using namespace std;

vector<User>UserSpisok;   //список зарегистрированных пользователей

bool FindLogin(string login)					//Метод проверки логина
{
	bool j = false;
	for (int i = 0; i < size(UserSpisok); i++) {
		if (UserSpisok[i].getLogin() == login) {
			j = true;

			return j;
			break;
		}
	}return j;
}
void NewUser() {									//метод создания нового пользователя чата

	string name;
	string login;
	string pass;
	cout << "Введите данные для регистрации\n";
	cout << "Имя: ";
	
	cin >> name;
	
	cout << "Логин: ";

	bool l = true;
	while (l) {
		cin >> login;
		if (FindLogin(login)) {
			cout << "Данный логин уже занят выберите другой!\n";
			cout << "Введите логин: ";
		}
		else {
			l = false;
		}
	}
	cout << "Пароль: ";
	cin >> pass;

	User U(name, login, pass);

	UserSpisok.push_back(U);
	cout << "Пользователь успешно зарегистрирован!\n\n";
}




int main(){
	setlocale(LC_ALL, "Rus");
	
	while (true) {
		int a;

		cout << "Введиде действие: \n1 - вход\n2 - регистрация\n3 - выход\n";
		cin >> a;
		switch (a)
		{
		case 1:								//вход по логину и паролю

		case 2:								// регистрация нового пользователя
			NewUser();						//вызываем метод добавления нового пользователя
			continue;
		case 3:
			break;

		default:
			cout << "Неверный ВВОД!" << endl;
			continue;
			
		}
		break;

		
	}
	for (int i = 0; i < size(UserSpisok); ++i) {
		cout << (i + 1) << ". " << UserSpisok[i].getName() << endl;
	}
	
}