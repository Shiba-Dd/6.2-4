#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <windows.h>

using namespace std;


void createArray(int* a, const int size, const int Low, const int High) {
    for (int i = 0; i < size; i++) {
        a[i] = Low + rand() % (High - Low + 1);
    }
}

void printArray(const int* a, const int size) {
    for (int i = 0; i < size; i++) {
        cout << setw(4) << a[i];
    }
    cout << endl;
}

int countOddElements(const int* a, const int size) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (a[i] % 2 != 0) {
            count++;
        }
    }
    return count;
}

int main() {
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);


    const int n = 10;
    int* a = new int[n];

    const int Low = -10;
    const int High = 10;


    createArray(a, n, Low, High);


    cout << "Початковий масив:" << endl;
    printArray(a, n);


    cout << "Кількість непарних елементів: " << countOddElements(a, n) << endl;

    delete[] a;
    return 0;
}