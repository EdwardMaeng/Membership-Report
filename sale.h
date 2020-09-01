#ifndef SALE_H
#define SALE_H

/*****************************************************************
 *   AUTHOR          : Yi, Edward, Miguel, Crystal
 *   PROJECT 1       : MemberContainer Class
 *   CLASS           : CS008
 *   SECTION         : MW: 9:45AM - 11:10AM, TR:9:45AM - 11:50AM
 *   Due Date        : 4/9/2020
 ******************************************************************/

#include "member.h"
#include "membercontainer.h"
#include "item.h"
#include "itemcontainer.h"
#include <cmath>

class Sale
{
public:
    /****************************************
    **  CONSTRUCTORS  **
    *****************************************/
    Sale( );
    Sale(MemberContainer& mcontainer, ItemContainer& tcontainer, string membership,
         string item, double price, int amount, int m, int d, int y);

    /****************************************
    **  MUTATOR  **
    *****************************************/
    void setMembership(string membership);
    void setItem(string item);
    void setAmountSold(int amount);
    void setDate(int m, int d, int y);
    void setPrice(double price);

    /****************************************
    **  ACCESSOR  **
    *****************************************/
    string getMembership( );
    string getItem( );
    int getAmountSold( );
    void getDate(int& m, int&d, int &y);
    double getPrice( );

    /****************************************
    **  MEMBER FUNCTIONS  **
    *****************************************/
    bool check_date(int m, int d, int y);
    bool check_year(int y);
    double total_price( );
    double total_revenue( );
    void print_info( );
    bool double_equals(double a, double b, double epsilon = 0.001); // for comparing price from itemcontainer

    /****************************************
    **  OPERATORS  **
    *****************************************/
    bool operator == (const Sale& RHS);

private:
    double _price;
    int _amount_sold; // amount of item bought
    int _day, _month, _year; // this is for the date bought (will be using the date functions)
    string _item_name, _membership; // Item name and membership number
    MemberContainer _mcontainer; // Member Container object
    ItemContainer _tcontainer; // Item Container Object
};

/***************
 * CONSTRUCTORS
 ***************/

/*********************************************************
 * Sale( )
 * -------------------------------------------------------
 * Postcondition: The Sale has been initialized as an
 * empty sale.
 *********************************************************/

/*********************************************************
 * Sale(MemberContainer& mcontainer,
 * ItemContainer& tcontainer, string membership,
 * string item, double price, int amount, int m, int d,
 * int y)
 * -------------------------------------------------------
 * Postcondition: The Sale has been initialized based on
 * member container, item container, membership, item name,
 * price, amount sold, and the date of the sale.
 *********************************************************/

/***********
 * MUTATORS
 ***********/

/*********************************************************
 * void setMembership(string membership)
 * -------------------------------------------------------
 * Postcondition: Set the membership in sales class based
 * on the given membership.
 *********************************************************/

/*********************************************************
 * void setItem(string item)
 * -------------------------------------------------------
 * Postcondition: Set the item name in sales class based
 * on the given item name.
 *********************************************************/

/*********************************************************
 * void setAmountSold(int amount)
 * -------------------------------------------------------
 * Postcondition: Set the amount sold in sales class based
 * on the given amount sold.
 *********************************************************/

/*********************************************************
 * void setDate(int m, int d, int y)
 * -------------------------------------------------------
 * Postcondition: Set the date in sales class based
 * on the given date.
 *********************************************************/

/*********************************************************
 * void setPrice(double price)
 * -------------------------------------------------------
 * Postcondition: Set the price in sales class based
 * on the given price.
 *********************************************************/

/************
 * ACCESSORS
 ************/

/*********************************************************
 * string getMembership( )
 * -------------------------------------------------------
 * Postcondition: Get the membership in sales class so
 * the user can access it outside this class.
 *********************************************************/

/*********************************************************
 * string getItem( )
 * -------------------------------------------------------
 * Postcondition: Get the item name in sales class so
 * the user can access it outside this class.
 *********************************************************/

/*********************************************************
 * int getAmountSold( )
 * -------------------------------------------------------
 * Postcondition: Get the amount sold in sales class so
 * the user can access it outside this class.
 *********************************************************/

/*********************************************************
 * void getDate(int& m, int& d, int& y)
 * -------------------------------------------------------
 * Postcondition: Get the date in sales class so
 * the user can access it outside this class.
 *********************************************************/

/*********************************************************
 * double getPrice( )
 * -------------------------------------------------------
 * Postcondition: Get the price in sales class so
 * the user can access it outside this class.
 *********************************************************/

/*******************
 * MEMBER FUNCTIONS
 *******************/

/*********************************************************
 * bool check_date(int m, int d, int y)
 * -------------------------------------------------------
 * Postcondition: Check the date in sales class based on
 * the given month, day, and year.
 *********************************************************/

/*********************************************************
 * bool check_year(int y)
 * -------------------------------------------------------
 * Postcondition: Check the year in sales class based on
 * the given year.
 *********************************************************/

/*********************************************************
 * double total_price( )
 * -------------------------------------------------------
 * Postcondition: Return total price based on the amount
 * sold and price of specified item (_amount_sold
 * times price of it).
 *********************************************************/

/*********************************************************
 * double total_revenue( )
 * -------------------------------------------------------
 * Postcondition: Retuns total revenue given the total
 * price of each sales. It is based on amount sold and
 * the price of the item (per member), plus exclude sales
 * tax of 8.75%.
 *********************************************************/

/*********************************************************
 * void print_info( )
 * -------------------------------------------------------
 * Postcondition: Print all of the information from the
 * sales class including: date, membership, item name,
 * price and amount sold.
 *********************************************************/

/*********************************************************
 * bool double_equals(double a, double b, double epsilon)
 * -------------------------------------------------------
 * Postcondition: A simple function that checks two double
 * numbers, since == comparsion is illegal.
 *********************************************************/

/************
 * OPERATORS
 ************/

/*********************************************************
 * bool operator == (const Sale& RHS)
 * -------------------------------------------------------
 * Postcondition: Compare two sales together to check if
 * they are equal to one another. You check membership,
 * item name, and amount sold of the two sales.
 *********************************************************/

#endif // SALE_H
