#include <iostream>
using namespace std;

class Matrix
{
    int ROWS;
    int COLS;
    int* mat;
public:
    int get_ROWS()const
    {
        return ROWS;
    } 
    int get_COLS()const
    {
        return COLS;
    }
    const int* get_mat()const
    {
        return mat;
    }
    int* get_mat()
    {
        return mat;
    }

    Matrix(int ROWS=8, int COLS=7)
    {
        this->ROWS = ROWS;
        this->COLS = COLS;
        this->mat = new int[ROWS*COLS] {};
        cout<<"Constructor:\t"<<this<<endl;
    }
    Matrix(const Matrix& mat)
    {
        this->ROWS = ROWS;
        this->COLS = COLS;
        this->mat = new int[ROWS*COLS]{};
        for (int i = 0; i < ROWS * COLS; i++)
        {
            this->mat[i] = mat[i];          
        }
        cout << "Constructor:\t" << this << endl;
    }
    ~Matrix()
    {
        delete[] this->mat;
        cout<< "Destructor:\t" << this << endl;
    }

    void print()const
    {
        cout << "ROWS: " << ROWS << endl;
        cout << "COLS: " << COLS << endl;
        cout << "Mat: " << mat <<"\t"<< endl;
    }
};
/*
Matrix operator+(Matrix left, Matrix right)
{

}
Matrix operator-(Matrix left, Matrix right)
{

}
Matrix operator*(Matrix left, Matrix right)
{

}
Matrix operator/(Matrix left, Matrix right)
{

}
*/

void main()
{
    setlocale(LC_ALL, "");
    Matrix mat;
    mat.print();
}