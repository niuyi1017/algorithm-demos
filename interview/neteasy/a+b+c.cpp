#include<iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    int a,b,c;
    cin>>a>>b>>c;
    int max = 0;
    int min,mid;
    
    if(a>=b&&a>=c){
        max = a;
        if(b>=c){
            mid = b;
            min = c;
        }
        else
        {
            mid = c;
            min = b;
        }
        
    }
    if (b >= a && b >= c)
    {
        max = b;
        if (a >= c)
        {
            mid = a;
            min = c;
        }
        else
        {
            mid = c;
            min = a;
        }
    }
    if (c >= b && c >= a)
    {
        max = c;
        if (b >= a)
        {
            mid = b;
            min = a;
        }
        else
        {
            mid = a;
            min = b;
        }
    }

   int x = (min+mid)*max;
   int y = min*mid*max;
   if(x>y){
       cout <<x;
   }else{
       cout<<y;
   }
   
//    int y = (min+max)*mid;
//    int z = (mid+max)*min;;
//    int m = ()
    
    return 0;
}
