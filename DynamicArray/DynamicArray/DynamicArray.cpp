#include <iostream>
using namespace std;

void printArray(int* arr, int size);
void addElement(int*& arr, int& size, int value);
void removeLastElement(int*& arr, int& size);

void testPointerAndReferences() {

	int* p = nullptr;

	int a = 10;
	p = &a;

	cout << p << endl;
	cout << *p << endl;

	int b = 20;
	p = &b;

	cout << p << endl;
	cout << *p << endl;

	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	p = arr;

	for (size_t i = 0; i < 10; i++)
	{
		cout << *p << endl;
		p++;
	}


	int c = 30;
	int& r = c;
	int* pc = &c;

	cout << r << endl; //30

	r++;
	

}

int main()
{
	testPointerAndReferences();

	int size = 3;
	int* arr = new int[size]{ 1,2,3 };
	printArray(arr, size);

	addElement(arr, size, 4);
	printArray(arr, size);

	addElement(arr, size, 5);
	printArray(arr, size);

	removeLastElement(arr, size);
	printArray(arr, size);
	
	delete[] arr;
}

void printArray(int* arr, int size)
{
	for (size_t i = 0; i < size; i++)
	{
		cout << arr[i] << "\t";
	}
	cout << endl;
}

void addElement(int*& arr, int& size, int value)
{
	int* tmp = new int[size + 1];

	for (size_t i = 0; i < size; i++)
	{
		tmp[i] = arr[i];
	}

	tmp[size] = value;

	delete[] arr;
	arr = tmp;
	size++;
}

void removeLastElement(int*& arr, int& size)
{
	int* tmp = new int[size - 1];

	for (size_t i = 0; i < size - 1; i++)
	{
		tmp[i] = arr[i];
	}

	delete[] arr;
	arr = tmp;
	size--;
}


