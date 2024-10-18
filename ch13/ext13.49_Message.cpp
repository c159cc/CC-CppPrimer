#include "../common/cc.h"
#include "ext13.49_Message.h"

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

void Message::move_folders(Message *m)
{
    folders = std::move(m->folders);
    for (auto f : m->folders)
    {
        f->remMsg(m);
        f->addMsg(this);
    }

    // 接管右侧资源之后释放右侧资源 
    m->folders.clear();
}

Message::Message(const Message &m) : contents(m.contents), folders(m.folders)
{
    add_to_Folders(m);
}

Message::Message(Message &&m) : contents(std::move(m.contents)){
    move_folders(&m);
}
Message &Message::operator=(Message &&m)
{
    if (this != &m)
    {
        // 清空自己的资源
        remove_from_Folders();
        contents = std::move(m.contents);
        move_folders(&m);
    }

    return *this;
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
Message &Message::operator=(Message &&m)
{
    if (this != &m)
    {
        remove_from_Folders();
        contents = std::move(m.contents);
        folders = std::move(m.folders);
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
