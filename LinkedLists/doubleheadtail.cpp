#include <iostream>
using namespace std;

class LinkedList4{
    private: 
    class Node{
        public:
        int val;
        Node* next;
        Node* prev;
    };
    Node* head;
    Node* tail;
    public:
    LinkedList4(){
        head = nullptr;
        tail = nullptr;
    }
    ~LinkedList4(){
        while(head != nullptr){
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
    void addStart(int v){
        Node* temp = new Node();
        temp->val = v;
        temp->prev = nullptr;
        temp->next = head;
        if(head == nullptr){
            head = tail = temp;
            return;
        }
        head->prev = temp;
        head = temp;
    }
    void removeStart(){
        Node* temp = head;
        head = head->next;
        head->prev= nullptr;
        delete temp;
    }
    void addEnd(int v){
        Node* temp = new Node();
        temp->val = v;
        temp->next = nullptr;
        temp->prev = tail;
        tail->next = temp;
        tail->next->prev = tail;
        tail = temp;
    }
    void removeEnd(){
        /*
        Node *currptr = head;
        while(currptr->next->next != nullptr){
            currptr = currptr->next;
        }
        Node* temp = currptr->next;
        currptr->next = nullptr;
        tail = currptr;
        */
        Node* temp = tail;
        tail = tail->prev;
        tail->next = nullptr;
        cout << temp->val << " was removed from the end" << endl;
        delete temp;
    }
    void print(){
        Node* currptr = head;
        cout << "Printing in order: ";
        while(currptr != nullptr){
            cout << currptr->val <<  " ";
            currptr = currptr->next;
        }
        cout << "\n";
    }
    void print2(){
            Node* currptr = tail;
            cout << "Printing reverse order: ";
            while(currptr != nullptr){
                cout << currptr->val << " ";
                currptr = currptr->prev;
            }
            cout << "\n";
    }
};
int main(){
 LinkedList4 a;
 for(int i = 0; i < 10; i++){
     a.addStart(i);
 }
 a.removeStart();
 a.addEnd(999);
 a.removeEnd();
 a.print();
 a.print2();
}