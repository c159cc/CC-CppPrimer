#include "../common/cc.h"

class Folder;
class Message
{
    friend class Folder;
    friend void swap(Message &, Message &);

public:
    explicit Message(const string &str = "") : contents(str) {}
    Message(const Message &m);
    Message &operator=(const Message &m);
    ~Message();
    void save(Folder &f);
    void remove(Folder &f);
    void print_debug();
    Message(Message &&m);
    Message &operator=(Message &&m);
    void move_folders(Message *m);

private:
    string contents;
    set<Folder *> folders;
    void add_to_Folders(const Message &m);
    void remove_from_Folders();

    void addFldr(Folder *f) { folders.insert(f); }
    void remFldr(Folder *f) { folders.erase(f); }
};
void swap(Message &, Message &);

class Folder
{
    friend void swap(Folder &, Folder &);
    friend class Message;

public:
    Folder() = default;
    Folder(const Folder &f);
    Folder &operator=(const Folder &f);
    ~Folder();
    void print_debug();

private:
    set<Message *> messages;
    void add_to_Message(const Folder &f);
    void remove_from_Message();

    void addMsg(Message *msg) { messages.insert(msg); }
    void remMsg(Message *msg) { messages.erase(msg); }
};
void swap(Folder &, Folder &);
 