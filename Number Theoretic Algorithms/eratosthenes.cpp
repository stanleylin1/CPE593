#include <iostream>
#include <vector>
using namespace std;
//O(nlog(n)) omega(1)
void erat(int n){
vector<bool> isPrime(n + 1, 1);
isPrime[0,1] = false; // 0 and 1 are NOT prime
for(int i = 4; i <= n ;i+=2){
    isPrime[i] = false; //setting all even numbers after and including 4 NOT prime ... 4,6,,8 etc
    for(int i = 3; i <= n; i+=2){ //starts at 3,5,7 etc
        if(isPrime[i] == true){ //if its true take the square and make it false
            for(int j = i*i; j <= n; j+=2*i){
                isPrime[j] = false;
            }
        }
    }
}
for(int c = 2; c <= n; c++){
    if(isPrime[c] == true){
        cout << c << " ";
    }
}
}
int main(){
 erat(100); //2 3 5 7
}