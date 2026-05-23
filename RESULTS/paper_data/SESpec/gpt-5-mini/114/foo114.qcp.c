#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int foo114(int * * points, int points_len, int points_rows, int points_cols);

int foo114(int * * points, int points_len, int points_rows, int points_cols) 
/*@
With points_l
Require store_int_array(points, points_len, points_l) && points_len > 0 && points_len < 100
Ensure Results(__return)
*/{

        int v1[] = {points[1][0] - points[0][0], points[1][1] - points[0][1]};
        int v2[] = {points[2][0] - points[0][0], points[2][1] - points[0][1]};
        return v1[0] * v2[1] - v1[1] * v2[0] != 0;
}