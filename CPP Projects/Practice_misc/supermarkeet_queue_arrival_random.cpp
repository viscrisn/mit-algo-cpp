/*(Supermarket simulation) Write a program that simulates a checkout line at a supermarket. The line is a queue object. Customers (i.e., customer objects) arrive in random integer intervals of 1 to 4 minutes. Also, each customer is served in random integer intervals of 1 to 4 minutes. Obviously, the rates need to be balanced. If the average arrival rate is larger than the average service rate, the queue will grow infinitely. Even with “balanced” rates, randomness can still cause long lines. Run the supermarket simulation for a 12-hour day (720 minutes) using the following algorithm:

1) Choose a random integer between 1 and 4 to determine the minute at which the first customer arrives.

2) At the first customer’s arrival time:
Determine customer’s service time (random integer from 1 to 4);
Begin servicing the customer;
Schedule arrival time of next customer (random integer 1 to 4 added to the current time).

3) For each minute of the day:
If the next customer arrives,
Say so,
Enqueue the customer;
Schedule the arrival time of the next customer;
If service was completed for the last customer;
Say so
Dequeue next customer to be serviced
Determine customer’s service completion time (random integer from 1 to 4 added to the current time).

Now run your simulation for 720 minutes and answer each of the following:
a) What is the maximum number of customers in the queue at any time?
b)What is the longest wait any one customer experiences?
c)What happens if the arrival interval is changed from 1-to-4 minutes to 1-to-3 minutes?
*/

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

void one_minute(queue<int> &supermarket)
{

}

int main()
{
    queue<int> supermarket;
    int total_duration = 720;
    for (int i=0;i<total_duration;i++ )
    {
    	one_minute(supermarket);
    }

}
