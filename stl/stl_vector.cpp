#include <iostream>
#include <vector>

using namespace std;

void vector_print(char *str, vector<int> &va)
{
	cout << str;
	if (va.empty())
	{
		cout << "empty vector\n";
		return;
	}

	for (vector<int>::iterator it = va.begin(); it != va.end(); it++)
		cout << *it << " ";
	cout << endl;
}

int vector_test()
{
	int i = 0;
	vector<int> va;
	for (i = 0; i < 6; i++)
	{
		va.push_back(i);
	}

	vector_print("after push back: ", va);

	va.insert(va.begin(), 10);
	va.insert(va.begin() + 2, 12);
	va.insert(va.end() - 1, 15); // va.end() 只能-x, 不能+x

	vector_print("after insert: ", va);

	va.erase(va.begin(), va.end());
	vector_print("after erase: ", va);

	va.push_back(21);
	va.push_back(22);

	vector_print("erase and insert: ", va);

	return 0;
}
