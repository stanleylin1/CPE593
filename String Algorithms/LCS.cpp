#include <iostream>
#include <cstring>
using namespace std;

int lcs(char *X, char *Y)
{
    if (*X == '\0' || *Y == '\0')
    {
        return 0;
    }
    if (*X == *Y)
    {
        return 1 + lcs(X + 1, Y + 1);
    }
    else
    {
        return max(lcs(X + 1, Y), lcs(X, Y + 1));
    }
    return -1;
}

int lcs2(char *X, char *Y, int m, int n)
{
    if (m == 0 || n == 0)
    {
        return 0;
    }
    if (X[m - 1] == Y[n - 1])
    {
        return 1 + lcs2(X, Y, m - 1, n - 1);
    }
    else
    {
        return max(lcs2(X, Y, m - 1, n), lcs2(X, Y, m, n - 1));
    }
    return -1;
}
int main()
{
    char X[] = "ABCDEFGH";
    char Y[] = "ACEFH";

    int m = strlen(X);
    int n = strlen(Y);

    cout << "Method 1: " << lcs(X, Y) << endl;
    cout << "Method 2: " << lcs2(X, Y, m, n) << endl;

    return 0;
}