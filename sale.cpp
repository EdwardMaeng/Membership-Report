/*****************************************************************
 *   AUTHOR          : Yi, Edward, Miguel, Crystal
 *   PROJECT 1       : MemberContainer Class
 *   CLASS           : CS008
 *   SECTION         : MW: 9:45AM - 11:10AM, TR:9:45AM - 11:50AM
 *   Due Date        : 4/9/2020
 ******************************************************************/

#include "sale.h"

/*********************************************************
 * Sale( )
 * -------------------------------------------------------
 * Postcondition: The Sale has been initialized as an
 * empty sale.
 *********************************************************/

Sale::Sale(): _amount_sold(0) { }

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

Sale::Sale(MemberContainer& mcontainer, ItemContainer& tcontainer, string membership,
           string item, double price, int amount, int m, int d, int y)
{
    _mcontainer = mcontainer;
    _tcontainer = tcontainer;

    if(_mcontainer.search_membership(membership) // checks for valid membership
            && (_tcontainer.search_item(item))   // checks for valid item name
            && (_tcontainer.find(item).getStock( ) - amount >= 0) // checks if stock is available
            && (double_equals(_tcontainer.find(item).getPrice( ), price))) // checks for valid price
    {
        _membership = membership;
        _item_name = item;
        _price = price;
        _amount_sold = amount;
        _day = d;
        _month = m;
        _year = y;

        // Neccessary for the sales class itself (used in sales class)
        _tcontainer.find(item).setStock(_tcontainer.find(item).getStock( ) - amount); // setting stock based on amount being sold (stock - sold)
        _mcontainer.find(_membership).set_amount_spent(_amount_sold * _price + _mcontainer.find(_membership).get_amount_spent( )); // setting amount spent based on the previous amount and the total price
        _mcontainer.find(_membership).set_rebate_amount(_mcontainer.find(_membership).get_preferred_member( )); // setting the rebate amount for preferred member

        // Neccessary changes for the member and item class (same logic as code above)
        mcontainer = _mcontainer;
        tcontainer = _tcontainer;
    }
}

/*********************************************************
 * void setMembership(string membership)
 * -------------------------------------------------------
 * Postcondition: Set the membership in sales class based
 * on the given membership.
 *********************************************************/

void Sale::setMembership(string membership)
{
    if(_mcontainer.search_membership(membership))
            _membership = membership;
}

/*********************************************************
 * void setItem(string item)
 * -------------------------------------------------------
 * Postcondition: Set the item name in sales class based
 * on the given item name.
 *********************************************************/

void Sale::setItem(string item)
{
    if(_tcontainer.search_item(item))
        _item_name = item;
}

/*********************************************************
 * void setAmountSold(int amount)
 * -------------------------------------------------------
 * Postcondition: Set the amount sold in sales class based
 * on the given amount sold.
 *********************************************************/

void Sale::setAmountSold(int amount) { _amount_sold = amount; }

/*********************************************************
 * void setDate(int m, int d, int y)
 * -------------------------------------------------------
 * Postcondition: Set the date in sales class based
 * on the given date.
 *********************************************************/

void Sale::setDate(int m, int d, int y)
{
   _day = d;
   _month =  m;
   _year = y;
}

/*********************************************************
 * void setPrice(double price)
 * -------------------------------------------------------
 * Postcondition: Set the price in sales class based
 * on the given price.
 *********************************************************/

void Sale::setPrice(double price) { _price = price; }

/*********************************************************
 * string getMembership( )
 * -------------------------------------------------------
 * Postcondition: Get the membership in sales class so
 * the user can access it outside this class.
 *********************************************************/

string Sale::getMembership( ) { return _membership; }

/*********************************************************
 * string getItem( )
 * -------------------------------------------------------
 * Postcondition: Get the item name in sales class so
 * the user can access it outside this class.
 *********************************************************/

string Sale::getItem( ) { return _item_name; }

/*********************************************************
 * int getAmountSold( )
 * -------------------------------------------------------
 * Postcondition: Get the amount sold in sales class so
 * the user can access it outside this class.
 *********************************************************/

int Sale::getAmountSold( ) { return _amount_sold; }

/*********************************************************
 * void getDate(int& m, int& d, int& y)
 * -------------------------------------------------------
 * Postcondition: Get the date in sales class so
 * the user can access it outside this class.
 *********************************************************/

void Sale::getDate(int& m, int&d, int &y)
{
    m = _month;
    d = _day;
    y = _year;
}

/*********************************************************
 * double getPrice( )
 * -------------------------------------------------------
 * Postcondition: Get the price in sales class so
 * the user can access it outside this class.
 *********************************************************/

double Sale::getPrice( ) { return _price; }

/*********************************************************
 * bool check_date(int m, int d, int y)
 * -------------------------------------------------------
 * Postcondition: Check the date in sales class based on
 * the given month, day, and year.
 *********************************************************/

bool Sale::check_date(int m, int d, int y) { return(_day == d && _month == m && _year == y); }

/*********************************************************
 * bool check_year(int y)
 * -------------------------------------------------------
 * Postcondition: Check the year in sales class based on
 * the given year.
 *********************************************************/

bool Sale::check_year(int y) { return(_year == y); }

/*********************************************************
 * double total_price( )
 * -------------------------------------------------------
 * Postcondition: Return total price based on the amount
 * sold and price of specified item (_amount_sold
 * times price of it).
 *********************************************************/

double Sale::total_price( ) { return(_amount_sold * _price); }

/*********************************************************
 * double total_revenue( )
 * -------------------------------------------------------
 * Postcondition: Retuns total revenue given the total
 * price of each sales. It is based on amount sold and
 * the price of the item (per member), plus exclude sales
 * tax of 8.75%.
 *********************************************************/

double Sale::total_revenue( )
{
    double total = total_price( ) * 0.9125; // without the sales tax

    return total;
}

/*********************************************************
 * void print_info( )
 * -------------------------------------------------------
 * Postcondition: Print all of the information from the
 * sales class including: date, membership, item name,
 * price and amount sold.
 *********************************************************/

void Sale::print_info( )
{
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);

    cout << _month << "/" << _day << "/" << _year << endl;

    cout << "MemberShip: " << getMembership() << endl;;

    cout << "Item: " <<  getItem() << endl;

    cout << "Price: " << getPrice() << endl;

    cout << "Amount Sold: " << getAmountSold() << endl << endl;
}

/*********************************************************
 * bool double_equals(double a, double b, double epsilon)
 * -------------------------------------------------------
 * Postcondition: A simple function that checks two double
 * numbers, since == comparsion is illegal.
 *********************************************************/

bool Sale::double_equals(double a, double b, double epsilon) { return std::abs(a - b) < epsilon; }

/*********************************************************
 * bool operator == (const Sale& RHS)
 * -------------------------------------------------------
 * Postcondition: Compare two sales together to check if
 * they are equal to one another. You check membership,
 * item name, and amount sold of the two sales.
 *********************************************************/

bool Sale::operator == (const Sale& RHS) { return(_membership == RHS._membership && _item_name == RHS._item_name && _amount_sold == RHS._amount_sold); }
