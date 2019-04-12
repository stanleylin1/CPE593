#include <iostream>
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
        int count = 0;
        for (int i = 0; i < a.rows * a.cols; i++)
        {
            cout << c.m[i] << " ";
            count++;
            if (count == a.rows)
            {
                cout << endl;
                count = 0;
            }
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
        int count = 0;
        for (int i = 0; i < a.rows * a.cols; i++)
        {
            cout << c.m[i] << " ";
            count++;
            if (count == a.rows)
            {
                cout << endl;
                count = 0;
            }
        }
        return c;
    }
};
int main()
{
    Matrix m1(3, 3, 1.0);
    Matrix m2(3, 3, 2.0);
    Matrix m3 = m1 + m2;
    Matrix m4 = m1 * m2;
}