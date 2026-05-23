void foo307(unsigned int n) {
  /*@ 
    requires \true;
    assigns \nothing;
  */

    unsigned int j;
    unsigned int i;
    unsigned int k;
    unsigned int l;

    i = 0;
    k = 0;
    j = 0;
    l = 0;

    /*@
      loop invariant 0 <= (integer)l <= (integer)n;
      loop invariant 0 <= (integer)i;
      loop invariant 0 <= (integer)j;
      loop invariant 0 <= (integer)k;
      loop invariant (integer)i == (((integer)l + 2) / 3);
      loop invariant (integer)j == (((integer)l + 1) / 2) - (((integer)l + 5) / 6);
      loop invariant (integer)k == (integer)l - (integer)i - (integer)j;
      loop invariant (integer)i + (integer)j + (integer)k == (integer)l;
      loop assigns i, j, k, l;
      loop variant (integer)n - (integer)l;
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

    //@ assert (integer)l == (integer)n;
    //@ assert (integer)i == (((integer)n + 2) / 3);
    //@ assert (integer)j == (((integer)n + 1) / 2) - (((integer)n + 5) / 6);
    //@ assert (integer)k == (integer)n - (integer)i - (integer)j;
    //@ assert (integer)i + (integer)j + (integer)k == (integer)n;
  }
