int hoo31(int A, int R) {
    int u,v,r;

    u=2*R+1;
    v=1;
    r=R*R-A;

    while(r>0) {
      r=r-v;
      v=v+2;
    }

  }
