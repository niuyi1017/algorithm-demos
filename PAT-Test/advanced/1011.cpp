#include <iostream>

using namespace std;



main(int argc, char const *argv[])
{   
    char arr[3];
    float temp = 1;
    float sum = 0;
    for (int i = 0;i<3;i++){
        float n1, n2, n3;
        float max = 0.0;
        cin >> n1 >> n2 >> n3;
        if(n1>=n2&&n1>=n3){
            max = n1;
            arr[i] = 'W';
        }
        if (n2 >= n1 && n2 >= n3)
        {
            max = n2;
            arr[i] = 'T';
        }
        if (n3 >= n2 && n3 >= n1)
        {
            max = n3;
            arr[i] = 'L';
        }

        temp =temp * max;
    }
    sum = (temp * 0.65-1) * 2;
    for(int i = 0;i<3;i++){
        cout<<arr[i]<<' ';
    }
    printf("%.2f",sum);
    return 0;
}
