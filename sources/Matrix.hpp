# include <iostream>
# include <vector>
#include <stdexcept>

using namespace std;

namespace zich{
class Matrix{
    private:
        int column;
        int row;
        vector<double> data;
    public:
        Matrix(vector<double> mat, int row, int col);
            // good_input(col,row);
            // this->column = col;
            // this->row = row; 
            // // this->data = mat;
            // this->data = move(mat);
        int getCol(){
            return column;
        };
        int getRow(){
            return row;
        };
        //bool good_input(int col, int row);
        //bool equals_size(Matrix& one, Matrix& two);
        //int sumMatrix(Matrix& mat);
        double sumMatrix1() const;
        Matrix operator+(Matrix& other);
        Matrix operator-(Matrix& other);
        Matrix& operator+=(Matrix& other);
        Matrix& operator-=(Matrix& other);
        // plus and minus onari
        friend Matrix operator+(Matrix& other);
        friend Matrix operator-(Matrix& other);
        // copare
        bool operator<(const Matrix& other) const;
        //bool operator<(Matrix other);
        bool operator<=(const Matrix& other) const;
        bool operator>(const Matrix& other) const;
        bool operator>=(const Matrix& other) const;
        bool operator==(const Matrix& other)const;
        bool operator!=(const Matrix& other) const;
        Matrix& operator++();
        Matrix& operator--();
        Matrix operator++(int ind);
        Matrix operator--(int ind);
        friend Matrix operator*(const double scalar,Matrix &other); // scalar*Matrix
        Matrix operator*(double scalar); // matrix*scalar
        Matrix& operator*=(double scalar); //matrix*=scalar
        Matrix operator*(Matrix& other); // matrix*matrix
        Matrix& operator*=(Matrix& other); // matrix*matrix
        // todo:
        friend ostream& operator<<(ostream& os, const Matrix& other);
        friend istream& operator>>(istream& is, Matrix& other);      
};
}