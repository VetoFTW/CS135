/*
Author: Martin Czarnecki
Course: CSCI-135
Instructor: Tong Yi
Assignment: E9.5
*/

class Rectangle{
    private:
        float w;
        float h;
    public:
        Rectangle(float width, float height){
            w = width;
            h = height;
        };
        
        float get_perimeter(){
            return w*2+h*2;
        };

        float get_area(){
            return w*h;
        };

        void resize(double factor){
            w *= factor;
            h *= factor;
        };
};