int findNthDigit(int num, int c, int r);

int findNthDigit(int num, int c, int r) {

		int result = 0;
		/*@
		loop invariant result == num / c || r >= 0;
		loop invariant result == 0 || result == num / c;
		loop invariant 0 <= result;
		loop invariant 0 <= r;
		loop invariant 0 <= num;
		loop invariant 0 < c;
		loop invariant num % c < c;
		loop invariant c != 0;
		loop invariant result == num / c || r > 0;
		loop invariant result == 0 || result == num / c;
		loop invariant 0 <= result;
		loop invariant 0 <= r;
		loop invariant 0 <= num;
		loop invariant 0 < c;
		loop assigns result;
		loop assigns r;
		loop assigns num;
		*/
		while (r > 0) {
			r -= 1;
			num *= 10;
			result = num / c;
			num %= c;
		}
		return result;
}
