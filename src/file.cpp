#include "file.h"

vector<string> File::get_lines(const char *file) 
{
	vector<string> lines;
	ifstream infile(file);
	if (!infile.is_open()) 
		throw;
	while (!infile.eof())
	{
		lines.push_back("");
		getline(infile, lines[lines.size() - 1]);
	}
	infile.close();
	return lines;
}

void File::write_lines(const char *file, vector<string> lines) 
{
	ofstream outfile(file);
	if (!outfile.is_open())
		throw;
	for (string line : lines) 
		outfile << line << endl;
	outfile.close();
}