#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int i = 0;  
    vector<int> vec;  
    for (i = 0; i < 10; i++)  
    {  
        vec.push_back(i);  
    }  
  
    cout << "初始化遍历：" << endl;  
    for (int i = 0; i < vec.size(); i++)  
    {  
        cout << vec[i] << "\t";  
    }  
  
    cout << endl << "迭代遍历：" << endl;  
    vector<int>::iterator it;  
    for (it = vec.begin(); it != vec.end(); it++)  
    {  
        cout <<*it << " ";  
    }  
  
    cout << endl << "插入遍历：" << endl;  
    vec.insert(vec.begin() + 4, 0); 
    vec.insert(vec.begin() + 6, 12);
    for (int i = 0; i < vec.size(); i++)  
    {  
        cout<< vec[i] << "\t";  
    }  
  
    cout << endl << "擦除遍历：" << endl;  
    vec.erase(vec.begin() + 2);  
    for (unsigned int i = 0; i < vec.size(); i++)  
    {  
        cout << vec[i] << "\t";  
    }  
  
    cout << endl << "迭代遍历：" << endl;  
    vec.erase(vec.begin() + 3, vec.begin() + 5);  
    for (vector<int>::iterator it = vec.begin(); it != vec.end(); it++)  
    {  
        cout<< *it << "\t";  
    }  
    cout << endl;  
    return 0;  
}
