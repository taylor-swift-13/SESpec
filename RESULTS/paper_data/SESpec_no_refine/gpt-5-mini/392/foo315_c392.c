
/*@ 
  logic integer fact(integer n) = n <= 0 ? 1 : n * fact(n-1);
*/

/*@
  requires \true;
  requires (1 == 1) && (num == \at(num,Pre)); 
  assigns \nothing;   
*/
int foo315_c392(int num) {

		int ret = 1;
		
            
        /*@
          loop invariant num == \at(num,Pre);
          loop assigns number, ret;
        */
        for (int number = 1; number <= num; number++) {
			ret *= number;
		}
            
		int result = (int) (ret % 100);
		return result;
}
