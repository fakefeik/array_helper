#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

static string operator*(const string &s, int d) {
	string temp_str = string(s);
	for (int i = 1; i < d; i++) 
		temp_str.append(s);
	return temp_str;
}

#pragma mark - vector stuff
#pragma mark - functions templates

template<typename T>
vector<T> operator|(vector<T> ins, void (*f) (T)) 
{
	for (T v : ins)
		f(v);
	return ins;
}

template<typename T>
vector<T> operator|(vector<T> ins, bool (*f) (T))
{
	vector<T> outs;
	for (T v : ins)
		if (f(v))
			outs.push_back(v);
	return outs;
}

template<typename TIn, typename TOut>
vector<TOut> operator|(vector<TIn> ins, TOut (*f) (TIn)) 
{
	vector<TOut> outs;
	for (TIn v : ins)
		outs.push_back(f(v));
	return outs;
}

#pragma mark - lambdas templates

template<typename T, typename F>
auto operator|(vector<T> ins, F f) 
	-> typename enable_if<is_same<void, typename result_of<F(T)>::type>::value, vector<T>>::type
{
	for (T v : ins)
		f(v);
	return ins;
}

template<typename T, typename F>
auto operator|(vector<T> ins, F f) 
	-> typename enable_if<is_same<bool, typename result_of<F(T)>::type>::value, vector<T>>::type
{
	vector<T> v2;
	for (T v : ins)
		if (f(v))
			v2.push_back(v);
	return v2;
}

template<typename T, typename F>
auto operator|(vector<T> ins, F f) 
	-> typename enable_if<is_same<T, typename result_of<F(T)>::type>::value, vector<T>>::type
{
	vector<T> outs;
	for (T v : ins)
		outs.push_back(f(v));
	return outs;
}

#pragma mark - functions example

vector<string> split(string s, char delim) 
{
	vector<string> elems;
	std::stringstream ss(s);
    std::string item;
    while (getline(ss, item, delim)) 
        elems.push_back(item);
    return elems;
}

static int m_sqr(int i) {
	return i * i;
}

static double m_sqrt(int i) {
	return sqrt(i);
}

static double m_sqrt(double d) {
	return sqrt(d);
}

static void println(int i) {
	cout << i << endl;
}

static void println(double d) {
	cout << d << endl;
}

static void println(string s) {
	cout << s << endl;
}

static bool is_even(int i) {
	return i % 2 == 0;
}

static int m_stoi(string s) {
	return stoi(s);
}