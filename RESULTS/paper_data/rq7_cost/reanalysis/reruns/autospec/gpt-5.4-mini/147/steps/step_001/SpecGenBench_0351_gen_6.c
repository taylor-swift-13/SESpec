int isPowerOfThree(int n);

int isPowerOfThree(int n) {

        int temp = n;
        /*@
        loop invariant temp == n || temp == n / 3 || temp == n / 9 || temp == n / 27 || temp == n / 81;
        loop invariant temp == 0 || temp % 3 != 0 || temp > 0;
        loop invariant temp >= 0;
        loop assigns temp;
        */
        while (temp != 0 && temp % 3 == 0) {
            temp /= 3;
        }
        return temp == 1;
}
