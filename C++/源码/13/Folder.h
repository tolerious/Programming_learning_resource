/*
 * This file contains code from "C++ Primer, Fourth Edition", by Stanley B.
 * Lippman, Jose Lajoie, and Barbara E. Moo, and is covered under the
 * copyright and warranty notices given in that book:
 * 
 * "Copyright (c) 2005 by Objectwrite, Inc., Jose Lajoie, and Barbara E. Moo."
 * 
 * 
 * "The authors and publisher have taken care in the preparation of this book,
 * but make no expressed or implied warranty of any kind and assume no
 * responsibility for errors or omissions. No liability is assumed for
 * incidental or consequential damages in connection with or arising out of the
 * use of the information or programs contained herein."
 * 
 * Permission is granted for this code to be used for educational purposes in
 * association with the book, given proper citation if and when posted or
 * reproduced.Any commercial use of this code requires the explicit written
 * permission of the publisher, Addison-Wesley Professional, a division of
 * Pearson Education, Inc. Send your request for permission, stating clearly
 * what code you would like to use, and in what specific way, to the following
 * address: 
 * 
 * 	Pearson Education, Inc.
 * 	Rights and Contracts Department
 * 	75 Arlington Street, Suite 300
 * 	Boston, MA 02216
 * 	Fax: (617) 848-7047
*/ 

#include <string>
#include <set>
#include <vector>

class Folder;

class Message {
    friend class Folder;
public:
    // folders is initialized to the empty set automatically
    Message(const std::string &str = ""): 
                  contents (str) { }  
    // copy control: we must manage pointers to this Message
    // from the Folders pointed to by folders
    Message(const Message&);
    Message& operator=(const Message&); 
    ~Message();  

    // add/remove this Message from specified Folder's set of messages
    void save(Folder&);   
    void remove(Folder&); 

    std::vector<Folder*> get_folders(); // return list of folders 
                               // in which this message resides
    std::string print_message() { return contents; }
    void debug_print(); // print contents and it's list of Folders, 
                        // printing each Folder as well
private:
    std::string contents;      // actual message text
    std::set<Folder*> folders; // Folders that have this Message

    // Utility functions used by copy constructor, assignment, and destructor:
    // Add this Message to the Folders that point to the parameter
    void put_Msg_in_Folders(const std::set<Folder*>&); 
    // remove this Message from every Folder in folders
    void remove_Msg_from_Folders(); 

    // used by Folder class to add self to this Message's set of Folder's
    void addFldr(Folder *f) { folders.insert(f); }
    void remFldr(Folder *f) { folders.erase(f); }
};

class Folder {
    friend class Message;
public:
    ~Folder(); // remove self from Messages in msgs
    Folder(const Folder&); // add new folder to each Message| in msgs
    Folder& operator=(const Folder&); // delete Folder from lhs messages
                                      // add Folder to rhs messages
    Folder() { } // defaults ok

    void save(Message&); // add this message to folder
    void remove(Message&); // remove this message from this folder
    
    // don't reveal implementation because it's likely to change
    // also better to copy than ref to the internal data structure so
    // have a copy to operate on not the actual contents is safer
    std::vector<Message*> messages(); // return list of messages in this folder
    void debug_print(); // print contents and it's list of Folders, 
private:
    typedef std::set<Message*>::const_iterator Msg_iter;
    std::set<Message*> msgs;  // messages in this folder

    void copy_msgs(const std::set<Message*>&);// add this Folder to each Message
    void empty_msgs();           // remove this Folder from each Message
    void addMsg(Message *m) { msgs.insert(m); }
    void remMsg(Message *m) { msgs.erase(m); }
};
