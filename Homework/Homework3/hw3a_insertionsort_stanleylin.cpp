/*
	Author: Stanley Lin
	I pledge my honor that I have abided by the Stevens Honor System.
*/

#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

void insertionSort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {                      //loop through n times(number of elements in the array)
        int temp = arr[i]; //set temp equal to the second element in the array because the first one is already in position
        int j = i - 1;     //create a variable to compare to the left number
        while (arr[j] > temp && j >= 0)
        {                        //compare the temp to number to the left, if number to the left is larger move it one position in ahead
            arr[j + 1] = arr[j]; //inserts number one position ahead
            j = --j;             //decrement j by one so all values to the left are accounted for
        }
        arr[j + 1] = temp; //inserts the element into position
    }
}

int main()
{
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

        insertionSort(arr, n); //runs insortion sort function
        cout << "Sorted Numbers(Insertion Sort): ";
        for (int i = 0; i < n; i++)
        { //loop to display the sorted numbers in console.
            cout << arr[i] << " ";
        }
    }
    file.close(); //close file
    return 0;
}