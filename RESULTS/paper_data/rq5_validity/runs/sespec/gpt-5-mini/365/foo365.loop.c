
/*@
  requires n >= 1;
  requires \true;
*/
int foo365(int n) {

    int sum = 0;
    int count = 0;

    /*@
      loop invariant 1 <= i && i <= n + 1;
      loop invariant 0 <= sum;
      loop invariant 0 <= count;
      loop invariant 0 <= i - 1 && i - 1 <= n;
      loop invariant count <= i - 1;
      loop invariant sum >= count;
      loop invariant sum <= (i - 1) * i / 2;
      loop invariant \forall integer k; 1 <= k < i ==> (k % 2 != 0 ==> k <= sum);
      loop invariant (count > 0) ==> (\exists integer k; 1 <= k < i && k % 2 != 0);
      loop invariant (i <= \at(n,Pre)) ==> (0 <= sum && sum <= (i - 1) * i / 2);
      loop invariant (i <= \at(n,Pre)) ==> (0 <= count && count <= i - 1);
      loop invariant n == \at(n,Pre);
      loop assigns i, sum, count;
    */
    for (int i = 1; i <= n; i++) {
        if (i % 2 != 0) {
            sum += i;
            count++;
        }
    }

    return sum / count;
}
