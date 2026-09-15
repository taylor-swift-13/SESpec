
/*@ 
  requires x_len >= 0;
  requires \valid_read(x + (0..x_len-1));
  assigns \nothing;   
  ensures \result == -1 <==> (x_len == 0 || (\forall integer k; 0 <= k < x_len ==> x[k] != 0));
  ensures \result != -1 ==> (0 <= \result && \result < x_len && x[\result] == 0);
  ensures \result != -1 ==> (\forall integer k; 0 <= k < \result ==> x[k] != 0);
  ensures (\exists integer k; 0 <= k < x_len && x[k] == 0) ==> \result != -1;
  ensures (\forall integer k; 0 <= k < x_len ==> x[k] != 0) ==> \result == -1;
  ensures \result >= -1;
  ensures \result == \result;  
*/
int foo107(int * x, int x_len) {

         	assert(x_len >= 0);
         	if (x_len == 0) {
            		return -1;
        	} else {
            		int index = 0;

            		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
              loop invariant 0 <= index <= x_len;
              loop invariant \forall integer k; 0 <= k < index ==> x[k] != 0;
              loop invariant (x_len - index > 0 && x[index] != 0) ==> (0 <= index && index < x_len);
              loop invariant (!(x_len - index > 0 && x[index] != 0)) ==> (index == x_len || (0 <= index && index < x_len && x[index] == 0));
              loop assigns index;
            */
            while (x_len - index > 0 && x[index] != 0) {
                		index = index + 1;
            		}
            
            		if (x_len - index == 0) {
               			index = -1;
            		}
            	return index;
        	}
}
