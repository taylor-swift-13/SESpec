#include <assert.h>

/*@
    ensures \result == 1;
*/
int f();

int f() {
    int some_a_len = 4;
    int some_a_0_len = 3;
    int some_a_0_0_len = 2;
    assert(some_a_len == 4);
    assert(some_a_0_len == 3);
    assert(some_a_0_0_len == 2);
    int x = 3;
    int y = 5;
    int int_array[3][5];
    /*@
        loop invariant 0 <= i <= x;
        loop assigns i, int_array[0..x-1][0..y-1];
    */
    for (int i = 0; i < x; ++i)
        /*@
            loop invariant 0 <= j <= y;
            loop assigns j, int_array[i][0..y-1];
        */
        for (int j = 0; j < y; ++j)
            int_array[i][j] = i + j;
    return int_array[2][4] == 6;
}
