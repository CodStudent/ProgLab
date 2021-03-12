#include <iostream>
#include <math.h>


class Point{
public:
    Point(float valueX, float valueY){
        x = valueX;
        y = valueY;
    };
    Point(){
        x = NULL;
        y = NULL;
    }
    Point(const Point &previous) {
        this->x = previous.x;
        this->y = previous.y;
    };
    Point& operator=(const Point &previous){
        this->x = previous.x;
        this->y = previous.y;
        return *this;
    };

    void ChangeX(float valueX){
        x = valueX;
    };
    void ChangeY(float valueY){
        y = valueY;
    };
    float GetX(){
        return x;
    };
    float GetY(){
        return y;
    };
    ~Point(){}
protected:
    float x;
    float y;
};

class StrangeLine{
public:
    StrangeLine(float valueX, float valueY){
        Points[0].ChangeX(valueX);
        Points[0].ChangeY(valueY);
        elem+=1;
    };
    StrangeLine(){
        Points[0].ChangeX(NULL);
        Points[0].ChangeY(NULL);
    };
    StrangeLine(const StrangeLine &previous){
        this->elem = previous.elem;
        for (int i=0; i<elem; i++)
            this->Points[i] = previous.Points[i];
    };
    StrangeLine& operator=(const StrangeLine &previous){
        this->elem = previous.elem;
        for (int i=0; i<elem; i++)
            this->Points[i] = previous.Points[i];
        return *this;
    };

    void AddPoint(float x, float y){
        if (elem<100){
            Points[elem].ChangeX(x);
            Points[elem].ChangeY(y);
            elem+=1;
        }
        else
            std::cout<<"You can't add more points\n";
    };

    float GetX(int numberOfPoint) {
        if (numberOfPoint >= elem) {
            std::cout<<"Not correct number of point\n";
            return -1;
        }
        return Points[numberOfPoint].GetX();
    };
    float GetY(int numberOfPoint){
        if (numberOfPoint >= elem) {
            std::cout<<"Not correct number of point\n";
            return -1;
        }
        return Points[numberOfPoint].GetY();
    };
    void ChangeX(int numberOfPoint, float valueX){
        if (numberOfPoint >= elem) {
            std::cout<<"Not correct number of point\n";
            return;
        }
        Points[numberOfPoint].ChangeX(valueX);
    };
    void ChangeY(int numberOfPoint, float valueY){
        if (numberOfPoint >= elem) {
            std::cout<<"Not correct number of point\n";
            return;
        }
        Points[numberOfPoint].ChangeY(valueY);
    };

    float Length(){
        float length = 0;
        for (int i=0; i<elem-1; i++)
            length += sqrt(pow((Points[i].GetX()-Points[i+1].GetX()),2)+pow((Points[i].GetY()-Points[i+1].GetY()),2));
        return length;
    };

    void Print(){
        std::cout<<"-------Line-------\n";
        for(int i=0; i<elem; i++)
            std::cout<<"Point-"<<i+1<<"|\tX="<<Points[i].GetX()<<"\tY="<<Points[i].GetY()<<std::endl;
        std::cout<<"Length="<<Length()<<std::endl;
    };
    ~StrangeLine(){}
protected:
    int elem=0;
    Point Points[100];
};

class StrangeLineWithEnd : public StrangeLine{
public:
    StrangeLineWithEnd(float valueX, float valueY){
        Points[0].ChangeX(valueX);
        Points[0].ChangeY(valueY);
        elem+=1;
    };
    StrangeLineWithEnd(){
        Points[0].ChangeX(NULL);
        Points[0].ChangeY(NULL);
    };
    StrangeLineWithEnd& operator=(const StrangeLineWithEnd &previous){
        this->elem = previous.elem;
        for (int i=0; i<elem; i++)
            this->Points[i] = previous.Points[i];
        return *this;
    };
    StrangeLineWithEnd(const StrangeLineWithEnd &previous){
        this->elem = previous.elem;
        for (int i=0; i<elem; i++)
            this->Points[i] = previous.Points[i];
    };
    float Length(){
        float length = 0;
        for (int i=0; i<elem-1; i++)
            length += sqrt(pow((Points[i].GetX()-Points[i+1].GetX()),2)+pow((Points[i].GetY()-Points[i+1].GetY()),2));
        length += sqrt(pow((Points[0].GetX()-Points[elem-1].GetX()),2)+pow((Points[0].GetY()-Points[elem-1].GetY()),2));
        return length;
    };
    ~StrangeLineWithEnd(){}
};

