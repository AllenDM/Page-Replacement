#include <iostream>
#include <fstream>
#include <deque>
#include <queue>
#include <list>
using namespace std;

main ()
{
    list<int> list;
    
    list.push_front(4);
    list.push_front(5);
    list.remove(6);
    cout << list.front() << endl;
    cout << list.back() << endl;
    
    
    return 0;
}