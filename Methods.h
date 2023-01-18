#pragma once
#include "User.h"
#include "Message.h"
#include <vector>
#include <exception>
#include <memory>

template <typename T> class Methods {
	vector<User> UserSpisok;				//������ ������������������ �������������
	vector<Message> messageList;			//������� ������, ������� ������ ��������� � ����
	shared_ptr<User> currentUser = nullptr; //��������� ��������� �� �������� ������������
	

public:
	

	int userLogin = 0;									// ��� ������� �������� ������
	shared_ptr<User>getCurrentUser()const;
shared_ptr<User>getUserByLogin(string& login);
//shared_ptr<User>getUserByName(string& name);

	bool FindName(T name);							//�������� �����
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
	
	void PrintMess();
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