#include <vector>
#include <iostream>
using namespace std;

int main()
{
    vector<int> test{5,4,3};
    swap(test[0], test[2]);
    for(int i = 0; i < test.size(); i++)
    {
        cout << test[i] << ',';
    }
}