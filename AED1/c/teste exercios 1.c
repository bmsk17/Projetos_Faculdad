#include<stdio.h>

int main(){
int i,j,maior=0,somat,nd=0,l=0,somato=0,somap=0,somapt=0,z=0,h=0;
int n[20],divisores[20],primo[20];

for(i=0;i<20;i++){
    scanf(" %d",&n[i]);
    if(maior<n[i]){
        maior=n[i];
    }
}

for(i=0;i<20;i++){
        somap=0;
        h=n[i];
        printf("%d",n[i]);
        for(j=1;j<=n[i];j++){

         if(n[i]%j == 0){
         printf("\n%d / %d = %d\n",n[i],j,n[i]%j);
            somap++;
        }
        }
        printf("SOMA = %d",somap);
        if(somap == 2){
            if(i!= 1){
             primo[z]=h;
            printf("Vetor primo = %d",primo[z]);
            z++;
            }
        }
        somap=0;
        printf("SOMA = %d\n",somap);
    }
    for(i=0;i<z;i++){
            printf("\n%d\n ",primo[i]);
     }
    }
