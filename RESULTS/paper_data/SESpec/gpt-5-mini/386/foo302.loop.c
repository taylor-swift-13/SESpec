
/*@
  logic integer pow10(integer k) =
    k <= 0 ? 1 : 10 * pow10(k-1);
*/

/*@
  logic integer pow10_mod(integer k, integer b) =
    k <= 0 ? 1 % b : (10 % b) * pow10_mod(k-1, b) % b;
*/

/*@
  predicate num_r_relation(integer init_num, integer init_r, integer cur_num, integer cur_r, integer b) =
    init_r >= cur_r &&
    init_r - cur_r >= 0 &&
    (cur_num % b) == (init_num * pow10_mod(init_r - cur_r, b)) % b;
*/

/*@
  requires \true;
  assigns \nothing;
*/
int unknown_helper();

/*@
  requires b != 0;
  requires r >= 0;
*/
int foo302(int num, int b, int r) {

		int result = 0;
		
        /*@
          loop invariant (\at(r,Pre) > 0) ==> (0 <= r && r <= \at(r,Pre));
          loop invariant (!(\at(r,Pre) > 0)) ==> ((result == 0) && (r == \at(r,Pre)) && (b == \at(b,Pre)) && (num == \at(num,Pre)));
          loop invariant b == \at(b,Pre);
          loop assigns r, num, result;
        */
            while (r > 0) {
			r -= 1;
			num *= 10;
			result = num / b;
			num %= b;
		}
            
		return result;
}
