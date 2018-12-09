#include<iostream>
#include<vector>
#include<set>

using namespace std;

int n, maxHeight;//n 节点个数，
vector<vector<int>> v;//类似二维数组，V为整个图，V里的每一个元素是一个节点，每个节点又储存这和这个节点想连的其他节点；
bool visit[10010];
vector<int> temp;
set<int> s;

void dfs(int node, int height){
  if(height > maxHeight){
    temp.clear();
    temp.push_back(node);
    maxHeight = height;
  }
  else if(maxHeight == height){
    temp.push_back(node);
  }
  visit[node] = true;
  for(int i =0;i<v[node].size();i++){
    if(visit[v[node][i]] == false){
      dfs(v[node][i],height+1);
    }
  }
}
int main(){
  scanf("%d", &n);
  v.resize(n+1);
  int a,b,cnt=0,s1=0;
  for(int i = 0;i<n-1;i++){
    scanf("%d%d",&a,&b);
    v[a].push_back(b);
    v[b].push_back(a);
  }
  for(int i =1;i<=n;i++){
    if(visit[i] == false){
      dfs(i, 1);
      if(i==1){
        if(temp.size() != 0){
          s1=temp[0];
        }
        for(int j = 0;j<temp.size();j++){
          s.insert(temp[j]);
        }
      }
      cnt ++;
    }
  }
  if(cnt >= 2){
    printf("Error: %d components", cnt);
  }
  else
  {
    temp.clear();
    maxHeight = 0;
    fill(visit,visit+10010,false);
    dfs(s1,1);
    for(int i=0; i< temp.size();i++)
      s.insert(temp[i]);
    for(auto it =s.begin();it !=s.end();it++){
      printf("%d\n",*it);
    }
  }
  
  return 0;
}
//20181209PAT