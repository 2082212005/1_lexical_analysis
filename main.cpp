#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <cmath>

using namespace std;

int main()
{
	fstream fs("in.txt");
	stringstream ss;
	ss << fs.rdbuf();
	string s;
	s=ss.str();
	printf("%s",s.c_str());
    return 0;
}
