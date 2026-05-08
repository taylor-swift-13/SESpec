int foo51(int year);

int foo51(int year) {

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
