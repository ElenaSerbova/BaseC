#include <iostream>
#include <cstdio> //stdio.h
using namespace std;

void WriteTextToFile();
void ReadTextFromFile();

int main()
{
	 WriteTextToFile();
	 ReadTextFromFile();
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
