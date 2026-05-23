
/*@
  requires \valid_read(points + (0..2));
  requires \forall integer i; 0 <= i < 3 ==> \valid_read(points[i] + (0..1));
  assigns \nothing;
  ensures \result == (((points[1][0] - points[0][0]) * (points[2][1] - points[0][1])
                      - (points[1][1] - points[0][1]) * (points[2][0] - points[0][0])) != 0);
*/
int foo114(int **points, int points_len, int points_rows, int points_cols);

int foo114(int **points, int points_len, int points_rows, int points_cols) {
    int v1[] = {points[1][0] - points[0][0], points[1][1] - points[0][1]};
    int v2[] = {points[2][0] - points[0][0], points[2][1] - points[0][1]};
    return v1[0] * v2[1] - v1[1] * v2[0] != 0;
}
