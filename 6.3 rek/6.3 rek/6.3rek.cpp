#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <windows.h>

using namespace std;

// Звичайні рекурсивні функції (для типу int)

void createArrayRecursive(int* a, const int size, const int Low, const int High, int i = 0) {
    a[i] = Low + rand() % (High - Low + 1);
    if (i < size - 1) {
        createArrayRecursive(a, size, Low, High, i + 1);
    }
}

void printArrayRecursive(const int* a, const int size, int i = 0) {
    cout << setw(6) << a[i];
    if (i < size - 1) {
        printArrayRecursive(a, size, i + 1);
    }
    else {
        cout << endl;
    }
}

int sumElementsRecursive(const int* a, const int size, int i = 0) {
    if (i >= size) {
        return 0;
    }
    return a[i] + sumElementsRecursive(a, size, i + 1);
}

// Шаблони рекурсивних функцій

template <typename T>
void createArrayRecursiveTemplate(T* a, const int size, const T Low, const T High, int i = 0) {
    a[i] = Low + static_cast<T>(rand()) / (static_cast<T>(RAND_MAX) / (High - Low));
    if (i < size - 1) {
        createArrayRecursiveTemplate(a, size, Low, High, i + 1);
    }
}

template <typename T>
void printArrayRecursiveTemplate(const T* a, const int size, int i = 0) {
    cout << setw(8) << fixed << setprecision(2) << a[i];
    if (i < size - 1) {
        printArrayRecursiveTemplate(a, size, i + 1);
    }
    else {
        cout << endl;
    }
}

template <typename T>
T sumElementsRecursiveTemplate(const T* a, const int size, int i = 0) {
    if (i >= size) {
        return 0;
    }
    return a[i] + sumElementsRecursiveTemplate(a, size, i + 1);
}

int main() {
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    srand(static_cast<unsigned>(time(nullptr)));

    const int n = 10;
    int* a = new int[n];

    // Звичайні рекурсивні функції
    cout << "=== 1. Рекурсія (int) ===" << endl;
    createArrayRecursive(a, n, -10, 10);
    cout << "Масив: ";
    printArrayRecursive(a, n);
    cout << "Сума елементів: " << sumElementsRecursive(a, n) << endl << endl;

    // Шаблони рекурсивних функцій (double) 
    cout << "=== 2. Шаблонна рекурсія (double) ===" << endl;
    double* b = new double[n];
    createArrayRecursiveTemplate<double>(b, n, -10.0, 10.0);
    cout << "Масив: ";
    printArrayRecursiveTemplate<double>(b, n);
    cout << "Сума елементів: " << sumElementsRecursiveTemplate<double>(b, n) << endl;

    delete[] a;
    delete[] b;
    return 0;
}