/*
	Author: Stanley Lin
	I pledge my honor that I have abided by the Stevens Honor System.
*/
#include <iostream>
#include <string>
#include <cctype>
#include <fstream>
using namespace std;
class Trie
{
  private:
    class Node
    {
      public:
        Node *next[26];
        bool isWord;
        Node()
        {
            for (int i = 0; i < 26; i++)
            {
                next[i] = nullptr;
            }
            isWord = false;
        }
    };
    Node root;

  public:
    Trie()
    {
        root = Node();
    }
    void insert(string word)
    {
        Node *p = &root;
        for (int i = 0; i < word.size(); i++)
        {
            /*
            if(isupper(word[i])){
                cout << "Word contains upper case letter, " << '"' << word << '"' << " was removed." << endl;
                return;
            }
            */
            if (isupper(word[i]))
            {
                word[i] = tolower(word[i]); //If words have capital letters they are made lowercase
            }
            if (word.find("'") != std::string::npos)
            {
                cout << word << " contained an apostrophe so it was removed." << endl; //If words have an apostrophe it is removed
                return;
            }
            if (p->next[word[i] - 'a'] == nullptr)
            {
                p->next[word[i] - 'a'] = new Node();
            }
            p = p->next[word[i] - 'a'];
        }

        p->isWord = true;
    }
    bool contains(string word)
    {
        Node *p = &root;
        for (int i = 0; i < word.size(); i++)
        {
            if (p->next[word[i] - 'a'] == nullptr)
            {
                return false;
            }
            p = p->next[word[i] - 'a'];
        }
        return p->isWord;
    }
    bool containsPrefix(string word)
    {
        Node *p = &root;
        for (int i = 0; i < word.size(); i++)
        {
            if (p->next[word[i] - 'a'] == nullptr)
            {
                return false;
            }
            p = p->next[word[i] - 'a'];
        }
        return true;
    }
};

int main()
{
    Trie a;
    ifstream file;
    string line;
    file.open("dict.txt");
    if (!file)
    {
        cout << "Unable to open dictionary" << endl;
        exit(1);
    }
    while (getline(file, line))
    {
        a.insert(line);
    }
    file.close();
    ifstream file2;
    string line2;
    file2.open("hw5.txt");
    if (!file2)
    {
        cout << "Unable to open file with words to check" << endl;
        exit(1);
    }
    while (getline(file2, line2))
    {
        //Contains
        if (a.contains(line2) == 1)
        {
            cout << line2 << " - True" << endl;
        }
        else
        {
            cout << line2 << " - False" << endl;
        }
        /*Prefix
    if(a.containsPrefix(line2) == 1){
    cout << line2 << " - True" << endl;
    }
    else{
        cout << line2 << " - False" << endl;
    }
    */
    }
}