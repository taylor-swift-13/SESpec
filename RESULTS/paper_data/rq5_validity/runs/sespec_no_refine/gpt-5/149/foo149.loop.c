
/*@
  // No additional predicates or logic functions are needed.
*/

int foo149(int a) {

    int i = 2;
    int mid = a/2;

    /*@
      loop invariant i >= 2;
      loop invariant mid == a / 2;
      loop invariant a == \at(a,Pre);
      loop invariant i <= mid + 1;
      loop assigns i;
    */
    while (i <= mid) {
        if (a%i == 0)
            return 0;
        i++;
    }

    return 1;
}
