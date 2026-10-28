#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <windows.h>

using namespace std;




void createArrayRecursive(int* a, const int size, const int Low, const int High, int i = 0) {
    a[i] = Low + rand() % (High - Low + 1);
    if (i < size - 1) {
        createArrayRecursive(a, size, Low, High, i + 1);
    }
}


void printArrayRecursive(const int* a, const int size, int i = 0) {
    cout << setw(4) << a[i];
    if (i < size - 1) {
        printArrayRecursive(a, size, i + 1);
    }
    else {
        cout << endl;
    }
}


int countOddElementsRecursive(const int* a, const int size, int i = 0) {
    if (i >= size) {
        return 0;
    }
    int count;
    if (a[i] % 2 != 0) {
        count = 1;
    }
    else {
        count = 0;
    }
    return count + countOddElementsRecursive(a, size, i + 1);
}

int main() {
   
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    const int n = 10;
    int* a = new int[n];

    const int Low = -10;
    const int High = 10;

    createArrayRecursive(a, n, Low, High);


    cout << "Початковий масив:" << endl;
    printArrayRecursive(a, n);

    int oddCount = countOddElementsRecursive(a, n);
    cout << "Кількість непарних елементів: " << oddCount << endl;

    delete[] a;
    return 0;
}