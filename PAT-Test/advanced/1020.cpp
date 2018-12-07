#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct node
{
  int index;
  int value;
};

vector<node> ans;
vector<int> post;
vector<int> in;

bool cmp(node a, node b){
  return a.index < b.index;
}
void pre(int root, int start, int end, int index ){
  if( start > end){
    return;
  }
  int i = start;
  while(i < end && in[i] != post[root]){
    i++;
  }
  ans.push_back({index, post[root]});
  pre(root-(end-i+1),start,i-1,2*index+1);
  pre(root - 1, i+1, end, 2 * index + 2);
}
int main(){
  int n;
  scanf("%d",&n);
  post.resize(n);
  in.resize(n);
  for(int i = 0;i<n;i++){
    scanf("%d",&post[i]);
  }
  for(int i = 0;i<n;i++){
    scanf("%d",&in[i]);
  }
  pre(n-1,0,n-1,0);
  sort(ans.begin(),ans.end(),cmp);
  for(int i= 0;i<ans.size();i++){
    if(i !=0 ){
      cout<< " ";
    }
    cout<<ans[i].value;
  }
  return 0;
}