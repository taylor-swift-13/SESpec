int foo128(int year);


/*@
ensures (year % 400 == 0) && (year % 100 == 0) && (year % 4 == 0) ==> (\result == 1);
ensures (year % 400 != 0) && (year % 100 == 0) && (year % 4 == 0) ==> (\result == 0);
ensures (year % 100 != 0) && (year % 4 == 0) ==> (\result == 1);
ensures (year % 4 != 0) ==> (\result == 0);

assigns \nothing;
*/

int foo128(int year) 
{

        int leap = 0;

        if (year % 4 == 0)
        {
            if ( year % 100 == 0)
            {
                if ( year % 400 == 0)
                    leap = 1;
                else
                    leap = 0;
            }
            else
                leap = 1;
        }
        else
            leap = 0;

	return leap;
}