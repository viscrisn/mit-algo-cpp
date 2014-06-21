#define C_OR_CPP 2 //  Change value to 1 here if you are submitting a C solution for this problem.
		   //  Change value to 2 here if you are submitting a C++ solution for this problem.

void dsmain();

#if C_OR_CPP == 1  // Dont change here

	int * findCost(char direction[],int length[]);

#endif



#if C_OR_CPP == 2  // Dont change here

class PebbleMerchant
{
	public:
		int * findCost(char direction[],int length[]);
};

#endif

