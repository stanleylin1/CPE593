#include <iostream>
using namespace std;

class LinkedList
{
  private:
    class Node
    {
      public:
        int val;
        Node *next;
    };
    Node *head;

  public:
    LinkedList() : head(nullptr) {}
    ~LinkedList()
    {
        while (head != nullptr)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
        }
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
    void addStart(int v)
    {

        Node *temp = new Node();
        temp->val = v;
        temp->next = head;
        head = temp;
    }
    void addEnd(int v)
    {
        Node *temp = new Node();
        temp->val = v;
        temp->next = nullptr;
        Node *currptr = head;
        if (head == nullptr)
        {
            head = temp;
            return;
        }
        while (currptr->next != nullptr)
        {
            currptr = currptr->next;
        }
        currptr->next = temp;
    }
    int removeStart()
    {
        int valRemoved;
        valRemoved = head->val;
        Node *temp = head;
        head = head->next;
        delete temp;
        cout << valRemoved << " was removed from the list." << endl;
        return valRemoved;
    }
    int removeEnd()
    { //at least two elements to have an end or else start and end will be the same
        int valRemoved;
        Node *currptr = head;
        if (currptr->next == nullptr)
        { //In case it only has one element in the list, you can also just run removeStart()
            Node *temp = head;
            valRemoved = head->val;
            head = head->next;
            delete temp;
            cout << valRemoved << " was removed from the list." << endl;
            return valRemoved;
            //return removeStart();
        }
        while (currptr->next->next != nullptr)
        {
            currptr = currptr->next;
        }
        Node *temp = currptr->next;
        valRemoved = temp->val;
        currptr->next = nullptr;
        delete temp;
        cout << valRemoved << " was removed from the list." << endl;
        return valRemoved;
    }
    void printHead()
    {
        cout << head->val << endl;
    }
    void insert(int v, int pos)
    {
        Node *temp = new Node();
        temp->val = v;
        temp->next = nullptr;
        Node *currptr = head;
        for (int i = 1; i < pos; i++)
        {
            currptr = currptr->next;
        }
        Node *temp2 = currptr->next;
        currptr->next = temp;
        temp->next = temp2;
    }
    void removeAt(int pos)
    {
        Node *currptr = head;
        if (pos == 0)
        {
            removeStart();
            return;
        }
        for (int i = 1; i < pos; i++)
        {
            currptr = currptr->next;
        }
        Node *temp = currptr->next;
        currptr->next = currptr->next->next;
        delete temp;
    }
    void remove(int v)
    {
        Node *currptr = head;
        while (currptr->next->val != v)
        {
            currptr = currptr->next;
        }
        Node *temp = currptr->next;
        currptr->next = currptr->next->next;
        cout << v << " was removed." << endl;
        delete temp;
    }
    void getStart()
    {
        cout << "Value of head: " << head->val << endl;
    }
    void getEnd()
    {
        Node *currptr = head;
        while (currptr->next != nullptr)
        {
            currptr = currptr->next;
        }
        cout << "Value of last element: " << currptr->val << endl;
    }
    void getPos(int v)
    {
        Node *currptr = head;
        int count = 0;
        while (currptr->val != v)
        {
            currptr = currptr->next;
            count++;
        }
        cout << v << " is at position " << count << endl;
    }
    int size()
    {
        int count = 1;
        Node *currptr = head;
        while (currptr->next != nullptr)
        {
            currptr = currptr->next;
            count++;
        }
        return count;
    }
};

int main()
{

    LinkedList a;
    for (int i = 1; i < 11; i++)
    {
        a.addEnd(i);
    }
    a.insert(30, 1); //1 30 2 3 4 5 6 7 8 9 10
    a.removeAt(1);   //1 2 3 4 5 6 7 8 9 10
    a.removeAt(0);   //2 3 4 5 6 7 8 9 10
    a.removeAt(8);   //2 3 4 5 6 7 8 9
    a.remove(7);     //2 3 4 5 6 8 9
    a.print();
    a.getStart();                                                               //2
    a.getEnd();                                                                 //9
    a.getPos(5);                                                                //3
    cout << "Current linkedlist contains: " << a.size() << " elements" << endl; //7
    /*
    for(int i = 1; i < 11;i++){
        a.addEnd(i);
    }
   a.addStart(50);
a.print();
a.removeStart();
a.print();
a.removeEnd();
a.print();
*/
}