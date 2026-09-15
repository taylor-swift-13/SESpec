
/*@ 
  assigns \nothing;
  
*/
int foo397(int p) {

		int even = 0;
		
        /*@
          loop invariant even >= 0;
          loop invariant p == \at(p,Pre);
          loop assigns even;
        */
        for (int c = 1; c <= p; c++) {
			int tmp = 2 * c;
			even = even + (tmp * tmp * tmp * tmp);
		}
            
		return even;
}
