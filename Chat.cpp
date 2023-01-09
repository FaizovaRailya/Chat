// Chat.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <Windows.h>
#include "User.h"
#include "Message.h"
#include "Methods.h"


using namespace std;

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Methods methods;
	bool f = true;
	while (f) {
		char a;
		cout << "------Введиде действие:------\n1 - вход\n2 - регистрация\n0 - выход\n";
		cin >> a;
		cin.ignore(100, '\n');
		string log, pas;

		switch (a) {
		case '1':													//вход по логину и паролю
			std::cout << "----Введите----\nЛогин: ";
			cin >> log;
			std::cout << "Пароль: ";
			cin >> pas;
			if (methods.UserSearch(log, pas)) {
				bool f1 = true;
				while (f1) {
					cout << "\n------Введите действиe:------\n1 - Прочитать сообщениe\n2 - Написать сообщение\n0 - Выйти\n";
					char b;
					cin >> b;
					cin.ignore(100, '\n');
					switch (b) {
					case '1':										//прочитать сообщения					
						methods.setShowChat();
						break;

					case '2':										//написать сообщение
						methods.setAddMessage();
						break;

					case '0':										//выход
						f1 = false;
						continue;
					default:
						cout << "Неверный ВВОД!\n" << endl;
						break;
					}
				}
			}
			break;
		case '2':								// регистрация нового пользователя
			try {
				methods.NewUser();					//вызываем метод добавления нового пользователя
			}
			catch (exception& e) {
				cout << e.what();
			}
			break;
		case '0':
			f = false;
			break;

		default:
			cout << "Неверный ВВОД!\n" << endl;
			break;
		}
	}
	return 0;
}
