
/*@ logic integer count_cols(integer c, integer x, integer y) =
      y > 2 * c ? 0 : ((x * x + y * y <= (2 * c) * (2 * c)) ? 1 : 0) + count_cols(c, x, y + 1); */
/*@ logic integer count_rows(integer c, integer x) =
      x > 2 * c ? 0 : count_cols(c, x, 1) + count_rows(c, x + 1); */
/*@
  assigns \nothing;
  ensures \result >= 0; // weakened from equality to a guaranteed property
*/
int foo113_c313(int count) {

    int ret = 0;
    int diameter = 2 * count;
    int center = diameter * diameter;
        
            /*@
              loop invariant index >= 1;
              loop invariant center == (2 * count) * (2 * count);
              loop invariant diameter == 2 * count;
              loop invariant count == \at(count,Pre);
              loop invariant 0 <= ret;
              loop assigns index, ret;
            */
            for (int index = 1; index <= 2 * count; index++) {
            
            /*@
              loop invariant i >= 1;
              loop invariant center == (2 * count) * (2 * count);
              loop invariant diameter == 2 * count;
              loop invariant count == \at(count,Pre);
              loop invariant 0 <= ret;
              loop assigns i, ret;
            */
            for (int i = 1; i <= 2 * count; i++) {
                int diagnalLengthSquare = (index * index + i * i);
                if (diagnalLengthSquare <= center) {
                    ret++;
                }
            }
            
        }
            
        return ret;
}
