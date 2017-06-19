#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int		i;
	vector<int> vec;

	cout << "初始vector大小:" << vec.size() << endl;
		
	vec.push_back(23);

	cout << "After Add 1 data: " << vec.size() << endl;

	for(i=0; i<6; i++)
	{
		vec.push_back(i);
	}

	cout << "after add 5 datas: " << vec.size() << endl;

	for(i=0; i<10; i++)
	{
		vec.push_back(i+10);
	}

	cout << "after add 10 datas: " << vec.size() << endl;

	/* 角标访问 */
	int		size = vec.size();
	for(i=0; i<size; i++)
		cout << vec[i] << " ";
	cout << endl;

	/* vector 迭代 */
	vector<int>::iterator iter = vec.begin();
	while( iter != vec.end() )
	{
		cout << *iter << " ";
		iter++;
	}
	cout <<  endl;

	return 0;
}
