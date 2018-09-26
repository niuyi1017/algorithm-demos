#include <cstdio>
#include <algorithm>

using namespace std;

struct node
{
    int id, best;
    int score[4], rank[4];
} stu[2005];
int exist[1000000], flag = -1;
bool cmpl(node a, node b) { return a.score[flag] > b.score[flag]; }

int main(int argc, char const *argv[])
{
    int n, m, id;
    //cin >> n >> m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d %d %d", &stu[i].id, &stu[i].score[1], &stu[i].score[2], &stu[i].score[3]);
        stu[i].score[0] = (stu[i].score[1] + stu[i].score[2] + stu[i].score[3]) / 3.0 + 0.5;
    }
    for (flag = 0; flag <= 3; flag++) //循环完毕，四科均排好序
    {
        sort(stu, stu + n, cmpl);   //将n个学生按照当前学科成绩从大到小排序
        stu[0].rank[flag] = 1;      //排完序后第一个学生的当前学科排名为1
        for (int i = 1; i < n; i++) //当前学科排名依次排序，特殊处理名次并列（成绩相等，名次相等）
        {
            stu[i].rank[flag] = i + 1;
            if (stu[i].score[flag] == stu[i - 1].score[flag])
            {
                stu[i].rank[flag] = stu[i - 1].rank[flag];
            }
        }
    }

    for (int i = 0; i < n; i++) //遍历n个学生
    {
        exist[stu[i].id] = i + 1;  //学号作为exist数组的下标，i+1作为下标为exist数组中学号的值 => 数组中值不为0的均有学生存在
        stu[i].best = 0;           //当前学生的排名最好的科目代码为0
        int minn = stu[i].rank[0]; //minn为当前学生的四个科目里排名最好的名次，遍历寻找
        for (int j = 1; j <= 3; j++)
        {
            if (stu[i].rank[j] < minn)
            {
                minn = stu[i].rank[j];
                stu[i].best = j;
            }
        }
    }
    char c[5] = {'A', 'C', 'M', 'E'};
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &id);
        int temp = exist[id];
        if (temp)
        {
            int best = stu[temp - 1].best; //best 为排名最好的科目的代码
            printf("%d %c\n", stu[temp - 1].rank[best], c[best]);
        }
        else
        {
            printf("N/A\n");
        }
    }
    return 0;
}
