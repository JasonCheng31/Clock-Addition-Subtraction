#include <iostream>
using namespace std;

class Time
{
public:
    Time(int hours, int minutes, int seconds)
    {
        Phours = hours;
        Pminutes = minutes;
        Pseconds = seconds;
        if (Phours == 0 && Pminutes == 0 && Pseconds == 0)
        {
            cout << endl;
        }

        else if (Phours > 24 || Pminutes >= 60 || Pseconds >= 60 || Phours <= 0 || Pminutes < 0 || Pseconds < 0)
        {
            cout << "Invalid input. Time reseted to 0 for this time: " << Phours << ":" << Pminutes << ":" << Pseconds << endl;
            Phours = 0;
            Pminutes = 0;
            Pseconds = 0;
        }
    }
    int getHours()
    {
        return Phours;
    }
    int getMinutes()
    {
        return Pminutes;
    }
    int getSeconds()
    {
        return Pseconds;
    }
    void display()
    {
        cout << Phours << ":" << Pminutes << ":" << Pseconds << endl;
    }

private:
    int Phours;
    int Pminutes;
    int Pseconds;
};

Time operator+(Time &a, Time &b)
{
    int Addhours = a.getHours() + b.getHours();
    int Addminutes = a.getMinutes() + b.getMinutes();
    int Addseconds = a.getSeconds() + b.getSeconds();
    if (Addseconds >= 60)
    {
        int value = Addseconds - 60;
        Addseconds = value;
        Addminutes++;
    }
    if (Addminutes >= 60)
    {
        int value2 = Addminutes - 60;
        Addminutes = value2;
        Addhours++;
    }
    if (Addhours > 24)
    {
        int value3 = Addhours - 24;
        Addhours = value3;
    }
    Time t(Addhours, Addminutes, Addseconds);
    return t;
}

Time operator-(Time &a, Time &b)
{
    int Minushours = a.getHours() - b.getHours();
    int Minusminutes = a.getMinutes() - b.getMinutes();
    int Minusseconds = a.getSeconds() - b.getSeconds();
    if (Minusseconds < 0)
    {
        int value3 = Minusseconds + 60;
        Minusseconds = value3;
        Minusminutes--;
    }
    if (Minusminutes < 0)
    {
        int value2 = Minusminutes + 60;
        Minusminutes = value2;
        Minushours--;
    }
    if (Minushours <= 0)
    {
        int value = Minushours + 24;
        Minushours = value;
    }
    if (a.getHours() == 0 && b.getHours() == 0)
    {
        Minushours = 0;
    }
    Time t(Minushours, Minusminutes, Minusseconds);
    return t;
}

int main()
{
    Time t1(10, 30, 20);
    Time t2(5, 15, 45);
    Time t3 = t1 + t2;
    cout << "Addition result:" << endl;
    t3.display();

    Time t4 = t1 - t2;
    cout << "\nSubtraction Result: " << endl;
    t4.display();
    return 0;
}