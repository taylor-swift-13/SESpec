int unknown();

void foo333() {

    int c = 0;

    while (unknown()) {
        {
          if (unknown()) {
            if ( c != 4 )
            {
            c  = c + 1;
            }
          } else {
            if (c == 4)
            {
            c  = 1;
            }
          }

        }

    }

}
