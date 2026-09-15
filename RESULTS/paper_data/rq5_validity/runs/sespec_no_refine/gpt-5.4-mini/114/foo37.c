

/*@
  requires \valid(&points[0] + (0..points_len-1));
  requires \forall integer i; 0 <= i < points_len ==> 0 <= points[i] <= 100;
  requires points_len > 0;
  requires points_len < 100;
           assigns PLACE_HOLDER;   
  ensures PLACE_HOLDER; 
    ensures \result == PLACE_HOLDER_RESULT;  
*/
int foo37(int * * points, int points_len, int points_rows, int points_cols);


int foo37(int * * points, int points_len, int points_rows, int points_cols) {

        int[] v1 = {points[1][0] - points[0][0], points[1][1] - points[0][1]};
        int[] v2 = {points[2][0] - points[0][0], points[2][1] - points[0][1]};
        return v1[0] * v2[1] - v1[1] * v2[0] != 0;
}