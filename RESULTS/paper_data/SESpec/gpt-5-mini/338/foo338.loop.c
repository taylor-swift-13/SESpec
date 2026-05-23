
/*@ 
  requires num >= 0;
*/
int foo338(int num) {

    int result = 0;

    /*@
      loop invariant 2 <= j;
      loop invariant 0 <= result;
      loop invariant num >= 0;
      loop invariant result == 0 || result >= 2;
      loop assigns j, result, num;
    */
    for (int j = 2; j <= num; j++) {

        /*@
          loop invariant 2 <= j;
          loop invariant 0 <= result;
          loop invariant num >= 0;
          loop invariant result == 0 || result >= 2;
          loop assigns result, num;
        */
        while (num % j == 0) {
            result = j;
            num /= j;
        }
    }

    return result;
}
