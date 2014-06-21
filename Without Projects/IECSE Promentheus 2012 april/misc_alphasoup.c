#include <iostream>
#include <cstdio>

int main(){
    int t,i;
    int alphabet[26];
    int letters[8] = {0,2,4,7,10,15,17,20};
    char c;
    int min;

    scanf("%d",&t);
    getchar();

    for (i=0;i<t;i++){
        min=1000;
        for (int x=0;x<26;x++)
            alphabet[x]=0;

        while((c=getchar())!=10){
            if (c==' ')
                continue;
            else{
                alphabet[c-65]++;
            }
        }

        alphabet[2] = alphabet[2]/2;

        for (int j=0;j<8;j++){
            if (alphabet[letters[j]]<min)
                min=alphabet[letters[j]];
        }

        printf("Case #%d: %d",i+1,min);
        if (i<t-1)
            printf("\n");

    }
    return 0;
}
