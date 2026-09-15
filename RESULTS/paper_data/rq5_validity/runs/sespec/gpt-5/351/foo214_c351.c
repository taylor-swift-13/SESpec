
/*@ logic integer pow2(integer e) = (e <= 0 ? 1 : 2 * pow2(e - 1)); */

/*@
  requires \true;
  assigns \nothing;
  ensures number == \old(number);
  ensures \old(number) <= 0 ==> \result == \old(number);
*/
int foo214_c351(int number) {

		int i = 0;
		int ret = 0;
		int total = number;
		
        /*@
          loop invariant 0 <= ret;
          loop invariant (\at(number,Pre) > 0) ==> (number == \at(number,Pre));
          loop invariant (\at(number,Pre) > 0) ==> (0 <= ret && 0 <= total);
          loop invariant (!(\at(number,Pre) > 0)) ==> ((total == \at(number,Pre))&&(ret == 0)&&(i == 0)&&(number == \at(number,Pre)));
          loop invariant number == \at(number,Pre);
          loop assigns i, total, ret;
        */
        while (total > 0) {
			if (ret % 2 == 0) {
				i = i | (1 << ret);
			}
			ret++;
			total >>= 1;
		}
            
		return number ^ i;
}
