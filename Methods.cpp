#include <iostream>
#include "Methods.h"
#include "User.h"

using namespace std;

int userLogin = 0;
bool Methods::FindLogin(string login) {						//����� �������� ������
	bool j = false;
	for (int i = 0; i < UserSpisok.size(); i++) {
		if (UserSpisok[i].getLogin() == login) {
			j = true;
			return j;
			break;
		}
	}return j;
}

void Methods::NewUser() {									//����� �������� ������ ������������
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


bool Methods::UserSearch(string login, string password) {	//����� ������ ������������ �� ������ � ������	
	int i = 0;
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

void Methods::PrintNamesUsers() {							//����� ��������� ������ ������������������ �������������
	for (int i = 0; i < UserSpisok.size(); ++i) {
		cout << UserSpisok[i].getName() << endl;
	}
}

int Methods::FindUserinUserSpisok(string name) {			//����� ��������� ��������� �� ������� ���
	for (int i = 0; i < UserSpisok.size(); ++i) {
		if (UserSpisok[i].getName() == name) {
			return i;
		}
	}return -1;
}

bool Methods::IsEmpty() {									//����� �������� ������� ���������
	bool i = true;
	if (messageList.size() > 0) { i = false; }	return i;
}

void Methods::setShowChat() {								//����� ������ ���������
	if (IsEmpty()) {
		cout << "� ��� ��� ��� �������� ���������!\n" << endl;
	}
	else {
		string from;
		string to;
		cout << "--------���--------\n";
		for (int i = 0; i < messageList.size(); ++i) {
			if (UserSpisok[userLogin].getName() == messageList[i].getFromMessage() || UserSpisok[userLogin].getName() == messageList[i].getToMessage() || messageList[i].getToMessage() == "all") {//���� ������� ������������
				from = (UserSpisok[userLogin].getName() == messageList[i].getFromMessage()) ? "����" : messageList[i].getFromMessage();
				if (messageList[i].getToMessage() == "all") {			//��������� ���� �������������
					to = "����";
				}
				else {
					to = (UserSpisok[userLogin].getName() == messageList[i].getToMessage()) ? "���" : messageList[i].getToMessage();
					//���� ������� ��� ����� to, �� ���������� ��������� ������ ����, ���� ���, �� �������� ��� ������������ � ����������� ��� �������� ���� to
				}
				cout << "��������� �� " << from << " ���� " << to << ": " << messageList[i].getText() << endl;
			}
		}
		cout << "-------------------" << endl;
	}
}

void Methods::setAddMessage(){								  //����� ���������� ��������� � ������

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



