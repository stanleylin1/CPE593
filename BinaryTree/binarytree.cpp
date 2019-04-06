#include <iostream>
using namespace std;

class BinaryTree{
    private:
    class Node{
        public:
        Node* left;
        Node* right;
        Node* parent;
        int val;

        void inorder(){ // L ROOT R
        if(left != nullptr){
            left->inorder();
        }
        cout << val <<  " ";
        if(right != nullptr){
            right->inorder();
        }
        }
        void preorder(){ //ROOT L R
        cout << val <<  " ";
        if(left != nullptr){
            left->preorder();
        }
        if(right != nullptr){
            right->preorder();
        }
        }
        void postorder(){ // L R ROOT
        if(left != nullptr){
            left->postorder();
        }
        if(right != nullptr){
            right->postorder();
        }
        cout << val <<  " ";
        }
    };
    Node* root;
    public:
    BinaryTree() : root(nullptr) {}
    void add(int v){
        if(root == nullptr){
            root = new Node();
            root->val = v;
            root->left = nullptr;
            root->right = nullptr;
            root->parent = nullptr;
            return;
        }
        Node *p = root;
        while(true){
            if(v < p->val){
                if(p->left == nullptr){
                    p->left = new Node();
                    p->left->val = v;
                    p->left->left = nullptr;
                    p->left->right = nullptr;
                    p->left->parent = p;
                    return;
                }
                p = p->left;
            }
            else{
                if(p->right == nullptr){
                    p->right = new Node();
                    p->right->val = v;
                    p->right->left = nullptr;
                    p->right->right  = nullptr;
                    p->right->parent = p;
                    return;
                }
                p = p->right;
            }
        }
    }
    void inorder(){
        if(root != nullptr){
            root->inorder();
        }
    }
    void preorder(){
        if(root != nullptr){
            root->preorder();
        }
    }
    void postorder(){
        if(root != nullptr){
            root->postorder();
        }
    }
};

int main(){
BinaryTree a;
a.add(5);
a.add(4);
a.add(6);
a.inorder();
}