#include <iostream>
#include <string>
using namespace std;
#pragma once

class Employee{
  public:
    Employee();
    int weeklySalary();
    int vacationHours();
    int healthInsurance();
};

class Professional:Employee{
  private:
    
    int vacation_Days_Per_Week = 1;
    int daily_Pay = 300;
    int health_insurance_line = 50000;

  public:
    int weeklySalary(){return 5 * daily_Pay;}
    int vacationHours(){return vacation_Days_Per_Week * 12;}
    int healthInsurance(){return health_insurance_line;}
};

class NonProfessional:Employee{
  private:
    int hourly_wage = 25;
    int hours_for_vacation = 10;
    int health_insurace_line = 25000;

  public:
    int weeklySalary(int hours_worked){return hours_worked * hourly_wage;}
    int vacationHours(int hours_worked){return hours_worked / hours_for_vacation;}
    int healthInsurance(){return health_insurace_line;}
};