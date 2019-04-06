#include <iostream>
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

  public:
    Node root;
    Trie()
    {
        root = Node();
    }
    void insert(string word){
        Node* currptr = &root;
        for(int i = 0; i < word.length(); i++){
            if(currptr->next[word[i]- 'a'] == nullptr){
                currptr->next[word[i]-'a'] = new Node();
            }
            currptr=currptr->next[word[i]-'a'];
        }
        currptr->isWord = true;
    }
    bool containsWord(string word){
        Node* currptr = &root;
        for(int i = 0; i < word.length();i++){
            if(currptr->next[word[i]-'a'] == nullptr){
                return false;
            }
            currptr=currptr->next[word[i]-'a'];
        }
        return currptr->isWord;
    }
    bool containsPrefix(string prefix){
        Node* currptr = &root;
        for(int i =0; i < prefix.length();i++){
            if(currptr->next[prefix[i]-'a'] == nullptr){
                return false;
            }
            currptr = currptr->next[prefix[i]-'a'];
        }
        return true;
    }
};

int main()
{
    Trie t;
    t.insert("cat");
    t.insert("dog");
    t.insert("mouse");
    cout << t.containsWord("cat") << endl; //True
    cout << t.containsWord("elephant") << endl; //False
    cout << t.containsPrefix("ca") << endl; //True
    cout << t.containsPrefix("el") << endl; //False
}
