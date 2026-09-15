void foo311(unsigned int n) {

    unsigned int j;
    unsigned int i;
    unsigned int k;
    unsigned int v4;
    unsigned int v3;
    unsigned int v2;
    unsigned int v1;
    unsigned int l;

    i = 0;
    k = 0;
    j = 0;
    l = 0;
    v4 = 0;
    v3 = 0;
    v2 = 0;
    v1 = 0;

    /*@
    loop invariant 0 <= l <= n;
    loop invariant i + j + k + v1 + v2 + v3 + v4 == l;
    loop invariant \forall unsigned int t; t < l && t % 7 == 0 ==> v1 >= 1;
    loop invariant \forall unsigned int t; t < l && t % 6 == 0 && t % 7 != 0 ==> v2 >= 1;
    loop invariant \forall unsigned int t; t < l && t % 5 == 0 && t % 6 != 0 && t % 7 != 0 ==> v3 >= 1;
    loop invariant \forall unsigned int t; t < l && t % 4 == 0 && t % 5 != 0 && t % 6 != 0 && t % 7 != 0 ==> v4 >= 1;
    loop assigns l;
    loop assigns i;
    loop assigns j;
    loop assigns k;
    loop assigns v1;
    loop assigns v2;
    loop assigns v3;
    loop assigns v4;
    */
    while (l < n) {
       if((l % 7) == 0){
       v1 = v1 + 1;
      }
       else if((l % 6) == 0){
       v2 = v2 + 1;
      }
       else if ((l % 5) == 0){
       v3 = v3 + 1;
      }
       else if ((l % 4) == 0) {
       v4 = v4 + 1;
      }
       else if((l % 3) == 0){
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
