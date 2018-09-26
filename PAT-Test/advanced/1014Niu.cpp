#include<iostream>

using namespace std;

int B[25][1010] = {0};//bank;
int T[1010] = {0};//Time
int TotalTime[25] = {0};


int main(int argc, char const *argv[])
{
    int n,m,k,q;
    cin>>n>>m>>k>>q;
    
    for(int  i = 1; i <=k; i++)
    {
       cin>>T[i];
    }

    for(int i = 1;i<=k;i++){
       
        if (i <= n * m)
        {
            int temp = i % n;
            B[temp][i] = T[i];
            cout << "B[temp][i] = " << B[temp][i]<<endl;
       }
       else
       {
           for (int j = 0; j < n; j++)
           {
               for (int a = 0; a < m; a++)
               {
                   TotalTime[j] += B[j][a];
               }
               cout <<j<< "  TotalTime = " << TotalTime[j]<<endl;
           }

           int minIndex = 0;
           for(int j = 0;j<n;j++){
               if(TotalTime[j]<=TotalTime[minIndex]){
                   minIndex = j;
               }
           }
           B[minIndex][i] = T[i];
           cout << "B[minIndex][i] = " << B[minIndex][i] << endl;
       }
       
       
    }
    int check[1008];
    for (int i = 1; i <= q; i++)
    {
        cin>>check[i];
    }
    int index,winIndex,pTime;
    for(int i = 1;i<=q;i++){
        winIndex = check[i]%n;
        for(int j = 0;j<=check[j];j++){
            pTime +=B[winIndex][j]; 
            
        }
        cout << pTime << " ";
    }

    return 0;
}
