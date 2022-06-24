#include <iostream>

using namespace std;

void pyramidsort(int* arr, int n) {
    int k = 0;
    bool key = false;
    while (k + 2 != n) {
        key = false;
        for (int i = 0; i < n; i++) {
            if (i * 2 + 2 + k < n) {
                if ((arr[i + k] > arr[i * 2 + 1 + k]) || (arr[i + k] > arr[i * 2 + 2 + k])) {
                    if (arr[i * 2 + 1 + k] < arr[i * 2 + 2 + k]) {
                        swap(arr[i + k], arr[i * 2 + 1 + k]);
                        key = true;
                    }
                    else if (arr[i * 2 + 2 + k] < arr[i * 2 + 1 + k]) {
                        swap(arr[i + k], arr[i * 2 + 2 + k]);
                        key = true;
                    }
                }
                if (arr[i * 2 + 2 + k] < arr[i * 2 + 1 + k])
                {
                    swap(arr[i * 2 + 1 + k], arr[i * 2 + 2 + k]);
                    key = true;
                }
            }
            else if (i * 2 + 1 + k < n) {
                if (arr[i + k] > arr[i * 2 + 1 + k]) {
                    swap(arr[i + k], arr[i * 2 + 1 + k]);
                    key = true;
                }
            }
        }
        if (!key) {
            k++;
        }
    }
}

int main() {
    setlocale(LC_ALL, "Russian");
    const int n = 10;
    int arr[n];
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 101;
    }
    cout << "Начальный массив: \n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    pyramidsort(arr, n);

    cout << "\n\nКонечный массив: \n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
}