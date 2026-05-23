
/*@ 
  assigns \nothing;
  ensures \result == cube_sum(diff) - tri_sum(diff);
*/
int foo163(int diff) {

		int result = 0;
		int max = 0;
		
            
        /*@
          loop invariant max == 0;
          loop invariant diff == diff;
          loop assigns j, result;
            */
            for (int j = 1; j <= diff; j++) {
			result += j * j * j;
		}
            
		
            
        /*@
          loop invariant max == tri_sum(j - 1);
          loop invariant result == cube_sum(diff);
          loop invariant 1 <= j <= diff + 1;
          loop assigns j, max;
            */
            /*@
          loop invariant (!(j <= diff)) ==> ();
          loop assigns j, max;
            */
            for (int j = 1; j <= diff; j++) {
			max += j;
		}
            
		return result - max;
}
