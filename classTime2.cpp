/*39. Create a class TIME with data members hours, minutes and seconds. Include constructors to
read and display time objects. Write a C++ program to add 2 time objects using operator
overloading.*/

#include<iostream>
using namespace std;

class Time{
    int hour,minute,seconds;
    public:
        Time(){}
        Time(int& hr,int& min,int& sec){
            hour = hr;
            minute = min;
            seconds = sec;
        }
        void showTime(){
            cout<<hour<<" hours : "<<minute<<" minutes : "<<seconds<<" seconds";
        }
        Time operator+(Time& t1){

            int Min , Hr ,Sec;
            Sec = seconds + t1.seconds;
            Min = minute + t1.minute;
            Hr = hour + t1.hour;

            Min += Sec / 60;
            Sec -= (Sec / 60) * 60;
            Hr += Min / 60;
            Min -= (Min / 60 ) * 60;


            return Time(Hr , Min , Sec);
        }
};

int main(){

    int h,m,s;

    cout<<"Enter Time 1 hours,minutes and seconds : ";
    cin>>h>>m>>s;
    Time t1(h,m,s);

    cout<<"Enter Time 2 hours,minutes and seconds : ";
    cin>>h>>m>>s;
    Time t2(h,m,s);

    Time t3 = t1 + t2;

    cout<<"\nTime 1 = ";
    t1.showTime();
    cout<<"\n\n";

    cout<<"Time 2 = ";
    t2.showTime();
    cout<<"\n\n";

    cout<<"Sum of both times = ";
    t3.showTime();
    cout<<"\n\n";

    return 0;
}
