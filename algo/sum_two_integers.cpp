// 371. Sum of Two Integers

int getSum(int a, int b) {
  if (b)
    return getSum(a ^ b, (a & b) << 1);
  return a;
}

 // Calculate the sum of two integers a and b, but you are not allowed to use the operator + and -

uint plus(uint a,uint b){
  return ((a<<16)|1)*((b<<16)|1)>>16;
}
int getSum(int _a,int _b){
  uint a=_a,b=_b,a1=a&0xFFFF,b1=b&0xFFFF,a2=a>>16,b2=b>>16;
  uint c=plus(a2,b2);
  if (b1>(~a1&0xFFFF))c=plus(c,1);
  c=(c<<16)|plus(a1,b1);
  return c;
}
