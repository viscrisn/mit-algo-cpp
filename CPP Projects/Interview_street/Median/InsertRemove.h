void Insert(int num_array[],int &no_of_ele,int element)
{
    no_of_ele++;
    int pos=0;
    for (pos=0;pos<no_of_ele-1;pos++ )
    {
    	if(num_array[pos]<element)
    	{
    	    continue;
    	}
        break;
    }

    for (int i=no_of_ele-1;i>pos;i-- )
    {
    	num_array[i]=num_array[i-1];
    }
    num_array[pos]=element;

}

int Remove(int num_array[],int &no_of_ele,int element)
{
    int position = -1;
    int first = 0;
    int last = no_of_ele-1;
    int mid = (first+last)/2;

    while((mid<=last))
    {
        mid = (first+last)/2;
        if(num_array[mid]==element)
        {
            position = mid;
            break;
        }
        else if(element>num_array[mid])
        {
            first = mid+1;
        }
        else if(element<num_array[mid])
        {
            last = mid;
        }
    }
    if(position == -1)
    {
        return -1;
    }

    for (int i=position;i<no_of_ele;i++ )
    {
    	num_array[i] = num_array[i+1];
    }
    no_of_ele--;
    return 0;


}
