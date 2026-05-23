int foo65(int n);


/*@

ensures n % 2 != 0 && n != 1 ==> \result == n;

ensures n % 2 == 0 && n != 1 ==> \result == n / 2;

ensures n == 1 ==> \result == 0;


assigns \nothing;
*/

int foo65(int n) 
{

        if (n == 1) {
            return 0;
        }
        if (n % 2 == 0) {
            return n / 2;
        }
        return n;
}