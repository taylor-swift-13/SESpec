
/*@
    requires n > 0;
*/
void foo44(int n) {
    int c = 0;

    /*@
      loop invariant n == \at(n,Pre);
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
    
    /*@ assert (n <= -1) ==> (c != n); */
}
