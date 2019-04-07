#include <iostream> //O(log(n))
#include <random>
#include <cmath>
using namespace std;

const double phi = (1 + sqrt(5)) / 2;
int goldenMeanSearch(int data[], int n)
{
	int L = 0;
	int R = n - 1;
	int S = (R - L) / phi;
	int x = R - S;
	int y = L + S;
	do
	{
		if (data[x] > data[y])
		{
			R = y;
			y = x;
			S = (R - L) / phi;
			x = R - S;
			data[x] = data[x + 1];
		}
		else
		{
			L = x;
			x = y;
			S = (R - L) / phi;
			y = L + S;
			data[y] = data[y + 1];
		}
	} while (L < R);
	return data[L];
}
int main()
{
	const int n = 20;
	//int data[n] = {1, 5, 16, 17, 18, 92, 15, 15, 12, 3, 2, 2, 2, 2, 2, 2, 1, 1, 1, 1, 0}; //15
	//int data[n] = {-6, -2, 1, 5, 10, 15, 16, 18, 15, 12, 11, 9, 6, 2, 1, 1, 1, -2, -3, -9}; //15
	int data2[n] = {1, 1, 5, 6, 11, 92, 93, 94, 50, 49, 38, 36, 12, 1, 0, 0, -1, -5, -6, -6}; //50
																							  //int data3[10] = {1,1,5,6,11,92,93,94,50,49};
	cout << goldenMeanSearch(data2, n) << '\n';
	// cout << goldenMeanSearch(data2, n) << endl;
	// cout << goldenMeanSearch(data3, 10);
}

/*
int goldenMeanSearch(int data[], int n) {
	int L = 0, R = n-1;
	int S = (R-L) / phi ;
	int x = R - S, y = L + S;
	do {
        cout << x << " " << y << endl;
        cout << data[x] << " " << data[y] << endl;
		if (data[x] > data[y]) {
			R = y;
			y = x;
			S = (R-L) / phi;
			x = (R - S);
            data[x] = data[x+1];
		} else {
			L = x;
			x = y;
			S = (R-L) / phi;
			y = (L + S);
            data[y] = data[y+1];
		}
	} while (L < R);
	return data[L];
}
*/
/*
#include <iostream>
#include <random>
#include <cmath>
#include <iomanip>
using namespace std;
typedef double (*FuncOneVar)(double);
double f(double x) { return 8 - x * x; }

const double PHI = (1 + sqrt(5)) /2;

double goldenMean(FuncOneVar f, double L, double R, double eps) {
	double s = (R-L) / PHI;
	double x1 = R - s;
	double x2 = L + s;
	double y1 = f(x1);
	double y2 = f(x2);
	while (  abs(R - L) > eps ) {
	if (y1 > y2) {
		R = x2;
		x2 = x1;
		y2 = y1;
		s = (R - L)/ PHI;
		x1 = R - s;
	} else if (y2 <= y1) {
		L = x1;
		x1 = x2;
		y1 = y2;
		s = (R - L) / PHI;
		x2 = L + s;
	}	
    if(y1 > y2){
        return x1;
    }
    else{
        return x2;
    }

}
    return 1;
}

int main() {
	cout << goldenMean(f, -1, 5, .0001);
}
*/