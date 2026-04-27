#include <iostream>
#include <cstring>
using namespace std;

class STRING{
    char str[100];
    public:
        STRING(){}
        STRING(const char *s) { strcpy(str, s); }

        STRING operator+(STRING s){
            STRING temp;
            strcpy(temp.str, str);
            strcat(temp.str, s.str);
            return temp;
        }

        bool operator==(STRING s){
            return strcmp(str, s.str) == 0;
        }

        void show(){ 
            cout << str << endl; 
        }
};

int main(){
    STRING s1("Hello "), s2("World"), s3;
    s3 = s1 + s2;
    s3.show();

    if (s1 == s2)
        cout << "Strings are equal" << endl;
    else
        cout << "Strings are not equal" << endl;

    return 0;
}
