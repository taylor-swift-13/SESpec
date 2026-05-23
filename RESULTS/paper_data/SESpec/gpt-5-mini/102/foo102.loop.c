
/*@
predicate valid_num(int n) = n >= 0;
*/

int foo102(int num) {

    /*@
      loop invariant (\at(num,Pre) >= 10) ==> (num >= 0);
      loop invariant !(\at(num,Pre) >= 10) ==> (num == \at(num,Pre));
      loop assigns num;
    */
    while (num >= 10) {
        int sum = 0;

        /*@
          loop invariant valid_num(num);
          loop invariant sum >= 0;
          loop assigns num, sum;
        */
        while (num > 0) {
            sum += num % 10;
            num /= 10;
        }

        num = sum;
    }

    return num;
}
