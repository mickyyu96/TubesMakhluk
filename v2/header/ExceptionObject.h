// ExceptionObject.h
#ifndef EXCEPTIONOBJECT_H
#define EXCEPTIONOBJECT_H
#include <iostream>
#include <string>
#include <windows.h>
using namespace std;

class ExceptionObject
{
	public :
		ExceptionObject(int);
		void DisplayErrorMessage();
		
	private :
		int id;
		const string message[4] = {
			">> ERROR! Dimensi ukuran dunia harus > 6!", 		// 0
			">> ERROR! Ada ID yang tidak dikenali!",			// 1
			">> ERROR! Pause World dulu sebelum melakukan Single-step Execution!",
			">> ERROR! Keypress tidak dikenali!"
		};
};

#endif
