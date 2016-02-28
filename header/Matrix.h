// Matrix.h
#ifndef MATRIX_H
#define MATRIX_H

class Matrix {
	public :
		// ctor, cctor, dtor (op= tidak dipakai karena NBrs dan NKol const, sehingga tidak mungkin diubah2 lagi)
		Matrix();
		Matrix(int, int);
		Matrix(const Matrix&);
		~Matrix();
		
		// getter setter
		int getNBrs() const { return NBrs; }
		int getNKol() const { return NKol; }
		char getInfo(int i, int j) const;
		void setInfo(char c, int i, int j);
		
		// PrintMatrix
		void PrintMatrix() const;
		
	private :
		char** M;
		const int NBrs, NKol;
};

#endif
