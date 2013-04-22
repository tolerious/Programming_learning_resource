#include "Folder.h"
#include <iostream>
using std::cerr; using std::endl;
using std::set; using std::string; using std::vector;

Message::Message(const Message &m): 
    contents(m.contents), folders(m.folders) 
{
    // add this Message to each Folder that points to m
    put_Msg_in_Folders(folders);  
}


Message& Message::operator=(const Message &rhs)
{
    if (&rhs != this) {
        remove_Msg_from_Folders(); // update existing Folders
        contents = rhs.contents;   // copy contents from rhs
        folders = rhs.folders;     // copy Folder pointers from rhs
        // add this Message to each Folder in rhs 
        put_Msg_in_Folders(rhs.folders); 
    }
    return *this;
}

Message::~Message()
{
    remove_Msg_from_Folders();
}

// add this Message to Folders that point to rhs
void Message::put_Msg_in_Folders(const set<Folder*> &rhs)
{
    for(std::set<Folder*>::const_iterator beg = rhs.begin(); 
                                     beg != rhs.end(); ++beg)
        (*beg)->addMsg(this);  // *beg points to a Folder
}

// remove this Message from corresponding Folders 
void Message::remove_Msg_from_Folders()
{
    // remove this message from corresponding folders
    for(std::set<Folder*>::const_iterator beg =
          folders.begin(); beg != folders.end(); ++beg)
        (*beg)->remMsg(this);  // *beg points to a Folder
}

void Folder::copy_msgs(const set<Message*> &m)
{
    for (Msg_iter beg = m.begin(); beg != m.end(); ++beg)
        (*beg)->save(*this);   // add this Folder to each Message
}

Folder::Folder(const Folder &f)
{
    copy_msgs(f.msgs);  // add this Folder to each Message in f.msgs
}

Folder& Folder::operator=(const Folder &f)
{
    if (&f != this) {
        empty_msgs();  // remove this folder from each Message in msgs
        copy_msgs(f.msgs); // add this folder to each Message in msgs
    }
    return *this;
}

Folder::~Folder()
{
    empty_msgs();
}


void Folder::empty_msgs()
{
    Msg_iter it = msgs.begin(); 
    while (it != msgs.end()) {
        Msg_iter next = it;
        ++next;                // remember next element in msgs
        (*it)->remove(*this);
        it = next;
    }
}

void Message::save(Folder &f)
{
    // add f to Folders and this Message to f's list of Messages
    folders.insert(&f);  
    f.addMsg(this);
}

void Message::remove(Folder &f)
{
    // remove f from Folders and this Message from f's list of Messages
    folders.erase(&f);
    f.remMsg(this);
}

void Folder::save(Message &m)
{
    // add m and add this folder to m's set of Folders
    msgs.insert(&m);
    m.addFldr(this);
}

void Folder::remove(Message &m)
{
    // erase m from msgs and remove this folder from m
    msgs.erase(&m);
    m.remFldr(this);
}

vector<Folder*> Message::get_folders()
{
    return vector<Folder*>(folders.begin(), folders.end());
}

vector<Message*> Folder::messages()
{
    return vector<Message*>(msgs.begin(), msgs.end());
}

void Folder::debug_print()
{
    cerr << "Folder contains " << msgs.size() << " messages" << endl;
    int ctr = 1;
    for (Msg_iter beg = msgs.begin(); beg != msgs.end(); ++beg)
        cerr << "Message " << ctr++ << ":\n\t" 
             << (*beg)->print_message() << endl;
}

void Message::debug_print()
{
    cerr << "Message:\n\t" << contents << endl;
    cerr << "Appears in " << folders.size() << " Folders" << endl;
}