class Figure : public StrangeLineWithEnd{
public:
    Figure(float valueX, float valueY){
        Points[0].ChangeX(valueX);
        Points[0].ChangeY(valueY);
        elem+=1;
    };
    Figure(){
        Points[0].ChangeX(NULL);
        Points[0].ChangeY(NULL);
    };
    Figure& operator=(const Figure &previous){
        this->elem = previous.elem;
        for (int i=0; i<elem; i++)
            this->Points[i] = previous.Points[i];
        return *this;
    };
    Figure(const Figure &previous){
        this->elem = previous.elem;
        for (int i=0; i<elem; i++)
            this->Points[i] = previous.Points[i];
    };

    float Square(){
        float square=0;
        for (int i=2; i<elem; i++){
            float p=sqrt(pow((Points[i].GetX()-Points[i-1].GetX()),2)+pow((Points[i].GetY()-Points[i-1].GetY()),2))+sqrt(pow((Points[i].GetX()-Points[0].GetX()),2)+pow((Points[i].GetY()-Points[0].GetY()),2))+sqrt(pow((Points[i-1].GetX()-Points[0].GetX()),2)+pow((Points[i-1].GetY()-Points[0].GetY()),2));
            p = p/2;
            square+=sqrt(p*(p-sqrt(pow((Points[i].GetX()-Points[i-1].GetX()),2)+pow((Points[i].GetY()-Points[i-1].GetY()),2)))*(p-sqrt(pow((Points[i].GetX()-Points[0].GetX()),2)+pow((Points[i].GetY()-Points[0].GetY()),2)))*(p-sqrt(pow((Points[i-1].GetX()-Points[0].GetX()),2)+pow((Points[i-1].GetY()-Points[0].GetY()),2))));
        }
        return square;
    };

    void Print(){
        std::cout<<"-------Figure-------\n";
        for(int i=0; i<elem; i++)
            std::cout<<"Point-"<<i+1<<"|\tX="<<Points[i].GetX()<<"\tY="<<Points[i].GetY()<<std::endl;
        std::cout<<"Length="<<Length()<<std::endl;
        std::cout<<"Square="<<Square()<<std::endl;
    };
    ~Figure(){}
};

class Triangle: public Figure{
public:
    Triangle(float valueX, float valueY){
        Line[0].ChangeX(valueX);
        Line[0].ChangeY(valueY);
        elem+=1;
    };
    Triangle(){
        Line[0].ChangeX(NULL);
        Line[0].ChangeY(NULL);
    };
    Triangle& operator=(const Triangle &previous){
        this->elem = previous.elem;
        for (int i=0; i<elem; i++)
            this->Line[i] = previous.Line[i];
        return *this;
    };
    Triangle(const Triangle &previous){
        this->elem = previous.elem;
        for (int i=0; i<elem; i++)
            this->Line[i] = previous.Line[i];
    };

    void AddPoint(float x, float y){
        if (elem<3){
            Line[elem].ChangeX(x);
            Line[elem].ChangeY(y);
            elem+=1;
        }
        else
            std::cout<<"You have 3 points and can't add more\n";
    };
    float Length(){
        if (elem != 3){
            std::cout<<"You have just "<<elem<<"points. Add more\n";
            return 0;
        }
        float length = 0;
        for (int i=0; i<elem-1; i++)
            length += sqrt(pow((Points[i].GetX()-Points[i+1].GetX()),2)+pow((Points[i].GetY()-Points[i+1].GetY()),2));
        length += sqrt(pow((Points[0].GetX()-Points[elem-1].GetX()),2)+pow((Points[0].GetY()-Points[elem-1].GetY()),2));
        return length;
    };
    float Square(){
        if (elem != 3){
            std::cout<<"You have just "<<elem<<"points. Add more\n";
            return 0;
        }
        float a = sqrt(pow((Points[0].GetX()-Points[1].GetX()),2)+pow((Points[0].GetY()-Points[1].GetY()),2));
        float b = sqrt(pow((Points[1].GetX()-Points[2].GetX()),2)+pow((Points[1].GetY()-Points[2].GetY()),2));
        float c = sqrt(pow((Points[1].GetX()-Points[0].GetX()),2)+pow((Points[1].GetY()-Points[0].GetY()),2));
        float p=(a+b+c)/2;
        float square = sqrt(p*(p-a)*(p-b)*(p-c));
        return square;
    };
    void Print(){
        std::cout<<"-------Triangle-------\n";
        for(int i=0; i<elem; i++)
            std::cout<<"Point-"<<i+1<<"|\tX="<<Points[i].GetX()<<"\tY="<<Points[i].GetY()<<std::endl;
        std::cout<<"Length="<<Length()<<std::endl;
        std::cout<<"Square="<<Square()<<std::endl;
    };
    ~Triangle(){}
protected:
    Point Line[3];
};

