#include <iostream>

using namespace std;

int main()
{
    //Addition O(n^2) O(rows*cols)
    int matrix1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int matrix2[] = {4, 5, 6, 7, 8, 9, 3, 2, 1};
    /*
    Matrix 1 Representation
    1 2 3 
    4 5 6
    7 8 9

    Matrix 2 Representation
    4 5 6 
    7 8 9
    3 2 1

    Both have 3 rows and 3 cols

    Matrix 3 Representation (Result Matrix)
    5 7 9
    11 13 15
    10 10 10

    To get a point (i,j)
    matrix[i*cols+j]
    */
    int rows = 3;
    int cols = 3;
    int matrix3[rows * cols]; //Same size as matrices being added... result matrix
    if (rows != cols)
    {
        return 0;
    }
    for (int i = 0; i < rows * cols; i++)
    {
        matrix3[i] = matrix1[i] + matrix2[i];
    }
    //To print the matrix
    int count = 0;
    for (int i = 0; i < rows * cols; i++)
    {
        count++;
        cout << matrix3[i] << " ";
        if (count == rows)
        {
            cout << '\n';
            count = 0;
        }
    }
    cout << endl;
    //Multiplication O(n^3) O(m*n*p)
    int m = 3; //Number of rows in matrix 1
    int n = 3; //Number of columns in matrix 2
    int p = 3; //Number of columns in matrix 1 and number of rows in matrix 2 MUST be the same
    /*
    Matrix 4 Representation
    1 2 3
    4 5 6 
    7 8 9

    Matrix 5 Representation
    9 8 7
    6 5 4
    3 2 1

    Matrix 6 Representation
    30 24 18
    74 69 54
    138 114 90
    */
    int matrix4[m][p] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int matrix5[p][n] = {{9, 8, 7}, {6, 5, 4}, {3, 2, 1}};
    int matrix6[m][p];

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < p; j++)
        {
            int dot = 0;
            for (int k = 0; k < n; k++)
            {
                dot = dot + (matrix4[i][k] * matrix5[k][j]);
            }
            matrix6[i][j] = dot;
        }
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < p; j++)
        {
            cout << matrix6[i][j] << " ";
        }
        cout << endl;
    }
    /*
    Upper and Lower Triangular Matrix 
    1 0 0 0
    2 3 0 0
    4 5 6 0
    7 8 9 10
    O(n^2)
    Lower
    get(i,j)
        if(j > i) if column is greater than row
            return 0;
        return matrix[(i*(i+1)/2)+j]
    end
    Upper
    1 2 3 4 
    0 5 6 7
    0 0 8 9
    0 0 0 10
    get(i,j)
        if(j < i) Row is greater than column, or column is less than row
            return 0;
        return matrix[(n * i) + j - (i * (i + 1) / 2)] //n is the size of the matrix if 3x3 n=3 4x4 n = 4 etc
    end

    Diagonal Matrix
    1 0 0
    0 2 0
    0 0 3
    O(n) multiplication
    get(i,j)
        if(i == j) 
            return matrix[i];
        return 0;
    end
    
    Tri Diagonal Matrix
    1 2 0
    3 4 5
    0 6 7
    O(n multiplication)
    get(i,j)
        if(abs(j-i) > 1) 
            return 0;
        return matrix[2*i+j]
    end

    O(n^2) to multiply a n*n matrix and a column vector 
    O(n^3) to check if its not ill configured
    Partial pivoting and full pivoting take O(n^2) time, O(n^3) + O(n^2) = O(n^2) so time complexity 
    is the same with or without

    Linear independency
    Overview
    -----------
    Addition O(m*n) O(n^2)
    Multiplication O(m*n*p) O(n^3)
    Diagonal O(n)
    Tridiagonal O(n)
    Upper/Lower Triangle O(n^2)
    Solving systems O(n^3), row reduction + back-substitution = O(n^3+n^2) = O(n^3) 
    Gaussian Elimination with partial pivoting O(n^3)
    Full pivoting O(n^3)
    LU Factorization O(n^3)
    Transpose/Inverse O(n^3)
    Diagonal Powers (D^k) O(nlog(k))
    Powers(A^k) O(n^3*log(k))
    Strassen O(n^2.81)
    Coppersmith-Winograd O(n^2.36)
    Gran Schmidt:
    Normalize first vector O(n)
    Subtract componenet in the first direction and normalize O(n)
    Subtract O(n^3)
    Normalize O(n^2)
    O(n^3) for the whole thing
    */
}