#include <iostream>
#include <vector>

using namespace std;

class A
{
    public:
        A() { cout << "ctor " << endl; }
        A( const A& a ) { cout << "copy ctor " << endl; }
        A( A&& a )
}