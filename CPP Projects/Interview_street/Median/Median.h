double Median(int num_array[],int no_of_ele)
{

    if(no_of_ele==0)
    {
        return -1;
    }
    else if(no_of_ele%2==1)
    {
        return num_array[no_of_ele/2]/1.0;
    }
    else
    {
        return (num_array[no_of_ele/2]
                + num_array[no_of_ele/2 -1])/2.0;
    }

}
