int findNthDigit(int num, int c, int r);

int findNthDigit(int num, int c, int r) {

		int result = 0;
		/*@
		loop invariant r >= 0;
		loop invariant c > 0;
		loop invariant result >= 0;
		loop assigns r;
		loop assigns num;
		loop assigns result;
		*/
		while (r > 0) {
			r -= 1;
			num *= 10;
			result = num / c;
			num %= c;
		}
		return result;
}
