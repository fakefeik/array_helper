#include <vector>
#include <fstream>
#include <string>

using namespace std;

class File 
{
public:
	static vector<string> get_lines(const char *file);
	static void write_lines(const char *file, vector<string> lines);
};
