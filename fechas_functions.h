#ifndef FECHAS_FUNCTIONS_H
#define FECHAS_FUNCTIONS_H

class Fechas{
public:
Fechas(): day_(01),month_(01),year_(2000){}
Fechas(int day,int month, int year): 
      day_(day), month_(month), year_(year){}
int day() const {return day_;}
int month() const {return month_;}
int year() const {return year_;}
friend std::ostream& operator<<(std::ostream &out, const Fechas &fecha);
private:
int day_;
int month_;
int year_;
};

std::ostream& operator<<(std::ostream &out, const Fechas &fecha);
std::string LeapYear(const Fechas &fecha);
void PlusDates(const Fechas &fecha, int upcoming_dates, std::string file);
Fechas operator+(const Fechas &fecha, int number);
void FirstComprobator(int parameters);
void SecondComprobator(std::string);
#endif
