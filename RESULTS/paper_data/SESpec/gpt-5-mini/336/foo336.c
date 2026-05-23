
/* The stray/invalid ACSL fragment at file top was removed. */

int foo336(int num) {

    int result = 0;
    
    /*@
      loop invariant 2 <= c;
      loop invariant result >= 0;
      loop assigns c, result, num;
    */
    for (int c = 2; c <= num; c++) {
        /*@
          loop invariant 2 <= c;
          loop invariant result >= 0;
          loop assigns c, num, result;
        */
        while (num % c == 0) {
            result = c;
            num /= c;
        }
    }
    return result;
}
