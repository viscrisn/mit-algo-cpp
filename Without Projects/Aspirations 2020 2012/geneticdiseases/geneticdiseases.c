#include "geneticdiseases.h"
#include<string.h>

char rectifyDiseases(char* pattern1 , char* pattern2)
{
	char res= '\0';

	int len1=strlen(pattern1);
	int len2=strlen(pattern2);
	if(len1>10)
        return res;
    if(len2>10)
        return res;

    int i=0;
    for(i=0;i<len1;i++)
    {
        if((pattern1[i]!='J')&&(pattern1[i]!='M')&&(pattern1[i]!='S')&&(pattern1[i]!='F'))
        return res;
    }

    for(i=0;i<len2;i++)
    {
        if((pattern2[i]!='J')&&(pattern2[i]!='M')&&(pattern2[i]!='S')&&(pattern2[i]!='F'))
        return res;
    }

    return 'B';
}
