
int foo391(int n) {

        int i = 1;
        int square = 1;
        
            
        /*@
          loop invariant 1 <= i;
          loop invariant square == 1 || square == (i - 1) * (i - 1);
          loop invariant square >= 1;
          loop invariant (square <= n) ==> (i * i <= n + 2 * i - 1);
          loop invariant (1 <= \at(n,Pre)) ==> (square == 1 || square == (i - 1) * (i - 1));
          loop invariant (1 <= \at(n,Pre)) ==> (1 <= i);
          loop invariant (1 <= \at(n,Pre)) ==> (((square == 1)&&(i == 1)&&(n == \at(n,Pre))) || (square == (i - 1) * (i - 1)));
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
