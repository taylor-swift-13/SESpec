int isPowerOfThree(int n);

int isPowerOfThree(int n) {

        int temp = n;
        /*@
        loop invariant temp > 0;
        loop invariant \exists integer k; k >= 0 && n == temp * (3^k);
        loop invariant temp == 0 || temp % 3 != 0 || temp >= 1;
        loop assigns temp;
        */
        while (temp != 0 && temp % 3 == 0) {
            temp /= 3;
        }
        return temp == 1;
}
