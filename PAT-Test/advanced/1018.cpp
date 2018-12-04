#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

const int inf = 999999999;
int cmax, n, sp, m;// n 车站， sp问题车站，  m条边
int minNeed = inf, minBack =inf;
int e[510][510], dis[510], weight[510];
bool visit[510];
vector<int> pre[510];
vector<int> path, temppath;
int main(int argc, char const *argv[])
{
  fill(e[0],e[0]+510*510,inf);
  fill(dis,dis+510,inf);
  scanf("%d%d%d%d", &cmax, &n, &sp, &m);
  // for (int i = 1; i <= n; i++)
  // {
  //   scanf("%d", &weight[i]);
  //   weight[i] = weight[i] - cmax / 2;
  // }
  return 0;
}
