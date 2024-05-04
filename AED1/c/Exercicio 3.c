#include<stdio.h>
double round(double number)
{
    return (number >= 0) ? (int)(number + 0.5) : (int)(number - 0.5);
}

float fatorial(float n){
  int i;
  float result=1;
  i=0;
  for(i=1;i<=n;i++){
     result=result*i;
  }
  return result;
}
int triangulo(float n,float k){
  float result=0,ni,ki,subi;
  int resultt=0;
  ni=fatorial(n);
  ki=fatorial(k);
  subi=fatorial(n-k);
  result=ni/(ki*subi);
  resultt=round(result);
  return resultt;
  }

int main(){
  int qtd,j,x1=0,i=0,y1,soma=0,n,k,t,z=0;
  scanf("%d\n",&n);
  scanf("%d\n",&qtd);
  scanf("%d",&k);
  float x[qtd],y[qtd];
  x1=n;
  do{
    y1=0;
    for(j=0;j<=n;j++){
        t=triangulo(n,j);
        if(t%k == 0){
            if(qtd<=0){
            break;
        }
        if(y1>x1+1){
            break;
        }
            x[z]=x1;
            y[z]=y1;
            soma++;
            z++;

        }
        y1++;
        qtd--;
    }
    x1++;
    n++;
  }while (qtd>0);
  printf("%d\n",soma);
  for(i=0;i<soma;i++){
     printf("(%.0f,%.0f)\n",x[i],y[i]);

  }

}
