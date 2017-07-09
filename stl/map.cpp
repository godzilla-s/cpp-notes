#include <iostream>
#include <map>

using namespace std;

template <class T1, class T2>
void iter(map<T1, T2> m)
{
	map<char, int>::iterator iter = m.begin();
	;
}

void print(map<int, int> a)
{
	cout << "map size: " << a.size() << endl;
	map<int, int>::iterator iter = a.begin();
	for(; iter != a.end(); iter++)
		cout << iter->first << ":" << iter->second << ", ";
	cout << endl;
}

void map_init()
{
	map<int, int> m1;
	
	for(int i=0; i<10; i++)
		m1[i] = i * 10;

	print(m1);	
}

void map_opr()
{
	map<char, int> m;
	map<char, int>::iterator iter;
	m['a'] = 11;
	m['b'] = 12;
	m['c'] = 13;
	m['d'] = 14;

	iter = m.find('a');
	cout << iter->first << ":" << iter->second << endl;
	//删除：erase
	m.erase('b');
	
	//m.erase(iter, m.end());	
}

int main()
{
	map_init();

	map_opr();

	return 0;
}
