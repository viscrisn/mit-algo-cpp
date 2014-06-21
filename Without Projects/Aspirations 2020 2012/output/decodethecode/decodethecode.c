# include "decodethecode.h"
#include<string.h>
#include<stdio.h>
#include<iostream>
#include<stdlib.h>

using namespace std;

char* decodeCode(char* encodedString)
{
    char cur;
    int i=0;
    char array[10][5];
    array[0][1] = 32;

    array[2][1] = 'a';array[2][2] = 'b';array[2][3] = 'c';
    array[3][1] = 'd';array[3][2] = 'e';array[3][3] = 'r';
    array[4][1] = 'g';array[4][2] = 'h';array[4][3] = 'i';
    array[5][1] = 'j';array[5][2] = 'k';array[5][3] = 'l';
    array[6][1] = 'm';array[6][2] = 'n';array[6][3] = 'o';

    array[7][1] = 'p';
    array[7][2] = 'q';
    array[7][3] = 'r';
    array[7][4] = 's';

    array[8][1] = 't';
    array[8][2] = 'u';
    array[8][3] = 'v';

    array[9][1] = 'w';
    array[9][2] = 'x';
    array[9][3] = 'y';
    array[9][4] = 'z';

    char*  decodedString = "";
    int len = strlen(encodedString);
    char temporary[len];

    int k =0;

    int count=0;
    char prev = encodedString[i++];
    while((cur=encodedString[i++])!='\0')
    {
        if((cur!='2')&&(cur!='3')&&(cur!='4')&&(cur!='5')&&(cur!='6')&&(cur!='7')&&(cur!='8')&&(cur!='9')&&(cur!='0')&&(cur!='#'))
        {
            return '\0';
        }
        if(prev==cur)
        {
            count++;
        }
        else
        {
            if(prev != '#')
            {
               // decodedString[k++] = array[prev - 48][count + 1];
               temporary[k++] = array[prev - 48][count + 1];
            }
            count = 0;
        }
        prev = cur;
    }
    temporary[k++] = array[prev - 48][count + 1];
    temporary[k++]='\0';
    decodedString = (char *) malloc(k * sizeof(char));

    strcpy(decodedString,temporary);
    return  decodedString;
}
