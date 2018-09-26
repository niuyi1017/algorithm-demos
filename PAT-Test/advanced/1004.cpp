#include <iostream>
#include <vector>//容器
#include <algorithm>


using namespace std;

vector<int> v[100];//容器数组，每一个数组元素都是一个容器，每一个容器又可以看作是是一个动态数组
int book[100],maxdeep = -1;//book暂存该层叶子节点数，maxdeep用于输出是的for循环

void dfs(int index,int depth){
    if(v[index].size() == 0){//如果当前容器的size == 0，则证明其下没有子节点，即为叶子节点
        book[depth]++;//遇到叶子节点就在book数组的该层+1
        maxdeep = max(depth,maxdeep);//maxdeep 为当前访问层与默认最大层的最大值
        return ;
    }
    for(int i = 0;i<v[index].size();i++){//当当前访问的节点有子节点时，逐个访问其子节点
        dfs(v[index][i],depth+1);//以dfs的方式访问当前节点的其中一个子节点的下一层，
    }
}

int main(int argc, char const *argv[])
{
    int n,m,k,node,c;
    scanf("%d %d",&n,&m);
    for(int i = 0;i<m;i++){
        scanf("%d %d",&node,&k);
        for (int j = 0;j < k;j++){
            scanf("%d",&c);
            v[node].push_back(c);//node为当前节点的id，v[node]中储存的值为其子节点的id
        }

    }

    dfs(1,0);//从第一个节点（根节点）第0层开始dfs遍历

    printf("%d",book[0]);
    for(int i = 1;i<=maxdeep;i++){
        printf(" %d",book[i]);
    }

    return 0;
}


