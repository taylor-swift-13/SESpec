
/*@ 
  logic integer fact(integer n) = 
    (n <= 1) ? 1 : n * fact(n - 1);
*/

/*@ 
  requires 0 <= num <= 12;
  assigns \nothing;
  ensures \result == (int)(fact(num) % 100);
  ensures num <= 1 ==> \result == 1;
  ensures 0 <= \result < 100;
*/
int foo392(int num) {

    int ret = 1;

    /*@
      loop invariant 1 <= number <= num + 1;
      loop invariant ret == fact(number - 1);
      loop assigns ret, number;
      loop variant num - number + 1;
    */
    for (int number = 1; number <= num; number++) {
        ret *= number;
    }

    int result = (int)(ret % 100);
    return result;
}
