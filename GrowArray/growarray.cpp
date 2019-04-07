#include<iostream>
using namespace std;

class GrowArray
{
  private:
    int len;
    int capacity;
    int *data;
    void grow()
    {
        int *old = data;
        data = new int[capacity * 2 + 1];
        for (int i = 0; i < len; i++)
        {
            data[i] = old[i];
        }
        capacity = capacity * 2 + 1;
        delete old;
    }

  public:
    GrowArray()
    {
        len = 0;
        capacity = 0;
        data = nullptr;
    }
    void addStart(int v)
    {
        if (len >= capacity)
        {
            grow();
        }
        int *old = data;
        data = new int[len + 1];
        data[0] = v;
        for (int i = 0; i <= len; i++)
        {
            data[i + 1] = old[i];
        }
        len++;
        delete old;
    }
    void addEnd(int v)
    {
        if (len >= capacity)
        {
            grow();
        }
        int *old = data;
        data = new int[len + 1];

        for (int i = 0; i < len; i++)
        {
            data[i] = old[i];
        }
        data[len] = v;
        len++;
        delete old;
    }
    void removeStart()
    {
        int *old = data;
        data = new int[--len];
        for (int i = 0; i < len; i++)
        {
            data[i] = old[i + 1];
        }
        delete old;
    }
    void removeEnd()
    {
        int *old = data;
        data = new int[--len];
        for (int i = 0; i < len; i++)
        {
            data[i] = old[i];
        }
        delete old;
    }
    void print()
    {
        for (int i = 0; i < len; i++)
        {
            cout << data[i] << " ";
        }
        cout << endl;
    }
};

int main(){
    GrowArray g;
    for(int i = 0; i < 10; i++){
        g.addEnd(i);
    }
    g.addEnd(100);
    g.removeStart();
    g.removeEnd();
    g.print(); //1 2 3 4 5 6 7 8 9
}