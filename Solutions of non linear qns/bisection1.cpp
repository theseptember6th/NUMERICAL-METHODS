#include <iostream>
#include <cmath>
using namespace std;

float function_(float x)
{
    return (x * log10(x) - 1.9);
}

bool check(float *x0, float *x1)
{
    if ((function_(*x0) * function_(*x1)) > 0)
    {
        cout << "Invalid Interval.. Please try again!";
        return true; // so that loop executes again
    }
    else
    {
        cout << "Root lies betn the interval " << *x0 << " " << *x1;
        if(function_(*x1)<0){// if the higher boundary x1 is in negative region ..swapping
               float temp=*x1;
               *x1=*x0;
               *x0=*x1;
        }
        return false; // loop breaks
    }
}

int loop_calculation(float x0, float x1, float error)
{
    return ((int)((log(abs(x1 - x0)) - log10(error)) / log10(2)));
}

void bisection(float x, float y, float error, int MAX_ITERATION)
{
    float z;
    int count=0;
    do
    { 
        
        z = (x + y) / 2;
        if (function_(z) > 0)
        { // positive region
            y = z;
        }
        else if (function_(z) < 0)
        { // negative region
            x = z;
        }
        else{
                cout << "the required root is " << z<<"\n";
                exit(0);
            }

         count++;
         if(count==(2*MAX_ITERATION)){
            cout<<"could not find the roots ,,function may be discontinous\n";
            cout<<"TERMINATING THE PROGRAM.......\n";
            exit(0);
         }   
    } while (abs(function_(z)) > error);

    cout<<"\n the required root is " <<z;
}


int main()
{
    float a, b, tolerance;
    cout << "\nYour function is (x*log10(x)-1.9)\n";
    // asking and checking interval again and again till we get the correct interval
    do
    {
        cout << "enter your interval (a,b) :\n";
        cin >> a >> b;
    } while (check(&a, &b));

    cout << "\nenter the tolerance : \n";
    cin >> tolerance;

    int n=loop_calculation(a,b,tolerance);  

    bisection(a,b,tolerance,n);


    return 0;
}