
#include <stdio.h>

int main(){
  int i,n,j;
  float result=1;
  i=0;
  scanf("%d",&n);
  for(j=0;j<n;j++){
        result=1;
  for(i=1;i<=j;i++){
     result=result*i;
  }
  printf("\nFatorial de %d = %.0f\n",j,result);
  }
  return result;
}
