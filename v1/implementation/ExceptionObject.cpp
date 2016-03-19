// ExceptionObject.cpp
#include "../header/ExceptionObject.h"
using namespace std;

ExceptionObject::ExceptionObject(int _ID) : id(_ID)
{
}

void ExceptionObject::DisplayErrorMessage()
{
	MessageBoxA(0, message[id].c_str(), "", MB_OK);
}
