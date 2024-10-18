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

void Message::save(Folder &f)
{
    addFldr(&f);
    f.addMsg(this);
}

void Message::remove(Folder &f)
{
    remFldr(&f);
    f.remMsg(this);
}

void Message::add_to_Folders(const Message &m)
{
    for (auto f : m.folders)
    {
        f->addMsg(this);
    }
}

void Message::remove_from_Folders()
{
    for (auto f : folders)
    {
        f->remMsg(this);
    }
}

Message::Message(const Message &m) : contents(m.contents), folders(m.folders)
{
    add_to_Folders(m);
}

Message::~Message()
{
    remove_from_Folders();
}

Message &Message::operator=(const Message &m)
{
    if (this != &m)
    {
        remove_from_Folders();
        contents = m.contents;
        folders = m.folders;
        add_to_Folders(m);
    }
    return *this;
}

void swap(Message &m1, Message &m2)
{
    using std::swap;
    m1.remove_from_Folders(); // 从所有的folder中移除自己
    m2.remove_from_Folders();

    swap(m1.contents, m2.contents);
    swap(m1.folders, m2.folders);

    // 此时m1的folder来自m2都不包含自己
    m1.add_to_Folders(m1);
    m2.add_to_Folders(m2);
}

void Message::print_debug()
{
    cout << "Message: " << contents << endl;
}

// Folder Implement
void Folder::print_debug()
{
    for (auto m : messages)
        std::cout << m->contents << " ";
    std::cout << std::endl;
}
void Folder::add_to_Message(const Folder &f)
{
    for (auto msg : f.messages)
    {
        msg->addFldr(this);
    }
}

void Folder::remove_from_Message()
{
    for (auto msg : messages)
    {
        msg->remFldr(this);
    }
}

Folder::Folder(const Folder &f) : messages(f.messages)
{
    add_to_Message(f);
}

Folder &Folder::operator=(const Folder &f)
{
    if (this != &f)
    {
        // 释放左边
        remove_from_Message();
        messages = f.messages;
        add_to_Message(f);
    }
    return *this;
}
Folder::~Folder()
{
    remove_from_Message();
}

void swap(Folder &f1, Folder &f2)
{
    using std::swap;
    f1.remove_from_Message(); // 从所有的message中移除自己
    f2.remove_from_Message();

    swap(f1.messages, f2.messages);

    // 此时f1的message来自f2都不包含自己
    f1.add_to_Message(f1);
    f2.add_to_Message(f2);
}
