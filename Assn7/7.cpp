#include <iostream>
using namespace std;

class Matrix{
    int a[2][2];
    public:
        void input(){
            cout << "Enter 4 elements: ";
            for(int i=0;i<2;i++)
                for(int j=0;j<2;j++)
                    cin >> a[i][j];
        }
        void display(){
            for(int i=0;i<2;i++) {
                for(int j=0;j<2;j++)
                    cout << a[i][j] << " ";
                cout << endl;
            }
        }
        friend Matrix operator*(Matrix, Matrix);
};

Matrix operator*(Matrix m1, Matrix m2){
    Matrix temp;
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++) {
            temp.a[i][j] = 0;
            for(int k=0;k<2;k++)
                temp.a[i][j] += m1.a[i][k] * m2.a[k][j];
        }
    }
    return temp;
}

int main(){
    Matrix m1, m2, m3;
    cout << "Matrix 1:\n"; m1.input();
    cout << "Matrix 2:\n"; m2.input();
    m3 = m1 * m2;
    cout << "Result:\n"; m3.display();
    return 0;
}
