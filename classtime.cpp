#include<iostream>
using namespace std;

class Time{
    int hour,minute;
    public:
        void setTime(int hr, int min){
            hour = hr;
            minute = min;
        }
        void showTime(){
            cout<<hour<<" hours : "<<minute<<" minutes";
        }
        static Time sum(Time t1 , Time t2){
            Time result;
            result.minute = t1.minute + t2.minute;
            result.hour = t1.hour + t2.hour;

            if(result.minute >= 60){
                result.hour += result.minute / 60;
                result.minute %= 60 ;
            }

            return result;
        }
};

int main(){

    Time t1,t2,t3;
    int h,m;

    cout<<"Enter Time 1 hours and minutes : ";
    cin>>h>>m;
    t1.setTime(h,m);

    cout<<"Enter Time 2 hours and minutes : ";
    cin>>h>>m;
    t2.setTime(h,m);

    t3 = Time::sum(t1,t2);

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
