
/*@ 
  logic integer fact(integer n) =
    n <= 0 ? 1 : n * fact(n - 1);
*/

/*@
  requires \true;
*/
int foo392(int num) {

		int ret = 1;
		
            
        /*@
          loop invariant number >= 1;
          loop invariant (number <= \at(num,Pre)) ==> (ret == fact(number-1));
          loop invariant (number == \at(num,Pre) + 1) ==> (ret == fact(\at(num,Pre)));
          loop invariant num == \at(num,Pre);
          loop assigns number, ret;
        */
        for (int number = 1; number <= num; number++) {
			ret *= number;
		}
            
		int result = (int) (ret % 100);
		return result;
}
