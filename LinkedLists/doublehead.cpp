#include <iostream>
using namespace std;

class LinkedList3{
    private: 
    class Node{
        public:
        int val;
        Node* next;
        Node* prev;
    };
    Node* head;
    public:
    LinkedList3(){
        head = nullptr;
    }
    ~LinkedList3(){
        while(head != nullptr){
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
    void print(){
        Node* currptr = head;
        while(currptr != nullptr){
            cout << currptr->val << " ";
            currptr=currptr->next;
        }
        cout << "\n";
    }
    void addStart(int v){
        Node* temp = new Node();
        temp->val = v;
        temp->next = head;
        temp->prev = nullptr;
        if(head != nullptr){
            head->prev = temp;
        }
        head = temp;
    
    }
    int removeStart(){
        int val = head->val;
        Node* temp = head;
        head = head->next;
        head->prev = nullptr;
        delete temp;
        cout << val << " was removed from the start." << endl;
        return val;
    }
    void addEnd(int v){
        Node* temp = new Node();
        temp->val = v;
        temp->next = nullptr;
        temp->prev = nullptr;
        Node* currptr = head;
        while(currptr->next != nullptr){
            currptr = currptr->next;
        }
        currptr->next = temp;
        temp->prev = currptr;
    }
    int removeEnd(){
        int val;
        Node* currptr = head;
        while(currptr->next->next != nullptr){
            currptr = currptr->next;
        }
        val = currptr->next->val;
        Node* temp = currptr->next;
        currptr->next = nullptr;
        delete temp;
        cout <<  val << " was removed from the end." << endl;
        return val;
    }
    void print2(){
        Node* currptr = head;

        while(currptr->next != nullptr){
            currptr= currptr->next;
        }
        while(currptr != nullptr){
            cout << currptr->val << " ";
            currptr = currptr->prev;
        }
        cout << "\n";
    }
    void insert(int v, int pos){
        Node* temp = new Node();
        temp->val = v;
        temp->next = nullptr;
        temp->prev = nullptr;
        Node* currptr = head;
        for(int i = 1; i < pos; i++){
            currptr = currptr->next;
        }
        Node* temp2 = currptr->next;
        currptr->next = temp;
        temp->prev = currptr;
        temp->next = temp2;
        temp2->prev = temp;
        cout<< v << " was inserted at position: " << pos << endl;
    }
    void removeAt(int pos){
        Node* currptr = head;
        for(int i = 1; i < pos;i++){
            currptr = currptr->next;
        }
        Node* temp = currptr->next;
        currptr->next->next->prev = currptr;
        currptr->next = currptr->next->next;
        cout << temp->val << " was removed at position: " << pos << endl;
        delete temp;
    }
};
int main(){
    LinkedList3 a;
    for(int i = 1; i < 11;i++){
        a.addStart(i);
    }
    a.addEnd(22);
    a.removeEnd();
    a.removeStart();
    a.print2();
    a.print();
    a.insert(99,1);
    a.print();
    a.print2();
    a.removeAt(1);//9 8 7 6 5 4 3 2 1
    a.print();
    a.print2(); //1 2 3 4 5 6 7 8 9
    /*
    for(int i = 1; i < 11; i++){
        a.addStart(i);
    }
    a.print();
    a.removeStart();
    a.print();
    a.addEnd(25);
    a.addStart(3);
    a.print();
    a.removeEnd();
    a.print();
    a.print2();
    */
}