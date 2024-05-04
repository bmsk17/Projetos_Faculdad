#include <stdio.h>
#include <string.h>

int main(){
char palavra[3][80],aux[80];
char alf[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','x','w','y','z'};
char alfb[26] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','X','W','Y','Z'};
int i,trocou=0,cont;

for(i=0;i<3;i++){
            scanf("%s",palavra[i]);
        }
printf("%s",palavra[1][1]);

do{
trocou=1;
for(i=0;i<3;i++){
    if(palavra[i][0] == alf[cont] || palavra[i][0] == alfb[cont]){
          if (strcmp(palavra[i],palavra[i-1]) < 0){
                    strcpy(aux,palavra[i-1]);
                    strcpy(palavra[i-1],palavra[i]);
                    strcpy(palavra[i], aux);
                    trocou=0;
        }
        }
}
}while(trocou!=1);

return 0 ;
}
