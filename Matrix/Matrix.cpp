#include <iostream>
using namespace std;

class Matrix
{
    int ROWS;
    int COLS;
    int** mat;
public:
    int get_ROWS()const
    {
        return ROWS;
    } 
    int get_COLS()const
    {
        return COLS;
    }
    int get_mat(int i,int j)const
    {
        if (ROWS > 0 && COLS > 0) return *this->mat[i, j];
        else
            return 0;
    }
     void set_ROWS(int ROWS)
    {
         this->ROWS = ROWS;
    } 
    void set_COLS(int COLS)
    {
        this->COLS = COLS;
    }
    void set_mat(int i, int j)
    {
        if ((i < 0) || (i >= ROWS)) return;
        if ((j < 0) || (j >= ROWS)) return;
        this->mat[i][j] = mat[i][j];
    }
    Matrix()
    {
        this->ROWS = 0;
        this->COLS = 0;
        this->mat = nullptr;
        cout<<"DefaultConstructor:\t"<<this<<endl;
    }
    Matrix(int ROWS, int COLS)
    {
        this->ROWS = ROWS;
        this->COLS = COLS;
        mat = (int**) new int*[ROWS];
        for (int i = 0; i < ROWS; i++) mat[i] = (int*)new int[COLS];
        for (int i = 0; i < ROWS; i++)
        {
            for (int j = 0; j < COLS; j++)
            {
                mat[i][j] = 0;
            }
        }
        cout << "Constructor:\t" << this << endl;
    }    
    Matrix(const Matrix& other)
    {
        this->ROWS = other.ROWS;
        this->COLS = other.COLS;
        mat = (int**) new int* [ROWS];
        for (int i = 0; i < ROWS; i++) mat[i] = (int*)new int[COLS];
        for (int i = 0; i < ROWS; i++)
        {
            for (int j = 0; j < COLS; j++)
            {
                mat[i][j] = other.mat[i][j];
            }
        }
        cout << "CopyConstructor:\t" << this << endl;
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
        for (int i = 0; i < ROWS; i++)
        {
            for (int j = 0; j < COLS; j++)
            {
                cout<<mat[i][j]<<"\t";
                
            }
            cout << endl;
        }
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
    Matrix mat(6,6);
    mat.print();
}