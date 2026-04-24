int f();

int f() {

    int[][][] some_a = (int *)malloc(sizeof(int) * (4))[3][2];

    assert some_a.length == 4;
    assert some_a[0].length == 3;
    assert some_a[0][0].length == 2;

    int x = 3;
    int y = 5;
    int[][] int_array = (int *)malloc(sizeof(int) * (x))[y];

    for (int i = 0; i < x; ++i) for (int j = 0; j < y; ++j) int_array[i][j] = i + j;

    return int_array[2][4] == 6;
}
