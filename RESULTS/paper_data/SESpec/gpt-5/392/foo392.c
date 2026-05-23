
/*@ 
  logic integer prefix_prod(integer m) = 
    (m <= 0 ? 1 : m * prefix_prod(m - 1));
*/

/*@ 
  assigns \nothing;
  ensures 0 <= \result <= 99;
*/
int foo392(int num) {

    int ret = 1;

    /*@
      loop invariant num == \at(num,Pre);
      loop invariant ret >= 1;
      loop invariant ret == prefix_prod(number - 1);
      loop invariant (number <= \at(num,Pre)) ==> (number >= 1);
      loop assigns number, ret;
    */
    for (int number = 1; number <= num; number++) {
        ret *= number;
    }

    int result = (int) (ret % 100);
    return result;
}
