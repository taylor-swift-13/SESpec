int evenBitSetNumber(int n);

int evenBitSetNumber(int n) {

        int count = 0;
        int res = 0;
        int temp = n;
        while (temp > 0) {
            if (count % 2 == 1) {
                res |= (1 << count);
            }
            count++;
            temp >>= 1;
        }
        return (n | res);
}
