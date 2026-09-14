                                                                            
extern int unknown_int(void);
extern int unknown_bool(void);
/*@
  requires x+y==k;
*/
void loopy_394(int i, int x, int y, int k) {
  int j = unknown_int();
  
  
  
  
  j=0;
  
  while (unknown_bool()) {
    if(j==i) {x++;y--;} else {y++;x--;} j++;
  }
  {;

}

  return;
}