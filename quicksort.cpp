#include <iostream>
using namespace std;

void quicksort(int size, int* arr) {
	int low = 0;
	int mid = arr[size / 2];
	int high = size - 1;
	do {
		while (arr[low] < mid) {
			low++;
		}
		while (arr[high] > mid) {
			high--;
		}
		if (low <= high) {
			int tmp = arr[low];
			arr[low] = arr[high];
			arr[high] = tmp;
			low++;
			high--;
		}
	} while (low <= high);
	if (high > 0) { quicksort(high + 1, arr); }
	if (low < size) {
		quicksort(size - low, &arr[low]);
	}
}

void output(int size, int* arr) {
	cout << "��������� ������: ";
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}

	cout << "�������� ������: ";
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
	cout << "\n";
}

int main() {
	setlocale(LC_ALL, "rus");
	srand(time(NULL));
	const int size = 10;
	int arr[size];

	cout << "��������� ������: \n1) ������� \n2) �������������\n";
	int choice;
	do {
		cin >> choice;
		switch (choice)
		{
		case 1:
			cout << "������� �������� �������" << endl;
			for (int i = 0; i < size; i++) {
				cin >> arr[i];
			}
			quicksort(size, arr);
			output(size, arr);
			break;

		case 2:
			for (int i = 0; i < size; i++) {
				arr[i] = rand() % 101;
			}
			quicksort(size, arr);
			output(size, arr);
			break;
		default:
			cout << "\n��������� ������: \n1) ������� \n2) �������������\n";
			break;
		}
	} while (1 == 1);
}
