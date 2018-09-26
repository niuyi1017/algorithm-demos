#include <iostream>
#include <math.h>
#include <string>
using namespace std;
int main()
{
    long long n;
    string s[10] = { "ling","yi","er","san","si","wu","liu","qi","ba","jiu" };
    cin>>n;
    int sum =0;
   for(int i =0;i<101;i++){
       sum = sum + n % 10;
       n=n/10;
   }
   string num[2];
   cout << sum<<endl;
   for(int i=0;i<3;i++){
       num[2-i] = s[sum%10];
       sum = sum/10;
   }
     for(int i = 0;i<2;i++) {
         cout << num[i];
     }
      
}
