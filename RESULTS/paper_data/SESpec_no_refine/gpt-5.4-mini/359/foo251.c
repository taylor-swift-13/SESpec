
/*@ 
  assigns \nothing;
  ensures \result ==
    (count_odd_upto(size) == 0 ? 0 : sum_odd_upto(size) / count_odd_upto(size));
*/
int foo251(int size) {

		int ret = 0;
		int total = 0;
		
            
        /*@
          loop invariant size == \at(size,Pre);
          loop invariant size == \at(size,Pre);
          loop assigns c, ret, total;
            */
            for (int c = 1; c <= size; c++) {
			if (c % 2 != 0) {
				ret += c;
				total++;
			}
		}
            
		return ret / total;
}
