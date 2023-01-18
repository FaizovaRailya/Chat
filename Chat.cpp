// Chat.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <Windows.h>
#include "User.h"
#include "Message.h"
#include "Methods.h"
#include "Methods.cpp"

using namespace std;

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Methods<string> methods;
	bool f = true;
	while (f) {
		char a;
		cout << "Количество пользователей: " << methods.sizeUserSpisok() << endl;
		cout << "------Введите действие:------\n1 - вход\n2 - регистрация\n0 - выход\n";
		cin >> a;
		cin.ignore(100, '\n');
		string log, pas;
		switch (a) {
		case '1':													//вход по логину и паролю		
			cout << "----Введите----\nЛогин: ";
			cin >> log;
			cout << "Пароль: ";
			cin >> pas;
			if (methods.UserSearch(log, pas)) {
				bool f1 = true;
				while (f1) {
					cout << "\n------Введите действиe:------\n1 - Прочитать сообщениe\n2 - Написать сообщение\n0 - Назад\n";
					char b;
					cin >> b;
					cin.ignore(100, '\n');

					switch (b) {
					case '1':										//прочитать сообщения					
						if (methods.IsEmpty()) {
							cout << "У вас еще нет входящих сообщений!\n" << endl;
						}
						else {
							cout << "\n------Введите действиe:------\n1 - Личные\n2 - Общие\n0 - Назад\n";
							char d;
							cin >> d;
							cin.ignore(100, '\n');

							switch (d)							{
							case '1':
								methods.setPrivateShowChat();   //вызываем метод вывода личных сообщений  
								continue;
							case '2':
								methods.setAllShowChat();		 //вызываем метод вывода общих сообщений
							case '0':
								continue;
							default:
								cout << "Неверный ВВОД!\n" << endl;
								break;
							}
						}
						break;
					case '2':										//написать сообщение
						methods.setAddMessage();
						break;
					case '0':										//назад
						methods.currrenNull();
						f1 = false;
						break;
					default:
						cout << "Неверный ВВОД!\n" << endl;
						break;
					}
				}
			}			
			break;
		case '2':									// регистрация нового пользователя
			try {
				methods.NewUser();					//вызываем метод добавления нового пользователя			
				methods.currrenNull();
			}
			catch (exception& e) {
				cout << e.what()<< endl;
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
	//methods.clear();
	//methods.PrintMess();
	//cout << methods.getCurrentUser() << endl;
	//methods.PrintMess();
	
	return 0;
}
