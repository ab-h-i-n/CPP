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

    t1.setTime(20,45);
    t2.setTime(1,30);
    t3 = Time::sum(t1,t2);

    cout<<"Time 1 = ";
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
