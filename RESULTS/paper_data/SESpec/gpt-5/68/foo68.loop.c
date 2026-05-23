


void foo68(unsigned int n) {

    unsigned int j;
    unsigned int i;
    unsigned int l;

    i = 0;
    j = 0;
    l = 0;

    /*@
      loop invariant 0 <= l <= n;
      loop invariant 0 <= i <= l;
      loop invariant 0 <= j <= l;
      loop invariant i + j == l;
      loop invariant \forall integer k; 0 <= k < l ==> ((k % 2 == 0) ==> (i >= 1)) || ((k % 2 == 1) ==> (j >= 1)) || (l == 0);
      loop invariant i == (l + 1) / 2 && j == l / 2 || i == l / 2 && j == (l + 1) / 2;
      loop invariant (l % 2 == 0) ==> (i == j);
      loop invariant (l % 2 == 1) ==> (i == j + 1);
      loop invariant \forall integer k; 0 <= k < l ==> ((k % 2 == 0) || (k % 2 == 1));
      loop invariant (l == n) ==> (i + j == n);
      loop invariant (0 < \at(n,Pre)) ==> (i + j == l);
      loop invariant (0 < \at(n,Pre)) ==> (0 <= j && j <= l);
      loop invariant (0 < \at(n,Pre)) ==> (0 <= i && i <= l);
      loop invariant (0 < \at(n,Pre)) ==> (0 <= l && l <= n);
      loop invariant (!(0 < \at(n,Pre))) ==> ((l == 0)&&(i == 0)&&(j == 0)&&(n == \at(n,Pre)));
      loop invariant n == \at(n,Pre);
      loop assigns i, j, l;
    */
    while (l < n) {
        if ((l % 2) == 0) {
            i = i + 1;
        }
        else{
            j = j + 1;
        }
        l = l + 1;
    }

}
