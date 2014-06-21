int check(int x,int y,int m,int n)
{
    if(x>m-1||x>n-1)
        return 0;
    if(x<0||y<0)
        return 0;
    return 1;
}
int checkdiagonal(char **arr,int m, int n, int x,int y)
{
    int x1=x;
    int y1=y;
    int count=0;
    while(check(x1,y1,m,n))

    {
        x1--;
        y1--;
        if(arr[x1][y1]!='E')
            count++;
    }
    x1=x;
    y1=y;
    while(check(x1,y1,m,n))
    {
        x1--;
        y1--;
        if(arr[x1][y1]!='E')
            count++;
    }
    x1=x;
    y1=y;
    while(check(x1,y1,m,n))
    {
        x1--;
        y1--;
        if(arr[x1][y1]!='E')
            count++;
    }
    x1=x;
    y1=y;
    while(check(x1,y1,m,n))
    {
        x1--;
        y1--;
        if(arr[x1][y1]!='E')
            count++;
    }
    return count;
    }
