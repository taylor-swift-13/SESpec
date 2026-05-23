#include <assert.h>

int f();

/*@
    requires \true;
    assigns \nothing;
    ensures \result == 1;
*/
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
        loop invariant \forall integer ii, jj; 0 <= ii < i && 0 <= jj < y ==> int_array[ii][jj] == ii + jj;
        loop assigns i, int_array;
        loop variant x - i;
    */
    for (int i = 0; i < x; ++i)
        /*@
            loop invariant 0 <= j <= y;
            loop invariant \forall integer jj; 0 <= jj < j ==> int_array[i][jj] == i + jj;
            loop assigns j, int_array[i];
            loop variant y - j;
        */
        for (int j = 0; j < y; ++j)
            int_array[i][j] = i + j;
    return int_array[2][4] == 6;
}
