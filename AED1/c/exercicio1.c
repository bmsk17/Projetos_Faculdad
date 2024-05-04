#include<stdio.h>


int main(){

int dia,mes,ano,validar,bisexto,b,c,d;
validar=0;
bisexto=0;
b=0;
c=0;
d=0;
scanf("%d/%d/%d",&dia,&mes,&ano);

bisexto=ano%4;
b=ano%100;
c=ano%400;
if(bisexto == b && b==c){
    d=1;
}else if(bisexto!=0){
    d=1;
}else if(bisexto!=b){
    d=1;
}

if(dia>31 || dia<1 || mes>12 || mes<1 || ano<1 || ano>9999 ){
        validar = 1;
}

if(mes==1 || mes==3 || mes==5 || mes==7 || mes==8 || mes==10 || mes==12){
    if(dia>31){
        validar = 1;
}}else if(mes==2 && d!=0 ){
    if(dia>29){
        validar = 1;
}}else if(mes==2 && d==0 ){
    if(dia>28){
        validar = 1;
}
}else if(mes==4 || mes==6 || mes==9 || mes==11){
    if(dia>30){
        validar = 1;
}}
if(validar == 0){
printf("True");
}else{
printf("False");
}
return 0;

}
