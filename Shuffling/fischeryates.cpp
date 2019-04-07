#include<iostream> //O(n)
#include<random>
#include<ctime>
#include <vector>
#define SIZE 1000
using namespace std;

void fischerYates(int arr[], int arraySize){
    for(int i = arraySize - 1; i > 0; i--){
        int random = rand()% (i + 1);
        swap(arr[i],arr[random]);
    }
    cout << endl;
    cout << "Shuffled Array: ";
    for(int i = 0; i < arraySize; i++){
        cout << arr[i] << " ";
    }
}
int main(){
    srand(time(NULL));
    cout << "How big is your array?" << endl;
    int arraySize;
    cin >> arraySize;
    int arr[SIZE];
    for(int i = 0; i < arraySize;i++){
        cout << "Enter number " << i+1 << ":" << " ";
        cin >> arr[i];
    }
    cout << "Unshuffled Array: ";
    for(int i = 0; i < arraySize;i++){
        cout << arr[i] << " ";
    }
    fischerYates(arr, arraySize);
}

/* Predfined Array
#include <iostream>
#include <random>
#include <ctime>

using namespace std;


void fisherYatesShuffle(int a[], int n) {
	for (int i = n-1; i > 0; i--) {
		int random = rand() % (i + 1);
		swap(a[i], a[random]);
	}
}

int main() {
	srand(time(NULL));
    int a[] = {1, 2, 3, 4, 5};
	fisherYatesShuffle(a, 5);
    for(int i = 0; i < 5; i++){
        cout << a[i] << " ";
    } cout << endl;
    
}*/