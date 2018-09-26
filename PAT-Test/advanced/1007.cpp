
#include <stdio.h>
#include <stdlib.h>

int MaxSubsequSum(int List[], int N)
{

    int i;
    int ThisSum, MaxSum;

    int h = List[0];
    int e = List[N - 1];
    int tempindex = 0;

    ThisSum = 0;
    MaxSum = -1;

    for (i = 0; i < N; i++)
    {
        ThisSum += List[i];

        if (ThisSum > MaxSum)
        {
            MaxSum = ThisSum;
            h = List[tempindex];
            e = List[i];
        }
        else if (ThisSum < 0)
        {
            ThisSum = 0;
            tempindex = i+1;
           
        }
    }
    if(MaxSum<0){
        MaxSum = 0;
    }
    printf("%d ", MaxSum);
    printf("%d ", h);
    printf("%d", e);
    return 0;
}

int main()
{
    int *p;
    int i, n;

    scanf("%d", &n);
    p = (int *)malloc(n * sizeof(int));

    for (i = 0; i < n; i++)
    {
        scanf("%d", p + i);
    }
    MaxSubsequSum(p, n);

    free(p);
    return 0;
}