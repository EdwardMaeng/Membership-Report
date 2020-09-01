/*****************************************************************
 *   AUTHOR          : Yi, Edward, Miguel, Crystal
 *   PROJECT 1       : Item Class
 *   CLASS           : CS008
 *   SECTION         : MW: 9:45AM - 11:10AM, TR:9:45AM - 11:50AM
 *   Due Date        : 4/9/2020
 ******************************************************************/
/****************************************************************
* Item Class
* This class represents a item object. It has Item_name, price
* and stock;
***************************************************************/

#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

class Item
{
public:
    typedef double value_type;
    typedef std::size_t size_type;

    /****************************************
    **  CONSTRUCTORS  **
    *****************************************/
    Item();
    Item(string name, value_type price, int stock);

    // BIG THREE
    Item(const Item &RHS) ;
    Item& operator =(const Item &RHS);

    /*******************************************
    **  ACCESSORS  **
    *******************************************/
    string getName();
    value_type getPrice();
    int getStock();

    friend std::ostream& operator<<(std::ostream& outs, Item& target);
    void print_info();
    void print_quantity();
    /**********************************************
    **  MUTATORS  **
    ***********************************************/
    void setName(const string name);
    void setPrice(const value_type price);
    void setStock(const int stock);

    /*******************************************
    **  OPERATORS  **
    *******************************************/
    bool operator == (const Item& RHS);
    bool operator > (const Item& RHS);

private:
    string _name;        //IN/OUT - name of item
    value_type _price;   //IN/OUT - price of item
    int _stock;          //IN/OUT - stock of item
};

#endif // ITEM_H

/**************************************************************************
 * Item Class
 *    Item Class hold an items information.
 *    The object of this class created by other classes will let the outside
 *    access the mutators, accessors, and operators functions.
 **************************************************************************/

/****************************************
 **  CONSTRUCTORS  **
 *****************************************/
/*****************************************
 * Item();
 *   Constructor: initialize private members to default values
 *   Parameters: None
 *   Return: None
 *****************************************/
/*****************************************
 *  Item(string name, value_type price, int stock);
 *   Constructor: initialize private members to the input data
 *   Parameters: name, price, and stock
 *   Return: None
 *****************************************/


/****************************************
 **  MUTATORS  **
 *****************************************/
/*******************************************
 *  void set_name (string name);
 *   Mutator: insert the name of item
 *   Parameters: string name
 *   Return: None
 *****************************************/
/*******************************************
 *  void setPrice(const value_type price);
 *   Mutator: insert the price of item
 *   Parameters: value_type price
 *   Return: None
 *****************************************/
/*******************************************
 *  void setStock(const int stock);
 *   Mutator: insert stock of item
 *   Parameters: int stock
 *   Return: None
 *****************************************/


/*******************************************
 **  ACCESSORS  **
 *******************************************/
/***********************************************
 * string getName();
 *   Accessor: return the name of item
 *   Parameters: None
 *   Return: return string name
 **********************************************/
/***********************************************
 * value_type getPrice();
 *   Accessor: return the price of item
 *   Parameters: None
 *   Return: the price of item
 **********************************************/
/***********************************************
 * int getStock();
 *   Accessor: return the stock of item
 *   Parameters: None
 *   Return: the stock of item
 **********************************************/
/*******************************************
 *  friend std::ostream& operator<<(
 *  std::ostream& outs, Item& target);
 *   Accessor: display the item
 *   Parameters: ostream outs and Item target
 *   Return: Ouput item
 *****************************************/
/*******************************************
 *  void print_info();
 *   Accessor: display the info of item
 *   Parameters: None
 *   Return: None
 *****************************************/
/*******************************************
 *  void print_quantity();
 *   Accessor: display the quantity of item
 *   Parameters: None
 *   Return: None
 *****************************************/


/*******************************************
 **  OPERATORS  **
 *******************************************/
/***********************************************
 *  bool operator == (const Item& RHS);
 *   Operator: compare Item
 *   Parameters: Item RHS
 *   Return: true if both Item are the same
 **********************************************/
/***********************************************
 *  bool operator > (const Item& RHS);
 *   Operator: compare Item
 *   Parameters: Item RHS
 *   Return: true if LHS is greater than RHS
 **********************************************/
