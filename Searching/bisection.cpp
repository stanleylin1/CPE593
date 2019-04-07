#include <iostream>//O(n) omega(1) 

using namespace std;
double f(double x){
    return x*x*x - x*x + 2;
}

double bisection(double (*f)(double x), double a, double b, double eps){
    double ya = f(a);
    double yb = f(b);
    if(ya* yb > 0){
        throw "Error";
    }
    double mid;
    do{
        mid = (a + b) / 2;
        double y = f(mid);
        if(y > 0){
            b = mid;
        }
        else if(y < 0){
            a  = mid;
        }
        else
        return mid;
    }while(b - a > eps);
    return mid;
}
int main(){
    cout << bisection(f, -200, 300, 0.01);//-1.0025
}





























/*
double f1(double x){
    return x*x*x - x*x + 2;
}
typedef double(*FuncOneVar)(double x);

double bisection(FuncOneVar f, double a, double b, double eps){
    double ya = f(a);
    double yb = f(b);
    if(ya * yb > 0){
        throw "Error";
    }
    double mid;
    do{
        mid = (a+b) / 2;
        double y = f(mid);
        if(y > 0){
            b = mid;
        }
        else if(y < 0){
            a = mid;
        }
        else 
        return mid;
    }while(b - a > eps);
    return mid;
}*/