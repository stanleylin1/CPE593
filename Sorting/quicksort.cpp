#include <iostream>
using namespace std;//omega(n log(n)) O(n^2)

void quicksort(int arr[], int L, int R){
    if(L >= R){ 
        return;
    }
    int pivot = (arr[L]+arr[R]) / 2;
    int i = L;
    int j = R;
    while(i < j){
        while(arr[i] < pivot){
            i++;
        }
        while(arr[j] > pivot){
            j--;
        }
        if(i < j){
            swap(arr[i], arr[j]);
        }
        quicksort(arr, L, j);
        quicksort(arr, j+1, R);
    }

}

int main(){
    int arr[5] = {4,3,5,2,1}; //Sort this array to 1 2 3 4 5
    int n = sizeof(arr)/sizeof(arr[0]);
    quicksort(arr, 0, n - 1);
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    return 1;
}





















/*
void quicksort(int arr[], int L, int R) { 
if(L >= R){

    return;
}
  int pivot = (arr[L] + arr[R]) / 2;
  cout << "Pivot: " << pivot << endl;
  int i = L;
  int j = R;
  while(i < j){
      while(arr[i] < pivot){
          i++;
      }
      while(arr[j] > pivot){
          j--;
      }
      if(i < j){
          swap(arr[i], arr[j]);
      }
      quicksort(arr, L, j);
      quicksort(arr, j+1, R);
  }
}
*/