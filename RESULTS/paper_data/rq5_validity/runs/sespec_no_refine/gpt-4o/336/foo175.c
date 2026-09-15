
/*@
  requires num >= 0;
  assigns \nothing;
*/
int foo175(int num) {

    int result = 0;

    /*@
      loop assigns c, result, num;
    */
    for (int c = 2; c <= num; c++) {

        /*@
          loop assigns c, result, num;
        */
        while (num % c == 0) {
            result = c;
            num /= c;
        }

    }

    return result;
}
