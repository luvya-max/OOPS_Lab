#include <iostream>
using namespace std;

class Polygon{
    protected:
        int width, height;
    public:
        void set_value(int w, int h) { width = w; height = h; }
        virtual float calculate_area() = 0; 
};

class Rectangle : public Polygon {
    public:
        float calculate_area(){ 
            return width * height;
        }
};

class Triangle : public Polygon {
public:
    float calculate_area(){
        return 0.5 * width * height; 
    }
};

int main(){
    Rectangle r;
    Triangle t;
    Polygon* p;

    p = &r;
    p->set_value(8, 4);
    cout << "Rectangle Area: " << p->calculate_area() << endl;

    p = &t;
    p->set_value(8, 4);
    cout << "Triangle Area: " << p->calculate_area() << endl;

    return 0;
}
