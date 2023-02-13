#include <iostream>
using namespace std;

struct Node
{
    Node *prev = nullptr;
    Node *next = nullptr;
    int val;

    Node(int val) {
        this->val = val;
        this->prev = nullptr;
        this->next = nullptr;
    }
};

class DLL
{
    Node *head = nullptr;
    Node *end = nullptr;

public:
    ~DLL() {
        if(!head) return;

        while(head->next) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void list() {
        Node* temp = head;
        cout << temp->val << " ";
        temp = temp->next;
        
        while(temp) {
            cout << temp->val << " ";
            temp = temp->next;
        }
    }

    void push(int value) {
        Node *node = new Node(value);
        node->val = value;

        if(!head) {
            head = node;
            end = node;
            return;
        }

        end->next = node;
        node->prev = end;
        end = node;
    }  
};

int main() {
    DLL dll;
    dll.push(3);
    dll.push(4);
    dll.push(5);
    dll.list();

}
