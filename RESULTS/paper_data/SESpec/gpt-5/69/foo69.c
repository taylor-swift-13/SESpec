
void foo69(unsigned int n) {

    unsigned int j;
    unsigned int i;
    unsigned int k;
    unsigned int l;

    i = 0;
    k = 0;
    j = 0;
    l = 0;

    /*@
      loop invariant 0 <= l <= n;
      loop invariant 0 <= i <= l;
      loop invariant 0 <= j <= l;
      loop invariant 0 <= k <= l;
      loop invariant i + j + k == l;
      loop invariant \forall integer t; 0 <= t < l ==> ((t % 3) == 0 ==> \exists integer p; t == 3*p);
      loop invariant \forall integer t; 0 <= t < l ==> (((t % 3) == 0) || (((t % 2) == 0) && ((t % 3) != 0)) || ((t % 2) == 1));
      loop invariant \forall integer t; 0 <= t < l ==> !(((t % 3) == 0) && (((t % 2) == 0) && ((t % 3) != 0)));
      loop invariant (l == n) ==> (i + j + k == n);
      loop invariant n == \at(n,Pre);
      loop assigns i, j, k, l;
    */
    while (l < n) {
        if ((l % 3) == 0) {
            i = i + 1;
        }
        else if((l % 2) == 0){
            j = j + 1;
        }
        else{
            k = k + 1;
        }
        l = l + 1;
    }

}
