//x^n mod m
#include <iostream> //O(log(n)) omega(1)
using namespace std;
int powermod(int x, int n, int m){
    int product = 1;
    while(n > 0){ //anything x^0 = 1 
        if(n % 2 == 1){
            product = (product * x) % m;
        }
        x = (x*x) % m;
        n = n/2;
    }
    return product;
}
int main(){
    cout << powermod(2, 5, 3) << endl; //2^5 =  32 , 32/3 = 10 r (2) <--
}