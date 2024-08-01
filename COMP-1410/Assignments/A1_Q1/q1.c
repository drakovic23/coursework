#include <stdio.h>
#include <assert.h>

//prototype
int choose(int n, int m);

int main() {
    //asserts for choose(n,m)
    assert(choose(4,2) == 6);
    //assert(choose(4,4) == 1);
    //assert(choose(6,2) == 15);
    //assert(choose(50,2) == 1225);
    return 0;
}

// choose(n,m) returns how many ways there are to choose m items from
// a set of n items
// requires: 0 <= m and 0 <= n
int choose(int n, int m)
{

    //base case
    if(m > n)
        return 0;
    //base case
    if(m == 0 || m == n)
        return 1;

    return choose(n - 1,m) + choose(n - 1,m - 1);
}
