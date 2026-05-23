
void foo67(int n) {

    int i;
    int k;
    int j;

    i = 0;
    j = 0;
    k = 0;

    /*@
      loop invariant 0 <= i; // Weakened to ensure establishment
      loop invariant 0 <= j <= i;
      loop invariant 0 <= k <= i; // Adjusted to ensure preservation
      loop invariant j + k == i;
      loop invariant (0 < \at(n,Pre)) ==> (j + k == i);
      loop invariant (0 < \at(n,Pre)) ==> (0 <= k <= i); // Adjusted to ensure preservation
      loop invariant (0 < \at(n,Pre)) ==> (0 <= j <= i);
      loop invariant (!(0 < \at(n,Pre))) ==> ((j == 0)&&(k == 0)&&(i == 0)&&(n == \at(n,Pre)));
      loop invariant n == \at(n,Pre);
      loop assigns i, j, k;
    */
    while(i < n){
        i = i + 3;
        if((i % 2) != 0)
            j = j + 3;
        else
            k = k + 3;
    }
}
