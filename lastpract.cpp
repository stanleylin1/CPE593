/*
Analysis of algorithms: loops, recursion, dynamic programming (memoization)
Sorting: insertion, quicksort, heapsort, mergesort
Shuffling: Fischer Yates
Searching: linear, binary, golden mean.
Number theoretic algorithms: gcd, lcm, brute force trial division, Eratosthenes' powermod Fermat, Miller-Rabin
GrowArray
LinkedLists, Stacks, Queues
Binary tree -inorder, preorder, postorder traversal
Trie (insert, containsWord, containsPrefix)
*/
#include <iostream>
using namespace std;
void quickSort(int arr[], int L, int R)
{
}
void insertionSort(int arr[], int size) //O(N^2) omega(N)
{
    for (int i = 1; i < size; i++)
    {
        int temp = arr[i];
        int j = i - 1;
        while (j >= 0 && temp < arr[j])
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = temp;
    }
}
int main()
{
    int arr[] = {7, 1, 3, 5, 10, 9, 4, 2, 6, 8};
    int size = sizeof(arr) / sizeof(arr[0]);
    //insertionSort(arr, size);
    quickSort(arr, 0, size - 1);
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
}