#include <iostream>
#include <math.h>
using namespace std;
int main()
{
    int n;
    int i = 0;
   cin >> n;
   while(n!=1){
       if(n%2==0){  
          if(n==0)
            break;
         n = n/2; 
       }else{
           n= (3*n+1)/2;
       }
     i++;
    
   }
   cout<<i<<endl;
}