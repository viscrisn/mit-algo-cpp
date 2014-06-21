#include <iostream>
#include <cstdio>

int main(){
    int t,i;
    int alphabet[26];
    int letters[12] = {4,7,8,11,12,14,15,17,18,19,20,21};
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

        alphabet[4] = alphabet[4]/3;
        alphabet[14] = alphabet[14]/2;

        for (int j=0;j<12;j++){
            if (alphabet[letters[j]]<min)
                min=alphabet[letters[j]];
        }

        printf("%d",min);
        if (i<t-1)
            printf("\n");

    }
    return 0;
}
