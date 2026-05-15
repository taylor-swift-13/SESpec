int unknown();

void foo427(){
    int x = 0;
    int y = 500000;

    while(x < 1000000) {
	    if (x < 500000) {
	        x = x + 1;
	    }
        else {
            x = x + 1;
            y = y + 1;
	    }
    }

}
