
/*@ predicate valid_num(integer x) = x >= 0; */

/*@
  requires num >= 0;
  assigns \nothing;
  ensures \at(\result, Post) >= 0 && \at(\result, Post) <= 9;
  
  ensures !(\at(\old(num), Pre) >= 10) ==> \result == \at(\old(num), Pre);
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
