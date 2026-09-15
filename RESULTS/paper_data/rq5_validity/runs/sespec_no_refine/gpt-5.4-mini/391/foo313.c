
/*@
  assigns \nothing;
  ensures n <= 0 ==> \result == 1;
  ensures n > 0 ==> (\result > n && \result == sq((int)(\result - 1)) && \result == 1 + (int)\sqrt((double)n));
*/
int foo313(int n) {

        int i = 1;
        int square = 1;
        
            
        /*@
          loop invariant (!(1 <= \at(n,Pre))) ==> ((square == 1)&&(i == 1)&&(n == \at(n,Pre)));
          loop invariant n == \at(n,Pre);
          loop assigns square, i;
            */
            while (square <= n) {
            square = i*i;
            i++;
        }
            
        return square;
}
