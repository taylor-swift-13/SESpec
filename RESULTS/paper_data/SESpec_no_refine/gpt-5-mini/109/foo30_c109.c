int foo30_c109(int n);


/*@

ensures n % 5 == 0 && n % 3 != 0 ==> \result == 0 + 0 + 5;

ensures n % 5 != 0 && n % 3 != 0 ==> \result == 0 + 0 + 0;

ensures n % 5 == 0 && n % 3 == 0 ==> \result == 0 + 3 + 5;

ensures n % 5 != 0 && n % 3 == 0 ==> \result == 0 + 3 + 0;


assigns \nothing;
*/

int foo30_c109(int n) 
{

        int res = 0;
        res += ((n % 3 == 0) ? 3 : 0);
        res += ((n % 5 == 0) ? 5 : 0);
        return res;
}