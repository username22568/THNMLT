#include<iostream>
#include<fstream>
#include<string>
using std::cout,std::endl;
using std::ios,std::ifstream;
using std::string;
const int max = 100;
const float PI = 3.14;
struct Square{
    float a;
    float S;
    float C;
};

struct Rectangle{
    float a;
    float b;
    float S;
    float C;
};

struct Circle{
    float r;
    float S;
    float C;
};

enum Type{
    square = 1,
    circle = 2,
    rect = 3
};
