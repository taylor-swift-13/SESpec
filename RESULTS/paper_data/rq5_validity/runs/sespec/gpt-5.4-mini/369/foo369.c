
/*@
  requires p != 0;
  requires value >= 0;
  assigns \nothing;
  ensures \result == 0 ==> (\forall integer k; 1 <= k <= value ==> k % p != dy);
  ensures \result != 0 ==> 1 <= \result;
  ensures \result != 0 ==> \result % p == dy;
  ensures \result != 0 ==> (\forall integer k; 1 <= k <= value && k % p == dy ==> k <= \result);
*/
int foo369(int value, int p, int dy) {

		int result = 0;
		
        /*@
          loop invariant 1 <= c;
          loop invariant 0 <= result;
          loop invariant result == 0 || (1 <= result && result < c);
          loop invariant result == 0 || result % p == dy;
          loop invariant result == 0 || (\forall integer k; 1 <= k < c ==> k % p != dy || k <= result);
          loop invariant (\exists integer k; 1 <= k < c && k % p == dy) ==> result != 0;
          loop invariant (\exists integer k; 1 <= k < c && k % p == dy) ==> result % p == dy;
          loop invariant dy == \at(dy,Pre);
          loop invariant p == \at(p,Pre);
          loop invariant value == \at(value,Pre);
          loop assigns c, result;
            */
            for (int c = 1; c <= value; c++) {
			if ((c % p) == dy) {
				result = c;
			}
		}
            
		return result;
}
