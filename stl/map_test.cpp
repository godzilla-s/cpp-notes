#include <map>

void map_iter(map<char, int, less<char>> &ma)
{
	for (map<char, int, less<char>>::iterator it = ma.begin(); it != ma.end(); it++)
		cout << (*it).first << ":" << (*it).second << endl;
	cout << endl;
}
int map_test()
{
	map<char, int, less<char>> ma;
	ma['a'] = 10;
	ma['b'] = 11;
	ma['c'] = 12;

	map_iter(ma);

	return 0;
}
