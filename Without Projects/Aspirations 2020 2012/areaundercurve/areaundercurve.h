#define C_OR_CPP 1 //  Change value to 1 here if you are submitting a C solution for this problem.
                   //  Change value to 2 here if you are submitting a C++ solution for this problem.

void dsmain();
struct Term
{
	int exponent;
	int coefficient;
};

#if C_OR_CPP == 1  // Dont change here

	double getAreaUnderCurve (struct Term* equation, int noOfTerms, int limit1,int limit2);

#endif



#if C_OR_CPP == 2  // Dont change here

class AreaUnderCurve
{
 public:
	double getAreaUnderCurve (struct Term* equation, int noOfTerms, int limit1,int limit2);
};
#endif

