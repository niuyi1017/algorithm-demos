#include<iostream>
#include<math.h>

using namespace std;

int sumC(int num,int day ){
    int sum = 0;
    for(int i =1;i<=day;i++){
        sum = sum+num;
        num = (int)ceil((double)num / 2);
    }
    return sum;
}
int main(int argc, char const *argv[])
{
    /* code */


    int day,total;
    cin >>day>>total;

    if(day ==total){
        cout<<1;
    }
    int first = 1;
    int last = total;
    int sum = 0;
    int mid = (first+last)/2;
    int result = 0;
    while(first<=last){
        sum = sumC(mid,day);
        if(sum>total){
            last = mid-1;
        }else if(sum ==total){
           
            result = mid;
            break;
        }else{
            first = mid + 1;
        }

        mid = (first+last)/2;
      
    }
    result = mid;
    cout<<result;

    return 0;
}
