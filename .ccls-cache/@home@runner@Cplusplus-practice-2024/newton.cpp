#include <iostream>
#include <cmath>

using namespace std;

double newton(int x, double tolerance = 0.0001) {
    if (x == 0) return 0;

    double root = x;
    double lastRoot = 0;

    while (abs(root - lastRoot) > tolerance) {
        lastRoot = root;
        root = (lastRoot + x / lastRoot) / 2;
    }

    return root;
}

int main() {
    int x = 625;
    cout << "Square root of " << x << " is " << newton(x, 0.01) << endl;
    return 0;
}
