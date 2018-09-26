#include<iostream>

using namespace std;
main(int argc, char const *argv[])
{
    int n;
    cin >> n;
   
    int thisTime = 0;
    int temp1 = 0;
    int temp2;
    for(int i = 0;i<n;i++){
        
        cin >> temp2;
        if(temp2>temp1){
            thisTime =thisTime + 6*(temp2-temp1);
        }
        if(temp2<temp1){
            thisTime = thisTime +4 * (temp1 - temp2);
        }
        
        
        thisTime = thisTime+5;
        
        temp1 = temp2;



    }
    cout<< thisTime;
    return 0;
}
