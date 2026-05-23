/*@ 
    requires n >= 1;
    ensures \result == (\sum integer i; 1 <= i <= n && i % 2 != 0; i) / 
                      (\numof integer i; 1 <= i <= n && i % 2 != 0; i);
    assigns \nothing;
*/
int averageOdd(int n) {

        int sum = 0;
        int count = 0;
        /*@
        loop invariant 1 <= i <= n + 1;
        loop invariant sum == (\sum integer j; 1 <= j < i && j % 2 != 0; j);
        loop invariant count == (\numof integer j; 1 <= j < i && j % 2 != 0; j);
        loop assigns i, sum, count;
        loop variant n - i;
        */
        for (int i = 1; i <= n; i++) {
            if (i % 2 != 0) {
                sum += i;
                count++;
            }
        }
        return sum / count;
}
