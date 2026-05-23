
/*@
  logic integer pow3(integer k) =
    k <= 0 ? 1 : 3 * pow3(k - 1);
*/

int foo147(int n) {

    int temp = n;

    /*@
      loop invariant n == \at(n,Pre);
      loop assigns temp;
    */
    while (temp != 0 && temp % 3 == 0) {
        temp /= 3;
    }

    return temp == 1;
}
