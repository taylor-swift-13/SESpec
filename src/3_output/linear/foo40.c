
/*@
    requires n > 0;
*/
void foo40(int n) {
    int c = 0;

    /*@
      loop invariant n == \at(n,Pre);
      loop invariant c >= 0;
      loop assigns c;
    */
    while (unknown()) {
        {
            if (unknown()) {
                if (c > n) {
                    c = c + 1;
                }
            } else {
                if (c == n) {
                    c = 1;
                }
            }
        }
    }

    /*@ assert (c != n) ==> (c >= 0); */
}
