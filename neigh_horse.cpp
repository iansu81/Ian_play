#include <iostream>
#include <string>
using namespace std;


int detect(string sound){
  int count = 0;
  int result = 0;
  for(char x: sound){
    if(x == 'n'){
      count++;
    }
    if(x == 'h'){
      count--;
    }
    result = max(result, count);
  }
  return result;
}


int main(){
  string input = "neighneigh";
  cout << detect(input) << endl;


}
