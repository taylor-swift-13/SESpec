
/*@
  requires num >= 2; // Strengthened precondition: num must be at least 2.
  assigns \nothing;
*/
int foo177(int num) {

    int result = 0;

    /*@
      loop assigns j, result, num;
    */
    for (int j = 2; j <= num; j++) {

        /*@
          loop assigns j, result, num;
        */
        while (num % j == 0) {
            result = j;
            num /= j;
        }

    }

    return result;
}
