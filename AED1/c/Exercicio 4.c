#include <stdio.h>
#include <string.h>

int maiuscula (int i) {
	if (i>90) {
		i=i-32;
	}
	return i;
}

int ordenar(char *a,char *b){
int x,y,repetir=0,i=0;
while (a[i]!='\0' && b[i]!='\0') {
		x=a[i];
		y=b[i];
		x=maiuscula(x);
		y=maiuscula(y);
		repetir=x-y;
		if (repetir!=0) {
			return repetir;
		}
		i++;
	}
	repetir=strlen(a)-strlen(b);
	return repetir;

}

int main(){
char palavra[100][80],aux[80];
int i,trocou=0;

for(i=0;i<100;i++){
            scanf("%s",palavra[i]);
        }
do{
trocou=1;
for(i=0;i<100;i++){
            if (ordenar(palavra[i],palavra[i+1]) > 0){
                    strcpy(aux,palavra[i]);
                    strcpy(palavra[i],palavra[i+1]);
                    strcpy(palavra[i+1],aux);
                    trocou=0;
}
}
}while(trocou!=1);

for(i=0;i<100;i++){
        printf("%s",palavra[i]);
        printf("\n");
}

return 0 ;
}

