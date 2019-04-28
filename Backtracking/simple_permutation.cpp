#include <iostream>
using namespace std;

class Permute{
    private:
    int* data;
    int n;
    int count;
    void swap(int& a, int &b){
        int temp = a;
        a = b;
        b = temp;
    }
    public:
    Permute(int* data, int n): data(data), n(n){
        count = 0;
        generate(n-1);
    }
    void generate(int N){ //O(2N!)
        if(N == 0){
            doit();
            return;
        }
        for(int c = 0; c<= N;c++){
            swap(data[c],data[N]);
            generate(N-1);
            swap(data[c], data[N]);
        }
    }
    void doit() {
        count++;
        for(int i = 0; i < n; i++){
            cout << data[i] << " ";
        }
        cout << endl;
    }
    int numPerm(){
        return count; //n!
    }
};

int main(){
    int x[]={1,2,3};
    Permute p(x,3);
    cout << p.numPerm() << endl;
}