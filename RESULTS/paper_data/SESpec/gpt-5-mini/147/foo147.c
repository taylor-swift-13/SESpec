
/* The stray malformed annotation has been removed. The valid loop contract is kept. */

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
