#include <iostream> //O(log(n)) omega(1)
using namespace std;
int gcd(int a, int b){
    if(b == 0){
        return a;
    }
    else
    {
        return gcd(b, a % b);
    }
    
}
int main(){
    cout << gcd(36, 6) << endl; //6
    cout << gcd(366,60) << endl; //6
    cout << gcd(255,12) << endl; //3
}