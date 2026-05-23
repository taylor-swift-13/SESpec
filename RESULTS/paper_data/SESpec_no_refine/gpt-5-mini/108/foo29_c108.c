int foo29_c108(int n);


/*@

ensures n % 5 == 0 && n % 3 != 0 ==> \result == 0 + 5;

ensures n % 5 == 0 && n % 3 == 0 ==> \result == 0 + 3 + 5;

ensures n % 5 != 0 && n % 3 == 0 ==> \result == 0 + 3;

ensures n % 5 != 0 && n % 3 != 0 ==> \result == 0;


assigns \nothing;
*/

int foo29_c108(int n) 
{

        int res = 0;
        if (n % 3 == 0) {
            res += 3;
        }
        if (n % 5 == 0) {
            res += 5;
        }
        return res;
}