#include<iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    char c[4] = {'N','E','S','W'};
    int n;
    char d;
    cin >>n;
    int count = 0;
    for(int i = 0;i<n;i++){
        cin >>d;
        if (d == 'R'){
            count++;
        }
        else
        {
            count--;
        }
        
    }
    // cout<< count%4<<endl;
    if(count <0){
        cout << c[4 + count % 4];
    }
    else
    {
        cout << c[count % 4];
    }
    
    
    return 0;
}
