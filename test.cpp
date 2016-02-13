#include <map>
#include <stdio.h>
using namespace std;

int main()
{
	map<const char*, int> m;
	bool result = m.insert(pair<const char*, int>("Hello", 0)).second;
	printf("%d\n", result);
	result = m.insert(pair<const char*, int>("Hello", 0)).second;
	printf("%d\n", result);
	return 0;
}