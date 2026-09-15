int countFac(int num);

 /*@
     requires num >= 1;
     assigns \nothing;
     ensures num == 1 ==> \result == 1;
     ensures num >= 2 ==>
         \result == (\sum integer s; 2 <= s && s*s <= num && num % s == 0; 1);
     ensures \result >= 0;
 */
int countFac(int num) {

		int result = 0;
		if (num == 1)
			return 1;
		/*@
		    loop invariant 2 <= size;
		    loop invariant size*size <= num;
		    loop invariant result >= 0;
		    loop invariant
		        (result == (\sum integer j; 2 <= j && j < size && j*j <= num && num % j == 0; 1))
		        ||
		        (result == (\sum integer j; 2 <= j && j <= size && j*j <= num && num % j == 0; 1));
		    loop assigns size, result;
		    loop variant num - size;
		*/
		for (int size = 2; size <= num / size; size++) {
			if (num % size == 0) {
				result++;
				if (num / size == size) {
					break;
				}
			}
		}
		return result;
}
