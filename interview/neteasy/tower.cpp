#include<iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    int t[1010];
    int maxIndex, minIndex;
    int n,k;
    int max = 0;
    int min = 0;
    int big,small;
    int count = 0;
   
    for(int i = i;i<=n;i++){

        cin >> t[i];
    }
   
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=n;j++){
            if(t[i]>max){
                max = t[j];
                maxIndex = j;
               
            }if(t[i]<min){
                min = t[j];
                minIndex = j;
                
            }
        }
        t[minIndex]++;
        t[maxIndex]--;
        
    }
    return 0;
}
