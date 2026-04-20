#include<iostream>
#include<fstream>
using namespace std;
template<class T>
class MyArray{
    T arr[50];
    int n;

    public:
        void input(){
            cout << "Enter number of elements: ";
            cin >> n;
            cout << "Enter elements: ";
            for(int i = 0; i < n; i++){
                cin >> arr[i];
            }
        }
        void display(){
            cout << "Array elements: ";
            for(int i = 0; i < n; i++){
                cout << arr[i] << " ";
            }
            cout << endl;
        }
        void saveToFile(){
            ofstream f;
            f.open("array.txt");
            for(int i = 0; i < n; i++){
                f << arr[i] << endl;
            }
            f.close();
            cout << "Array saved to file." << endl;
        }
        void readFromFile(){
            ifstream f;
            f.open("array.txt");
            if(!f){
                cout << "File not found!" << endl;
                return;
            }
            n = 0;
            while(f >> arr[n]){
                n++;
            }
            f.close();
            cout << "Array loaded from file." << endl;
        }
};
int main(){
    MyArray<int> a;
    
    a.input();
    a.display();
    a.saveToFile();
    MyArray<int> b;
    b.readFromFile();
    b.display();
    return 0;
}