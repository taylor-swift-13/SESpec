
/*@ logic integer cntdiv(integer num, integer c, integer end) =
      c >= end ? 0 : ((num % c == 0) ? 1 : 0) + cntdiv(num, c + 1, end);
*/

/*@
  assigns \nothing;

  ensures num == \old(num);

  ensures \result != \null;
  ensures \valid_read(\result);

  ensures (cntdiv(num, 1, num + 1) % 2 != 0) ==> \result != \null;

  ensures (cntdiv(num, 1, num + 1) % 2 == 0) ==> \result != \null;
*/
const char * foo282(int num) {

		int result = 0;
		
            
        /*@
          loop invariant \at(num,Pre) < 1 ==> c == 1;
          loop invariant \at(num,Pre) >= 1 ==> 1 <= c <= \at(num,Pre) + 1;

          loop invariant num == \at(num,Pre);

          loop invariant 0 <= result <= c - 1;

          loop invariant result > 0 ==> (\exists integer k; 1 <= k < c && num % k == 0);
          loop assigns c, result;
        */
        for (int c = 1; c <= num; c++) {
			if (num % c == 0) {
				result++;
			}
		}
            
		if (result % 2 == 0) {
			return "Even";
		} else {
			return "Odd";
		}
}
