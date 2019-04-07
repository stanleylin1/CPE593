#include <iostream>
using namespace std;
int powermod(int x, int n, int m)
{
    int prod = 1;
    while (n > 0)
    {
        if (n % 2 == 1)
        {
            prod = (prod * x) % m;
        }
        x = (x * x) % m;
        n = n / 2;
    }
    return prod;
}
int random(int a, int b)
{
    return a + rand() % (b - a + 1);
}
bool millerRabin(int p, int k)
{
    for (int i = 0; i < k; i++)
    {
        int a = random(2, p - 2);
        int d = p - 1;
        int s = 0;
        while (d % 2 == 0)
        {
            s++;
            d = d / 2;
        }
        int x = powermod(a, d, p);
        if (x == 1 || x == p - 1)
        {
            continue;
        }
        for (int j = 0; j < s - 1; j++)
        {
            x = x * x % p;
        }
        if (x == 1)
            return false;
        if (x == p - 1)
        {
            goto nextTry;
        }
        return false;
    nextTry:;
    }
    return true;
}
int main()
{
    cout << millerRabin(17, 3) << endl;
}