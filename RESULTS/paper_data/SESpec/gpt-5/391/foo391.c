
/*@
  requires \true;
  assigns \nothing;
  ensures \result > n;
  ensures n < 1 ==> \result == 1;
  ensures \result >= 1;
  ensures \result == \result;  
*/
int foo391(int n) {

        int i = 1;
        int square = 1;
        
        /*@
          loop invariant 1 <= i;
          loop invariant 1 <= square;
          loop invariant n == \at(n,Pre);
          loop invariant i >= 1 ==> square >= 1;
          loop invariant i >= 1 ==> (i - 1) <= square;
          loop invariant i >= 1 ==> (i - 1) * (i - 1) <= square;
          loop invariant i >= 2 ==> (i - 2) * (i - 2) < square;
          loop invariant \forall integer k; 1 <= k < i ==> (k * k) <= square;
          loop invariant \exists integer k; 1 <= k < i ==> square == k * k;
          loop invariant (square <= n) ==> (i - 1) * (i - 1) <= n;
          loop invariant (i >= 2) ==> ((i - 2) * (i - 2) <= n ==> (i - 1) * (i - 1) <= n || square > n);
          loop invariant (i >= 2) ==> ((i - 2) * (i - 2) <= n);
          loop invariant (square >= (i - 1)) ;
          loop invariant (1 <= \at(n,Pre)) ==> (i >= 1) ;
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
