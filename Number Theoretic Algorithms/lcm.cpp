#include <iostream> //O(log(n)) omega(1)
using namespace std;
int gcd(int a, int b){
    if(b == 0){
        return a;
    }
    else{
        return gcd(b, a % b);
    }
}
int lcm(int a, int b){
    return (a*b)/gcd(a,b);
}
int main(){
    cout << lcm(36,6) << endl; //36
}