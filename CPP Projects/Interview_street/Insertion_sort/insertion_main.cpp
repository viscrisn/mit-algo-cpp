//PSEUDO CODE FOR INSERTION SORT

/*for i  = 2 to N
    j = i
   while j > 1 and a[j] < a[j - 1]
        swap a[j] and a[j - 1]
        j = j-1 */

#include<iostream>

using namespace std;

int main()
{
    int test=0;
    cin>>test;

    while(test!=0)
    {
        test--;
        int no_of_ele=0;
        cin>>no_of_ele;

        int num_array[no_of_ele];

        for (int i=0; i<no_of_ele; i++ )
        {
            cin>>num_array[i];
        }

        int total=0;
        for (int i=1; i<no_of_ele; i++ )
        {
            int j=i;
            while((j>0)&&(num_array[j] < num_array[j-1]))
            {
                swap(num_array[j],num_array[j-1]);
                total++;
                j=j-1;
            }
        }
        cout<<total<<"\n";
    }
}
