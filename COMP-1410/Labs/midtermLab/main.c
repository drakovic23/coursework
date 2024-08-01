#include <stdio.h>
#include <assert.h>

int count_ones(int n);
int count_ones_up_to_n(int n);
void row_sums(int n, int m, int matrix[][10], int * sums);

int main()
{

    assert(count_ones(1231) == 2);
    assert(count_ones(113451) == 3);
    assert(count_ones(1) == 1);

    //printf("%d\n", count_ones_up_to_n(19));

    int matrix[5][10] = {
            {1,2,3,4,5,6,7,8,9,10},
            {5,4,3,2,1,-1,-2,-3,-4,-5},
            {10,9,8,7,6,5,4,3,2,1},
            {7,7,7,7,7,7,7,7,7},
            {5,5,5,5,5,5,5,5}

    };

    int m2[3][10] = {
            {1,2,3},
            {4,5,6},
            {7,8,9}
    };
    int sum[3] = {};
    row_sums(3,3, m2, sum);

    //print
    for(int x=0; x < 3;x++)
    {
        printf("%d ",sum[x]);
    }
    return 0;
}

int count_ones(int n)
{
    if(n == 0)
        return 0;
    if(n % 10 == 1)
        return 1 + count_ones(n / 10);

    return count_ones(n / 10);
}

int count_ones_up_to_n(int n)
{
    if(n == 0)
        return 0;
    if(count_ones(n) > 0)
        return count_ones(n) + count_ones_up_to_n(n - 1);

    return count_ones_up_to_n(n - 1);

}

void row_sums(int n, int m, int matrix[][10], int * sums)
{
    for(int x = 0; x < n; x++)
    {
        for(int i=0; i < m; i++)
        {
            *(sums + x) += *(*(matrix + x) + i); //matrix[x][i] = *(*(matrix + x) + i;
        }
    }
}
