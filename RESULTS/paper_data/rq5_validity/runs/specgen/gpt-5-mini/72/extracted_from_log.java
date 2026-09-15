class SVCOMP_linear_0236__310 {
    /*@ 
      @ requires n >= 0;
      @ 
      @ ensures v2 == (\sum int x; 0 <= x && x < n && (x % 6) == 0; 1);
      @ ensures v3 == (\sum int x; 0 <= x && x < n && (x % 6) != 0 && (x % 5) == 0; 1);
      @ ensures v4 == (\sum int x; 0 <= x && x < n && (x % 6) != 0 && (x % 5) != 0 && (x % 4) == 0; 1);
      @ ensures i  == (\sum int x; 0 <= x && x < n && (x % 6) != 0 && (x % 5) != 0 && (x % 4) != 0 && (x % 3) == 0; 1);
      @ ensures j  == (\sum int x; 0 <= x && x < n && (x % 6) != 0 && (x % 5) != 0 && (x % 4) != 0 && (x % 3) != 0 && (x % 2) == 0; 1);
      @ ensures k  == (\sum int x; 0 <= x && x < n && (x % 6) != 0 && (x % 5) != 0 && (x % 4) != 0 && (x % 3) != 0 && (x % 2) != 0; 1);
      @ ensures i + j + k + v2 + v3 + v4 == n;
      @*/
    static void foo310(unsigned int n) {
    
    unsigned
    /*@ spec_public @*/ unsigned int j;
    /*@ spec_public @*/ unsigned int i;
    /*@ spec_public @*/ unsigned int k;
    /*@ spec_public @*/ unsigned int v4;
    /*@ spec_public @*/ unsigned int v3;
    /*@ spec_public @*/ unsigned int v2;
    /*@ spec_public @*/ unsigned int l;
    
    i = 0;
    k = 0;
    j = 0;
    l = 0;
    v4 = 0;
    v3 = 0;
    v2 = 0;
    
    /*@ 
      @ maintaining 0 <= l && l <= n;
      @ maintaining i >= 0 && j >= 0 && k >= 0 && v2 >= 0 && v3 >= 0 && v4 >= 0;
      @ maintaining i == (\sum int x; 0 <= x && x < l && (x % 6) != 0 && (x % 5) != 0 && (x % 4) != 0 && (x % 3) == 0; 1);
      @ maintaining j == (\sum int x; 0 <= x && x < l && (x % 6) != 0 && (x % 5) != 0 && (x % 4) != 0 && (x % 3) != 0 && (x % 2) == 0; 1);
      @ maintaining k == (\sum int x; 0 <= x && x < l && (x % 6) != 0 && (x % 5) != 0 && (x % 4) != 0 && (x % 3) != 0 && (x % 2) != 0; 1);
      @ maintaining v2 == (\sum int x; 0 <= x && x < l && (x % 6) == 0; 1);
      @ maintaining v3 == (\sum int x; 0 <= x && x < l && (x % 6) != 0 && (x % 5) == 0; 1);
      @ maintaining v4 == (\sum int x; 0 <= x && x < l && (x % 6) != 0 && (x % 5) != 0 && (x % 4) == 0; 1);
      @ maintaining i + j + k + v2 + v3 + v4 == l;
      @ decreases n - l;
      @*/
    while (l < n) {
    if((l % 6) == 0){
    v2 = v2 + 1;
    }
    else if ((l % 5) == 0){
    v3 = v3 + 1;
    }
    else if ((l % 4) == 0) {
    v4 = v4 + 1;
    }
    else if((l % 3) == 0){
    i = i + 1;
    }
    else if((l % 2) == 0){
    j = j + 1;
    }
    else{
    k = k + 1;
    }
    l = l + 1;
    }
    
    }
    }