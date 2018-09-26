#include<iostream>
#include<vector>
#include<queue>

using namespace std;

struct node
{
    int popTime,endTime;
    queue<int> q;
};

int main(int argc, char const *argv[])
{
    int n,m,k,q;
    cin>>n>>m>>k>>q;//n个窗口，每个窗口可以排m人，一共K个人需要被服务，最后查询q个人的离开事件
    int index = 1;

    vector<int> time(k+1),result(k+1);
    for(int i = 1;i<= k;i++){
        cin>>time[i];
    }

    vector<node> window(n+1);
    vector<bool> sorry(k+1,false);
    


    return 0;
}
