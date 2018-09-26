#include<iostream>
#include<cmath>
using namespace std;

bool isPrime(int n){
    if(n<=1)return false;
    int sqt = int(sqrt(n*1.0));
    for(int i = 2;i<=sqt;i++){
        if(n%i==0)return false;
    }
    return true;
   
}

main(int argc, char const *argv[])
{
    int n,d;
    
    while(scanf("%d",&n) != EOF){
        if(n<0)break;
        scanf("%d",&d);
        if(!isPrime(n)){
            printf("No\n");
            continue;
        }
        int len = 0,arr[100];
        
        while(n!=0){
            arr[len++] = n%d;
            n = n/d;   
        }
        for(int i = 0;i<len;i++){
            n = n*d+arr[i];
        }
        printf("%s", isPrime(n) ? "Yes\n" : "No\n");
    }
    
   
    return 0;
}
