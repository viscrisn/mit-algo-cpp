#include<iostream>
#include<stdio.h>
#include<cstring>
#include<stdlib.h>
#include<cmath>
#include<vector>
#include<algorithm>
#include<map>
#include<functional>
#include<stack>
#include<set>
#include<queue>
#include<fstream>

using namespace std;

string sphinx_word;
string vocab[50];
int dynamic_array[50][50],n;

int labyrinth(int i1, int j1)
{
    if (i1 > j1)
    {
        return 0;
    }
    if (dynamic_array[i1][j1] != 99999999)
    {
        return dynamic_array[i1][j1];
    }
    set<int> sand_dict;
    for (int i=0; i < n; i++)
    {
        for (int j=i1; vocab[i].length() <= j1-j+1; j++)
        {
            if (sphinx_word.substr(j,vocab[i].length())==vocab[i])
            {
                sand_dict.insert(labyrinth(i1,j-1)^labyrinth(j+vocab[i].length(),j1));
            }
        }
    }
    for (int i=0;; i++)
    {
        if (sand_dict.count(i)==0)
        {
            dynamic_array[i1][j1]=i;
            return i;
        }
    }
}

int main()
{
    for (int i = 0; i < 50; i++)
    {
        for (int j = 0; j < 50; j++)
        {
            dynamic_array[i][j] = 99999999;
        }
    }
    cin>>sphinx_word;
    cin>>n;
    for (int j = 0; j < n; j++)
    {
        cin>>vocab[j];
    }
    if (labyrinth(0,sphinx_word.length()-1) == 0)
        printf("I DIE");
    else
        printf("I LIVE");
}

