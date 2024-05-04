#include<stdio.h>

int main(){
int i,j,maior=0,somat,nd=0,somato=0,somap=0,z=0,h=0,aux;
int n[100],primo[100];

for(i=0;i<100;i++){
    scanf(" %d",&n[i]);
    if(maior<=n[i]){
        maior=n[i];
    }
}
/* DIVIDIR  */
for(i=0;i<100;i++){
        somat=0;
        for(j=1;j<=n[i];j++){
         if(n[i]%j == 0){
            somat++;
        }
        }
        if(somato<=somat){
            somato=somat;
            nd=n[i];
        }
        somat=0;
    }
/* PRIMO  */
for(i=0;i<100;i++){
    somap=0;
    h=n[i];
    for(j=1;j<=n[i];j++){
        if(n[i]%j == 0){
        somap++;
        }
        }
        if(somap == 2){
            if(i!= 1){
                primo[z]=h;
                z++;
            }
        }
        somap=0;
}
printf("%d: ",nd);
for(j=2;j<=nd-1;j++){
                if(nd%j == 0){
                    printf("%d ",j);
                    }
        }
printf("\n%d\n",maior);
/* Ordenar Vetor Primo*/
for(i=0;i<=z-1;i++){
        aux=0;
    if(primo[i]>primo[i+1]){
        aux=primo[i];
        printf("\nVetor %d = %d\n",i,aux);
        primo[i] = primo[i+1];
        printf("Vetor %d = %d\n",i,primo[i+1]);
        primo[i+1]=aux;
        printf("Vetor %d = %d\n",i+1,aux);
        printf("primo[i] = %d\n",primo[i]);
        printf("primo[i+1] = %d\n",primo[i+1]);
        printf("aux = %d\n",aux);
    }
}
for(i=0;i<z;i++){
            printf("%d ",primo[i]);
     }

}
