int foo391(int n);


/*@
ensures \exists integer i_60; (1 <= i_60) && (i_60 >= 1) && (\forall integer k_50; 1 <= k_50 && k_50 <= i_60 - 1 ==> k_50 * k_50 == k_50 * k_50) && (1 <= n ==> 1 <= i_60) ==> (\result > n) && (1 <= \result) && (\result >= 1) && (1 <= n ==> \result > 0 && i_60 > 0) && (1 <= n ==> \result == 1 && i_60 == 1 && n == n || \result == (i_60 - 1) * (i_60 - 1)) && (!(1 <= n) ==> \result == 1 && i_60 == 1 && n == n);

assigns \nothing;
*/

int foo391(int n) 
{

        int i = 1;
        int square = 1;
        
        /*@
          loop invariant 1 <= i;
          loop invariant 1 <= square;
          
          loop invariant square >= 1 && i >= 1;
          loop invariant \forall integer k; 1 <= k <= i-1 ==> ( (k*k) == (k * k) );
          
          loop invariant (1 <= \at(n,Pre)) ==> (square > 0 && i > 0);
          loop invariant (1 <= \at(n,Pre)) ==> (1 <= i);
          loop invariant (1 <= \at(n,Pre)) ==> (((square == 1)&&(i == 1)&&(n == \at(n,Pre))) || (square == (i-1)*(i-1)));
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