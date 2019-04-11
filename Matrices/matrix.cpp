#include <iostream>

using namespace std;

int main()
{
    //addition O(n^2) O(rows*cols)
    int rows = 3;
    int cols = 3;
    int matrix1[rows][cols] = {{1, 2, 3},
                               {4, 5, 6},
                               {7, 8, 9}};
    int matrix2[rows][cols] = {{11, 12, 13},
                               {14, 15, 16},
                               {17, 18, 19}};
    int matrix3[rows][cols];
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            matrix3[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << matrix3[i][j] << " ";
        }
        cout << endl;
    }
    //multiplication O(n^3) O(m*n*p)
    int m = 5; //rows of the first table
    int n = 4; // rows of the second table cols of first
    int p = 3; //columns of the second table
    int a[m][n] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}, {17, 18, 19, 20}};
    int b[n][p] = {{20, 21, 22},
                   {23, 24, 25},
                   {26, 27, 28},
                   {29, 30, 31}};
    int c[m][p];
    cout << endl;
    for (int k = 0; k < m; k++)
    {
        for (int j = 0; j < p; j++)
        {
            int dot = 0;
            for (int i = 0; i < n; i++)
            {
                dot = dot + (a[k][i] * b[i][j]);
                //cout << a[k][i] * b[i][j] << " ";
            }
            c[k][j] = dot;
        }
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < p; j++)
        {
            cout << c[i][j] << " ";
        }
        cout << endl;
    }
    /*
    Upper/Lower triangle is still O(n^3) 1/8 * n^3 = n^3
    Diagonal matrix is O(n) multiplication
    Tri-Diagonal matrix is O(n) multiplication 3n = n
    */
}