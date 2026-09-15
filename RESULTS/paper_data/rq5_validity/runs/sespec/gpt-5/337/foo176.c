
/*@
  requires num >= 0;
  assigns \nothing;
  ensures (\old(num) > 1) ==> (\result == 0 || \result >= 2);
*/
int foo176(int num) {

		int ret = 0;
		
            /*@
          loop invariant j >= 2;
          loop invariant ret == 0 || (ret >= 2 && ret <= j);
          loop assigns j, ret, num;
            */
            for (int j = 2; j <= num; j++) {
			
            /*@
              loop invariant j >= 2;
              loop invariant num >= 1;
              loop invariant ret == 0 || (ret >= 2 && ret <= j);
              loop assigns ret, num;
            */
            while (num % j == 0) {
				ret = j;
				num /= j;
			}
            
		}
            
		return ret;
}
