#ifndef MEMBER_H
#define MEMBER_H

/*****************************************************************
 *   AUTHOR          : Yi, Edward, Miguel, Crystal
 *   PROJECT 1       : Member Class
 *   CLASS           : CS008
 *   SECTION         : MW: 9:45AM - 11:10AM, TR:9:45AM - 11:50AM
 *   Due Date        : 4/9/2020
 ******************************************************************/

#include <iostream>

using namespace std;

class Member
{
public:

    /****************************************
    **  CONSTRUCTORS  **
    *****************************************/
    Member ();
    Member (string _name, string _num, double amount, bool type,
            int _month, int _day,  int _year);


    /**********************************************
    **  MUTATORS  **
    ***********************************************/
    void set_name (string name);
    void set_member_number (string num);
    void set_preferred_member (bool type);
    void set_amount_spent (double amount);
    void set_rebate_amount (bool type);
    void set_exp_date (int m, int d, int y);


    /*******************************************
    **  ACCESSORS  **
    *******************************************/
    bool check_exp_year(int y);
    bool check_exp_month(int m);
    string get_name () const;
    string get_member_number () const;
    bool get_preferred_member () const;
    double get_amount_spent () const;
    double get_rebate_amount () const;
    void get_exp_date (int& m, int&d, int &y);
    int get_month ();
    int get_year ();

    void print_info ();
    void print_rebate ();

    /*******************************************
    **  OPERATORS  **
    *******************************************/
    bool operator == (const Member& RHS);
    bool operator > (const Member& RHS);
    bool greater_than_name (const Member& RHS);


private:
    string _name;             //IN/OUT - name of member
    string _membership_num;   //IN/OUT - membership number

    double _amount_spent;     //IN/OUT - amount spent by member
    double _rebate_amount;
    bool _preferred_member;   //IN/OUT - membership type

    int _exp_day;             //IN/OUT - expiration date
    int _exp_month;
    int _exp_year;
};

#endif // MEMBER_H

/**************************************************************************
 * Member Class
 *    Member Class is a data structure defined to hold a member information.
 *    This class is basically a subclass of the membercontainer class.
 *    It holds the name, membership number, amount spent, rebate amount,
 *    a type of member, and date.
 *    The object of this class created by other classes will let the outside
 *    access the mutators, accessors, and operators functions.
 **************************************************************************/

/****************************************
 **  CONSTRUCTORS  **
 *****************************************/
/*****************************************
 *  Member ();
 *   Constructor: initialize private members to default values
 *   Parameters: None
 *   Return: None
 *****************************************/
/*****************************************
 *  Member (string _name, string _num, double amount, bool type,
 *          int _month, int _day,  int _year);
 *   Constructor: initialize private members to the input data
 *   Parameters: name, _num, amount, type, and date
 *   Return: None
 *****************************************/


/****************************************
 **  MUTATORS  **
 *****************************************/
/*******************************************
 *  void set_name (string name);
 *   Mutator: insert the name of member
 *   Parameters: string name
 *   Return: None
 *****************************************/
/***********************************************
 * void set_member_number (string num);
 *   Mutator: insert the membership number
 *   Parameters: string num
 *   Return: None
 **********************************************/
/***********************************************
 *  void set_preferred_member (bool type);
 *   Mutator: set the membership type
 *   Parameters: bool type
 *   Return: None
 **********************************************/
/***********************************************
 * void set_amount_spent (double amount);
 *   Mutator: set the amount spent by member
 *   Parameters: double amount
 *   Return: None
 **********************************************/
/***********************************************
 * void set_rebate_amount (bool type);
 *   Mutator: return the hour wage
 *   Parameters: bool type
 *   Return: None
 **********************************************/
/***********************************************
 *  void set_exp_date (int m, int d, int y);
 *   Mutator: set the exp date
 *   Parameters: int m, int d, int y
 *   Return: None
 **********************************************/



/*******************************************
 **  ACCESSORS  **
 *******************************************/
/***********************************************
 * bool check_exp_year(int y);
 *   Accessor: return true if is the exp year
 *   Parameters: int y as the year
 *   Return: true if is the exp year else false
 **********************************************/
/***********************************************
 * bool check_exp_month(int m);
 *   Accessor: return true if is the exp month
 *   Parameters: int m as the month
 *   Return: true if is the exp year else false
 **********************************************/
/***********************************************
 * string get_name () const;
 *   Accessor: return the name of member
 *   Parameters: None
 *   Return: string name of member
 **********************************************/
/***********************************************
 * string get_member_number () const;
 *   Accessor: return the membership number
 *   Parameters: None
 *   Return: string of membership numbers
 **********************************************/
/***********************************************
 * bool get_preferred_member () const;
 *   Accessor: return membership type
 *   Parameters: None
 *   Return: bool membership type
 **********************************************/
/***********************************************
 * double get_amount_spent () const;
 *   Accessor: return the total amount spent by member
 *   Parameters: None
 *   Return: double of amount spent
 **********************************************/
/***********************************************
 * double get_rebate_amount () const;
 *   Accessor: return the rebate amount
 *   Parameters: None
 *   Return: double of the rebate amount
 **********************************************/
/***********************************************
 * void get_exp_date (int& m, int&d, int &y);
 *   Accessor: return the exp date
 *   Parameters: int& m, int&d, int &y
 *   Return: date passed by reference
 **********************************************/
/***********************************************
 * int get_month ();
 *   Accessor: return the month
 *   Parameters: None
 *   Return: return month
 **********************************************/
/***********************************************
 * int get_year ();
 *   Accessor: return the year
 *   Parameters: None
 *   Return: return year
 **********************************************/
/***********************************************
 * void print_info ();
 *   Accessor: print the member information
 *   Parameters: None
 *   Return: none
 **********************************************/
/***********************************************
 * void print_rebate ();
 *   Accessor: print the rebate information
 *   Parameters: None
 *   Return: none
 **********************************************/

/*******************************************
 **  OPERATORS  **
 *******************************************/
/***********************************************
 *  bool operator == (const Member& RHS);
 *   Operator: compare members
 *   Parameters: Member RHS
 *   Return: true if both members hold the same
 *           member number
 **********************************************/
/***********************************************
 *  bool operator > (const Member& RHS);
 *   Operator: compare members
 *   Parameters: Member RHS
 *   Return: true if member number is valid
 **********************************************/
/***********************************************
 *  bool greater_than_name (const Member& RHS);
 *   Operator: compare members
 *   Parameters: Member RHS
 *   Return: true if member number is valid
 **********************************************/
