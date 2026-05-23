int foo138(int a, int b, int factor);


/*@

ensures b % factor == 0 && a % factor == 0 ==> \result == 0;

ensures b % factor != 0 && a % factor == 0 ==> \result == 1;

ensures a % factor != 0 ==> \result == 1;


assigns \nothing;
*/

int foo138(int a, int b, int factor) 
{

        if(a % factor != 0) {
            return 1;
        }
        if(b % factor != 0) {
            return 1;
        }
        return 0;
}