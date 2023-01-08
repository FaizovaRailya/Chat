#include "Message.h"
#include <string>
#include<iostream>
using namespace std;

Message::Message(const string& fromMessage, const string& toMessage, const string& text) : fromMessage_(fromMessage), toMessage_(toMessage), text_(text) {}

string& Message::getText() {return text_;}
string& Message::getFromMessage() {return fromMessage_;}
string& Message::getToMessage() {return toMessage_;}

