#include <iostream>
#include "Methods.h"

using namespace std;

template<typename T>
shared_ptr<User> Methods<T>::getUserByLogin(string& login)			// указатель на логин пользователя
{
	for (auto& user : UserSpisok)
		if (login == user.getLogin())
			return make_shared<User>(user);
	return nullptr;
}

//template<typename T>
//shared_ptr<User> Methods<T>::getUserByName(string& name)		// указатель на имя пользователя
//{
//	for (auto& user : UserSpisok)
//		if (name == user.getName())
//			return make_shared<User>(user);
//	return nullptr;
//}

template<typename T>
shared_ptr<User> Methods<T>::getCurrentUser()
{
	return currentUser  ;
}

template<typename T>
bool Methods<T>::FindName(T name) {								     //метод проверки имени
	bool j = false;
	for (size_t i = 0; i < UserSpisok.size(); i++) {
		if (UserSpisok[i].getName() == name) {
			j = true;
			return j;
			break;
		}
	}return j;
}

template<typename T>
bool Methods<T>::FindLogin(T login) {								//метод проверки логина
	bool j = false;
	for (size_t i = 0; i < UserSpisok.size(); i++) {
		if (UserSpisok[i].getLogin() == login) {
			j = true;
			return j;
			break;
		}
	}return j;
}

template<typename T> void Methods<T>::NewUser() {					//метод создания нового пользователя
	string name, login, password;
	cout << "---- Введите данные для регистрации ----\n";
	cout << "Имя: ";
	bool n = true;
	while (n) {
		cin >> name;
		if (name == "all") {			// исключение
			throw NameExp();
		}
		if (FindName(name)) {
			cout << "Данное имя уже занято выберите другое!\n\n";
			cout << "------- Введите -------\nИмя: ";
		}
		else {
			n = false;
		}
	}

	cout << "Логин: ";
	bool l = true;
	while (l) {
		cin >> login;
		if (login == "all") {       // исключение
			throw LoginExp();
		}
		if (FindLogin(login)) {
			cout << "Данный логин уже занят выберите другой!\n\n";
			cout << "------- Введите -------\nЛогин: ";
		}
		else {
			l = false;
		}
	}
	cout << "Пароль: ";
	cin >> password;

	User user(name, login, password);			//создаем объект класа User
	UserSpisok.push_back(user);					// добавляем пользователя в массив
	currentUser = make_shared<User>(user);		//создаем указатель на текущего пользователя
	//cout << currentUser << endl;
	cout << "Пользователь зарегистрирован!\n\n";
}

template<typename T>
bool Methods<T>::UserSearch(T login, T password) {					//метод поиска пользователя по логину и паролю	
	int i = 0;
	bool flag = false;
	while (i < UserSpisok.size()) {
		string l = UserSpisok[i].getLogin();
		string p = UserSpisok[i].getPassword();
		if (login == l && password == p) {
			cout << endl << "--------------------------Пользователь: " << UserSpisok[i].getName() << " ----------------------\n";
			userLogin = i;							
			currentUser = getUserByLogin(login);   //указатель на текущего пользователя
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

template<typename T> void Methods<T>::PrintNamesUsers() {				    //метод получения списка зарегестрированных пользователей
	for (size_t i = 0; i < UserSpisok.size(); ++i) {
		cout << UserSpisok[i].getName() << endl;
	}
}

template<typename T> int Methods<T>::FindUserinUserSpisok(string name) {	//метод проверяет корректно ли введено имя
	for (size_t i = 0; i < UserSpisok.size(); ++i) {
		if (UserSpisok[i].getName() == name) {
			return i;
		}
	}return -1;
}

template<typename T>
bool Methods<T>::IsEmpty() {												//метод проверки наличия сообщений
	bool i = true;
	if (messageList.size() > 0) { i = false; }	return i;
}

template<typename T> void Methods<T>::setPrivateShowChat() {				//метод чтения личных сообщений
	string from;
	string to;
	cout << "--------------ЧАТ--------------\n";
	for (size_t i = 0; i < messageList.size(); ++i) {
		if (UserSpisok[userLogin].getName() == messageList[i].getFromMessage() || UserSpisok[userLogin].getName() == messageList[i].getToMessage()) {//если текущий пользователь
			from = (UserSpisok[userLogin].getName() == messageList[i].getFromMessage()) ? "Меня" : messageList[i].getFromMessage();

			to = (UserSpisok[userLogin].getName() == messageList[i].getToMessage()) ? "Мне" : messageList[i].getToMessage();
			//если текущее имя равно to, то отправляем сообщение самому себе, если нет, то получаем имя пользователя и присваиваем его значение полю to

			if (messageList[i].getToMessage() != "all")
				cout << "от " << from << " кому " << to << ": " << messageList[i].getText() << endl;
		}
	}
	cout << "-------------------------------" << endl;
}

template<typename T> void Methods<T>::setAllShowChat() {							// метод чтения общих сообщений
	string from;
	string to;
	cout << "-----------ОБЩИЙ ЧАТ-----------\n";
	for (size_t i = 0; i < messageList.size(); ++i) {
		if (UserSpisok[userLogin].getName() == messageList[i].getFromMessage() || UserSpisok[userLogin].getName() == messageList[i].getToMessage() || messageList[i].getToMessage() == "all") {//если текущий пользователь
			from = (UserSpisok[userLogin].getName() == messageList[i].getFromMessage()) ? "Меня" : messageList[i].getFromMessage();
			if (messageList[i].getToMessage() == "all") 						//сообщение всем пользователям
				cout << "от " << from << ": " << messageList[i].getText() << endl;
		}
	}
	cout << "-----------------------------" << endl;
}

template<typename T> void Methods<T>::setAddMessage() {							//метод добавления сообщения в массив
	string inputName;
	string message;
	cout << "Введите имя кому отправить сообщение:\n";
	PrintNamesUsers();									  //выводим список пользователей
	cout << "all - отправить всем\n";

	cin >> inputName;
	if (inputName == "all") {							  //отправка всем пользователям
		cout << "Введите текст сообщения: \n";
		
		getline(cin, message, '\n');
		getline(cin, message, '\n');
		messageList.push_back(Message(UserSpisok[userLogin].getName(), "all", message));
		cout << "Сообщение разослано всем пользователям!\n";	
	}
	else {													//отправка личных сообщений
		int t = -1;
		t = FindUserinUserSpisok(inputName);
		if (t == -1) {
			cout << "Пользователь с данным именем не найден\n";
		}
		else {
			cout << "Введите текст сообщения: \n";			
			getline(cin, message, '\n');
			getline(cin, message, '\n');
			messageList.push_back(Message(UserSpisok[userLogin].getName(), inputName, message));
		}
	}
}

template<typename T> int Methods<T>::sizeUserSpisok() {					//количество зарегистрированных пользователей
	int size = UserSpisok.size();
	return size;
}

template<typename T>
void Methods<T>::currrenNull(){
	currentUser = nullptr;
}

//template<typename T>
//void Methods<T>::PrintMess()
//{
//	for (int i = 0; i < messageList.size(); ++i) {
//		cout << "вектор:";
//		cout << messageList[i].getFromMessage() << " ";
//		cout << messageList[i].getToMessage() << " ";
//		cout << messageList[i].getText() << endl;
//	}
//}
//
//template<typename T>
//void Methods<T>::clear()
//{
//	UserSpisok.clear();
//	messageList.clear();
//	vector<User>().swap(UserSpisok);
//	vector<Message>().swap(messageList);
//}


