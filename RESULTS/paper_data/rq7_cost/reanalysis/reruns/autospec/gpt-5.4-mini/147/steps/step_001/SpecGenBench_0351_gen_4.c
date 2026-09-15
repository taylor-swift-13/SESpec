int isPowerOfThree(int n);

int isPowerOfThree(int n) {

        int temp = n;
        /*@
        loop invariant n == 0 || temp > 0;
        loop invariant n > 0 ==> (\exists integer k; temp * (3^k) == n);
        loop invariant temp >= 0;
        loop assigns temp;
        */
        while (temp != 0 && temp % 3 == 0) {
            temp /= 3;
        }
        return temp == 1;
}
