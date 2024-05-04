#include<stdio.h>

int main(){
int i,j,maior=0,somat,nd=0,l=0,somato=0,somap=0,somapt=0,z=0,h=0,s=0;
int n[20],divisores[20],primo[20];

for(i=0;i<20;i++){
    scanf(" %d",&n[i]);
    if(maior<n[i]){
        maior=n[i];
    }
}

for(i=0;i<20;i++){
        somat=0;
        for(j=1;j<=n[i];j++){
         if(n[i]%j == 0){
            somat++;
            printf("\n%d / %d = %d",n[i],j,n[i]%j);
        }
        }
        printf("\nSoma total = %d\n",somato);
        if(somato<=somat){
            somato=somat;
            nd=n[i];
        }
        printf("\n%d soma = %d\n",n[i],somat);
        somat=0;
    }

printf("%d: ",nd);
for(j=1;j<=nd;j++){
                if(nd%j == 0){
                    printf("%d ",j);
                    }
        }
    }
