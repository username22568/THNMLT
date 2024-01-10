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
//Tính chu vi dien tich
float CVHV(float a){
    return 4*a;
}
float DTHV(float a){
    return a*a;
}
float CVHCN(float a,float b){
    return 2*(a + b);
}
float DTHCN(float a,float b){
    return b*a;
}
float DTHT(float r){
    return PI*r*r;
}
float CVHT(float r){
    return 2*PI*r;
}

void ReadData(void *a[],Type type[],int &num,Square sqr[max],Circle cir[max],Rectangle rct[max]){
    ifstream data;
    data.open("input.txt",ios::in);
    string dat,temp;
    int pos;
    int count = 0;
    int cnt1 = 0;
    int cnt2 = 0;
    int cnt3 = 0;
    if(data.good()){
        getline(data,dat);
        num = stoi(dat);
        while(!data.eof()){
            getline(data,dat);
            pos = dat.find_first_of(":",0);
            temp = dat.substr(0,pos);
            if(temp == "Square"){
                pos = dat.find_first_of("=",0);
                temp = dat.substr(pos+1,dat.length()-1);
                sqr[cnt1].a = stof(temp);
                sqr[cnt1].C = CVHV(sqr[cnt1].a);
                sqr[cnt1].S = DTHV(sqr[cnt1].a);

                a[count] = (void*)&sqr[cnt1];
                type[count] = Type::square;

                count++;
                cnt1++;
            }
            else if(temp == "Circle"){
                pos = dat.find_first_of("=",0);
                temp = dat.substr(pos+1,dat.length()-1);
                cir[cnt2].r = stof(temp);
                cir[cnt2].C = CVHT(cir[cnt2].r);
                cir[cnt2].S = DTHT(cir[cnt2].r);

                a[count] = (void*)&cir[cnt2];
                type[count] = Type::circle;

                count++;
                cnt2++;
            }
            else{
                pos = dat.find_first_of("=",0);
                int pos2 = dat.find_first_of(",",0);
                temp = dat.substr(pos+1,pos2-1);
                rct[cnt3].a = stof(temp);
                pos = dat.find_first_of("=",pos2);
                temp = dat.substr(pos+1,dat.length()-1);
                rct[cnt3].b = stof(temp);
                rct[cnt3].S = DTHCN(rct[cnt3].a,rct[cnt3].b);
                rct[cnt3].C = CVHCN(rct[cnt3].a,rct[cnt3].b);

                a[count] = (void*)&rct[cnt3];
                type[count] = Type::rect;

                count++;
                cnt3++;
            }
        }
    }
}
