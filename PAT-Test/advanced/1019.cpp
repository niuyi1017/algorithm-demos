#include<iostream>
#include<vector>
using namespace std;

int main(){

  int num, d;
  cin>>num>>d;
  vector<int> arr;
  while (num != 0)
  {
    arr.push_back(num % d);
    num = num / d;
  }
  
  int length = arr.size();
  
  bool flag = true;
  for (int i = 0; i <length/2; i++)
  {
    if(arr[i] != arr[length-1-i]){
      flag = false;
      break;
    }
  }
  if(flag){
    cout<<"Yes"<<endl;
    for(int i=0;i<length-1;i++){
      printf("%d ",arr[i]);
    }
    printf("%d", arr[length-1]);
  }else{
    cout << "No" << endl;
    for (int i = length-1; i > 0; i--)
    {
      printf("%d ", arr[i]);
    }
    printf("%d", arr[0]);
  }
  return 0;
}