// mExceptionObject.cpp

#include "../header/ExceptionObject.h"

int main()
{
	ExceptionObject E1(0);
	E1.DisplayErrorMessage();

	ExceptionObject E2(1);
	E2.DisplayErrorMessage();
	
	ExceptionObject E3(2);
	E2.DisplayErrorMessage();
	
	ExceptionObject E4(3);
	E2.DisplayErrorMessage();
	
	ExceptionObject E5(4);
	E2.DisplayErrorMessage();

	return 0;
}
