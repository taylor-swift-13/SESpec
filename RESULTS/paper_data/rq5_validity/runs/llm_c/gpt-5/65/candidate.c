/*@ 
  requires k >= 0;
  assigns \nothing;
  ensures \true;
*/
void foo263(int k) {

    int n;
    int i;

    n = 0;
    i = 0;

    /*@
      loop invariant 0 <= i <= 2*k;
      loop invariant n == (i + 1) / 2;
      loop assigns i, n;
      loop variant 2*k - i;
    */
    while (i < 2 * k) {
       if(i % 2 == 0){
       n = n + 1;
      }
       i = i + 1;
      }

    //@ assert i == 2*k;
    //@ assert n == k;

  }
