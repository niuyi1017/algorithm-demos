#include <iostream>
#include <string>
#include<vector>
using namespace std;

int  main(int argc, char const *argv[])
{
   int n;
   cin>>n;
   vector<long> arr(n);

   for(int i = 0;i<n;i++){
       cin>>arr[i];
   }
   for(int i =0;i<n;i++){
       int sum = 0;
       int val = arr[i];
       int s = arr[i];
       int y = 0;
       for(int j = 0; j < 9; j++)
       {
          
           if (s >= 10)
           {
               y = s % 10;
               s = s / 10;
               if(s<10){
                   sum = sum+s+y;
                   break;
               }else{
                   sum = sum + y;
               }
              
              
           }
        //   else
        //    {
        //        sum = sum  + s;
        //        break;
        //    }
           //    else
           //    {

           //        break;
           //    }
        }
    //    if(sum != 0){

       
        if(val%sum==0){
            cout<<"Yse"<<endl;
        }
        else
        {
            cout << "No" << endl;
        }
    //    }else{
    //        if(val==0){
    //            cout << "Yse" << endl;
    //        }
    //        else
    //        {
    //            cout << "No" << endl;
    //        }
           
    //    }
       
   }
    return 0;
}
