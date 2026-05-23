
/*@ logic integer prefix_pairs{L}(int *pairs, integer num, integer index, int p) =
      index <= 0 ? 0 :
      prefix_pairs(pairs, num, index - 1, p) +
      \numof integer y; 0 <= y < num && y > index - 1 && pairs[index - 1] + pairs[y] == p;

    logic integer suffix_pairs{L}(int *pairs, integer index, integer j, int p) =
      j <= index + 1 ? 0 :
      suffix_pairs(pairs, index, j - 1, p) +
      ((pairs[index] + pairs[j - 1] == p) ? 1 : 0);
*/

/*@
  requires 0 <= num;
  requires num <= pairs_len;
  requires \valid_read(pairs + (0 .. num-1));
  assigns \nothing;
  ensures \result == prefix_pairs(pairs, num, num, p);
  ensures \result >= 0;
  ensures \result <= num * (num - 1) / 2;
  ensures \result == 0 <==> (\forall integer i, j; 0 <= i < j < num ==> pairs[i] + pairs[j] != p);
  ensures \result == \null ==> \false;
*/

int foo243(int * pairs, int pairs_len, int num, int p) {

		int result = 0;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 0 <= index <= num;
          loop invariant result == prefix_pairs(pairs, num, index, p);
          loop assigns index, result;
            */
            for (int index = 0; index < num; index++) {
			

            /*@
          loop invariant 0 <= index && index < num;
          loop invariant index + 1 <= j && j <= num;
          loop invariant result == prefix_pairs(pairs, num, index, p) + suffix_pairs(pairs, index, j, p);
          loop assigns j, result;
            */
            for (int j = index + 1; j < num; j++) {
				if (pairs[index] + pairs[j] == p) {
					result++;
				}
			}
            
		}
            
		return result;
}
