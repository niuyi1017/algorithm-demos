#include <iostream>
#include <algorithm>

using namespace std;

bool visit[1010];
int cities[1010][1010];
int n;
void dfs(int node)
{
    visit[node] = true;
    for (int i = 1; i <= n; i++)
    {
        if (visit[i] == false && cities[node][i] == 1)
        {
            dfs(i);
        }
    }
}

int main(int argc, char const *argv[])
{
    int m, k,a,b;
    cin >> n >> m >> k;
   
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        cities[a][b] = cities[b][a] = 1;
    }

    for (int i = 0; i < k; i++)
    {
        fill(visit, visit + 1010, false);
       
        cin >> a;
        int cnt = 0;
        visit[a] = true;

        for (int j = 1; j <= n; j++)
        {
            if (visit[j] == false)
            {
                dfs(j);
                cnt++;
            }
        }
        
        cout << cnt - 1 << endl;
       
    }

    return 0;
}
