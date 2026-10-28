#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <windows.h>

using namespace std;


void createArrayRecursive(double* a, const int size, const double Low, const double High, int i = 0) {
    a[i] = Low + (static_cast<double>(rand()) / RAND_MAX) * (High - Low);
    if (i < size - 1) {
        createArrayRecursive(a, size, Low, High, i + 1);
    }
}


void printArrayRecursive(const double* a, const int size, int i = 0) {
    cout << setw(8) << fixed << setprecision(2) << a[i];
    if (i < size - 1) {
        printArrayRecursive(a, size, i + 1);
    }
    else {
        cout << endl;
    }
}


int findMinIndexRecursive(const double* a, const int size, int i = 1, int minIndex = 0) {
    if (i >= size) {
        return minIndex;
    }
    if (a[i] < a[minIndex]) {
        minIndex = i;
    }
    return findMinIndexRecursive(a, size, i + 1, minIndex);
}


int findNegativeIndexRecursive(const double* a, const int size, int startIndex) {
    if (startIndex >= size) {
        return -1;
    }
    if (a[startIndex] < 0) {
        return startIndex;
    }
    return findNegativeIndexRecursive(a, size, startIndex + 1);
}


double sumRangeRecursive(const double* a, int start, int end) {
    if (start >= end) {
        return 0;
    }
    return a[start] + sumRangeRecursive(a, start + 1, end);
}


double sumBetweenFirstAndSecondNegativeRecursive(const double* a, const int size) {
    int firstNeg = findNegativeIndexRecursive(a, size, 0);
    if (firstNeg == -1) {
        return 0;
    }

    int secondNeg = findNegativeIndexRecursive(a, size, firstNeg + 1);
    if (secondNeg == -1 || secondNeg - firstNeg <= 1) {
        return 0;
    }

    return sumRangeRecursive(a, firstNeg + 1, secondNeg);
}


void filterElementsRecursive(const double* src, double* dest, const int size, bool fitCondition, int& destIdx, int srcIdx = 0) {
    if (srcIdx >= size) {
        return;
    }
    bool condition = (abs(src[srcIdx]) <= 1);
    if ((fitCondition == true && condition == true ) || (fitCondition != true && condition != true)) {
        dest[destIdx] = src[srcIdx];
        destIdx++;
    }
    filterElementsRecursive(src, dest, size, fitCondition, destIdx, srcIdx + 1);
}


void copyArrayRecursive(const double* src, double* dest, const int size, int i = 0) {
    if (i >= size) return;
    dest[i] = src[i];
    copyArrayRecursive(src, dest, size, i + 1);
}

void transformArrayRecursive(double* a, const int size) {
    double* temp = new double[size];
    int destIdx = 0;

    
    filterElementsRecursive(a, temp, size, true, destIdx);
 
    filterElementsRecursive(a, temp, size, false, destIdx);

   
    copyArrayRecursive(temp, a, size);

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
    const double Low = -3;
    const double High = 3;

    createArrayRecursive(a, n, Low, High);

    cout << "\nПочатковий масив:" << endl;
    printArrayRecursive(a, n);

    int minIdx = findMinIndexRecursive(a, n);
    cout << "\n1.1. Номер мінімального елемента (індекс): " << minIdx << endl;

    double sum = sumBetweenFirstAndSecondNegativeRecursive(a, n);
    cout << "1.2. Сума елементів між першим і другим від'ємними: " << sum << endl;

    transformArrayRecursive(a, n);

    cout << "\nМодифікований масив (|a[i]| <= 1 спочатку):" << endl;
    printArrayRecursive(a, n);

    delete[] a;
    return 0;
}