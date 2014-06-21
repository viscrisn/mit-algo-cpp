#include<iostream>
#include<vector>
#include<string>
#include<cmath>
#include<cctype>
#include<algorithm>
#include<sstream>
#include<queue>
#include<cstdlib>
#include<map>
#include<set>

using namespace std;


class TomekPhone
{
public:
    int minKeystrokes(vector <int> frequencies, vector <int> keySizes)
    {
        sort(keySizes.begin(),keySizes.end());
        sort(frequencies.begin(),frequencies.end());

        int round =0;
        int round_size = keySizes.size(),cur_pos = 0;
        int min_strokes =0;

        int total_key=0;
        for (int i=0;i<round_size;i++ )
        {
        	total_key+=keySizes[i];
        }
        if(total_key < frequencies.size())
        {
            return -1;
        }

        for (int i=frequencies.size()-1; i >= 0;)
        {
            if(keySizes[cur_pos]>0)
            {
                keySizes[cur_pos] -= 1;
                if(cur_pos == 0)
                {
                    round++;
                }
                cur_pos = (cur_pos+1)%round_size;
            }
            else
            {
                if(cur_pos == 0)
                {
                    round++;
                }
                cur_pos = (cur_pos+1)%round_size;
                continue;
            }

            min_strokes += round*frequencies[i--];

        }
        return min_strokes;

    }
};

int main()
{
    TomekPhone a;
    vector<int> a1;
    vector<int> b1;

    a1.push_back(11);
    a1.push_back(23);
    a1.push_back(4);
    a1.push_back(50);
    a1.push_back(1000);
    a1.push_back(7);
    a1.push_back(18);

    b1.push_back(3);
    b1.push_back(1);
    b1.push_back(4);

    cout<<a.minKeystrokes(a1,b1);
}



