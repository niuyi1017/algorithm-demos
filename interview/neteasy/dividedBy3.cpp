#include <iostream>
using namespace std;
int isThree(int n){
    int temp;
    if(n%3 !=0){
        temp = (n/3)*2+(n%3-1);
    }
    else
    {
        temp = n/3*2;
    }
    return temp;
    
}
int  main(int argc, char const *argv[])
{
    int l,r;
    int count = 0;
    cin >>l>>r;
    count = isThree(r)-isThree(l-1);
    cout << count;
}
// return 0;
