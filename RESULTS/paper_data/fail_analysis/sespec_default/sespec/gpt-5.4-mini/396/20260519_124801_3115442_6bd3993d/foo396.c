
/*@
  assigns \nothing;
*/
int foo396(int p) {

        int even = 0;
        
        /*@
          loop invariant p == \at(p,Pre);
          loop invariant even >= 0;
          loop assigns c, even;
          loop variant p - c + 1;
        */
        for (int c = 1; c <= p; c++) {
			int count = 2 * c;
			even = even + (count * count * count * count);
		}
            
		return even;
}
