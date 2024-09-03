#include <iostream>
using namespace std;

// Function to calculate the sum from 'first' to 'last' inclusive
int sum_from_to(int first, int last) {
    int sum = 0;
    for (int i = first; i <= last; i++) {
        sum += i;
    }
    return sum;
}

// Function to find the greatest common divisor (GCD)
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Function to reduce the fraction by dividing num and denom by their GCD
int reduce(int &num, int &denom) {
    if (num <= 0 || denom <= 0) {
        return 0;  // Failure to reduce
    }
    int divisor = gcd(num, denom);
    num /= divisor;
    denom /= divisor;
    return 1;  // Successful reduction
}

int main() {
    int first = 1, last = 10;
    cout << "Sum from " << first << " to " << last << " is " << sum_from_to(first, last) << endl;

    int num = 8, denom = 12;
    if (reduce(num, denom)) {
        cout << "Reduced fraction: " << num << "/" << denom << endl;
    } else {
        cout << "Failed to reduce the fraction." << endl;
    }

    return 0;
}
