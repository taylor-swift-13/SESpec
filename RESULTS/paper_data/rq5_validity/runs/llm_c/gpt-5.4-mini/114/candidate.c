#include <stddef.h>

/*@ 
    requires points_len >= 3;
    requires points_rows >= 3;
    requires points_cols >= 2;
    requires \valid_read(points + (0 .. points_len-1));
    requires \forall integer i; 0 <= i < points_len ==> \valid_read(points[i] + (0 .. 1));
    assigns \nothing;
    ensures \result == 0 || \result == 1;
*/
int isBoomerang(int * * points, int points_len, int points_rows, int points_cols);

int isBoomerang(int * * points, int points_len, int points_rows, int points_cols) {

        int v1_0 = points[1][0] - points[0][0];
        int v1_1 = points[1][1] - points[0][1];
        int v2_0 = points[2][0] - points[0][0];
        int v2_1 = points[2][1] - points[0][1];
        return v1_0 * v2_1 - v1_1 * v2_0 != 0;
}
