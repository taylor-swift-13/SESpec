int foo40_c117(int a, int b, int m);


/*@

ensures m % b == 0 && m % a == 0 ==> \result == 1;

ensures m % b != 0 && m % a == 0 ==> \result == 0;

ensures m % a != 0 ==> \result == 0;


assigns \nothing;
*/

int foo40_c117(int a, int b, int m) 
{

        return m % a == 0 && m % b == 0;
}