int getFirstSetBitPos(int num);

int getFirstSetBitPos(int num) {

		int result = 1;
		while ((num & 1) == 0) {
			num >>= 1;
			result++;
		}
		return result;
}
