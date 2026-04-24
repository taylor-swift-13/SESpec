int getFirstSetBitPos(int size);

int getFirstSetBitPos(int size) {

		int ret = 1;
		while ((size & 1) == 0) {
			size >>= 1;
			ret++;
		}
		return ret;
}
