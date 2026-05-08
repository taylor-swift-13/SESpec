#include <assert.h>

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
    for (int i = 0; i < x; ++i)
        for (int j = 0; j < y; ++j)
            int_array[i][j] = i + j;
    return int_array[2][4] == 6;
}
