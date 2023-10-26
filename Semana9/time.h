#ifndef _TIME.H_
#define _TIME.H_
#include <string>

class Time{
    public: 
    explicit Time(int = 0, int = 0, int = 0);
    
    void setTime(int,int,int);
    void setHour(int);
    void setMinute(int);
    void setSecond(int);

    unsigned int getHour() const;
    unsigned int getMinute() const;
    unsigned int getSecond() const;

    std::string toUniversalString() const;
    std::string toStandardString() const;

    private:
    unsigned int hour{0};
    unsigned int minute{0};
    unsigned int second{0};
    
};

#endif