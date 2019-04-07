#include <iostream> //O(log(n) omega(1)

using namespace std;
int binarySearch(int arr[], int left, int right, int target){
    if(right < left){
        return -1;
    }
    int mid = (right + left)/2;
    if(arr[mid] == target){
        return mid;
    }
    else if(arr[mid] > target){
        return binarySearch(arr, 0, mid - 1, target);
    }
    else{
        return binarySearch(arr, mid+1, right, target);
    }
}
int main(){
    int arr[] = {1,2,3,4,5};
    int x = 55;
    int size= sizeof(arr)/sizeof(arr[0]);
    cout << binarySearch(arr, 0, size - 1, x);
}