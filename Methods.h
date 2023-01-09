#pragma once
#include "User.h"
#include "Message.h"
#include <vector>
#include <exception>

class Methods {
	vector<User>UserSpisok;				//������ ������������������ �������������
	vector<Message> messageList;		//������� ������, ������� ������ ��������� � ����

public:
	bool FindLogin(string login);						//����� �������� ������
	void NewUser();										//����� �������� ������ ������������
	bool UserSearch(string login, string password);     //����� ������ ������������ �� ������ � ������
	void PrintNamesUsers();							    //����� ��������� ������ ������������������ �������������
	int FindUserinUserSpisok(string name);				//����� ��������� ��������� �� ������� ���
	bool IsEmpty();										//����� �������� ������� ���������
	void setShowChat();									//����� ������ ���������
	void setAddMessage();								//����� ���������� ��������� � ������
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