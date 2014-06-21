int main()
{
    ofstream arrayData("C:\\arrat.txt"ios::app);

    if(!arrayData)
    {
        cout<<"Error\n";
        return 0;
    }
    for(int i =0; i <size;i++)
    {
        arrayData<<array[a]<<endl;
    }
    arrayData.close();
    return 0;
}
