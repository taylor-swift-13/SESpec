
/*@ 
  assigns \nothing; 
  ensures 0 <= \result;
  ensures (n <= 0) ==> \result == 0;
  ensures \result == 0 ==> (\forall integer k; 1 <= k <= n ==> (k % x) != y);
  ensures \result != 0 ==> (1 <= \result <= n);
  ensures \result != 0 ==> ((\result % x) == y);
  ensures \result != 0 ==> (\forall integer k; 1 <= k <= n && (k % x) == y ==> k <= \result);
*/
int foo382(int n, int x, int y) {

    int max = 0;
    
    /*@
      loop invariant 1 <= i;
      loop invariant 0 <= max;
      loop invariant max < i;
      loop invariant y == \at(y,Pre);
      loop invariant x == \at(x,Pre);
      loop invariant n == \at(n,Pre);
      loop invariant (max == 0) ==> (\forall integer k; 1 <= k < i ==> (k % \at(x,Pre)) != \at(y,Pre));
      loop invariant (max != 0) ==> (1 <= max < i);
      loop invariant (max != 0) ==> ((max % \at(x,Pre)) == \at(y,Pre));
      loop invariant \forall integer k; (1 <= k < i && (k % \at(x,Pre)) == \at(y,Pre)) ==> k <= max;
      loop invariant (max != 0) ==> (\exists integer k; 1 <= k < i && k == max && (k % \at(x,Pre)) == \at(y,Pre));
      loop invariant (\forall integer k; 1 <= k < i ==> k <= max || (k % \at(x,Pre)) != \at(y,Pre));
      loop invariant (i > \at(n,Pre)) ==> ((max == 0) <==> (\forall integer k; 1 <= k <= \at(n,Pre) ==> (k % \at(x,Pre)) != \at(y,Pre)));
      loop invariant (i > \at(n,Pre)) ==> ((max == 0) || ((1 <= max <= \at(n,Pre)) && ((max % \at(x,Pre)) == \at(y,Pre)) && (\forall integer k; 1 <= k <= \at(n,Pre) && (k % \at(x,Pre)) == \at(y,Pre) ==> k <= max)));
      loop assigns i, max;
    */
    for (int i = 1; i <= n; i++) {
        if ((i % x) == y) {
            max = i;
        }
    }
        
    return max;
}
