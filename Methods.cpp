#include <iostream>
#include "Methods.h"
using namespace std;

template<typename T>
bool Methods<T>::FindLogin(T login){								//����� �������� ������
	bool j = false;
	for (int i = 0; i < UserSpisok.size(); i++) {
		if (UserSpisok[i].getLogin() == login) {
			j = true;
			return j;
			break;
		}
	}return j;
}

template<typename T> void Methods<T>::NewUser() {					//����� �������� ������ ������������
	string name;
	string login;
	string password;
	cout << "------������� ������ ��� �����������------\n";
	cout << "���: ";
	cin >> name;
	if (name == "all") {			// ����������
		throw NameExp();
	}
	cout << "�����: ";
	bool l = true;
	while (l) {
		cin >> login;
		if (login == "all") {       // ����������
			throw LoginExp();
		}
		if (FindLogin(login)) {
			cout << "������ ����� ��� ����� �������� ������!\n\n";
			cout << "-------- ������� --------\n�����: ";
		}
		else {
			l = false;
		}
	}	
	cout << "������: ";
	cin >> password;

	User U(name, login, password);				//������� ������ ����� User
	UserSpisok.push_back(U);					// ��������� ������������ � ������
	cout << "������������ ���������������!\n\n";
}

template<typename T>
bool Methods<T>::UserSearch(T login, T password){					//����� ������ ������������ �� ������ � ������	
	int i = 0;
	//int userLogin = 0;
	bool flag = false;
	while (i < UserSpisok.size()) {
		string l = UserSpisok[i].getLogin();
		string p = UserSpisok[i].getPassword();
		if (login == l && password == p) {
			cout << endl << "------ ������������: " << UserSpisok[i].getName() << " ------\n";
			userLogin = i;
			flag = true;
			return flag;
			break;
		}
		else { ++i;}
	}
	if (flag == false) {
		cout << "\n�������� ����� ��� ������!!!\n";
	}
	return flag;
}

template<typename T> void Methods<T>::PrintNamesUsers() {				    //����� ��������� ������ ������������������ �������������
	for (int i = 0; i < UserSpisok.size(); ++i) {
		cout << UserSpisok[i].getName() << endl;
	}
}

template<typename T> int Methods<T>::FindUserinUserSpisok(string name) {	//����� ��������� ��������� �� ������� ���
	for (int i = 0; i < UserSpisok.size(); ++i) {
		if (UserSpisok[i].getName() == name) {
			return i;
		}
	}return -1;
}

template<typename T>
bool Methods<T>::IsEmpty() {												//����� �������� ������� ���������
	bool i = true;
	if (messageList.size() > 0) { i = false; }	return i;
}

template<typename T> void Methods<T>::setPrivateShowChat() {				//����� ������ ������ ���������
	string from;
	string to;
	cout << "------------���------------\n";
	for (int i = 0; i < messageList.size(); ++i) {
		if (UserSpisok[userLogin].getName() == messageList[i].getFromMessage() || UserSpisok[userLogin].getName() == messageList[i].getToMessage() || messageList[i].getToMessage() == "all") {//���� ������� ������������
			from = (UserSpisok[userLogin].getName() == messageList[i].getFromMessage()) ? "����" : messageList[i].getFromMessage();

			to = (UserSpisok[userLogin].getName() == messageList[i].getToMessage()) ? "���" : messageList[i].getToMessage();
			//���� ������� ��� ����� to, �� ���������� ��������� ������ ����, ���� ���, �� �������� ��� ������������ � ����������� ��� �������� ���� to
		}
		if (messageList[i].getToMessage() != "all")
			cout << "�� " << from << " ���� " << to << ": " << messageList[i].getText() << endl;

	}
	cout << "-------------------------" << endl;

}

template<typename T> void Methods<T>::setAllShowChat(){							// ����� ������ ����� ���������
	string from;
	string to;
	cout << "-----------����� ���-----------\n";
	for (int i = 0; i < messageList.size(); ++i) {
		if (UserSpisok[userLogin].getName() == messageList[i].getFromMessage() || UserSpisok[userLogin].getName() == messageList[i].getToMessage() || messageList[i].getToMessage() == "all") {//���� ������� ������������
			from = (UserSpisok[userLogin].getName() == messageList[i].getFromMessage()) ? "����" : messageList[i].getFromMessage();

			if (messageList[i].getToMessage() == "all") 			//��������� ���� �������������
				cout << "�� " << from << ": " << messageList[i].getText() << endl;
		}
	}
	cout << "-----------------------------" << endl;
}

template<typename T> void Methods<T>::setAddMessage(){							//����� ���������� ��������� � ������
	string inputName;
	string message;
	cout << "������� ��� ���� ��������� ���������:\n";
	PrintNamesUsers();									  //������� ������ �������������
	cout << "all - ��������� ����\n";

	cin >> inputName;
	if (inputName == "all") {							  //�������� ���� �������������
		cout << "������� ����� ���������: \n";
		cout << endl;
		getline(cin, message, '\n');
		getline(cin, message, '\n');
		messageList.push_back(Message(UserSpisok[userLogin].getName(), "all", message));
		cout << "��������� ��������� ���� �������������!\n";
	}
	else {
		int t = -1;
		t = FindUserinUserSpisok(inputName);
		if (t == -1) {
			cout << "������������ � ������ ������ �� ������\n";
		}
		else {
			cout << "������� ����� ���������: \n";
			cout << endl;
			getline(cin, message, '\n');
			getline(cin, message, '\n');
			messageList.push_back(Message(UserSpisok[userLogin].getName(), inputName, message));
		}
	}
}

template<typename T> int Methods<T>::sizeUserSpisok() {					//���������� ������������������ �������������
	int size = UserSpisok.size();
	return size;
}