#include <iostream>
#include <iomanip>
using namespace std;
class Time {
    //user type of data
    //data members 
    private :
    int hours , min, sec;
    public : //member function 
    //we need setters and getters to change the value of data members 
    //we call it interface 

    void sethour(int hour){
        //this To understand ‘this’ pointer, it is important to know how objects look at functions and data members of a class. this-> this is the notation 
        if (hour <0){
            this->hours = 0;
        }
        this->hours = hour%24;
    }
    void setmin(int m){
        if (m < 0){
            this->min=0;
        }
        this->min = m%60; 
    }
    void setsec(int s){
        if(s <0){
            this->sec=0;
        }
        this->sec = s%60;
    }
    //show data 
    //universal time 24h
    //standars time 12h Am Pm
    void showTime(int type){
        if (type == 1) {
        cout << setfill('0') << setw(2) << hours << ":" << setfill('0') << setw(2) << min << ":" << setfill('0') << setw(2) << sec << endl;
    } else {//else type is 0
        if (hours >= 12) {
            hours = hours % 12;
            cout << setfill('0') << setw(2) << hours << ":" << setfill('0') << setw(2) << min << ":" << setfill('0') << setw(2) << sec << "PM" << endl;
        } else {
            cout << setfill('0') << setw(2) << hours << ":" << setfill('0') << setw(2) << min << ":" << setfill('0') << setw(2) << sec << "AM" << endl;
        }
        }    }

    
    //set default values and build a constructor 
    Time(){
        hours = 10 ;
        min = 30 ;
        sec = 15;
    }
    //overload constructor 
    Time (int h, int m,int s){
        this->hours = h ;
        this->min = m ;
        this->sec = s ;
    }
    //  +-*/ function 
    Time operator +(const Time & t) const{
        int h =this->hours+ t.hours;
        int m = this->min +t.min;
        int s = this->sec + t.sec;
        if (s>=60){
            s-=60;
            m++;
        }
        if(m>=60){
            m-=60;
            h++;
        }
        Time newTime(h,m,s); //constructor new time
        return newTime;
    }
    Time operator -(const Time & t) const{
        int h =this->hours- t.hours;
        int m = this->min -t.min;
        int s = this->sec - t.sec;
        if (s>=60){
            s+=60;
            if(s < 0){
                s = -s;
            }
            m--;
        }
        if(m>=60){
            if (m<0)
                m= -m;
            m+=60;
            h--;
        }
        if(s < 0){
                s = -s;
            }
        if (m<0)
                m= -m;
        if (h<0)
            h = -h;
        Time mewTime(h,m,s); //constructor new time
        return mewTime;
    }
    // Overload ++ operator (post-increment)
    Time operator++(int) {
        Time temp(hours, min, sec);
        sec++;
        if (sec >= 60) {
            sec = 0;
            min++;
            if (min >= 60) {
                min = 0;
                hours++;
                if (hours >= 24) {
                    hours = 0;
                }
            }
        }
        return temp;
    }

    // Overload -- operator (post-decrement)
    Time operator--(int) {
        Time temp(hours, min, sec);
        sec--;
        if (sec < 0) {
            sec = 59;
            min--;
            if (min < 0) {
                min = 59;
                hours--;
                if (hours < 0) {
                    hours = 23;
                }
            }
        }
        return temp;
    }
   //Time (int h, int m, int s); declaration d'un constructeur out of the class 

};
// Constructor definition outside the class
/*Time :: Time (int h, int m, int s){
    hours = h ;
    min = m ;
    sec = s ;
}*/
int main(){
    Time t; //initial values is random 3
    //t.sethour(8);
    //t.setmin(7);
    //t.setsec(60);
    t.showTime(0);
    Time t1(12,40,19);//donner des valeurs a partir de la declaration d'objet !! 
    t1.showTime(1);
    Time t2 = t1+t;
    t2.showTime(0);
    Time t3 = t2-t1;
    t3.showTime(0);  
    Time t4 ;
    t4++;
    t4.showTime(0);
    Time t5 ;
    t5--;
    t5.showTime(1);
    return 0;
}