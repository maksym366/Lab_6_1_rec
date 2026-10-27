#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

const int N = 20;

// Рекурсивне заповнення масиву випадковими числами
void fillArray(int a[], int n, int i = 0) {
    if (i == n)
        return;

    a[i] = rand() % 71 - 20; // Діапазон від -20 до 50
    fillArray(a, n, i + 1);
}

// Рекурсивне виведення масиву
void printArray(const int a[], int n, int i = 0) {
    if (i == n) {
        cout << '\n';
        return;
    }

    cout << setw(4) << a[i];
    printArray(a, n, i + 1);
}

// Перевірка критерію: додатний елемент,
// індекс якого не кратний 5
bool satisfiesCriterion(int value, int index) {
    return value > 0 && index % 5 != 0;
}

// Рекурсивне обчислення кількості елементів
int countElements(const int a[], int n, int i = 0) {
    if (i == n)
        return 0;

    int count = satisfiesCriterion(a[i], i) ? 1 : 0;
    return count + countElements(a, n, i + 1);
}

// Рекурсивне обчислення суми елементів
int sumElements(const int a[], int n, int i = 0) {
    if (i == n)
        return 0;

    int sum = satisfiesCriterion(a[i], i) ? a[i] : 0;
    return sum + sumElements(a, n, i + 1);
}

// Рекурсивна заміна потрібних елементів нулями
void replaceElements(int a[], int n, int i = 0) {
    if (i == n)
        return;

    if (satisfiesCriterion(a[i], i))
        a[i] = 0;

    replaceElements(a, n, i + 1);
}

int main() {
    srand(static_cast<unsigned int>(time(nullptr)));

    int a[N];

    fillArray(a, N);

    cout << "Initial array:\n";
    printArray(a, N);

    int count = countElements(a, N);
    int sum = sumElements(a, N);

    replaceElements(a, N);

    cout << "\nNumber of elements: " << count << '\n';
    cout << "Sum of elements: " << sum << '\n';

    cout << "\nModified array:\n";
    printArray(a, N);

    return 0;
}