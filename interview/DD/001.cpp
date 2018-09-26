#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int map[1000][1000] = {0};

    int row, col;
    int times;
    cin >> row >> col >> times;
    int r, c;
    int count = 0;
    vector<int> result(times);
    for (int i = 0; i < times; i++)
    {
        cin >> r >> c;
        if (r >= row || c >= col)
        {
            result[i] = count;
            continue;
        }else{
            if (map[r][c] == 1)
            {
                result[i] = count;
                continue;
            }
            else
            {
                map[r][c] = 1;
            }
        }
       
       
       

        if (r == 0)
        {
            if (c == 0)
            {
                if (map[r + 1][c] != 1 && map[r][c + 1] != 1)
                {
                    count++;
                    result[i] = count;
                }
                else
                {
                    result[i] = count;
                }
            }
            else
            {
                if (map[r + 1][c] != 1 && map[r][c + 1] != 1 && map[r][c - 1] != 1)
                {
                    count++;
                    result[i] = count;
                }
                else
                {
                    result[i] = count;
                }
            }
        }
        else
        {
            if (c == 0)
            {
                if (map[r + 1][c] != 1 && map[r][c + 1] != 1 && map[r][c - 1] != 1)
                {
                    count++;
                    result[i] = count;
                }
                else
                {
                    result[i] = count;
                }
            }

            else
            {
                if (map[r - 1][c] != 1 && map[r + 1][c] != 1 && map[r][c + 1] != 1 && map[r][c - 1] != 1)
                {
                    count++;
                    result[i] = count;
                }
                else
                {
                    result[i] = count;
                }
            }
        }
    }
    for (int i = 0; i < times; i++)
    {
        if (i != (times - 1))
        {
            cout << result[i] << " ";
        }
        else
        {
            cout << result[i];
        }
    }
}