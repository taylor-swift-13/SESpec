int maxPrimeFactors(int num);

int maxPrimeFactors(int num) {

		int result = 0;
		for (int c = 2; c <= num; c++) {
			/*@
			loop assigns num;
			loop assigns result;
			*/
			while (num % c == 0) {
				result = c;
				num /= c;
			}
		}
		return result;
}
