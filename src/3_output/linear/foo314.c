
/*@
    requires n <= 20000001;
    */
    
void foo314(unsigned int n) {

    unsigned int j;
    unsigned int i;
    unsigned int k;

    i = 0;
    k = 0;
    j = 0;

    /*@
      loop invariant i == j && j == k;
      loop invariant i % 3 == 0;
      loop invariant j % 3 == 0;
      loop invariant k % 3 == 0;
      loop invariant (!(i < n)) ==> (i >= n && i == j && j == k);
      loop assigns i, j, k;
    */
    while (i < n) {
       i = i + 3;
       j = j + 3;
       k = k + 3;
    }

    /*@ assert i == j; */
}
