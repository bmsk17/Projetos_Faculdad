for(i=0;i<20;i++){
    scanf(" %d",&n[i]);
    if(maior<n[i]){
        maior=n[i];
    }
}

for(i=0;i<20;i++){
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
for(i=0;i<z;i++){
    printf("\n%d\n ",primo[i]);
}
}
