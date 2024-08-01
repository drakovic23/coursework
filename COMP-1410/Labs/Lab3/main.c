#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

bool matrix_equals(const int n, const int m, const int * a, const int * b);
void negate_row(const int n, const int m, int * a, const int r);
void negate_col(const int n, const int m, int * a, const int c);
void matrix_add(const int n, const int m, const int * a, const int * b, int * c);

int main()
{
    int a1[2][3] = {{0, 1, 2}, {3, 4, 5}};
    int a2[2][3] = {{0, 1, 2}, {3, 4, 5}};
    int a3[2][3] = {{0, -1, 2}, {3, -4, 5}};

    int b1[4][3] = {{0, 1, 2}, {3, 4, 5}, {6, 7, 8}, {9, 10, 11}};
    int b2[4][3] = {{0, 1, 2}, {3, 4, 5}, {6, 7, 8}, {9, 10, 11}};
    int b3[4][3] = {{0, 1, -2}, {3, 4, -5}, {6, 7, -8}, {9, 10, -11}};

    int c1[3][4] = {{0, 1, 2, 3}, {4, 5, 6, 7}, {8, 9, 10, 11}};
    int c2[3][4] = {{0, 1, 2, 3}, {4, 5, 6, 7}, {8, 9, 10, 11}};
    int c3[3][4] = {{0, 1, 2, 3}, {-4, -5, -6, -7}, {8, 9, 10, 11}};

    //Testing matrix_equals
    assert(matrix_equals(2,3,&a1[0][0], &a2[0][0]));
    assert(!matrix_equals(2,3,&a1[0][0], &a3[0][0]));

    assert(matrix_equals(4,3,&b1[0][0], &b2[0][0]));
    assert(!matrix_equals(4,3,&b1[0][0], &b3[0][0]));

    assert(matrix_equals(3,4, &c1[0][0], &c2[0][0]));
    assert(!matrix_equals(3,4, &c1[0][0], &c3[0][0]));

    //Testing negate_col
    negate_col(2, 3, &a3[0][0], 1);
    assert(matrix_equals(2,3,&a1[0][0], &a3[0][0]));
    negate_col(2, 3, &a3[0][0], 1);
    assert(!matrix_equals(2,3,&a1[0][0], &a3[0][0]));

    negate_col(4, 3, &b3[0][0], 2);
    assert(matrix_equals(4,2,&b1[0][0], &b3[0][0]));
    negate_col(4, 3, &b3[0][0], 2);
    assert(!matrix_equals(4,2,&b1[0][0], &b3[0][0]));

    //Testing negate_row
    negate_row(3, 4, &c3[0][0], 1);
    assert(matrix_equals(3, 4, &c1[0][0], &c3[0][0]));
    negate_row(3, 4, &c3[0][0], 1);
    assert(!matrix_equals(3, 4, &c1[0][0], &c3[0][0]));


    //Test matrix_add
    int d[3][2] = { {1,3}, {1,0}, {1,2} };
    int d2[3][2] = { {0,0}, {7,5}, {2,1} };
    int empty_matrix[3][2] = {};
    int expected_sum[3][2] = { {1,3}, {8,5}, {3,3} };
    matrix_add(3,2,&d[0][0],&d2[0][0],&empty_matrix[0][0]);
    assert(matrix_equals(3,2,&empty_matrix[0][0],&expected_sum[0][0]));

    int e[4][3] = { {5,5,0}, {7,3,1}, {3,4,3}, {8,4,5} };
    int e2[4][3] = { {7,2,1}, {1,1,1}, {2,2,2}, {100,2,5} };
    int empty_matrix2[4][3] = {};
    int expected_sum2[4][3] = {{12,7,1}, {8,4,2}, {5,6,5}, {108,6,10} };
    matrix_add(4,3,&e[0][0], &e2[0][0],&empty_matrix2[0][0]);
    assert(matrix_equals(4,3,&empty_matrix2[0][0],&expected_sum2[0][0]));

    int f[1][1] = { {100} };
    int f2[1][1] = {{200}};
    int empty_matrix3[1][1] = {};
    int expected_sum3[1][1] = {{300}};
    matrix_add(1,1,&f[0][0], &f2[0][0],&empty_matrix3[0][0]);
    assert(matrix_equals(1,1,&empty_matrix3[0][0],&expected_sum3[0][0]));

    return 0;
}
// matrix_add(n, m, a, b, c) computes the sum of the matrices a and b;
// the result is stored in the matrix c
// requires: n >= 1, m >= 1
// a, b, and c point to the (0, 0) element of an n x m matrix
// the memory c points to can be modified
void matrix_add(const int n, const int m, const int * a, const int * b, int * c)
{
    const int * end_of_a = a+m*n;
    while(a < end_of_a) //Since a, b and c are assumed to be the same size we don't have to check others
    {
        int sum = *a + *b;
        *c = sum;
        a++;
        b++;
        c++;
    }
}

// matrix_equals(n, m, a, b) returns true exactly when the n x m matrices
// pointed to by a and b are equal
// requires: n >= 1, m >= 1
// a and b point to the (0, 0) element of an n x m matrix
bool matrix_equals(const int n, const int m, const int * a, const int * b)
{
    const int * end_of_a = a+m*n;
    while(a < end_of_a)
    {
        if(*a != *b)
        {
            return false;
        }
        a++;
        b++;
    }
    return true;
}

void negate_row(const int n, const int m, int * a, const int r)
{
    //a + r*m is the row we want
    // a+ (r+1)*m is the row after the row we want
    for(int * p = a + r*m; p < a + (r+1)*m; p++)
    {
        *p *= -1;
    }
}

void negate_col(const int n, const int m, int * a, const int c)
{
    // a + c is the column we want
    // a + n*m is the end of a
    // incrementing by a row at a time
    for(int * p = a + c; p < a + n*m; p+=m)
    {
        *p *= -1;
    }
}