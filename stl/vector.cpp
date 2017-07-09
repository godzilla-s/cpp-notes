#include <iostream>
#include <vector>

using namespace std;

template <class T>
void print(vector<T> vec)
{
	int i;
	
	cout << "vector size: " << vec.size() << endl;
	for(i=0; i<vec.size(); i++)
		cout << vec[i] << " ";
	cout << endl;
}

template <class T>
void vectorIter(vector<T> vec)
{
	return;
}

template <class T>
void checkEmpty(vector<T> vec)
{
	if(!vec.empty())
		cout << "vector is not empty\n";
	else
		cout << "vector is empty\n";
}

//Vector 初始化
void vector_init()
{
	int i;

	//默认初始化
	vector<int> vec1;
	for(i=0; i<10; i++)
		vec1.push_back(i+3);
	print(vec1);	

	//使用vec1初始化
	vector<int> vec2(vec1);
	vec2.push_back(20); 
	print(vec2);

	//使用vec2初始化
	vector<int> vec3(vec2.begin(), vec2.end());
	print(vec3);

	//初始化容量为10
	vector<int> vec4(10);
	print(vec4);

	//初始化容量为10, 数据为4
	vector<int> vec5(10, 4);
	print(vec5);

	vector<int> vec6;
	checkEmpty(vec6);
	vec6.insert(vec6.end(), 1 ,3); //在vector末尾添加一个数据
	vec6.insert(vec6.end(), 2, 4);
	vec6.insert(vec6.begin(), 1, 5); //在vector开始添加一个数据
	vec6.insert(vec6.begin(), 1, 7);
	checkEmpty(vec6);
	print(vec6);
	//取出末尾数据
	vec6.pop_back();
	print(vec6);

	//数组初始化
	int a[] = {1, 2, 3, 4, 5, 6, 7};
	vector<int> vec7(a, a+7);
	print(vec7);
}

//vector 操作
void vector_opr()
{
	cout << "#### vector element operate\n";
	vector<int>  vec;
	
	//插入数据：push_back
	vec.push_back(10);
	vec.push_back(20);
	print(vec);
	
	//插入数据: insert
	vec.insert(vec.begin(), 1, 1); //在开头处插入1个1
	print(vec);
	vec.insert(vec.begin(), 2, 3); //在开头处插入2个3
	print(vec);
	vec.insert(vec.end(), 1, 5);
	vec.insert(vec.end(), 2, 8);
	print(vec);

	//删除数据
	vec.pop_back(); //从尾部删除
	//cout << "删除 : " << a << endl;
	print(vec);

	//删除数据: erase
	vec.erase(vec.begin(), vec.end());
	print(vec);
}

//vector 迭代
void vector_iter()
{
	vector<int> vec;

	cout << "#### vector iteratot\n";

	for(int i=0; i<10; i++)
		vec.push_back(i+1);
	vector<int>::iterator iter = vec.begin();
	for(; iter != vec.end(); iter++)
		cout << *iter << ",";
	cout << endl;

	vector<int>::iterator reve = vec.end();
	for(; reve != vec.begin(); reve--)
		cout << *reve << ",";
	cout << endl;	
}

int main()
{
	vector_init();
	
	vector_opr();

	vector_iter();

	return 0;
}
