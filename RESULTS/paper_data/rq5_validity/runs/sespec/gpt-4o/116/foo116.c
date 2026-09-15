int foo116(int a, int b, int factor);


/*@
ensures (b % factor == 0) && (a % factor == 0) ==> (\result == 1);
ensures (b % factor != 0) && (a % factor == 0) ==> (\result == 0);
ensures (a % factor != 0) ==> (\result == 0);

assigns \nothing;
*/

int foo116(int a, int b, int factor) 
{

        if (a % factor != 0) {
            return 0;
        }
        if (b % factor != 0) {
            return 0;
        }
        return 1;
}