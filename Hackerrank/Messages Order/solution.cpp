#include <iostream>
#include <algorithm>
#include <vector>

//Editable code---------------------------------------------------------------------------------------------------------------------------
using namespace std;

class Message {
    //private data members Text, id, current_id
    string Text;
    static int id;
    int current_id;
public: 
    Message() { // Default Constructor
        Text="";
        current_id=++id;
    }
    Message(string text){ // Parameterised Constructor
        Text=text;
        current_id=++id;
    }
    const string& get_text() {
        return Text;
    }
    bool operator < (const Message& M2) { // Operator Overloading of <
        if(current_id < M2.current_id)
            return true;
        else
            return false;
    }
};
int Message::id=0; //Initialise static variable

class MessageFactory {
public:
    MessageFactory() {}
    Message create_message(const string& text) {
        return Message(text);// retur object of type Message
    }
};
//---------------------------------------------------------------------------------------------------------------------------
class Recipient {
public:
    Recipient() {}
    void receive(const Message& msg) {
        messages_.push_back(msg);
    }
    void print_messages() {
        fix_order();
        for (auto& msg : messages_) {
            cout << msg.get_text() << endl;
        }
        messages_.clear();
    }
private:
    void fix_order() {
        sort(messages_.begin(), messages_.end());
    }
    vector<Message> messages_;
};

class Network {
public:
    static void send_messages(vector<Message> messages, Recipient& recipient) {
    // simulates the unpredictable network, where sent messages might arrive in unspecified order
        random_shuffle(messages.begin(), messages.end());         
        for (auto msg : messages) {
            recipient.receive(msg);
        }
    }
};



int main() {
    MessageFactory message_factory;
    Recipient recipient;
    vector<Message> messages;
    string text;
    while (getline(cin, text)) {
        messages.push_back(message_factory.create_message(text));
    }
    Network::send_messages(messages, recipient);
    recipient.print_messages();
}
