#include <iostream>
#include <chrono>

using namespace std;

// Iterative Factorial
unsigned long long factorialIterative(int n) {
    unsigned long long fact = 1;
    for (int i = 1; i <= n; i++) {
        fact *= i;
    }
    return fact;
}

// Recursive Factorial
unsigned long long factorialRecursive(int n) {
    if (n <= 1)
        return 1;
    return n * factorialRecursive(n - 1);
}

int main() {
    int n;

    cout << "Enter a non-negative integer: ";
    if (!(cin >> n) || n < 0) {
        cout << "Invalid input!" << endl;
        return 1;
    }

    // Iterative Time
    auto start1 = chrono::high_resolution_clock::now();
    unsigned long long ans1 = factorialIterative(n);
    auto end1 = chrono::high_resolution_clock::now();

    chrono::duration<double, nano> time1 = end1 - start1;

    // Recursive Time
    auto start2 = chrono::high_resolution_clock::now();
    unsigned long long ans2 = factorialRecursive(n);
    auto end2 = chrono::high_resolution_clock::now();

    chrono::duration<double, nano> time2 = end2 - start2;

    cout << "\n--- Results for " << n << "! ---" << endl;
    cout << "Iterative Result : " << ans1 << endl;
    cout << "Iterative Time   : " << time1.count() << " ns" << endl;
    cout << "-------------------------------" << endl;
    cout << "Recursive Result : " << ans2 << endl;
    cout << "Recursive Time   : " << time2.count() << " ns" << endl;

    return 0;
}