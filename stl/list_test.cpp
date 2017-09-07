#include <list>
#include <numeric>
//#include <algorithm>

//从前向后迭代
void list_iter1(list<int> &lst)
{
	for (list<int>::iterator it = lst.begin(); it != lst.end(); it++)
		cout << *it << "\t";
	cout << endl;
}

//从后向前迭代
void list_iter2(list<int> &lst)
{
	for (list<int>::reverse_iterator it = lst.rbegin(); it != lst.rend(); it++)
		cout << *it << "\t";
	cout << endl;
}

int list_test()
{
	list<int> la;
	for (int i = 0; i < 3; i++)
		la.push_front(i);

	for (int i = 10; i < 14; i++)
		la.push_back(i);

	list_iter1(la);

	list_iter2(la);

  // 累计所有元素
	int sum = accumulate(la.begin(), la.end(), 0);
	cout << "sum: " << sum << endl;

	return 0;
}
