#include <iostream>
#include <cstdio> //stdio.h
using namespace std;

void WriteTextToFile();
void ReadTextFromFile();

void WriteBinaryData();
void ReadBinaryData();

int main()
{
	// WriteTextToFile();
	// ReadTextFromFile();

	 WriteBinaryData();
	 ReadBinaryData();
}

void WriteTextToFile()
{
	//absolute path: C:\Test\test.txt

	//relative path: test.txt - in current directory
	//relative path: .\test.txt - in current directory
	//relative path: ..\test.txt - in parent directory
	//relative path: files\test.txt - in files directory

	FILE* file;
	errno_t errorCode = fopen_s(&file, "test.txt", "a");

	if (errorCode != 0)
	{
		cout << "Error code: " << errorCode << endl;
		return;
	}

	cout << "File openned" << endl;

	char str[256];
	cout << "Enter text: ";
	cin.getline(str, 256);

	fputs(str, file);
	fputs("\n", file);

	fclose(file);
}

void ReadTextFromFile()
{
	FILE* file;
	errno_t errorCode = fopen_s(&file, "test.txt", "r");

	if (errorCode != 0)
	{
		cout << "Error code: " << errorCode << endl;
		return;
	}

	char str[256];

	while (!feof(file)) //while not end of file
	{
		fgets(str, 256, file);
		cout << str;
	}

	fclose(file);
}

void WriteBinaryData()
{
	FILE* file;
	errno_t errorCode = fopen_s(&file, "test.bin", "w");

	if (errorCode != 0)
	{
		cout << "Error code: " << errorCode << endl;
		return;
	}

	int a = 123;
	fwrite(&a, sizeof(int), 1, file);

	double b = 23.4;
	fwrite(&b, sizeof(double), 1, file);

	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	fwrite(arr, sizeof(int), 10, file);

	char str[10] = "Hello";
	fwrite(str, sizeof(char), 10, file);

	fclose(file);
}

void ReadBinaryData()
{
	FILE* file;
	errno_t errorCode = fopen_s(&file, "test.bin", "r");

	if (errorCode != 0)
	{
		cout << "Error code: " << errorCode << endl;
		return;
	}

	int a;
	fread(&a, sizeof(int), 1, file);

	double b;
	fread(&b, sizeof(double), 1, file);

	int arr[10] = { 0 };
	fread(arr, sizeof(int), 10, file);	

	char str[10];
	fread(str, sizeof(char), 10, file);

	cout << "a = " << a << endl;
	cout << "b = " << b << endl;

	for (size_t i = 0; i < 10; i++)
	{
		cout << arr[i] << "\t";
	}
	cout << endl;

	cout << str << endl;

	fclose(file);
}
