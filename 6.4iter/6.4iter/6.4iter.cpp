#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <windows.h>

using namespace std;


void createArray(double* a, const int size, const double Low, const double High) {
    for (int i = 0; i < size; i++) {
        a[i] = Low + (static_cast<double>(rand()) / RAND_MAX) * (High - Low);
    }
}

void printArray(const double* a, const int size) {
    for (int i = 0; i < size; i++) {
        cout << setw(8) << fixed << setprecision(2) << a[i];
    }
    cout << endl;
}

int findMinIndex(const double* a, const int size) {
    if (size <= 0) return -1;
    int minIndex = 0;
    for (int i = 1; i < size; i++) {
        if (a[i] < a[minIndex]) {
            minIndex = i;
        }
    }
    return minIndex;
}


double sumBetweenFirstAndSecondNegative(const double* a, const int size) {
    int firstNeg = -1;
    int secondNeg = -1;

    for (int i = 0; i < size; i++) {
        if (a[i] < 0) {
            if (firstNeg == -1) {
                firstNeg = i;
            }
            else if (secondNeg == -1) {
                secondNeg = i;
                break;
            }
        }
    }

    if (firstNeg == -1 || secondNeg == -1 || secondNeg - firstNeg <= 1) {
        return 0; 
    }

    double sum = 0;
    for (int i = firstNeg + 1; i < secondNeg; i++) {
        sum += a[i];
    }
    return sum;
}


void transformArray(double* a, const int size) {
    double* temp = new double[size];
    int index = 0;


    for (int i = 0; i < size; i++) {
        if (abs(a[i]) <= 1) {
            temp[index] = a[i];
            index++;
        }
    }


    for (int i = 0; i < size; i++) {
        if (abs(a[i]) > 1) {
            temp[index] = a[i];
            index++;
        }
    }


    for (int i = 0; i < size; i++) {
        a[i] = temp[i];
    }

    delete[] temp;
}

int main() {
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    srand(static_cast<unsigned>(time(nullptr)));

    int n;
    cout << "Введіть розмір масиву n: ";
    cin >> n;

    if (n <= 0) return 0;

    double* a = new double[n];
    const double Low = -3.0;
    const double High = 3.0;

    createArray(a, n, Low, High);

    cout << "\nПочатковий масив:" << endl;
    printArray(a, n);

    int minIdx = findMinIndex(a, n);
    cout << "\n1.1. Номер мінімального елемента (індекс): " << minIdx << endl;

    double sum = sumBetweenFirstAndSecondNegative(a, n);
    cout << "1.2. Сума елементів між першим і другим від'ємними: " << sum << endl;

    transformArray(a, n);

    cout << "\nМодифікований масив (|a[i]| <= 1 спочатку):" << endl;
    printArray(a, n);

    delete[] a;
    return 0;
}