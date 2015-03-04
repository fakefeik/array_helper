#include "main.h"
#include <algorithm>
#include <typeinfo>
#include <type_traits>

using namespace std;

int main()
{
	const int arr[] = {1, 2, 3, 4, 10, 40, 928};
	vector<int> vectors(arr, arr + sizeof(arr) / sizeof(arr[0]));
	
	vectors 
		| [](int e) -> bool { return e > 0; } 
		| [](int e) -> void { cout << e << endl; };
	
	cout << endl;

	const string arr1[] = {"1", "2", "3", "78"};
	vector<string> vecstr(arr1, arr1 + sizeof(arr1) / sizeof(arr1[0]));

	vecstr 
		| m_stoi 
		| m_sqrt//[](int e) -> bool { return e % 2 == 1; } 
		| [](double e) -> double { return e * e * e; } 
		| println;

	getline(cin, string());
	return 0;
}