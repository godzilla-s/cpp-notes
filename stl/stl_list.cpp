#include <iostream>
#include <list>
#include <string>
#include <numeric>

using namespace std;

//从前向后
void list_print(char *str, list<int> &lst)
{
	cout << str;
	if (lst.empty())
	{
		cout << "Empty List\n";
		return ;
	}

	for (list<int>::iterator it = lst.begin(); it != lst.end(); it++)
		cout << *it << " ";
	cout << endl;
}

//从后向前
void list_printZ(list<int> &lst)
{
	if (lst.empty())
	{
		cout << "Empty List\n";
		return ;
	}

	cout << "reverse display: ";

	for (list<int>::reverse_iterator it = lst.rbegin(); it != lst.rend(); it++)
		cout << *it << " ";
	cout << endl;
}

int list_test()
{
	list<int> la;
	for (int i = 0; i < 3; i++)
		la.push_front(i);

	list_print("push front: ", la);

	for (int i = 10; i < 14; i++)
		la.push_back(i);

	list_print("push back: ", la);

	la.pop_back();
	la.pop_front();

	list_print("after pop: ", la);

	list_printZ(la);

	la.insert(la.begin(), 30);
	la.insert(la.begin(), 40);

	list_print("after insert: ", la);

	la.sort();
	list_print("after sort: ", la);

	int sum = accumulate(la.begin(), la.end(), 0);
	cout << "sum: " << sum << endl;

	list<int> lb;
	for (int i = 0; i < 5; i++)
		lb.push_front(i+20);

	list_print("list b: ", lb);

	// 合并, 如果b为空，这会core掉
	// la.merge(lb);
	
	list_print("list merge: ", la);

	// 删除所有
	la.erase(la.begin(), la.end());


	lb.clear();

	list_print("after clear: ", lb);

	la.push_front(30);
	la.push_front(31);
	la.push_front(32);
	la.push_front(33);
	la.push_front(33);
	
	list_print("la list new: ", la);
	
	la.merge(lb);
	
	list_print("after merge la and lb: ", la);
	
	return 0;
}
