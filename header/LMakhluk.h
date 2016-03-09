// LMakhluk.h

#ifndef LMAKHLUK_H
#define LMAKHLUK_H
#include <cstdlib>
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

				Makhluk* getInfo() { return info; }
				void setInfo(Makhluk* _info) { info = _info; }
				ElmtMakhluk* getNext() { return next; }
				void setNext(ElmtMakhluk* _next) { next = _next; }

			private:
				Makhluk* info;
				ElmtMakhluk* next;
		};

		ElmtMakhluk* first;

	public :
		ElmtMakhluk* getFirst() { return first; }
		void setFirst(ElmtMakhluk* _first) { first = _first; }

		ElmtMakhluk* getLast();
		ElmtMakhluk* findPrecMakhluk(Makhluk*);
		ElmtMakhluk* findMakhluk(Makhluk*);
};

#endif // LMakhluk_H
