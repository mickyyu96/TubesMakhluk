// LMakhluk.h

#ifndef LMAKHLUK_H
#define LMAKHLUK_H

#include "Makhluk.h"

class LMakhluk
{
	public :
		LMakhluk();
		~LMakhluk();

		void Add(Makhluk*);
		void Del(Makhluk*);

	private :
		class ElmtMakhluk
		{
			public :
				ElmtMakhluk();
				ElmtMakhluk(Makhluk*, ElmtMakhluk*);
				~ElmtMakhluk();

				Makhluk* getInfo();
				void setInfo(Makhluk*);
				ElmtMakhluk* getNext();
				void setNext(ElmtMakhluk*);

			private:
				Makhluk* info;
				ElmtMakhluk* next;
		};

		ElmtMakhluk* first;

	public :
		ElmtMakhluk* getFirst();
		void setFirst(ElmtMakhluk*);
		ElmtMakhluk* getLast();
		ElmtMakhluk* findPrecMakhluk(Makhluk*);
		ElmtMakhluk* findMakhluk(Makhluk*);
};

#endif // LMakhluk_H
