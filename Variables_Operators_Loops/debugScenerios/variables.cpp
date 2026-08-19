#include <iostream>
#include <cmath>

using namespace std;

//Calculate hourly wage from salary (contains errors)
int main(){
    const int workWeeks = 52;
    int workHoursPerWeek;
    int annualSalary;
    double hourlyWage;

    cout << "Enter salary: $";
    cin >> annualSalary;
    cout << "Enter number of hours worked per week: ";
    cin >> workHoursPerWeek;

    

    hourlyWage = ((double)annualSalary / workWeeks) / workHoursPerWeek;


    cout << "Equivalent hourly wage is: $" << round(hourlyWage*100)/100 << "." << endl;
}
