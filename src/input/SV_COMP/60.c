/*@ assigns \nothing; */
int foo60();

int foo60() {

    int some_a[4][3][2];

    int x = 3;
    int y = 5;
    int int_array[3][5];

    for (int i = 0; i < x; ++i) for (int j = 0; j < y; ++j) int_array[i][j] = i + j;

    return int_array[2][4] == 6;
}
