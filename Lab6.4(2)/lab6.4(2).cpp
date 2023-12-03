#include <iostream>
#include <cmath>

using namespace std;

void fillArrayRecursive(double*& arr, int n) {
    arr = new double[n];
    cout << "Enter the elements of the array:\n";
    for (int i = 0; i < n; ++i) {
        cout << "Element " << i + 1 << ": ";
        cin >> arr[i];
    }
}

void printArrayRecursive(const double* arr, int n) {
    cout << "Array: ";
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

int findMaxAbsIndexRecursive(const double* arr, int n, int currentIndex = 1, int maxIndex = 0) {
    if (currentIndex == n) {
        return maxIndex;
    }

    if (abs(arr[currentIndex]) > abs(arr[maxIndex])) {
        maxIndex = currentIndex;
    }

    return findMaxAbsIndexRecursive(arr, n, currentIndex + 1, maxIndex);
}

double sumAfterFirstPositiveRecursive(const double* arr, int n, int currentIndex = 0, bool foundPositive = false, double sum = 0.0) {
    if (currentIndex == n) {
        return sum;
    }

    if (foundPositive) {
        sum += arr[currentIndex];
    }
    else if (arr[currentIndex] > 0) {
        foundPositive = true;
    }

    return sumAfterFirstPositiveRecursive(arr, n, currentIndex + 1, foundPositive, sum);
}

void rearrangeArrayHelperRecursive(double*& arr, int n, double a, double b, int i, int j) {
    if (i < j) {
        while (i < j && static_cast<int>(arr[i]) >= a && static_cast<int>(arr[i]) <= b) {
            ++i;
        }
        while (i < j && (static_cast<int>(arr[j]) < a || static_cast<int>(arr[j]) > b)) {
            --j;
        }
        if (i < j) {
            std::swap(arr[i], arr[j]);
            ++i;
            --j;
        }
        rearrangeArrayHelperRecursive(arr, n, a, b, i, j);
    }
}

void rearrangeArrayRecursive(double*& arr, int n, double a, double b) {
    rearrangeArrayHelperRecursive(arr, n, a, b, 0, n - 1);
}

int main() {
    int n;
    double a, b;

    cout << "Enter the size of the array (n): ";
    cin >> n;

    double* arr;
    fillArrayRecursive(arr, n);
    printArrayRecursive(arr, n);

    int maxAbsIndex = findMaxAbsIndexRecursive(arr, n);
    cout << "1.1. Index of the maximum absolute element: " << maxAbsIndex << "\n";

    double sumAfterPositive = sumAfterFirstPositiveRecursive(arr, n);
    cout << "1.2. Sum of elements after the first positive element: " << sumAfterPositive << "\n";

    cout << "Enter the values of a and b: ";
    cin >> a >> b;

    rearrangeArrayRecursive(arr, n, a, b);

    printArrayRecursive(arr, n);

    delete[] arr;
    return 0;
}