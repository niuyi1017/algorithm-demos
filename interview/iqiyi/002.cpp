#include<iostream>

using namespace std;
int res(int n){
    if(n==1){
        return 2;
    }else if(n==2){
        return 3;
    }
    else{
        return (res(n-1)+res(n-2));
    }
}
int main(){
int n;
cin>>n;
cout<<res(n);

return 0;
}