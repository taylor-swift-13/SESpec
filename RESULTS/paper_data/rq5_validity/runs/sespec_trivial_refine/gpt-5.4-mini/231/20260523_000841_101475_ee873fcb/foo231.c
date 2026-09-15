
        /*@
        */
        
/*@
  requires p_len >= 0;
  requires p_len == 0 || \valid_read(p + (0 .. p_len - 1));
  assigns \nothing;
  ensures \result == pair_count(p, p_len);
  ensures p_len <= 1 ==> \result == 0;
  ensures \result >= 0;
  ensures \result == pair_count_acc(p, p_len, 0);
*/

int foo231(int * p, int p_len, int array) {

		int count = 0;
		int total = p_len;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 0 <= index <= total - 1;
          loop invariant count == \numof{ integer i, j; 0 <= i < index && i + 1 <= j < total && p[i] != p[j] };
          loop assigns index, count;
            */
            for (int index = 0; index < total - 1; index++) {
			
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant index + 1 <= c <= total;
          loop invariant count == \numof{ integer i, j; 0 <= i < index && i + 1 <= j < total && p[i] != p[j] } + \numof{ integer j; index + 1 <= j < c && p[index] != p[j] };
          loop assigns count, c;
            */
            for (int c = index + 1; c < total; c++) {
				if (p[index] != p[c]) {
					count++;
				}
			}
            
		}
            
		return count;
}
