#include <iostream>
#include <string>
#include <deque>

using namespace std;

int deque_init()
{
	deque<string>	de;
	de.push_back("data1");
	de.push_back("data2");
	de.push_back("data3");

	de.push_front("data4");

	return 0;
}

int main()
{
	deque_init();

	return 0;
}

