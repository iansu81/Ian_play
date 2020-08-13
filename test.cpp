#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    vector<int> test{5,6,2,3,8,7,9};
    // swap(test[0], test[2]);
    // for(int i = 0; i < test.size(); i++)
    // {
    //     cout << test[i] << ',';
    // }
    sort(test.rbegin(), test.rend());
    for(int i = 0; i < test.size(); i++)
    {
        cout << test[i] << ',';
    }


}