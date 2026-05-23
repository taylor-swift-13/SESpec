
/*@
*/

	/*@
  requires 0 <= num;
  requires 0 <= pairs_len;
  requires num <= pairs_len;
  requires \valid_read(pairs + (0 .. num - 1));
  assigns \nothing;
  ensures \result == pair_count(pairs, num, p);
  ensures \result >= 0;
  ensures num < 2 ==> \result == 0;
  ensures \result <= (num * (num - 1)) / 2;
*/

int foo245(int * pairs, int pairs_len, int num, int p) {

		int ret = 0;
		
            /*@
          loop invariant 0 <= index <= num;
          loop invariant ret >= 0;
          loop assigns index, ret, j;
            */
            for (int index = 0; index < num; index++) {
			
            /*@
          loop invariant 0 <= index < num;
          loop invariant index + 1 <= j <= num;
          loop invariant ret >= 0;
          loop assigns j, ret;
            */
            for (int j = index + 1; j < num; j++) {
				if (pairs[index] + pairs[j] == p) {
					ret++;
				}
			}
            
		}
            
		return ret;
}
