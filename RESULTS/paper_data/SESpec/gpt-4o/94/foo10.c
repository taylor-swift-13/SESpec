int foo10(int n);


/*@

ensures n % 4 != 0 ==> \result == 1;

ensures n % 4 == 0 ==> \result == 0;


assigns \nothing;
*/

int foo10(int n) 
{

        return n % 4 != 0;
}