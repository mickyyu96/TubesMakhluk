// LMakhluk.h
#ifndef LMAKHLUK_H
#define LMAKHLUK_H
#include "Makhluk.h"

class LMakhluk {
	public :
		// ctor, dtor (cctor dan op= tidak diperlukan)
		LMakhluk();
		~LMakhluk();
		
		// operasi dasar list
		void Add();
		void Delete();
		
	private :
		class ElmtMakhluk {
			public :
				// ctor, dtor (cctor dan op= tidak diperlukan)
				ElmtMakhluk();
				~ElmtMakhluk();
				
				// getter setter
				Makhluk* getInfo();
				ElmtMakhluk* getNext();
				
			private:
				Makhluk* info;
				ElmtMakhluk* next;
		};
		
		ElmtMakhluk* first;
	
	public :
		// getter setter
		ElmtMakhluk* getFirst();
};

#endif
