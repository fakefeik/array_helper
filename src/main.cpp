#include "main.h"

using namespace std;

int main()
{
    for (auto line : File::get_lines("in.txt")) 
    {
        split(line, ' ') 
            | m_stoi 
            | [](int e) -> bool { return e != 0; } 
            | [](int e) -> int { return e - 1; }
            | [](int e) -> void { cout << e << " "; };
        cout << endl;
    }
    
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