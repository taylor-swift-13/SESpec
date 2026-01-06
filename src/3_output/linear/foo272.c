
void foo272() {
    int i;
    int j;
    int k;

    i = 0;
    j = 0;

    /*@
      loop invariant (0 <= k) ==> (i == j);
      loop invariant (0 <= k) ==> (i <= k + 1);
      loop invariant (!(0 <= k)) ==> ((j == 0) && (i == 0));
      loop assigns i, j;
    */
    while (i <= k) {
       i++;
       j = j + 1;
    }

    /*@ assert i == j; */
}
