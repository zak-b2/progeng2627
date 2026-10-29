#include <iostream>

bool leap_year(int year){
    return year % 400 == 0 || (year % 4 == 0 && year % 100 != 0);
}

int monthLength(int month, int year){
    if (month == 2)
    {
        return (leap_year(year)?29:28);
    }
    if (month == 4 || month == 6 || month == 9 || month == 11)
    {
        return 31;
    }
    return 30;
}

void next_date(int d1, int m1, int y1, int& d2, int& m2, int& y2){
    y2 = y1;
    if (d1 == monthLength(m1, y1))
    {
        d2 = 1;
        m2 = m1 + 1;
        if (m2 == 13)
        {
            m2 = 1;
            y2++;
        }
    }
    else
    {
        d2 = d1 + 1;
        m2 = m1;
    }
}

int main(){
    int d1,d2,m1,m2,y1,y2;
    d1 = 1;
    m1 = 1;
    y1 = 1;
    next_date(d1,m1,y1,d2,m2,y2);
    std::cout<<(d2 == 2 && m2 == 1 && y2 == 1)<<std::endl;
    
    d1 = 30;
    m1 = 1;
    y1 = 1;
    next_date(d1,m1,y1,d2,m2,y2);
    std::cout<<(d2 == 1 && m2 == 2 && y2 == 1)<<std::endl;
    
    d1 = 29;
    m1 = 1;
    y1 = 1;
    next_date(d1,m1,y1,d2,m2,y2);
    std::cout<<(d2 == 30 && m2 == 1 && y2 == 1)<<std::endl;
    
    d1 = 30;
    m1 = 12;
    y1 = 1;
    next_date(d1,m1,y1,d2,m2,y2);
    std::cout<<(d2 == 1 && m2 == 1 && y2 == 2)<<std::endl;
    
    d1 = 28;
    m1 = 2;
    y1 = 1;
    next_date(d1,m1,y1,d2,m2,y2);
    std::cout<<(d2 == 1 && m2 == 3 && y2 == 1)<<std::endl;
    
    d1 = 28;
    m1 = 2;
    y1 = 4;
    next_date(d1,m1,y1,d2,m2,y2);
    std::cout<<(d2 == 29 && m2 == 2 && y2 == 4)<<std::endl;
    
    d1 = 28;
    m1 = 2;
    y1 = 400;
    next_date(d1,m1,y1,d2,m2,y2);
    std::cout<<(d2 == 29 && m2 == 2 && y2 == 400)<<std::endl;
    
    d1 = 28;
    m1 = 2;
    y1 = 100;
    next_date(d1,m1,y1,d2,m2,y2);
    std::cout<<(d2 == 1 && m2 == 3 && y2 == 100)<<std::endl;
}