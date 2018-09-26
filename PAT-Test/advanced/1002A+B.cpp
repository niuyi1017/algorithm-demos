/*

17/25分；
测试点1、3、4、5未通过；

*/

#include<iostream>

using namespace std;

struct polynomia
{
    int ex; //指数
    float co;//系数
    /* data */
};

int main(int argc, char const *argv[])
{
    
    int m,n;//每行多项式的个数；
    cin >> m;
    polynomia marr[1001];
    for(int i = 0;i<m;i++){
        polynomia temp;
        cin >> temp.ex;
        cin >> temp.co;
      
        marr[i] = temp;
    }

    cin >> n;
    polynomia narr[1001];
    for (int i = 0; i < n; i++)
    {
        polynomia temp;
        cin >> temp.ex;
        cin >> temp.co;
        

        narr[i] = temp;
    }
    polynomia carr[1001] = {0};

    int i = 0,j = 0;
    for(int k = 0;k<1001;k++){
        
        polynomia temp;
        if(marr[i].ex == narr[j].ex){
            temp.ex = marr[i].ex;
            temp.co = marr[i].co + narr[j].co;
            i++;
            j++;
        }
        else if (marr[i].ex > narr[j].ex)
        {
            temp.ex = marr[i].ex;
            temp.co = marr[i].co;
            i++;

            /* code */
        }
        else 
        {
            temp.ex = narr[j].ex;
            temp.co = narr[j].co;
            j++;

            /* code */
        }

        if(temp.co == 0){
            continue;
        }
        else
        {
            carr[k] = temp;
        }
        
    }
    int num = 0;
    int p = m+n;
    for (int i = 0; i < p && carr[i].co != 0.0; i++)
    {
       
            num++;
    }
    cout<< (num);
    for (int i = 0; i < num; i++)
    {
        printf(" %d %.1f", carr[i].ex, carr[i].co);
        //系数改为只保留一位小数输出，测试点1、5可通过
    }

    /* code */
    return 0;
}

