#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int G[550][550]; //图最多有550个城市
    int v, e;        //城市，路（测试用例的城市数和路数）
    int c1, c2;      //当前城市，目标城市
    cin >> v;

    for (int i = 0; i < 550; i++) //初始化城市间路的距离都是无穷大
    {
        for (int j = 0; j < 550; j++)
        {
            G[i][j] = 99999999;
        }
    }

    cin >> e;        //暂存路的个数；
    cin >> c1 >> c2; //暂存当前城市、目标城市

    int Weight[550]; //每个城市的救援队数量
    for (int i = 0; i < v; i++)
    {
        cin >> Weight[i];
    }

    int v1, v2;                 //路两头的城市
    int l;                      //路的长度
    for (int i = 0; i < e; i++) //将测试用例的路长覆盖掉初始路长
    {
        cin >> v1 >> v2 >> l;
        G[v1][v2] = l;
        G[v2][v1] = l;
    }

    /* 图初始化完毕 */

    /* Dijkstra算法开始 */

    int dis[510]; //初始化dis[i]：从出发点到i结点最短路径的路径长度为999999
    const int inf = 999999;
    for (int i = 0; i < 510; i++)
    {
        dis[i] = inf;
    }

    dis[c1] = 0;
    int w[550]; // w[i]：从出发点到i点救援队的数目之和
    w[c1] = Weight[c1];
    int num[510]; //num[i]：从出发点到i结点最短路径的条数
    num[c1] = 1;
    bool visit[510];
    for (int i = 0; i < v; i++)
    { //遍历所有城市，找未收录的城市里是否有dis最小者；

        int u = -1, minn = inf; //u为未访问的节点，minn为i到j的最小距离
        for (int j = 0; j < v; j++)
        {                                           //遍历除i节点外的所有节点
            if (visit[j] == false && dis[j] < minn) //如果当前节点j没有被访问过且i到j的dis小于dis的最小值
            {
                u = j;         //将当前城市赋值给U，下一个被访问的节点点就是U了；
                minn = dis[j]; //更新最小值；
            }
        }
        if (u == -1)
            break; //如果没有找到未收录的城市里有dis最小的城市，则证明遍历完毕；

        visit[u] = true; //将u城市标注为已访问过；
        for (int i = 0; i < v; i++)     //遍历城市，找出u到其他城市的最短路径
        {
            if (visit[i] == false && G[u][i] != inf)    //如果当前城市i没有被访问过并且u到i的距离不是初始值的无穷大（图里的空节点）
            {
                if (dis[u] + G[u][i] < dis[i])          //如果从出发点到u的距离+u到i的距离<出发点到i的距离
                {
                    dis[i] = dis[u] + G[u][i];          //则更新出发点到i的最短距离为经过u到达i；
                    num[i] = num[u];                    //更新到达i的路径数 =到达u的路径数
                    w[i] = w[u] + Weight[i];            //可以召集的总救援队数更新为在到达u的总救援队数+城市i的救援队数
                }
                else if (dis[u] + G[u][i] == dis[i])    //如果从出发点到u的距离+u到i的距离 = 出发点到i的距离
                {

                    num[i] = num[i] + num[u];           //更新到达城市i的路数 = 到达城市i的初始路径数+经过u到达i的路径数
                    if (w[i] < Weight[i] + w[u])         //如果从出发点到达i召集的总人数<经过u到达i的总人数
                    {
                        w[i] = Weight[i] + w[u];          //更新从出发点到达i召集的总人数为经过u到达i的总人数
                    }
                }
            }
        }
    }
    printf("%d %d", num[c2], w[c2]);

    return 0;
}
