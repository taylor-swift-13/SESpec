
/*@
  requires \true;
  assigns \nothing;
*/
int foo177(int num) {
    int result = 0;
    /* >>> LOOP INVARIANT TO FILL <<< */
    /*@
      loop invariant \true;
      loop assigns j, result, num;
    */
    for (int j = 2; j <= num; j++) {
        /* >>> LOOP INVARIANT TO FILL <<< */
        /*@
          loop invariant \true;
          loop assigns result, num;
        */
        while (num % j == 0) {
            result = j;
            num /= j;
        }
    }
    return result;
}
