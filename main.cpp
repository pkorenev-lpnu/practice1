#include <iostream>
#include <thread>
#include <chrono>
#include <cmath>
#include <iomanip>

using namespace std;

void calculate_and_print_results(double a, double b, int n) {
    double h, x, y, min_x, min_y, max_x, max_y;

    h = (b - a) / n;
    
    x = a;
    y = (x + sin(2 * x)) / (x*x - 3);

    cout << "\nx\ty" << endl;

    cout.width(5);
    cout.precision(5);
    cout << x << y << endl;

    min_x = x;
    max_x = x;
    min_y = y;
    max_y = y;

    for(int i = 1; i <= n; i++) {
        x = a + h * i;
        y = (x + sin(2 * x)) / (x*x - 3);

        cout.width(5);
        cout.precision(5);
        cout << x << "\t" << y << endl;

        if (y < min_y) {
            min_x = x;
            min_y = y;
        } 
        else if (y > max_y) {
            max_x = x;
            max_y = y;
        }
    }

    cout << "\nThe largest value taken by the function is " << max_y << " at " << max_x 
         << "\nThe smallest value taken by the function is " << min_y << " at " << min_x;
}

int main() {
    int n;
    double a, b, eps = 1e-9;

    do {
        do {
            cout << "Enter a: ";
            cin >> a;
        } while(abs(a * a - 3.0) < eps);

        do {
            cout << "Enter b: ";
            cin >> b;
        } while(abs(b * b - 3.0) < eps);
    } while(a > b || abs(a - b) < eps);

    do {
        cout << "Enter n: ";
        cin >> n;
    } while(n <= 0);

    ::calculate_and_print_results(a, b, n);

    cout << "\nEnd of program" << endl;

    std::this_thread::sleep_for(std::chrono::milliseconds(500));

    return 0;
}
