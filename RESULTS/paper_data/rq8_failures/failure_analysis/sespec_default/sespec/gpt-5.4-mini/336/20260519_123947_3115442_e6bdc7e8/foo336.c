
/*@
  assigns \nothing;
*/
int foo336(int num) {
    int result = 0;

    /*@
      loop invariant \true;
      loop assigns c, result, num;
    */
    for (int c = 2; c <= num; c++) {

        /*@
          loop invariant \true;
          loop assigns result, num;
        */
        while (num % c == 0) {
            result = c;
            num /= c;
        }
    }

    return result;
}
