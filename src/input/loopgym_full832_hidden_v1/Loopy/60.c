                                                                                                              
extern int unknown_int(void);

/*@
  requires 0 <= b;
*/
void loopy_60(int a, int b) {
    
    
    int res, cnt;
    
    res = a;
    cnt = b;
    while (cnt > 0) {
	cnt = cnt - 1;
	res = res + 1;
    }
    {;

}

    return;
}