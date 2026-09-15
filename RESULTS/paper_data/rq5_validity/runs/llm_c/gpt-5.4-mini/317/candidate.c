/*@
    requires num >= 1;
    assigns \nothing;
    ensures num == 1 ==> \result == 1;
    ensures num > 1 ==> \result >= 0;
*/
int countFac(int num);

 /*@
    requires num >= 1;
    assigns \nothing;
    ensures num == 1 ==> \result == 1;
    ensures num > 1 ==> \result >= 0;
*/
int countFac(int num) {

		int result = 0;
		if (num == 1)
			return 1;
		/*@
		    loop invariant 2 <= size;
		    loop invariant size <= num / size + 1;
		    loop invariant result >= 0;
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
