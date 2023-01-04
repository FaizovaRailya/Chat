#include "Message.h"

Message::Message(const string& fromMessage, const string& toMessage, const string& text):text_(text), fromMessage_(fromMessage), toMessage_(toMessage){}

string& Message::getText()
{
	return text_;
}

string& Message::getFromMessage()
{
	return fromMessage_;
}

string& Message::getToMessaget()
{
	return toMessage_;
}
