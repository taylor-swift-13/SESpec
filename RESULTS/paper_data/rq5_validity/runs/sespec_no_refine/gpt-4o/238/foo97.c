
/*@
  // No additional predicate or logic function is required for this program.
*/

/*@
  requires \valid(&a[0] + (0..a_len-1));
  requires \forall integer i; 0 <= i < a_len ==> 0 <= a[i] <= 100;
  requires a_len > 0;
  requires a_len < 100;
  assigns \nothing;
  ensures \result == 
    \sum(0 <= i < a_len, 
         \sum(i + 1 <= j < a_len, ((a[i] ^ a[j]) % 2 == 1 ? 1 : 0)));
*/
int foo97(int * a, int a_len, int n) {

    int count = 0;
    int length = a_len;

    /*@
      loop invariant 0 <= i <= length;
      loop invariant count >= 0;
      loop invariant length == \at(a_len,Pre);
      loop invariant n == \at(n,Pre);
      loop invariant a_len == \at(a_len,Pre);
      loop invariant a == \at(a,Pre);
      loop invariant count == 
        \sum(0 <= k < i, 
             \sum(k + 1 <= l < length, ((a[k] ^ a[l]) % 2 == 1 ? 1 : 0)));
      loop assigns i, count;
    */
    for (int i = 0; i < length; i++) {

        /*@
          loop invariant i + 1 <= j <= length;
          loop invariant count >= 0;
          loop invariant count == 
            \sum(0 <= k < i, 
                 \sum(k + 1 <= length, ((a[k] ^ a[l]) % 2 == 1 ? 1 : 0))) +
            \sum(i + 1 <= l < j, ((a[i] ^ a[l]) % 2 == 1 ? 1 : 0));
          loop assigns j, count;
        */
        for (int j = i + 1; j < length; j++) {
            if ((a[i] ^ a[j]) % 2 == 1) {
                count++;
            }
        }
    }

    return count;
}
