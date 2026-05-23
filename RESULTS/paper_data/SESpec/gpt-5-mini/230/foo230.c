
/*@
  requires pairs != \null;
  requires pairs_len >= 0;
  requires \valid(pairs + (0 .. pairs_len - 1));
  requires \forall integer i; 0 <= i && i < pairs_len ==> 0 <= pairs[i] && pairs[i] <= 100;
  assigns \nothing;
  ensures 0 <= \result;
*/
int foo230(int * pairs, int pairs_len, int array) {

    int count = 0;
    int total = pairs_len;

    /*@ 
      loop invariant total == \at(pairs_len,Pre);
      loop invariant 0 <= count;
      loop invariant array == \at(array,Pre);
      loop invariant pairs_len == \at(pairs_len,Pre);
      loop invariant pairs == \at(pairs,Pre);
      loop invariant \forall integer p; 0 <= p && p < pairs_len ==> 0 <= pairs[p] && pairs[p] <= 100;
      loop assigns count, total;
    */
    for (int index = 0; index < total - 1; index++) {

        /*@
          loop invariant 0 <= index && index <= total - 1;
          loop invariant 0 <= count;
          loop invariant total == \at(pairs_len,Pre);
          loop invariant pairs_len == \at(pairs_len,Pre);
          loop invariant pairs == \at(pairs,Pre);
          loop invariant \forall integer p; 0 <= p && p < pairs_len ==> 0 <= pairs[p] && pairs[p] <= 100;
          loop assigns count;
        */
        for (int k = index + 1; k < total; k++) {
            if (pairs[index] != pairs[k]) {
                count++;
            }
        }

    }

    return count;
}
