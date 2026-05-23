/*@ 
    requires n > 0;
    ensures \result == 0 || \result == 3 || \result == 5 || \result == 8;
    ensures \result == 3 <==> (n % 3 == 0 && n % 5 != 0);
    ensures \result == 5 <==> (n % 5 == 0 && n % 3 != 0);
    ensures \result == 8 <==> (n % 3 == 0 && n % 5 == 0);
    ensures \result == 0 <==> (n % 3 != 0 && n % 5 != 0);
    assigns \nothing;
*/
int fizzBuzz(int n) {

        int res = 0;
        res += ((n % 3 == 0) ? 3 : 0);
        res += ((n % 5 == 0) ? 5 : 0);
        return res;
}
