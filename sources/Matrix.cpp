#include <iostream>
#include "Matrix.hpp"

using namespace std;


namespace zich{
    Matrix::Matrix(vector<double> mat, int row, int col){
        //good_input(col,row);
        if(col <= 0 || row <= 0 || mat.size() != col*row){
            throw runtime_error("row and col must be positive");
        }
        this->column = col;
        this->row = row; 
            // this->data = mat;
        this->data = move(mat);
    }    
    // bool Matrix::good_input(int col, int row) const{
    //     if(col <= 0 || row <= 0){
    //         throw runtime_error("row and col must be positive");
    //     }
    //     return true;
    // }
    // bool Matrix::equal_size(const Matrix& one, const Matrix& two) {
    //     //Matrix::good_input(one.getCol(),one.getRow());
    //     //good_input(two.getCol(), two.getRow());
    //     if (!(one->getCol() == two.getCol() && one.getRow() == two.getRow())){
    //         throw runtime_error("row and col must be equals");
    //     }
    //     return true;
    // }   
    // int Matrix:: sumMatrix(Matrix& other){
    //     int sum = 0;
    //     int len = other.getCol()*other.getRow();
    //     for(size_t i=0; i<len; i++){
    //         sum += other.data.at(i);
    //     }
    //     return sum;
    // }
    double Matrix:: sumMatrix1() const{
        double sum = 0;
        int len = this->column*this->row;
        for(size_t i=0; i<len; i++){
            sum += this->data.at(i);
        }
        return sum;
    }
    Matrix Matrix:: operator+(Matrix& other){
        //Matrix::equal_size(*this, other);
        if (this->column != other.column || this->row != other.row){
            throw runtime_error("Matrix must be same size");
        }
        Matrix ans = Matrix{other.data,other.getCol(),other.getRow()};
        int len = other.getCol()*other.getRow();
        for(size_t i=0; i<len; i++){
            ans.data.at(i) = this->data.at(i) + other.data.at(i);
        }
        return ans;
    }
    Matrix Matrix:: operator-(Matrix& other){
        //equal_size(*this, other);
        if (this->column != other.column || this->row != other.row){
            throw runtime_error("Matrix must be same size");
        }
        Matrix ans = Matrix{other.data,other.row,other.column};
        int len = other.getCol()*other.getRow();
        for(size_t i=0; i<len; i++){
            ans.data.at(i) = this->data.at(i) - other.data.at(i);
        }
        return ans;
    }
    Matrix& Matrix:: operator+=(Matrix& other){
        //equal_size(*this, other);
        if (this->column != other.column || this->row != other.row){
            throw runtime_error("Matrix must be same size");
        }
        int len = other.getCol()*other.getRow();
        for(size_t i=0; i<len; i++){
            this->data.at(i) = this->data.at(i) + other.data.at(i);
        }
        return *this;
    }
    Matrix& Matrix:: operator-=(Matrix& other){
        //equal_size(*this, other);
        if (this->column != other.column || this->row != other.row){
            throw runtime_error("Matrix must be same size");
        }
        int len = other.getCol()*other.getRow();
        for(size_t i=0; i<len; i++){
            this->data.at(i) = this->data.at(i) - other.data.at(i);
        }
        return *this;
    }
    // plus and minus onari
    Matrix operator+(Matrix& other){
        Matrix ans = Matrix(other.data,other.row,other.column);
        return ans;
    }
    Matrix operator-(Matrix& other){
        Matrix ans = Matrix(other.data,other.row,other.column);
        int len = other.column*other.row;
        for(size_t i=0; i< len; i++){
            ans.data.at(i) *= -1;
        }
        return ans;
    }
    // copare
    bool Matrix:: operator<(const Matrix& other) const{ 
        if (this->column != other.column || this->row != other.row){
            throw runtime_error("Matrix must be same size");
        }
        //equal_size(*this, other);
        double sum_this = this->sumMatrix1();
        double sum_other = other.sumMatrix1();
        return sum_this < sum_other;
    }
    bool Matrix:: operator<=(const Matrix& other) const{
        if (this->column != other.column || this->row != other.row){
            throw runtime_error("Matrix must be same size");
        }
        double sum_this = this->sumMatrix1();
        double sum_other = other.sumMatrix1();
        return sum_this <= sum_other;
    }
    bool Matrix:: operator>(const Matrix& other) const{
        if (this->column != other.column || this->row != other.row){
            throw runtime_error("Matrix must be same size");
        }
        //equal_size(*this, other);
        double sum_this = this->sumMatrix1();
        double sum_other = other.sumMatrix1();
        return sum_this > sum_other;
    }
    bool Matrix:: operator>=(const Matrix& other) const{
        if (this->column != other.column || this->row != other.row){
            throw runtime_error("Matrix must be same size");
        }
        //equal_size(*this, other);
        double sum_this = this->sumMatrix1();
        double sum_other = other.sumMatrix1();
        return sum_this >= sum_other;
    }
    bool Matrix:: operator==(const Matrix& other)const {
        if (this->column != other.column || this->row != other.row){
            throw runtime_error("Matrix must be same size");
        }
        for (size_t i = 0; i < this->data.size(); i++) {
            if(this->data.at(i) != other.data.at(i)){
                return false;
            }
        }
        return true;
        
    }
    bool Matrix:: operator!=(const Matrix& other) const{
        if (this->column != other.column || this->row != other.row){
            throw runtime_error("Matrix must be same size");
        }
        //equal_size(*this, other);
        double sum_this = this->sumMatrix1();
        double sum_other = other.sumMatrix1();
        return sum_this != sum_other;
    } 
    ///////////////////////////////not sure///////////////////////////////////////
    Matrix& Matrix:: operator++(){
        Matrix ans = Matrix(this->data,this->row,this->column);
        int len = this->column * this->row;
        for(size_t i =0; i<len; i++){
            this->data.at(i) += 1;
        }
        return *this;

    }
    Matrix& Matrix:: operator--(){
        Matrix ans = Matrix(this->data,this->row,this->column);
        int len = this->column * this->row;
        for(size_t i =0; i<len; i++){
            this->data.at(i) -= 1;
        }
        return *this;
    }
    Matrix Matrix:: operator++(int ind){
        Matrix copy(*this);
        int len = this->column * this->row;
        for(size_t i =0; i<len; i++){
            this->data.at(i) += 1;
        }
        return copy;
    }
    Matrix Matrix:: operator--(int ind){
        Matrix copy(*this);
        int len = this->column * this->row;
        for(size_t i =0; i<len; i++){
            this->data.at(i) -= 1;
        }
        return copy;
    }
    Matrix operator*(double scalar, Matrix& other){ // scalar*Matrix
        Matrix ans = Matrix(other.data,other.row,other.column);
        int len = other.column * other.row;
        for(size_t i =0; i<len; i++){
            ans.data.at(i) *= scalar;
        }
        return ans;
    } 
    Matrix Matrix:: operator*(double scalar){ // matrix*scalar
        Matrix ans = Matrix(this->data,this->row,this->column);
        int len = this->column * this->row;
        for(size_t i =0; i<len; i++){
            ans.data.at(i) *= scalar;
        }
        return ans;       
    }
    Matrix& Matrix:: operator*=(double scalar){
        int len = this->column * this->row;
        for(size_t i =0; i<len; i++){
            this->data.at(i) *= scalar;
        }
        return *this;
    }
    Matrix Matrix:: operator*(Matrix& other){ // kefel matrix
        if (this->column != other.row){
            throw runtime_error("The matrixes size is illegal");
        }
        vector<double> tmp;
        for (int i = 0; i < this->row; i++){
            for (int j = 0; j < other.column; j++){
                double flag = 0;
                for (int k = 0; k < this->column; k++){
                    int i_this = (i*this->column)+k;
                    int i_other = (k*other.column)+j;
                    flag += this->data.at(size_t(i_this))*other.data.at(size_t(i_other));
                }
                tmp.push_back(flag);
            }
            
        }
        Matrix ans = Matrix(tmp, this->row, other.column);
        return ans;
    }
    Matrix& Matrix:: operator*=(Matrix& other){ // kefel matrix
        if (this->column != other.row){
            throw runtime_error("The matrixes size is illegal");
        }
        vector<double> tmp;
        for (int i = 0; i < this->row; i++){
            for (int j = 0; j < other.column; j++){
                double flag = 0;
                for (int k = 0; k < this->column; k++){
                    int i_this = (i*this->column)+k;
                    int i_other = (k*other.column)+j;
                    flag += this->data.at(size_t(i_this))*other.data.at(size_t(i_other));
                }
                tmp.push_back(flag);
            }
            
        }
        //cout << tmp << endl;
        this->data = tmp;
        this->column = other.column;
        return *this;
    }
    // todo:
    ostream& operator<<(ostream& os, const Matrix& other){
        for (int i = 0; i <other.row; i++){
            for (int j = 0; j < other.column; j++){
                if (j == 0){
                    operator<<(os,"[");
                    int ind = i+(j*other.column);
                    os << other.data.at(size_t(ind));
                    operator<<(os," ");
                }
                else if (j == other.column-1){
                    int ind = i+(j*other.column);
                    os << other.data.at(size_t(ind));
                    operator<<(os,"]");
                }
                else {
                    int ind = i+(j*other.column);
                    os << other.data.at(size_t(ind));
                    operator<<(os," ");
                }  
            }
            if (!(i+1 == other.row)){
                operator<<(os,"\n");
            }    
        }
        return os;
    }
    istream& operator>>(istream& is, Matrix& other){
        string tmp;
        getline(is,tmp);
        for(size_t i = 0; i<tmp.length()-1; i++){
            if((tmp.at(i) == ',') && tmp.at(i+1) != ' '){
                throw runtime_error("error: after ',' must be space");
            }
            if(tmp.at(i) == ']' && tmp.at(i+1) != ','){
                throw runtime_error("error");
            }
            if(tmp.at(i) == '[' && tmp.at(i+1) == ' '){
                throw runtime_error("error1");
            }
            //(tmp.at(i) >= '0' && tmp.at(i) <= '9')
        }
        return is;
        
        
        
        //return cin >> other << endl;
    }
};