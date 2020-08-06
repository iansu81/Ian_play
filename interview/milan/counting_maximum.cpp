#include <iostream>
#include <vector>
#include <unordered_map>

using namespace::std;
class Soulution{
    public:
        vector<int> counting_max(vector<int> arr){
        
            vector<int> result{1};
            int max_count = 1;
            int max = arr[arr.size()-1];
            
            
            for( vector<int>::iterator it = (arr.end() - 2) ; it != (arr.begin() -1); it--){
                if(*it > max){
                    max = *it;
                    max_count = 1;
                }
                else if(*it == max){
                    max_count++;
                }
                vector<int>::iterator result_it = result.begin();
                result.insert(result_it, max_count);
            }
            return result;
        }


};


int main(){
    vector<int> test{5,4,5,3,2};
    Soulution sol;
    vector<int> result = sol.counting_max(test);
    for(auto const& item: result){
        cout << item << ", ";
    }

}