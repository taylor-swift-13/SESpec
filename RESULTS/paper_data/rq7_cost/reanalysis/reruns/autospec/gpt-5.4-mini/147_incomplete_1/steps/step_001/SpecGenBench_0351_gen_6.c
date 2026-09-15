int isPowerOfThree(int n);

int isPowerOfThree(int n) {

        int temp = n;
        /*@
        loop invariant n == 0 || n > 0;
        loop invariant temp >= 0;
        loop invariant (\exists integer k; k >= 0 && temp * (3^k) == n);
        loop invariant temp == 0 || temp % 3 != 0 || temp == n;
        loop assigns temp;
        */
        while (temp != 0 && temp % 3 == 0) {
            temp /= 3;
        }
        return temp == 1;
}
