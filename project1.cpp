#include <iostream>
#include<vector>
#include<algorithm>

using namespace std;

int partition(vector<int> input_arry, int left, int right, int k){
    int pivot = input_arry[right];
    int i = left;
    for(int j = left; j < (right - 1); j++)
    {
        if( pivot >=input_arry[j])
        {
            swap(input_arry[i], input_arry[j]);
            i++;
        }
    }
    swap(input_arry[i], pivot);
    return i;


}



int kth_largest_search(vector<int>& input_arry, int left, int right, int k){

    int index = partition(input_arry,left, right, k);
    if(index == k){
        return input_arry[index];
    }
    else if(index > k){
        return kth_largest_search(input_arry, left, index -1, k);
    }
    else{
        return kth_largest_search(input_arry, index+1, right, k);
    }
}


int kth_largest(vector<int> input_arry, int k)
{
    return kth_largest_search(input_arry, 0, input_arry.size()-1, k);

}




int main(){

    vector<int> test{1,2,3,4,5,6,7};
    cout << kth_largest(test, 3) << endl;

} 