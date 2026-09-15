
/*@
  requires \true;
*/

int unknown(void);

void foo64() {

    int i;
    int j;
    int a;
    int b;

    a = 0;
    b = 0;
    j = 1;
    i = 1;

    /*@
      loop invariant 0 <= a;
      loop invariant 1 <= i;
      loop invariant 1 <= j;

      loop invariant a == (i - 1) / 2;

      loop invariant (i - 1) % 2 == 0;
      loop invariant i >= 1 && j >= 1;
      loop invariant \forall integer k; 0 <= k < a ==> k + 1 <= i;
      loop invariant a <= i;
      loop assigns a, b, i, j;
    */
    while (unknown()) {
      a = a + 1;
      b = b + j - i;
      i = i + 2;
      if (i % 2 == 0){
        j = j + 2;
      }
      else{
        j = j + 1;
      }
    }

}
