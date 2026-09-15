int findNthDigit(int num, int c, int r);

int findNthDigit(int num, int c, int r) {

		int result = 0;
		/*@
		loop invariant 0 <= result;
		loop invariant 0 <= r;
		loop invariant c != 0;
		loop invariant result == num / c || r > 0;
		loop invariant num % c < c;
		loop invariant num < c || result == num / c;
		loop invariant result == num / c;
		loop invariant result == num / c || r >= 0;
		loop invariant result == num / c || r > 0;
		loop invariant result == 0 || result == num / c;
		loop invariant result <= num / c;
		loop invariant r <= r + 1;
		loop invariant num == 0 || result >= 0;
		loop invariant num < c || result == num / c;
		loop invariant num % c == 0 || result == 0;
		loop invariant num % c < c;
		loop invariant c != 0;
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
