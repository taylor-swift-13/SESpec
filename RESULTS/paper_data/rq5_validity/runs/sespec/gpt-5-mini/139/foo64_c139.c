int foo64_c139(int a, int b, int m);


/*@

ensures m % a != 0 ==> \result == 1;

ensures m % b != 0 && m % a == 0 ==> \result == 1;

ensures m % b == 0 && m % a == 0 ==> \result == 0;


assigns \nothing;
*/

int foo64_c139(int a, int b, int m) 
{

        return m % a != 0 || m % b != 0;
}