int findDivisor(int num, int z);

int findDivisor(int num, int z) {

		if (z < 0) {
			z = -z;
		}
		int result = 0;
		for (int loop = 1; loop <= z; loop++) {
			if (num % loop == 0) {
				result = result + 1;
			}
		}
		return result;
}
