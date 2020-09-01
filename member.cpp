#include "member.h"

/*****************************************************************
 *   AUTHOR          : Yi, Edward, Miguel, Crystal
 *   PROJECT 1       : Member Class
 *   CLASS           : CS008
 *   SECTION         : MW: 9:45AM - 11:10AM, TR:9:45AM - 11:50AM
 *   Due Date        : 4/9/2020
 ******************************************************************/
#include <iomanip>

#include "member.h"

/**************************************************************
 * Member ();
 * ____________________________________________________________
 * This function intializes the members with default values
 * ___________________________________________________________
 * Pre-Condition
 * None
 *
 * Post-Condition
 * initialize private members to default values
 *************************************************************/
Member::Member(): _amount_spent(0), _rebate_amount(0), _preferred_member(false) { }

/**************************************************************
 * Member (string _name, string _num, double amount, bool type,
 *          int _month, int _day,  int _year);
 * ____________________________________________________________
 * This function intializes the members with input values
 * ___________________________________________________________
 * Pre-Condition
 * None
 *
 * Post-Condition
 * Intializes all private members with input data
 *************************************************************/
Member::Member (string name,    //IN - name
                string _num,    //IN - membership number
                double amount,  //IN - amount spent by member
                bool type,      //IN - type of membership
                int _month,     //IN - date
                int _day,
                int _year)
{
    set_name (name);
    set_member_number (_num);
    set_preferred_member(type);
    set_amount_spent(amount);
    set_exp_date (_month, _day, _year);
    set_rebate_amount (type);
}

/**************************************************************
 * void Member::set_name (string name)
 * ____________________________________________________________
 * This function sets the name for member
 * ___________________________________________________________
 * Pre-Condition
 * string name is inputted
 *
 * Post-Condition
 * set input data to name member
 *************************************************************/
void Member::set_name (string name)  //IN - string name
{ _name = name; }

/**************************************************************
 * void Member::set_member_number (string num)
 * ____________________________________________________________
 * This function sets the membership number for member
 * ___________________________________________________________
 * Pre-Condition
 * string num is inputted
 *
 * Post-Condition
 * set input data to _membership_num member
 *************************************************************/
void Member::set_member_number (string num)  //IN - string num
{
    _membership_num = num;
}

/**************************************************************
 * void Member::set_amount_spent (double amount)
 * ____________________________________________________________
 * This function sets the amount spent of member
 * ___________________________________________________________
 * Pre-Condition
 * double amount is inputted
 *
 * Post-Condition
 * set input data to _amount_spent member
 *************************************************************/
void Member::set_amount_spent (double amount)  //IN - double amount
{
    _amount_spent = amount;
}

/**************************************************************
 * void Member::set_rebate_amount (bool type)
 * ____________________________________________________________
 * This function sets the rebate amount
 * ___________________________________________________________
 * Pre-Condition
 * bool type of membership
 *
 * Post-Condition
 * set input data to _rebate_amount member
 *************************************************************/
void Member::set_rebate_amount (bool type)   //IN - bool type
{
    _rebate_amount = 0;
    if (type)
        _rebate_amount = 0.05 * _amount_spent;
}

/**************************************************************
 * void Member::set_preferred_member (bool type)
 * ____________________________________________________________
 * This function sets the type of member
 * ___________________________________________________________
 * Pre-Condition
 * bool type of membership
 *
 * Post-Condition
 * set input data to bool preferred member
 *************************************************************/
void Member::set_preferred_member (bool type)  //IN - bool type
{
    _preferred_member = type;
}

/**************************************************************
 * void Member::set_exp_date (int m, int d, int y)
 * ____________________________________________________________
 * This function sets the type of member
 * ___________________________________________________________
 * Pre-Condition
 * date given te set the exp date
 *
 * Post-Condition
 * save the expiration date
 *************************************************************/
void Member::set_exp_date (int m, int d, int y) //IN - date
{
    _exp_day = d;
    _exp_month =  m;
    _exp_year = y;
}

/**************************************************************
 * bool Member::check_exp_year(int y)
 * ____________________________________________________________
 * This function checks the expiration date
 * ___________________________________________________________
 * Pre-Condition
 * a int year is given
 *
 * Post-Condition
 * return true if it is the exp year
 *************************************************************/
bool Member::check_exp_year(int y) { return(y == _exp_year); }

/**************************************************************
 * bool Member::check_exp_month(int m)
 * ____________________________________________________________
 * This function checks for the exp month
 * ___________________________________________________________
 * Pre-Condition
 * a int month is given
 *
 * Post-Condition
 * return true if it is the exp month
 *************************************************************/
