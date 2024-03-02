#include <iostream>

using namespace std;

bool binary_search(int key, int arr[], int arr_length) {

	int l = 0;
	int r = arr_length - 1;
	int mid;
	bool flag = false;

	while ((l <= r) && (flag == false)) {

		mid = (r + l) / 2;


		if (arr[mid] == key) {
			flag = true;
		};
		if (arr[mid] > key) {
			r = mid - 1;
		}

		else {
			l = mid + 1;
		};

	}


	if (flag == true) {

		return true;
	}
	else {

		return false;
	};

}

void push_back(int*& arr, int& size, int value) 
{
	int* newArray = new int[size + 1];

	for (unsigned int i = 0; i < size; i++)
	{
		newArray[i] = arr[i];
	};

	newArray[size] = value;

	delete[] arr;

	arr = newArray;
};

int square_summ(int n) {

	int k = 0;

	while (n != 0) 
	{
		k += (n % 10) * (n % 10);
		n = n / 10;

	};

	return k;
}

void lucky_num(int n) {

	int k = square_summ(n); // первая итерация

	bool flag = false;

	int size = 1;

	int* arr = new int[size];

	arr[size - 1] = k;

	while ((k != 1) and (flag == false))
	{
		int temp = square_summ(k);
		
		bool t = binary_search(temp, arr, size);

		if (t == true) {
			flag = true;
		};

		push_back(arr, size, temp);
		
		k = temp;
	};

	if (k == 1) {
		cout << "number is lucky" << endl;
	}

	else {
		cout << "number is not lucky" << endl;
	};

	delete[] arr;
};




int main() {

	int n;

	cin >> n;

	lucky_num(n);

	return 0;
}