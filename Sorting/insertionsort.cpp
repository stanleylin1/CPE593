#include <iostream>
using namespace std; //O(n^2) omega(n)

void insertionsort(int arr[], int n){
    for(int i = 1; i < n;i++){
        int temp = arr[i];
        int j = i - 1; //starts out at 0
        while(j >= 0 && arr[j] > temp){
            arr[j+1] = arr[j];
            j = j - 1;
        }
        arr[j+1] = temp;
    }
}
int main(){
    int arr[5] = {12,11,13,5,6}; //Sort this array to 1 2 3 4 5
    int n = sizeof(arr)/sizeof(arr[0]);
    insertionsort(arr, n);
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    return 1;
}






















/*
void insertionsort(int arr[], int n) { //O(n^2) omega(n)
for(int i = 1; i < n; i++){ 
int temp = arr[i];
int j = i - 1; //0 at first run
while(j >= 0 && arr[j] > temp){
    arr[j+1] = arr[j];
    j = j - 1;
}
arr[j + 1] = temp;
}
}
*/