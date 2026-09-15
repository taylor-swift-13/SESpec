int isPowerOfThree(int n);

int isPowerOfThree(int n) {

        int temp = n;
        /*@
        loop invariant temp == n / (int)pow(3, k);
        loop invariant temp >= 0;
        loop invariant temp == 0 || temp % 3 != 0 || temp == n;
        loop assigns temp;
        */
        while (temp != 0 && temp % 3 == 0) {
            temp /= 3;
        }
        return temp == 1;
}
