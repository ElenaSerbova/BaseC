#include <iostream>
#include <cstring> //string.h

using namespace std;

int main()
{
	char str1[200];

	cout << "Enter a string: ";
	cin.getline(str1, 200);

	char str2[200];

	cout << "Enter a string: ";
	cin.getline(str2, 200);

	//int res = strcmp(str1, str2);
	//int res = _stricmp(str1, str2);
	//int res = strncmp(str1, str2, 3);
	int res = _strnicmp(str1, str2, 3);

	if (res < 0)
	{
		cout << "str1 < str2" << endl;
	}
	else if (res > 0)
	{
		cout << "str1 > str2" << endl;
	}
	else
	{
		cout << "str1 = str2" << endl;
	}

	
	strcpy_s(str1, 200, str2);
	strcat_s(str1, 200, " ");

	char str3[] = "Hello";
	strcat_s(str1, 200, str3);

	cout << str1 << endl;

}

