int foo256(int n);


/*@

ensures n / 400 == 0 && n / 100 == 0 ==> \result == (n - n / 4 + n / 4 * 2) % 7;

ensures n / 400 == 0 && n / 100 != 0 ==> \result == (n - n / 4 + n / 100 + (n / 4 - n / 100) * 2) % 7;

ensures n / 400 != 0 && n / 100 == 0 ==> \result == (n - n / 4 - n / 400 + (n / 4 + n / 400) * 2) % 7;

ensures n / 400 != 0 && n / 100 != 0 ==> \result == (n - n / 4 + n / 100 - n / 400 + (n / 4 - n / 100 + n / 400) * 2) % 7;


assigns \nothing;
*/

int foo256(int n) 
{

        int hund1 = n / 100;
        int hund4 = n / 400;
        int leap = n / 4;
        int ordd = n - leap ;
        if (hund1 != 0) {
            ordd += hund1 ;
            leap -= hund1 ;
        }
        if (hund4 != 0) {
            ordd -= hund4 ;
            leap += hund4 ;
        }
        int days = ordd + leap * 2;
        return days % 7;
}