bool Member::check_exp_month(int m) { return(m == _exp_month); }

/**************************************************************
 * string Member::get_name () const
 * ____________________________________________________________
 * This function returns the name of member
 * ___________________________________________________________
 * Pre-Condition
 * None
 *
 * Post-Condition
 * return string name of member
 *************************************************************/
string Member::get_name () const { return _name; }

/**************************************************************
 * string Member::get_member_number () const
 * ____________________________________________________________
 * This function returns the number of member
 * ___________________________________________________________
 * Pre-Condition
 * None
 *
 * Post-Condition
 * return string number of member
 *************************************************************/
string Member::get_member_number() const { return _membership_num; }

/**************************************************************
 * double Member::get_amount_spent ()const
 * ____________________________________________________________
 * This function returns the amount spent
 * ___________________________________________________________
 * Pre-Condition
 * None
 *
 * Post-Condition
 * return amount spent as double
 *************************************************************/
double Member::get_amount_spent () const { return _amount_spent; }

/**************************************************************
 * double Member::get_rebate_amount ()const
 * ____________________________________________________________
 * This function returns the rebate amount
 * ___________________________________________________________
 * Pre-Condition
 * None
 *
 * Post-Condition
 * return rebate amount as double
 *************************************************************/
double Member::get_rebate_amount () const { return _rebate_amount; }

/**************************************************************
 * bool Member::get_preferred_member ()const
 * ____________________________________________________________
 * This function returns the type of membership
 * ___________________________________________________________
 * Pre-Condition
 * None
 *
 * Post-Condition
 * return type of membership as a bool
 *************************************************************/
bool Member::get_preferred_member () const { return _preferred_member; }

/**************************************************************
 * double Member::get_exp_date (int& m, int&d, int &y)
 * ____________________________________________________________
 * This function returns the date
 * ___________________________________________________________
 * Pre-Condition
 * Parameters are given to pass by reference
 *
 * Post-Condition
 * return the date as int
 *************************************************************/
void Member::get_exp_date (int& m, int&d, int &y)  //IN/OUT date

{
    m = _exp_month;
    d = _exp_day;
    y = _exp_year;
}

/**************************************************************
 * int Member::get_month ()
 * ____________________________________________________________
 * This function returns the month
 * ___________________________________________________________
 * Pre-Condition
 * None
 *
 * Post-Condition
 * return the month
 *************************************************************/
int Member::get_month () { return _exp_month; }

/**************************************************************
 * int Member::get_year ()
 * ____________________________________________________________
 * This function returns the year
 * ___________________________________________________________
 * Pre-Condition
 * None
 *
 * Post-Condition
 * return the year
 *************************************************************/
int Member::get_year () { return _exp_year; }

/**************************************************************
 * void Member::print_info ()
 * ____________________________________________________________
 * This function prints out the information for member
 * ___________________________________________________________
 * Pre-Condition
 * All private members are initialized
 *
 * Post-Condition
 * print out to screen the information of the member
 *************************************************************/
void Member::print_info ()
{
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);

    cout << _exp_month << "/" << _exp_day << "/" << _exp_year << endl;
    cout << "Member #: " << get_member_number() << endl;
    cout << "Member Name: " << get_name () << endl;
    if (get_preferred_member( ))
        cout << "Preferred" << endl;
    else
        cout << "Basic" << endl;
    cout << "Amount Spent: $" << get_amount_spent () << endl;
    cout << "Rebate: $" << get_rebate_amount() << endl << endl;
}

/**************************************************************
 * void Member::print_rebate ()
 * ____________________________________________________________
 * This function prints out the information for rebate
 * ___________________________________________________________
 * Pre-Condition
 * All private members are initialized
 *
 * Post-Condition
 * print out to screen the information of rebate
 *************************************************************/
void Member::print_rebate ()
{
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);

    cout << "Member #: " << get_member_number() << endl;
    if (get_preferred_member( ))
        cout << "Preferred" << endl;
    else
        cout << "Basic" << endl;
    cout << "Rebate: $" << get_rebate_amount() << endl << endl;
}

/**************************************************************
 * bool Member::operator == (const Member& RHS)
 * ____________________________________________________________
 * This function compare if Member's information are equal
 * ___________________________________________________________
 * Pre-Condition
 * None
 *
 * Post-Condition
 * return true if Member's information are equal else false
 *************************************************************/
bool Member::operator == (const Member& RHS) { return(_membership_num.compare(RHS._membership_num) == 0); }

bool Member::operator > (const Member& RHS) { return(_membership_num.compare(RHS._membership_num) > 0); }

bool Member::greater_than_name (const Member& RHS) { return(_name.compare(RHS._name) > 0); }
