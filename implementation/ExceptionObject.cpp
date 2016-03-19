// ExceptionObject.cpp
#include "../header/ExceptionObject.h"
using namespace std;

ExceptionObject::ExceptionObject(int _ID) : id(_ID)
{
}

void ExceptionObject::DisplayErrorMessage()
{
	cout << message[id] << endl;
}
