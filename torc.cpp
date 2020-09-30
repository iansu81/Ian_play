
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;


int calculateCopies(string string1, string string2) {
    int j = 0;
    int ans = 1;
    for(int i = 0 ; i < string2.size(); i++)
    {
        if(j >= string1.length() )
        {
            cout << "ans : " << ans << endl;
            ++ans;
            j = 0;
        }
        while(string2[i] != string1[j])
        {
            cout << "I: " << i << endl;
            cout << "J: " << j << endl;
            
            cout << "1: " << string1[j] << endl;
            cout << "2: " << string2[i] <<endl;
            ++j;
            if(j >= string1.length() )
            {
                cout << "ans in while: " << ans << endl;
                ++ans;
                j = 0;
            }
        }
        ++j;


    }
    return ans;

}


int main()
{

    string A = "ABCD";
    string B = "DAD" ;
    cout << "Ans " << calculateCopies(A,B) << endl;

}