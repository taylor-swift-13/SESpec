/*@
    requires num > 0;
    ensures \result >= 0;
    ensures \result == (\sum integer size; 2 <= size <= num / size && num % size == 0; 1);
*/
int countFac(int num);

int countFac(int num) {

		int result = 0;
		if (num == 1)
			return 1;
		/*@
		    loop invariant 2 <= size <= num / size + 1;
		    loop invariant result >= 0;
		    loop invariant result == (\sum integer s; 2 <= s < size && num % s == 0; 1);
		    loop assigns size, result;
		    loop variant num / size - size;
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
