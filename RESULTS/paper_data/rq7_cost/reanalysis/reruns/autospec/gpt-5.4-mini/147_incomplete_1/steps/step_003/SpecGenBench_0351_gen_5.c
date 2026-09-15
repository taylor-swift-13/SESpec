int isPowerOfThree(int n);

int isPowerOfThree(int n) {

        int temp = n;
        /*@
        loop invariant temp <= n;
        loop invariant temp == 0 || temp > 0;
        loop invariant temp == 0 || temp % 3 == 0 || temp % 3 == 1 || temp % 3 == 2;
        loop invariant temp == n || temp < n;
        loop invariant n == 0 || temp >= 0;
        loop invariant temp >= 0 || temp <= 0;
        loop invariant temp == n;
        loop invariant temp == n || temp > 0;
        loop invariant temp == n || temp == 0 || temp > 0;
        loop invariant temp == n || temp < n;
        loop invariant temp == n / 3 || temp == n;
        loop invariant temp == n / (int)pow(3, k);
        loop invariant temp == n / (int)pow(3, 0);
        loop invariant temp == n / (int)pow(3, 0) || temp > 0;
        loop invariant temp == n / (int)\pow(3, k);
        loop invariant temp == n / (int)(pow(3, k));
        loop invariant temp == n / (3 ^ 0) || temp == n;
        loop invariant temp == 0 || temp >= 1;
        loop invariant temp == 0 || temp > 0;
        loop invariant temp == 0 || temp == 1 || temp % 3 != 0;
        loop invariant temp == 0 || temp % 3 == 0 || temp == 1;
        loop invariant temp == 0 || temp % 3 == 0 || temp % 3 == 1 || temp % 3 == 2;
        loop invariant temp == 0 || temp % 3 == 0 || temp % 3 != 0;
        loop invariant temp == 0 || temp % 3 != 0 || temp >= 1;
        loop invariant temp == 0 || temp % 3 != 0 || temp == n;
        loop invariant temp == 0 || temp % 3 != 0 || temp <= n;
        loop invariant temp <= n;
        loop invariant temp <= n || n <= temp;
        loop invariant temp <= n || n < 0;
        loop invariant temp % 3 == 0 || temp == n;
        loop invariant temp % 3 == 0 || temp % 3 != 0;
        loop invariant temp != 0;
        loop invariant n == temp || n == 3 * temp || n == 9 * temp;
        loop invariant n == temp * 1 || n == 0;
        loop invariant n == 0 || temp >= 1;
        loop invariant n == 0 || temp == 0 || temp % 3 == 0 || temp % 3 == 1 || temp % 3 == 2;
        loop invariant n == 0 || n > 0;
        loop invariant n % 3 == 0 || n % 3 != 0;
        loop invariant \exists integer k; k >= 0 && temp * (3^k) == n;
        loop invariant \exists integer k; k >= 0 && temp * (3^k) <= n;
        loop invariant \exists integer k; k >= 0 && n == temp * (3^k);
        loop invariant 0 <= temp;
        loop invariant 0 < temp;
        loop invariant (\exists integer k; k >= 0 && temp * (3^k) == n);
        loop assigns temp;
        */
        while (temp != 0 && temp % 3 == 0) {
            temp /= 3;
        }
        return temp == 1;
}
