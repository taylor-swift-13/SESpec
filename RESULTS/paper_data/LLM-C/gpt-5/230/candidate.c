int countPairs(int * pairs, int pairs_len, int array);

/*@ 
  requires pairs_len >= 0 ==> \valid_read(pairs + (0 .. pairs_len-1));
  assigns \nothing;
  ensures pairs_len <= 1 ==> \result == 0;
  ensures pairs_len >= 0 ==> 0 <= \result <= (pairs_len * (pairs_len - 1)) / 2;
  ensures pairs_len >= 0 ==>
           \result ==
             \sum(integer i = 0; i < pairs_len; i++)
               \sum(integer j = i + 1; j < pairs_len; j++)
                 (pairs[i] != pairs[j] ? 1 : 0);
*/
int countPairs(int * pairs, int pairs_len, int array) {

		int count = 0;
		int total = pairs_len;
		/*@
		  loop invariant 0 <= index <= total;
		  loop invariant count ==
		    \sum(integer i = 0; i < index; i++)
		      \sum(integer j = i + 1; j < total; j++)
		        (pairs[i] != pairs[j] ? 1 : 0);
		  loop assigns count, index;
		  loop variant (total - 1) - index;
		*/
		for (int index = 0; index < total - 1; index++) {
			/*@
			  loop invariant index + 1 <= k <= total;
			  loop invariant count ==
			    \sum(integer i = 0; i < index; i++)
			      \sum(integer j = i + 1; j < total; j++)
			        (pairs[i] != pairs[j] ? 1 : 0)
			    + \sum(integer j = index + 1; j < k; j++)
			        (pairs[index] != pairs[j] ? 1 : 0);
			  loop assigns count, k;
			  loop variant total - k;
			*/
			for (int k = index + 1; k < total; k++) {
				if (pairs[index] != pairs[k]) {
					count++;
				}
			}
		}
		return count;
}
