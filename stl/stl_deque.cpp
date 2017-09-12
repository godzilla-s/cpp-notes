#include <deque>

void deque_print(const char *str, deque<int> &d)
{
	cout << str;
	if (d.empty())
	{
		cout << "empty deque\n";
		return;
	}

	for (deque<int>::iterator it = d.begin(); it != d.end(); it++)
		cout << *it << " ";
	cout << endl;
}

int deqeue_test()
{
	deque<int> da;

	da.push_front(1);
	da.push_front(2);
	da.push_front(3);

	deque_print("set deque: ", da);

	da.push_back(4);
	da.push_back(5);

	deque_print("add push back: ", da);

	da.pop_back();
	da.pop_back();
	da.pop_front();

	deque_print("after pop deque: ", da);

	return 0;
}
