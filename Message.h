#pragma once
#include <string>
using namespace std;

class Message {
	string text_;
	string fromMessage_;
	string toMessage_;
public:
	Message() = default;
	Message(const string& fromMessage, const string& toMessage, const string& text);
	~Message() = default;
	string& getText();
	string& getFromMessage();
	string& getToMessage();
};