class Trapezoid : public Figure{
public:
    Trapezoid(float valueX, float valueY){
        Points[0].ChangeX(valueX);
        Points[0].ChangeY(valueY);
        elem+=1;
    };
    Trapezoid(){
        Points[0].ChangeX(NULL);
        Points[0].ChangeY(NULL);
    };
    Trapezoid& operator=(const Trapezoid &previous){
        this->elem = previous.elem;
        for (int i=0; i<elem; i++)
            this->Points[i] = previous.Points[i];
        return *this;
    };
    Trapezoid(const Trapezoid &previous){
        this->elem = previous.elem;
        for (int i=0; i<elem; i++)
            this->Points[i] = previous.Points[i];
    };
    ~Trapezoid(){}

protected:
    int Check(){
        if (elem != 4)
            return -1;
        float x1 = Points[0].GetX() - Points[1].GetX();
        float y1 = Points[0].GetY() - Points[1].GetY();
        float x2 = Points[2].GetX() - Points[3].GetX();
        float y2 = Points[2].GetY() - Points[3].GetY();
        bool TrueFalse = (x1*y2 == y1*x2);
        if (TrueFalse == true) {
            return 1234;
        }
        x1 = Points[0].GetX() - Points[3].GetX();
        y1 = Points[0].GetY() - Points[3].GetY();
        x2 = Points[1].GetX() - Points[2].GetX();
        y2 = Points[1].GetY() - Points[2].GetY();
        TrueFalse = (x1*y2 == y1*x2);
        if (TrueFalse == true) {
            return 1423;
        }
        return -1;
    }

public:
    void AddPoint(float x, float y){
        if (elem<4){
            Points[elem].ChangeX(x);
            Points[elem].ChangeY(y);
            elem+=1;
        }
        else
            std::cout<<"You have 4 points and can't add more\n";
    };

    float Length(){
        if (Check() == -1){
            std::cout<<"You have not enough points or it's not trapezoid. So  can't calculate length\n";
            return -1;
        }
        float length = 0;
        for (int i=0; i<elem-1; i++)
            length += sqrt(pow((Points[i].GetX()-Points[i+1].GetX()),2)+pow((Points[i].GetY()-Points[i+1].GetY()),2));
        length += sqrt(pow((Points[0].GetX()-Points[elem-1].GetX()),2)+pow((Points[0].GetY()-Points[elem-1].GetY()),2));
        return length;
    };
    float Square(){
        int Grounds = Check();
        if (Grounds == -1){
            std::cout<<"You have not enough points or it's not trapezoid. So I can't calculate square\n";
            return -1;
        }
        float a, b, c, d;
        if (Grounds == 1234){
            a = sqrt(pow((Points[0].GetX()-Points[1].GetX()),2)+pow((Points[0].GetY()-Points[1].GetY()),2));
            b = sqrt(pow((Points[2].GetX()-Points[3].GetX()),2)+pow((Points[2].GetY()-Points[3].GetY()),2));
            c = sqrt(pow((Points[1].GetX()-Points[2].GetX()),2)+pow((Points[1].GetY()-Points[2].GetY()),2));
            d = sqrt(pow((Points[3].GetX()-Points[0].GetX()),2)+pow((Points[3].GetY()-Points[0].GetY()),2));
        }
        else{
            a = sqrt(pow((Points[1].GetX()-Points[2].GetX()),2)+pow((Points[1].GetY()-Points[2].GetY()),2));
            b = sqrt(pow((Points[3].GetX()-Points[0].GetX()),2)+pow((Points[3].GetY()-Points[0].GetY()),2));
            c = sqrt(pow((Points[0].GetX()-Points[1].GetX()),2)+pow((Points[0].GetY()-Points[1].GetY()),2));
            d = sqrt(pow((Points[2].GetX()-Points[3].GetX()),2)+pow((Points[2].GetY()-Points[3].GetY()),2));
        }
        float square = ((a+b)/2)*sqrt(c*c-pow(((pow(b-a,2)+c*c-d*d)/(2*(b-a))),2));
        return square;
    };

