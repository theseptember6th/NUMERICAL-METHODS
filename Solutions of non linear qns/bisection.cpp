#include <iostream>
#include <cmath>

using namespace std;

float function_(float x) {
    return (x * log10(x) - 1.9);
}

void bisection(float x, float y) {
    float z = (x + y) / 2; // Initial guess at the midpoint
    float tolerance = 0.000001;

    while (abs(function_(z)) > tolerance) {
        if (function_(z) < 0) {
            x = z;
        } else {
            y = z;
        }
        z = (x + y) / 2;
    }

    cout << "The root for the function is " << z << "\n";
}

int main() {
    float a = 0;
    float b = 1;

    int iteration = 0;
    int max_iteration = 200;

    // finding the interval(a,b)
    while (true) {
        if (function_(a) * function_(b) < 0) {
            bisection(a, b);
            break;
        } else if (iteration == max_iteration) {
            cout << "\nIterated for 200 times and couldn't find the roots of the function\n";
            exit(0);
        } else {
            iteration++;
            
            a++;
            b++;
        }
    }

    return 0;
}
