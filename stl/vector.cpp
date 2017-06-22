#include <iostream>
#include <vector>

using namespace std;

int vector_with_int()
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

void print_vector(vector<string> vec)
{
	int 	i, size;
	size = vec.size();
	for(i=0; i<size; i++)
	{
		cout << vec[i] << " ";
	}	
	cout << endl;
}

int vector_with_string()
{
	int		i;

	vector<string> vec;
	vec.push_back("Cars");
	vec.push_back("Plane");
	vec.push_back("Ship");

	/* 在开头插入数据 */
	vec.insert(vec.begin(), "Head");
	/* 在结尾插入数据 */
	vec.insert(vec.end(), "Tail");

	print_vector(vec);
	return 0;		
}

int main()
{
	vector_with_string();
	return 0;
}
