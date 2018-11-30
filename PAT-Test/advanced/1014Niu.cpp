#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct node
{
    int popTime, endTime;
    queue<int> q;
};

int main()
{
    int n, m, k, q;
    scanf("%d%d%d%d", &n, &m, &k, &q); //n个窗口，每个窗口可以排m人，一共K个人需要被服务，最后查询q个人的离开时间
    int index = 1;

    vector<int> time(k + 1), result(k + 1);
    for (int i = 1; i <= k; i++)
    {
        scanf("%d", &time[i]);
    }
    vector<node> window(n + 1);
    vector<bool> sorry(k + 1, false);

    for (int i = 1; i <= m; i++)
    { //铺满前 m*n 个人
        for (int j = 1; j <= n; j++)
        {
            if (index <= k)
            {
                window[j].q.push(time[index]);
                if (window[j].endTime >= 540)
                {
                    sorry[index] = true;
                }
                window[j].endTime += time[index];
                if (i == 1)
                {
                    window[j].popTime = window[j].endTime;
                }
                result[index] = window[j].endTime;
                index++;
            }
        }
    }

    while (index <= k)
    {
        int tempmin = window[1].popTime, tempWindow = 1;
        for (int i = 2; i <= n; i++)
        {
            if (window[i].popTime < tempmin)
            {
                tempmin = window[i].popTime;
                tempWindow = i;
            }
        }
        window[tempWindow].q.pop();
        window[tempWindow].q.push(time[index]);
        window[tempWindow].popTime += window[tempWindow].q.front();
        if (window[tempWindow].endTime >= 540)
        {
            sorry[index] = true;
        }
        window[tempWindow].endTime += time[index];
        result[index] = window[tempWindow].endTime;

        index++;
    }

    for (int i = 1; i <= q; i++)
    {
        int query, minutes;
        cin >> query;
        minutes = result[query];
        if (sorry[query] == true)
        {
            printf("Sorry\n");
        }
        else
        {
            printf("%02d:%02d\n", (minutes + 480) / 60, (minutes + 480) % 60);
        }
    }
    return 0;
}
