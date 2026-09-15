/*@
    requires \valid(points+(0..points_len-1));
    requires \forall integer i; 0 <= i < points_len ==> \valid(points[i]+(0..points_cols-1));
    requires points_len == points_rows;
    requires points_len == 3;
    requires points_cols == 2;
    assigns \nothing;
    ensures \result == 1 <==> 
        (points[1][0] - points[0][0]) * (points[2][1] - points[0][1]) - 
        (points[1][1] - points[0][1]) * (points[2][0] - points[0][0]) != 0;
    ensures \result == 0 <==> 
        (points[1][0] - points[0][0]) * (points[2][1] - points[0][1]) - 
        (points[1][1] - points[0][1]) * (points[2][0] - points[0][0]) == 0;
*/
int isBoomerang(int * * points, int points_len, int points_rows, int points_cols) {

        int v1[2] = {points[1][0] - points[0][0], points[1][1] - points[0][1]};
        int v2[2] = {points[2][0] - points[0][0], points[2][1] - points[0][1]};
        return v1[0] * v2[1] - v1[1] * v2[0] != 0;
}
