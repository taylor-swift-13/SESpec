
        /*@
  assigns \nothing;
  ensures \result == 0 <==> (\exists integer k; 2 <= k <= \old(a) / 2 && \old(a) % k == 0);
  ensures \result == 1 <==> (\forall integer k; 2 <= k <= \old(a) / 2 ==> \old(a) % k != 0);
  ensures \result == 0 || \result == 1;
*/
int foo149(int a) {

    int i = 2;
    int mid = a / 2;

    /*@
      loop invariant 2 <= i;
      loop invariant \forall integer k; 2 <= k < i ==> a % k != 0;
      loop assigns i;
    */
    while (i <= mid) {
        if (a % i == 0)
            return 0;
        i++;
    }

    return 1;
}
