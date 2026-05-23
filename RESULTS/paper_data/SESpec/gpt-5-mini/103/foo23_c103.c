int foo23_c103(int n);


/*@

ensures n % 2 == 0 ==> \result == 1;

ensures n % 2 != 0 ==> \result == 0;


assigns \nothing;
*/

int foo23_c103(int n) 
{

        return n % 2 == 0;
}