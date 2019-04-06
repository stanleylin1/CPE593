#include <iostream>
#include <vector>
using namespace std;
#define size 1000
void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[size];
    int R[size];
    for (i = 0; i < n1; i++)
    {
        L[i] = arr[l + i];
    }
    for (j = 0; j < n2; j++)
    {
        R[j] = arr[m + j + 1];
    }
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}
void mergesort(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = (l + r) / 2;
        mergesort(arr, l, m);
        mergesort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

int main()
{
    int arr[] = {55, 22, 34, 99, 17};
    int size1 = sizeof(arr) / sizeof(arr[0]);
    mergesort(arr, 0, size1 - 1);
    for (int i = 0; i < size1; i++)
    {
        cout << arr[i] << " ";
    }
}

/*
void merge(int arr[], int l, int m, int r){
    int i,j,k;
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[10000];
    int R[10000];
    for(i = 0; i < n1;i++){
        L[i] = arr[l+i];
    }
    for(j = 0; j<n2;j++){
        R[j] = arr[m+1+j];
    }
    i = 0;
    j = 0;
    k = l;
    while( i < n1 && j < n2){
        if(L[i] <= R[j]){
            arr[k] = L[i];
            i++;
        }
        else{
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while(i < n1){
        arr[k] = L[i];
        i++;
        k++;
    }
    while(j < n2){
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergesort(int arr[], int l, int r){
    if(l < r){
        int m = (l+r)/2;
        mergesort(arr, l, m);
        mergesort(arr, m+1, r);
        merge(arr, l,m,r);
    }
}
*/