/*
	Author: Stanley Lin
	I pledge my honor that I have abided by the Stevens Honor System.
*/

#include <iostream>
#include <fstream>
#include <random>
#include <time.h>

using namespace std;

void quickSort(int arr[], int left, int right)
{
    int random = left + rand() % (right - left); //generates a random number between the left and right
    int pivot = arr[random];                     //sets pivot to random number in the array
    int i = left;
    int j = right;
    if (left >= right) //if left is greater or equal to right end program (met in the middle)
    {
        return;
    }
    while (i <= j) //while loop to go through list of numbers
    {
        while (arr[i] < pivot) //if number in array is less than the pivot  increment i checks through the left side
        {
            i++;
        }
        while (arr[j] > pivot) //if number in array is greater than the pivot decrement j checks through the right side
        {
            j--;
        }
        if (i <= j) //when i is less than or equal to j swap and then increment i and decrement j to put them in order
        {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }
    if (left < j) //if the left is less than j the left still needs to be sorted
    {
        quickSort(arr, left, j);
    }
    if (i < right) // if i is less than the right the right still needs to be sorted
    {
        quickSort(arr, i, right);
    }
}

int main()
{
    srand(time(NULL));       //seed to generate random number
    string numberOfElements; //string for number of elements
    string numbersToSort;    //string for numbers that are going to be sorted
    ifstream file;           //read from file
    file.open("hw3.dat");    //opens file called hw3.dat
    if (!file)
    { //if theres an error display cannot open file and exit
        cerr << "Cannot open file" << endl;
        exit(1);
    }
    else
    {
        getline(file, numberOfElements);             //get data from first line and input it into numberOfElements string
        int n = stoi(numberOfElements);              //convert string into integer
        cout << "Number of Elements: " << n << '\n'; //displays number of elements in console
        int arr[n] = {0};                            //creates an array based on the numbers of elements, filled with zeros for now
        int b = 0;
        while (!file.eof())
        { //until the end of file insert values into the array starting from 0
            file >> arr[b];
            ++b;
        }
        quickSort(arr, 0, n - 1); //runs quick sort function
        cout << "Sorted Numbers(Quick Sort): ";
        for (int i = 0; i < n; i++)
        { //loop to display the sorted numbers in console.
            cout << arr[i] << " ";
        }
    }
    file.close(); //close file
    return 0;
}
