int averageEven(int n);

 /*@
     requires n >= 2;
     assigns \nothing;
     ensures \result == n / 2 + 1;
 */
int averageEven(int n) {

        int sum = 0;
        int count = 0;
        /*@
            loop invariant 1 <= i <= n+1;
            loop invariant sum == \sum integer j; 1 <= j < i && j % 2 == 0; j;
            loop invariant count == \sum integer j; 1 <= j < i && j % 2 == 0; 1;
            loop assigns i, sum, count;
            loop variant n - i + 1;
        */
        for (int i = 1; i <= n; i++) {
            if (i % 2 == 0) {
                sum += i;
                count++;
            }
        }
        return sum / count;
}
