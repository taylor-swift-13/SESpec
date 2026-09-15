
/*@
  ensures \result == 16 * poly4_sum(p);
  assigns \nothing;
*/
int foo396(int p) {

		int even = 0;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop assigns c, even;
            */
            for (int c = 1; c <= p; c++) {
			int count = 2 * c;
			even = even + (count * count * count * count);
		}
            
		return even;
}
