#include <iostream>
#include <string>
#include <list>
using namespace std;
 
void PrintIt(list<int> n)
{
    for(list<int>::iterator iter=n.begin(); iter!=n.end(); ++iter)
      cout<<*iter<<" ";//用迭代器进行输出循环
}
// List 构造函数:
// list() 声明一个空列表；
// list(n) 声明一个有n个元素的列表，每个元素都是由其默认构造函数T()构造出来的
// list(n, val) 声明一个由n个元素的列表，每个元素都是由其复制构造函数T(val)得来的
// list(n, val) 声明一个和上面一样的列表
// list(first, last) 声明一个列表，其元素的初始值来源于由区间所指定的序列中的元素

int main()
{
    list<int> listn1,listn2;    //给listn1,listn2初始化
    listn1.push_back(123);
    listn1.push_back(0);
    listn1.push_back(34);
    listn1.push_back(1123);    //now listn1:123,0,34,1123
    listn2.push_back(100);
    listn2.push_back(12);    //now listn2:12,100
    listn1.sort();
    listn2.sort();    //给listn1和listn2排序

	PrintIt(listn1);
    cout<<endl;
    PrintIt(listn2);
    listn1.merge(listn2);    //合并两个排序列表后,listn1:0，12，34，100，123，1123
    cout<<endl;
    PrintIt(listn1);
}
