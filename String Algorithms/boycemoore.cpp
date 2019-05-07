#include <iostream>
using namespace std;

int boyceMoore(string search, string target)
{
    int table[256];
    int n = search.length();
    int k = target.length();
    for (int i = 0; i < 256; i++)
    { //create a table and set all values to the size of the target
        table[i] = k;
    }
    for (int i = 0; i < k; i++)
    { //for each letter subtract distance till end of target
        table[target[i]] = k - 1 - i;
    }
    int i = 0, j = 0;
    while (i + k <= n)
    {
        j = k - 1;
        while (search[i + j] == target[j])
        { //if found compare the strings
            j -= 1;
            if (j < 0)
            {
                return i;
            }
        }
        i = i + table[search[i + k - 1]];
    }
    return -1;
}
int main()
{
    string search = "dajsshellomaskld";
    string target = "hello";
    cout << "Found at index: " << boyceMoore(search, target);
}