#include <iostream> //O(n) omega(1)
#include<cmath>
using namespace std;

bool isPrime(int n){
    for(int i = 2; i < n;i++){ //can do i <= sqrt(n) to make it O(sqrt(n)) 
        if(n % i == 0){ //if it is even first pass
            return false;
        }
    }
    return true;
}

int countPrimes(int n){ //O(n^2) or O(n*log(n)) depending on which isPrime is used
    int count = 0;
    for(int i = 2; i <= n; i++){
        if(isPrime(i) == true){
            count++;
        }
    }
    return count;
}
int main(){
    cout << isPrime(7) << endl; //1
    cout << isPrime(100) << endl; //0
    cout << countPrimes(2) << endl;
}