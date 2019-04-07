#include <iostream>

using namespace std;

class LinkedList2
{
  private:
    class Node
    {
      public:
        int val;
        Node *next;
    };
    Node *head;
    Node *tail;

  public:
    LinkedList2()
    {
        head = nullptr;
        tail = nullptr;
    }
    ~LinkedList2()
    {
        while (head != nullptr)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
        }
    }
    void addStart(int v)
    {
        Node *temp = new Node();
        temp->val = v;
        temp->next = head;
        head = temp;
        if (tail == nullptr)
        {
            tail = head;
            return;
        }
    }
    int removeStart()
    {
        int removedVal = head->val;
        if (head->next == nullptr)
        {
            head = tail = nullptr;
            cout << removedVal << " was removed from the start." << endl;
            return removedVal;
        }
        Node *temp = head;
        head = head->next;
        delete temp;
        cout << removedVal << " was removed from the start." << endl;
        return removedVal;
    }
    void print()
    {
        Node *currptr = head;
        while (currptr != nullptr)
        {
            cout << currptr->val << " ";
            currptr = currptr->next;
        }
        cout << "\n";
    }
    void addEnd(int v)
    {
        Node *temp = new Node();
        temp->val = v;
        temp->next = nullptr;
        if (head == nullptr)
        {
            head = tail = temp;
            return;
        }
        else
        {
            tail->next = temp;
            tail = temp;
        }
    }
    int removeEnd()
    {
        int removedVal;
        Node *currptr = head;
        if (head->next == nullptr)
        { //can call removeStart()
            removedVal = head->val;
            head = tail = nullptr;
            cout << removedVal << " was removed from the end." << endl;
            return removedVal;
        }
        while (currptr->next->next != nullptr)
        {
            currptr = currptr->next;
        }
        removedVal = currptr->next->val;
        Node *temp = currptr->next;
        currptr->next = nullptr;
        tail = currptr;
        delete temp;
        cout << removedVal << " was removed from the end." << endl;
        return removedVal;
    }
    void printTail()
    {
        cout << "Tail value is: " << tail->val << endl;
    }
};
int main()
{
    LinkedList2 a;
    a.addEnd(1);
    a.addEnd(2);
    a.addEnd(3);
    a.print();
    a.printTail();
    a.removeEnd();
    a.print();
    a.printTail();
    delete &a; //delete
    /*
    for(int i = 1; i < 11; i++){
        a.addStart(i);
    }
    a.print();
    a.removeStart();
    a.print();
    a.printTail();
    a.addEnd(789);
    a.print();
    a.printTail();
    */
}