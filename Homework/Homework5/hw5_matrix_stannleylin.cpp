/*
	Author: Stanley Lin
	I pledge my honor that I have abided by the Stevens Honor System.
    References: http://www.cs.upc.edu/~jordicf/Teaching/programming/pdf4/MATH03_Gaussian-4slides.pdf
                https://github.com/StevensDeptECE/CPE593/blob/master/Matrices/Matrix.cc
*/
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
class Matrix
{
  private:
    int rows;
    int cols;
    double val;
    double *m;
    Matrix(int rows, int cols) : rows(rows), cols(cols), m(new double[rows * cols])
    {
    }

  public:
    Matrix(int rows, int cols, int val) : rows(rows), cols(cols), val(val), m(new double[rows * cols])
    {
        for (int i = 0; i < rows * cols; i++)
        {
            m[i] = val;
        }
    }
    friend Matrix operator+(const Matrix &a, const Matrix &b)
    {
        if (a.rows != b.rows || a.cols != b.cols)
        {
            throw "Bad Size";
        }
        Matrix c(a.rows, a.cols);
        for (int i = 0; i < a.rows * a.cols; i++)
        {
            c.m[i] = a.m[i] + b.m[i];
        }
        return c;
    }
    friend Matrix operator*(const Matrix &a, const Matrix &b)
    {
        if (a.cols != b.rows)
        {
            throw "Bad Size";
        }
        Matrix c(a.rows, b.cols);
        for (int i = 0; i < a.rows; i++)
        {
            for (int j = 0; j < b.cols; j++)
            {
                double dot = 0;
                for (int k = 0; k < a.cols; k++)
                {
                    dot += a.m[i * a.cols + k] * b.m[k * b.cols + j];
                }
                c.m[i * a.cols + j] = dot;
            }
        }
        return c;
    }
    double operator()(int i, int j) const
    {
        return m[i * cols + j];
    }
    double &operator()(int i, int j)
    {
        return m[i * cols + j];
    }
    static Matrix read(istream &s)
    {
        int n;
        int v;
        s >> n;
        Matrix m(n, n);
        for (int i = 0; i < n * n; i++)
        {
            s >> m.m[i];
        }
        int count = 0;
        cout << "Original Matrix: " << endl;
        for (int i = 0; i < n * n; i++) //To print the matrix
        {
            cout << m.m[i] << " ";
            count++;
            if (count == n)
            {
                cout << endl;
                count = 0;
            }
        }
        return m;
    }
    void partialPivot(int i, vector<double> &B)
    {
        int biggestPos = i;
        double biggest = (*this)(i, i);
        for (int j = i; j < rows; j++)
        {
            if ((*this)(j, i) > biggest)
            {
                biggest = (*this)(j, i);
                biggestPos = j;
            }
        }
        for (int k = 0; k < rows; k++)
        {
            swap(m[rows * biggestPos + k], m[k]);
        }
        swap(B[biggestPos], B[0]);
        /*
        cout << "\nMatrix After Pivot: " << endl;
        int count = 0;
        for (int i = 0; i < rows * cols; i++)
        {
            cout << m[i] << " ";
            count++;
            if (count == rows)
            {
                cout << endl;
                count = 0;
            }
        }
        */
    }
    int getRows(const Matrix &a)
    {
        return a.rows;
    }
    friend void backSubstitute(Matrix &m, vector<double> &x, vector<double> &B)
    {
        for (int i = m.rows - 1; i >= 0; --i)
        {
            double s = 0;
            for (int j = i + 1; j < m.rows; ++j)
            {
                s = s + m(i, j) * x[j];
            }
            x[i] = (B[i] - s) / m(i, i);
        }

        /*
        for (int n = m.rows; n > 0; n--)
        {
            x[n - 1] = B[n - 1] / m(n - 1, n - 1);
            cout << "x[" << n - 1 << "] =" << x[n - 1] << endl;
            for (int j = n - 2; j >= 0; j--)
            {
                cout << "B[J] = " << B[j] << endl;
                B[j] -= m(j, n) * x[n - 1];
            }
        }
        */
        /*
        cout << endl;
        cout << " Back Substitute Testing: " << endl;
        int count = 0;
        for (int i = 0; i < m.rows * m.cols; i++)
        {
            cout << m.m[i] << " ";
            count++;
            if (count == 3)
            {
                cout << endl;
                count = 0;
            }
        }
        */
    }
    friend vector<double> solve(Matrix &m, vector<double> &B)
    {
        vector<double> x;
        cout << "Solving for: " << endl;
        for (int i = 0; i < m.cols; i++)
        {
            cout << B[i] << endl;
        }
        x.reserve(m.rows);
        for (int i = 0; i < m.rows; i++)
        {
            m.partialPivot(0, B);
            for (int k = i + 1; k < m.rows; k++)
            {
                double s = -m(k, i) / m(i, i);
                int j = i;
                m(k, j) = 0;

                for (j = i + 1; j < m.cols; j++)
                {
                    m(k, j) += s * m(i, j);
                }
                B[k] += s * B[i];
            }
            backSubstitute(m, x, B);
        }

        cout << "\nSolution: " << endl;
        for (int i = 0; i < m.rows; i++)
        {
            cout << x[i] << "\n";
        }
        return x;
    }
};
vector<double> read(int n, istream &s)
{
    vector<double> B;
    B.reserve(n);
    double tmp;
    for (int i = 0; i < n; i++)
    {
        s >> tmp;
        B.push_back(tmp);
    }
    return B;
}

int main()
{
    /*
    Matrix a(3, 4, 0.0);
    Matrix b(4, 2, 1.0);
    Matrix c = b;
    Matrix d = a + a;
    Matrix e = a * b;
    b(1, 1);
    cout << b(1, 2) << endl;
    e = b;
    */
    ifstream f("hw5.dat");
    Matrix A = Matrix::read(f);
    vector<double> B = read(A.getRows(A), f);
    vector<double> x = solve(A, B);
}