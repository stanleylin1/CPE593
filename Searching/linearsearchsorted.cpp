#include <iostream>
 //O(n) omega(1)
using namespace std;

int linearsearchsorted(int arr[], int size, int target){
    for(int i = 0; i < size;i++){
        if(arr[i] >= target){
            if(arr[i] > target){
                return -1;
            }
            return i;
        }
    }
    return -1;
}
int main(){
    int arr[] = {5,22,33,54,65};
    int size = sizeof(arr)/sizeof(arr[0]);
    int target = 33;
    cout << linearsearchsorted(arr, size, target);
}