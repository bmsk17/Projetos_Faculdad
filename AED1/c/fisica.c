#include<stdio.h>
#include<math.h>

int main(){
int i;
float h,r0,g,v0,n0,n9,s,x,r,n,n00,m1,m2,a1,a2;
g=980;
i=0,m1=0,m2=0,a1=0,a2=0;
printf("Altura inicial (CM):  \n");
scanf("%f",&h);
printf("Alcance no angulo zero (CM):  \n");
scanf("%f",&r0);
v0=r0*sqrt(g/(2*h));
printf(" \nVelocidade inicial = %.2f CM/s",v0);

printf(" \nDe (angulo): ");
scanf("%f",&n0);
printf(" \nIntervalo de cima para baixo (angulo): ");
scanf("%f",&n9);
n00=n0+n9;
for(n=n00;n>=n0;n--){
    x=(n/360)*2*3.14159;
    r=(v0*cos(x)*((v0*sin(x))+sqrt(((pow(v0,2))*(pow(sin(x),2)))+(2*g*h))))/g;
    printf(" \nANGULO(graus) = %.1f ",n);
    printf("       Alcance(CM) = %.1f",r);
    if (m1<r){
        m1=r;
        a1=n;
    }
}
n00=n0-n9;
for(n=n0;n>n00;n--){
    x=(n/360)*2*3.14159;
    r=(v0*cos(x)*((v0*sin(x))+sqrt(((pow(v0,2))*(pow(sin(x),2)))+(2*g*h))))/g;
    printf(" \nANGULO(graus) = %.1f ",n);
    printf("       Alcance(CM) = %.1f",r);
     if (m2<r){
        m2=r;
        a2=n;
    }
}
if(m1>m2){
    printf("\nMelhor Angulo : %.1f = %.2f",a1,m1);
}else{
    printf("\nMelhor Angulo : %.1f = %.2f",a2,m2);
}
}
