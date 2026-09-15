class SVCOMP_linear_0237__311 {
    /*@ 
      @ requires n >= 0;
      @ ensures v1 >= 0 && v2 >= 0 && v3 >= 0 && v4 >= 0 && i >= 0 && j >= 0 && k >= 0;
      @ ensures v1 <= n && v2 <= n && v3 <= n && v4 <= n && i <= n && j <= n && k <= n;
      @ ensures v1 + v2 + v3 + v4 + i + j + k == n;
      @*/
    static void foo311(/*unsigned*/ int n) {

    /* unsigned */
    /*unsigned*/ int j;
    /*unsigned*/ int i;
    /*unsigned*/ int k;
    /*unsigned*/ int v4;
    /*unsigned*/ int v3;
    /*unsigned*/ int v2;
    /*unsigned*/ int v1;
    /*unsigned*/ int l;

    i = 0;
    k = 0;
    j = 0;
    l = 0;
    v4 = 0;
    v3 = 0;
    v2 = 0;
    v1 = 0;

    /*@
      @ maintaining 0 <= l && l <= n;
      @ maintaining v1 >= 0 && v2 >= 0 && v3 >= 0 && v4 >= 0 && i >= 0 && j >= 0 && k >= 0;
      @ maintaining v1 + v2 + v3 + v4 + i + j + k == l;
      @ decreases n - l;
      @*/
    while (l < n) {
    if((l % 7) == 0){
    v1 = v1 + 1;
    }
    else if((l % 6) == 0){
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