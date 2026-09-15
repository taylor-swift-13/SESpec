int isPowerOfThree(int n);

int isPowerOfThree(int n) {

        int temp = n;
        /*@
        loop invariant temp == n;
        loop invariant temp >= 0;
        loop invariant temp == 0 || temp > 0;
        loop invariant n == 0 || temp > 0;
        loop invariant n != 0 ==> temp != 0;
        loop invariant \exists integer k; k >= 0 && n == temp * (3^k);
        loop invariant temp == n || temp == n / 3 || temp == n / 9 || temp == n / 27 || temp == n / 81;
        loop invariant temp == n || temp % 3 != 0 || temp == 0 || temp > 0;
        loop invariant temp == n / (int)pow(3, k);
        loop invariant temp == n / ((int)1) || temp > 0;
        loop invariant temp == 1 || temp % 3 != 0;
        loop invariant temp == 0 || temp > 0;
        loop invariant temp == 0 || temp % 3 != 0 || temp > 0;
        loop invariant temp == 0 || temp % 3 != 0 || temp == n;
        loop invariant temp == 0 || (\exists integer k; k >= 0 && n == temp * (3^k));
        loop invariant n > 0 ==> temp > 0;
        loop invariant n > 0 ==> (\exists integer k; temp * (3^k) == n);
        loop invariant n == temp * (3 ^ 0);
        loop invariant n == 0 || temp > 0;
        loop invariant n != 0 ==> temp != 0;
        loop invariant \exists integer k; k >= 0 && n == temp * (3^k);
        loop invariant 0 <= temp;
        loop invariant 0 < temp;
        loop assigns temp;
        */
        while (temp != 0 && temp % 3 == 0) {
            temp /= 3;
        }
        return temp == 1;
}
