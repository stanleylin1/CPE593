#include <iostream>

using namespace std;

int powermod(int x, int n, int m){
    int prod = 1;
    while(n > 0){
        if(n % 2 == 1){
            prod = (prod * x) % m;
        }
        x = (x*x) % m;
        n = n/2;
    }
    return prod;
}
int random(int a, int b) {
	return a + rand() % (b-a+1);
}
bool fermat(int p, int k){ //O(klog(n)) omega(1)
    if(p <= 1){
        return false;
    }
    if(p <= 3 && p > 1){
        return true;
    }
    for(int i = 0; i < k; i++){
        int a = random(2, p - 1);
        if(powermod(a, p - 1, p) != 1){ //if it is not odd
            return false;
        }
    }
    return true; //prob
}
int main(){
    cout << fermat(3, 3) << endl;
    cout << fermat(1,3) << endl;
}