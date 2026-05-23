
/*@ 
  assigns \nothing;
*/
int foo355(int num) {

		int result = 0;
		int end = 0;
		int sum = num;
		
        /*@
          loop invariant num == \at(num,Pre);
          loop invariant result >= 0;
          loop invariant sum <= \at(num,Pre);
          loop assigns end, sum, result;
        */
        while (sum > 0) {
			if (result % 2 == 1) {
				end |= (1 << result);
			}
			result++;
			sum >>= 1;
		}
            
		return (num | end);
}
