#include <iostream> //O(n) omega(1);

using namespace std;
int linearSearch2(int arr[],int size,int x){
    for(int i = 0; i < size;i++){
        if(arr[i] == x){
            return i;
        }
    }
    return -1;
}
int main(){
    
    int x = 5;
    int arr[] = {1,2,3,4,5};
    int size = sizeof(arr)/sizeof(arr[0]);
    cout << linearSearch2(arr, size, x);
}