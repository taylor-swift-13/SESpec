int highestPowerOf2(int num);

int highestPowerOf2(int num) {

		int max = 1;
		while (max <= num) {
			max *= 2;
		}
		return max / 2;
}
