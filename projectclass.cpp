#include <iostream>
#include <math.h>
using namespace std;
void menue(){
    cout << "===================IKRAM======================="<<endl;
    cout << "|                                             |"<<endl;
    cout << "|                 1.Rectangle                 |"<<endl;
    cout << "|                                             |"<<endl;
    cout << "|                 2.Cercle                    |"<<endl;
    cout << "|                                             |"<<endl;
    cout << "|                 3.Heart                     |"<<endl;
    cout << "|                                             |"<<endl;
    cout << "|                 0.Chinese                    |"<<endl;
    cout << "|                                             |"<<endl;
    cout << "|                 4.Exit                      |"<<endl;
    cout << "|                                             |"<<endl;
    cout << "=================Bousfiha======================"<<endl;
}
void chinesemenue(){
    cout << "===================IKRAM======================="<<endl;
    cout << "|                                              |"<<endl;
    cout << "|                 1.矩形                       |"<<endl;
    cout << "|                                              |"<<endl;
    cout << "|                 2.圆                         |"<<endl;
    cout << "|                                              |"<<endl;
    cout << "|                 3.心灵                       |"<<endl;
    cout << "|                                              |"<<endl;
    cout << "|                 0.英文                       |"<<endl;
    cout << "|                                              |"<<endl;
    cout << "|                 4.出口                        |"<<endl;
    cout << "|                                              |"<<endl;
    cout << "=================Bousfiha======================"<<endl;    
}

class Rectanglee {
private:
    double width;
    double length;
    char fillchar;

public:
    void setWidth(double w) {
        width = w;
    }

    void setLength(double l) {
        length = l;
    }

    double getArea() {
        return length * width;
    }

    double getPerimeter() {
        return 2 * (width + length);
    }

    void showInfo() {
        cout << "Width: " << width << endl;
        cout << "Length: " << length << endl;
        cout << "Area: " << getArea() << endl;
        cout << "Perimeter: " << getPerimeter() << endl;
    }

    void setFillChar(char fc = 'p') {
        fillchar = fc;
    }

    void draw() {
        for (int i = 0; i < width; i++) {
            for (int j = 0; j < length; j++) {
                cout << fillchar;
            }
            cout << endl;
        }
    }
};

void rec() {
    double w, l;
    char p;
    cout << "Please enter the width: ";
    cin >> w;
    cout << "Please enter the length: ";
    cin >> l;
    cout << "Please enter the character you want: ";
    cin >> p;
    Rectanglee rect;
    rect.setWidth(w);
    rect.setLength(l);
    rect.showInfo();
    rect.setFillChar(p); // Default fill character is 'p'
    rect.draw();
}

class Heartt{
    double size , x,y;
    char p  ,r;
    public :
    void getsizee(double t){
        size =t ;
    }
    void upper(char o){
        p = o ;
    }
    void down(char i){
        r =i;
    }
    void drawe(){
    for (x=0;x<size;x++)
    {
        for (y=0;y<=4*size;y++)
        {
            double dist1 = sqrt( pow(x-size,2) + pow(y-size,2) );
            double dist2 = sqrt( pow(x-size,2) + pow(y-3*size,2) );

            if (dist1 < size + 0.5 || dist2 < size + 0.5 )
            cout<<p;
            else
            cout<<" ";


        }
        cout<<endl;

    }

    for ( x=1;x<2*size;x++)
    {
        for(y=0;y<x;y++)
        cout<<" ";

        for (y=0; y<4*size + 1 - 2*x; y++)
        cout<<r;

        cout<<endl;
    }

}
};
void qlyeb(){
    double x ;
    char e,t;
    cout << "Please enter the size : ";
    cin  >> x;
    cout <<"\nPlease enter the felling up ";
    cin>>e;
    cout <<"\nPlese enter the down ";
    cin>>t;
    Heartt h;
    h.getsizee(x);
    h.upper(e);
    h.down(t);
    h.drawe();

}
class Cercle {
    private:
    int X;
    int Y;
    int R;
    char e ;

public:
    void gett(int x, int y , int r, char p){
        X =x;
        Y=y;
        R =r;
        e = p;
    }

    void draweircle() {
        for (int y = -R; y <= R; y++) {
            for (int x = -R; x <= R; x++) {
                float distance = sqrt(x * x + y * y);
                if (distance <= R - 0.5) {
                    cout << e<<" ";
                } else {
                    cout << "  ";
                }
            }
            cout << endl;
        }
    }
};
void cer(){
    int x ,y,r;
    char e;
    cout << "Please enter X : ";
    cin >>x;
    cout<<"\n Please enter Y : ";
    cin>>y;
    cout <<"\n Please enter the radius : ";
    cin >>r;
    cout <<"\n Please enter the filling character :";
    cin >>e;
    Cercle cerr;
    cerr.gett(x,y,r,e);
    cerr.draweircle();
}
int main (){
int choice ;
   bool b ;
   char p;
   do {
    if (!b)
        menue();
    else
        chinesemenue();
    cout<< "Please choose a number : ";
    cin>> choice;
    switch (choice){
        case 1 :
            cout <<"you choose the rectangle" ;
            rec();
        case 2:
            cout << "You choose the circle ";
            cer();
        case 3 :
            cout <<"You choose the heart";
            qlyeb();
            
    }
       } 
    while(choice != 4);

    return 0;
}