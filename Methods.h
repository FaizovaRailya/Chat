#pragma once
#include "User.h"
#include "Message.h"
#include <vector>
#include <exception>

template <typename T> class Methods {
	vector<User> UserSpisok;				//������ ������������������ �������������
	vector<Message> messageList;		//������� ������, ������� ������ ��������� � ����
	
public:
	int userLogin = 0;									// ��� ������� �������� ������
	bool FindLogin(T login);							//�������� ������
	void NewUser();										//�������� ������ ������������
	bool UserSearch(T login, T password);				//����� ������������ �� ������ � ������
	void PrintNamesUsers();							    //��������� ������ ������������������ �������������
	int FindUserinUserSpisok(string name);				//�������� ��������� �� ������� ���
	bool IsEmpty();										//�������� ������� ���������
	void setPrivateShowChat();							//������ ������ ���������
	void setAllShowChat();								//������ ����� ���������
	void setAddMessage();								//���������� ��������� � ������
	int sizeUserSpisok();								//���������� ������������������ �������������
};

class LoginExp : public exception {			//���������� ���� ������ ����� "all"
public:
	const char* what() const noexcept override {
		return "ERROR: ����� �����!\n\n";
	}
};

class NameExp : public exception {			//���������� ���� ������� ��� "all"
public:
	const char* what()const noexcept override {
		return "ERROR: ��� ������������ ������!\n\n";
	}
};