#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
struct node
{
  int come, time;
} tempCustomer;

bool cmpl(node a, node b)
{
  return a.come < b.come;
}
int main()
{
  int n, k;
  cin >> n >> k;
  vector<node> customs;
  for (int i = 0; i < n; i++)
  {
    int hh, mm, ss, time;
    scanf("%d:%d:%d %d", &hh,&mm,&ss,&time);
    int cometime = hh * 3600 + mm * 60 + ss;
    if (cometime > 61200)
    {
      continue;
    }
    tempCustomer = {cometime, time * 60};
    customs.push_back(tempCustomer);
  }
  sort(customs.begin(), customs.end(), cmpl);

  vector<int> windows(k, 28800);
  double result = 0.0;
  for (int i = 0; i < customs.size(); i++)
  {
    int tempIndex = 0, minFinish = windows[0];
    for (int j = 1; j < k; j++)
    {
      if (minFinish > windows[j])
      {
        minFinish = windows[j];
        tempIndex = j;
      }
    }
    if (windows[tempIndex] <= customs[i].come)
    {
      windows[tempIndex] = customs[i].come + customs[i].time;
    }
    else
    {
      result += (windows[tempIndex] - customs[i].come);
      windows[tempIndex] += customs[i].time;
    }
  }

  if (customs.size() == 0)
  {
    printf("0.0");
  }
  else
  {
    printf("%.1f", result / 60.0 / customs.size());
  }
  return 0;
}