    void Print(){
        std::cout<<"-------Trapezoid-------\n";
        for(int i=0; i<elem; i++)
            std::cout<<"Point-"<<i+1<<"|\tX="<<Points[i].GetX()<<"\tY="<<Points[i].GetY()<<std::endl;
        if ((Check() != -1) && (elem==4)) {
            std::cout << "Length=" << Length() << std::endl;
            std::cout << "Square=" << Square() << std::endl;
        }
        else
            std::cout<<"It's not Trapezoid or you have not enough points"<<std::endl;
    };
protected:
    Point Points[4];
};

class TrueFigure : public Figure{
public:
    TrueFigure(float valueX, float valueY){
        Points[0].ChangeX(valueX);
        Points[0].ChangeY(valueY);
        elem+=1;
    };
    TrueFigure(){
        Points[0].ChangeX(NULL);
        Points[0].ChangeY(NULL);
    };
    TrueFigure& operator=(const TrueFigure &previous){
        this->elem = previous.elem;
        for (int i=0; i<previous.elem; i++)
            this->Points[i] = previous.Points[i];
        return *this;
    };
    TrueFigure(const TrueFigure &previous){
        this->elem = previous.elem;
        for (int i=0; i<elem; i++)
            this->Points[i] = previous.Points[i];
    };
    void Print(){
        if (Check() == false){
            std::cout<<"It isn't true figure\nCorrect your points or add more\n";
            for(int i=0; i<elem; i++)
                std::cout<<"Point-"<<i+1<<"|\tX="<<Points[i].GetX()<<"\tY="<<Points[i].GetY()<<std::endl;
            return;
        }
        std::cout<<"-------True Figure-------\n";
        for(int i=0; i<elem; i++)
            std::cout<<"Point-"<<i+1<<"|\tX="<<Points[i].GetX()<<"\tY="<<Points[i].GetY()<<std::endl;
        std::cout<<"Length="<<Length()<<std::endl;
        std::cout<<"Square="<<Square()<<std::endl;
    };
    ~TrueFigure(){}
protected:
    bool Check(){
        if (elem<3)
            return false;
        float a = sqrt(pow((Points[0].GetX()-Points[1].GetX()),2)+pow((Points[0].GetY()-Points[1].GetY()),2));
        for (int i = 1; i<elem-1; i++){
            float b = sqrt(pow((Points[i].GetX()-Points[i+1].GetX()),2)+pow((Points[i].GetY()-Points[i+1].GetY()),2));
            if (a != b)
                return false;
        }
        a = sqrt(pow((Points[0].GetX()-Points[1].GetX()),2)+pow((Points[0].GetY()-Points[1].GetY()),2));
        float b = sqrt(pow((Points[1].GetX()-Points[2].GetX()),2)+pow((Points[1].GetY()-Points[2].GetY()),2));
        float c = sqrt(pow((Points[0].GetX()-Points[2].GetX()),2)+pow((Points[0].GetY()-Points[2].GetY()),2));
        float FirstCos = (pow(b, 2)+pow(c, 2)-pow(a, 2))/(2*b*c);
        for(int i = 3; i < elem; i++){
            a = sqrt(pow((Points[i-2].GetX()-Points[i-1].GetX()),2)+pow((Points[i-2].GetY()-Points[i-1].GetY()),2));
            b = sqrt(pow((Points[i-1].GetX()-Points[i].GetX()),2)+pow((Points[i-1].GetY()-Points[i].GetY()),2));
            c = sqrt(pow((Points[i-2].GetX()-Points[i].GetX()),2)+pow((Points[i-2].GetY()-Points[i].GetY()),2));
            float Cos = (pow(b, 2)+pow(c, 2)-pow(a, 2))/(2*b*c);
            if (FirstCos != Cos)
                return false;
        }
        return true;
    }
};


int main(){
    Figure l(0, 6);
    l.AddPoint(4, 0);
    l.AddPoint(0, -6);
    l.AddPoint(-4, 0);
    Figure f(0, 10);
    f = l;
    f.Print();
    return 0;
}
