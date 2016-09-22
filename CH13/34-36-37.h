#include <string>
#include <set>

using namespace std;

class Folder;
class Message
{
	friend void swap(Message&, Message&);
	friend class Folder;

public:
	// folders is implicitly initialized to the empty set
	explicit Message(const string &str = ""): contents(str) {}
	// copy control to manage pointers to this Message
	Message(const Message &m);
	Message& operator=(const Message &rhs);
	~Message();
	// add/remove this Message from the specified Folder's set of messages
	void save(Folder &f);
	void remove(Folder &f);

private:
	string contents; // actual message text
	set<Folder*> folders; // Folders that have this Message
	// utility functions used by copy constructor, assignment, and destructor
	// add this Message to the Folders that point to the parameter
	void add_to_Folders(const Message &m);
	// remove this Message from every Folder in folders
	void remove_from_Folders();
	void addFldr(Folder *f)
	{
		folders.insert(f);
	}
	void remFldr(Folder *f)
	{
		folders.erase(f);
	}
};

void swap(Message &lhs, Message &rhs);

class Folder
{
	friend void swap(Folder&, Folder&);
	friend class Message;

public:
	Folder() = default;
	Folder(const Folder &f);
	Folder& operator=(const Folder &);
	~Folder();

private:
	std::set<Message*> msgs;
	void add_to_Message(const Folder &f);
	void remove_from_Message();
	void addMsg(Message *m)
	{
		msgs.insert(m);
	}
	void remMsg(Message *m)
	{
		msgs.erase(m);
	}
};

void swap(Folder &lhs, Folder &rhs);
