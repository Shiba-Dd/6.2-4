#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <windows.h>

using namespace std;

// Звичайні функції 

void createArray(int* a, const int size, const int Low, const int High) {
    for (int i = 0; i < size; i++) {
        a[i] = Low + rand() % (High - Low + 1);
    }
}

void printArray(const int* a, const int size) {
    for (int i = 0; i < size; i++) {
        cout << setw(6) << a[i];
    }
    cout << endl;
}

int sumElements(const int* a, const int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += a[i];
    }
    return sum;
}

//  Шаблони функцій 

template <typename T>
void createArrayTemplate(T* a, const int size, const T Low, const T High) {
    for (int i = 0; i < size; i++) {
        a[i] = Low + static_cast<T>(rand()) / (static_cast<T>(RAND_MAX) / (High - Low));
    }
}

template <typename T>
void printArrayTemplate(const T* a, const int size) {
    for (int i = 0; i < size; i++) {
        cout << setw(8) << fixed << setprecision(2) << a[i];
    }
    cout << endl;
}

template <typename T>
T sumElementsTemplate(const T* a, const int size) {
    T sum = 0;
    for (int i = 0; i < size; i++) {
        sum += a[i];
    }
    return sum;
}

int main() {
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);


    const int n = 10;
    int* a = new int[n];

    // Звичайні функції 
    cout << " 1. Звичайні функції (int) " << endl;
    createArray(a, n, -10, 10);
    cout << "Масив: ";
    printArray(a, n);
    cout << "Сума елементів: " << sumElements(a, n) << endl << endl;

    // Шаблони функцій 
    cout << " 2. Шаблони функцій (double) " << endl;
    double* b = new double[n];
    createArrayTemplate<double>(b, n, -10, 10);
    cout << "Масив: ";
    printArrayTemplate<double>(b, n);
    cout << "Сума елементів: " << sumElementsTemplate<double>(b, n) << endl;

    delete[] a;
    delete[] b;
    return 0;
}