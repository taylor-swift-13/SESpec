int foo67_helper1_c142(int x);
int foo67_c142(int x);


/*@

ensures x % 2 != 0 ==> \result == 1;

ensures x % 2 == 0 ==> \result == 0;


assigns \nothing;
*/

int foo67_c142(int x) 
{

         	return x%2 != 0;
}