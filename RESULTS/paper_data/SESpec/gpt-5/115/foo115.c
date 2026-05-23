int foo115(int a, int b, int factor);


/*@
ensures (b % factor == 0) && (a % factor == 0) ==> (\result == 1);
ensures (b % factor != 0) && (a % factor == 0) ==> (\result == 0);
ensures (a % factor != 0) ==> (\result == 0);

assigns \nothing;
*/

int foo115(int a, int b, int factor) 
{

        return a % factor == 0 && b % factor == 0;
}