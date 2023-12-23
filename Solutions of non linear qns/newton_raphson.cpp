#include <iostream>
#include <cmath>
using namespace std;

float function_(float x)
{
    //return (x * log10(x) - 1.9);  // xlogx-1.9
    return (pow(x,3)-x-11);    //x3-x-11
}

float derivative_(float x)
{
    //return (log10(x) + 1 / log10(2.7182)); // logx+1/loge
    return(3*pow(x,2)-1);  //3x2-1
}

void Newton_Raphson(float x, float error)
{
    int count;
    do
    {
        if (abs(derivative_(x) < error))
        {
            cout << "derivative of function is zero\n";
            cout << "EXITING......";
            exit(0);
        }
        else
        {
            x = x - (function_(x) / derivative_(x));
        }
        count++;
        if (count >= 50)
        {
            cout << "Iterated for 50 times,solution cant be found\n";
            cout << "function might be discontinous\n";
            cout << "EXITING\n";
            exit(0);
        }
    } while (abs(function_(x)) > error);

    cout << "\nthe required answer is " << x;
}

int main()
{
    cout << "you have the function xlogx-1.9\n";
    float a, error;
    cout << "enter the starting point: ";
    cin >> a;
    cout << "\n enter the tolerable error ";
    cin >> error;
    Newton_Raphson(a, error);
    return 0;
}