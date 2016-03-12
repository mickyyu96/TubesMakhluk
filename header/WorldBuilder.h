// WorldBuilder.h
#ifndef WORLDBUILDER_H
#define WORLDBUILDER_H
#include "World.h"
#include <string>

class WorldBuilder
{
	public:
		static WorldBuilder* getBuilderInstance() { return builderInstance; }
		string getStrMakhluk() { return strMakhluk; }
		void setStrMakhluk(const string& _str) { strMakhluk = _str; }
		void buildWorldObjects();

	private:
		WorldBuilder(int, int);

	private:
		static WorldBuilder* builderInstance;
		string strMakhluk;
		const int NBrs, NKol;
};

#endif