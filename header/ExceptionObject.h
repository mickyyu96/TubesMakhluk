// ExceptionObject.h
#include <iostream>
#include <string>
using namespace std;

class ExceptionObject
{
	public :
		ExceptionObject(int);
		void DisplayErrorMessage();
		
	private :
		int id;
		const string message[2] = {
			">> ERROR! Dimensi ukuran dunia harus > 6!", 		// 0
			">> ERROR! Ada ID yang tidak dikenali!"			// 1
		};
};
