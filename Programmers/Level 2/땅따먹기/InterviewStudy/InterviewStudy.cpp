#include <iostream>
using namespace std;

public class Rectangle
{
    protected double width;
    protected double height;

    public void setWitch(double width) { this.width = width; }

    public double getWidth() { return this.width; }

    public void setHeight(double height) { this.height = height; }

    public double getHeight() { return this.height; }

    public double getArea() { return this.getWidth() * this.getHeight(); }
}

int main()
{
    std::cout << "Hello World!\n";
}