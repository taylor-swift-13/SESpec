
/*@ 
  logic integer fact(integer n) =
    n <= 0 ? 1 : n * fact(n - 1);
*/

int foo392(int num) {

		int ret = 1;
		
        /*@
          loop invariant 1 <= number;
          loop invariant num == \at(num,Pre);
          loop invariant ret == fact(number - 1);
          loop invariant (number <= \at(num,Pre)) ==> (ret == fact(number - 1));
          loop invariant (number <= \at(num,Pre)) ==> (ret >= 1);
          loop assigns number, ret;
        */
            for (int number = 1; number <= num; number++) {
			ret *= number;
		}
            
		int result = (int) (ret % 100);
		return result;
}
