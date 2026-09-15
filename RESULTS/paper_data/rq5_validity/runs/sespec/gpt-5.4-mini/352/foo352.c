int foo352(int number);


/*@
ensures \exists integer ret_62, total_61; (total_61 <= 0) && (0 <= ret_62) && (total_61 == number >> ret_62) ==> (\result == (number ^ 0));

assigns \nothing;
*/

int foo352(int number) 
{

		int result = 0;
		int ret = 0;
		int total = number;
		
            /*@
          loop invariant 0 <= ret;
          loop invariant total == (\at(number,Pre) >> ret);
          loop invariant number == \at(number,Pre);
          loop assigns result, total, ret;
            */
            while (total > 0) {
			if (ret % 2 == 0) {
				result = result | (1 << ret);
			}
			ret++;
			total >>= 1;
		}
            
		return number ^ result;
}