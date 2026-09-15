int foo118(int a, int b, int m);


/*@
ensures (m % b == 0) && (m % a == 0) ==> (\result == 1);
ensures (m % b != 0) && (m % a == 0) ==> (\result == 0);
ensures (m % a != 0) ==> (\result == 0);

assigns \nothing;
*/

int foo118(int a, int b, int m) 
{

        if(m % a != 0) {
            return 0;
        }
        if(m % b != 0) {
            return 0;
        }
        return 1;
}