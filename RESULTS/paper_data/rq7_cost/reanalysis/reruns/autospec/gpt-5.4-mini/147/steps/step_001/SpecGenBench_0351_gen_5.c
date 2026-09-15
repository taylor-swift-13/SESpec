int isPowerOfThree(int n);

int isPowerOfThree(int n) {

        int temp = n;
        /*@
        loop invariant temp == 0 || temp > 0;
        loop invariant n == temp * (3 ^ 0);
        loop invariant temp == 0 || (\exists integer k; k >= 0 && n == temp * (3^k));
        loop assigns temp;
        */
        while (temp != 0 && temp % 3 == 0) {
            temp /= 3;
        }
        return temp == 1;
}
