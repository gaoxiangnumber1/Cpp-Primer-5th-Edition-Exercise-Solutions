#include <iostream>
#include "msgfldr.h"

Message::Message(const Message &m): contents(m.contents), folders(m.folders)
{
	add_to_Folders(m); // add this Message to the Folders that point to m
}
Message& Message::operator=(const Message &rhs) // copy assignment
{
	// handle self-assignment by removing pointers before inserting them
	remove_from_Folders(); // update existing Folders
	contents = rhs.contents; // copy message contents from rhs
	folders = rhs.folders; // copy Folder pointers from rhs
	add_to_Folders(rhs); // add this Message to those Folders
	return *this;
}
Message::~Message() // destructor
{
	remove_from_Folders();
}
// add/remove this Message from the specified Folder's set of messages
void Message::save(Folder &f)
{
	folders.insert(&f); // add the given Folder to our list of Folders
	f.addMsg(this); // add this Message to f's set of Messages
}
void Message::remove(Folder &f)
{
	folders.erase(&f); // take the given Folder out of our list of Folders
	f.remMsg(this); // remove this Message to f's set of Messages
}

void Message::add_to_Folders(const Message &m)
{
	// for each Folder that holds m
	for(set<Folder*>::iterator f = m.folders.begin(); f != m.folders.end(); ++f)
	{
		(*f)->addMsg(this); // add a pointer to this Message to that Folder
	}
}
// remove this Message from every Folder in folders
void Message::remove_from_Folders()
{
	// for each Folder that holds m
	for(set<Folder*>::iterator f = folders.begin(); f != folders.end(); ++f)
	{
		(*f)->remMsg(this); // remove this Message from that Folder
	}
}

void swap(Message &lhs, Message &rhs)
{
	// remove pointers to each Message from their(original) respective Folders
	lhs.remove_from_Folders();
	rhs.remove_from_Folders();
	// swap the contents and Folder pointer sets
	swap(lhs.contents, rhs.contents); // swap(string&, string&)
	swap(lhs.folders, rhs.folders); // swap(set&, set&)
	// add pointers to each Message to their(new) respective Folders
	lhs.add_to_Folders(lhs);
	rhs.add_to_Folders(rhs);
}

Folder::Folder(const Folder &f): msgs(f.msgs)
{
	add_to_Message(f);
}
Folder& Folder::operator=(const Folder &rhs)
{
	remove_from_Message();
	msgs = rhs.msgs;
	add_to_Message(rhs);
	return *this;
}
Folder::~Folder()
{
	remove_from_Message();
}
void Folder::add_to_Message(const Folder &f)
{
	for(set<Message*>::iterator m = f.msgs.begin(); m != f.msgs.end(); ++m)
	{
		(*m)->addFldr(this);
	}
}
void Folder::remove_from_Message()
{
	for(set<Message*>::iterator m = msgs.begin(); m != msgs.end(); ++m)
	{
		(*m)->remFldr(this);
	}
}

void swap(Folder &lhs, Folder &rhs)
{
	lhs.remove_from_Message();
	rhs.remove_from_Message();
	swap(lhs.msgs, rhs.msgs);
	lhs.add_to_Message(lhs);
	rhs.add_to_Message(rhs);
}

int main()
{
	Message msg("gaoxiangnumber1");
	Folder fldr;

	return 0;
}
