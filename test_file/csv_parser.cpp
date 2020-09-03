#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <iomanip>
using namespace std;

int main()
{

    fstream fin;
    fin.open("data_tib.csv", ios::in);
    vector<string> row;
    string temp, word;
    vector<float> ans;
    while (fin >> temp)
    {

        row.clear();

        stringstream s(temp);

        while (getline(s, word, ','))
        {
            row.push_back(word);
        }
        ans.push_back(stof(row[13]));

    }
    for(int i = 0; i < ans.size(); i++)
    {
        cout << "ans: " << std::setprecision(9) << ans[i] << endl;
    }
}