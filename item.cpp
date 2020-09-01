#include "item.h"

/****************************************************************
* Item Class
* This class represents a item object. It has Item_name, price
* and stock;
***************************************************************/

/******************************
** CONSTRUCTOR  **
******************************/
/****************************************************************
* Item ();
* Constructor; Initialize class attributes
* Parameters: none
* Return: none
***************************************************************/
Item::Item(): _name(""), _price(0), _stock(100) { }

/****************************************************************
* Item(string name,value_type Price,size_type amount);
* Constructor; Initialize class attributes
* Parameters: name(string)//IN- the name for the new attribute
*             price(value_type)//IN- the price for the new attribute
*             amount(size_type)//IN- the amount for the new attribute
* Return: none
***************************************************************/
Item::Item(string name, value_type price, int stock): _name(name), _price(price), _stock(stock) { }

/****************************************************************
* Item(const Item &right)
* Constructor; Initialize class attributes
* Parameters: right(Item&)//IN- copy from right
* Return: none
***************************************************************/
Item::Item(const Item &RHS)
{
    _name = RHS._name;
    _price = RHS._price;
    _stock = RHS._stock;
}

/************************************************************************
* operator =(const Item right);
*
*   This method will copy from the right item
*------------------------------------------------------------------------
*   Parameter: right(Item&)//IN- copy from right
*------------------------------------------------------------------------
*   Return: *this(Item&)
*************************************************************************/

Item& Item::operator =(const Item &RHS)
{
    _name = RHS._name;
    _price = RHS._price;
    _stock = RHS._stock;
    return *this;
}

/************************************************************************
* string getName();
*
*   ACCESSORS; This method will return the Item_name
*------------------------------------------------------------------------
*   Parameter: none
*------------------------------------------------------------------------
*   Return: Item_name(string)
*************************************************************************/
string Item::getName() { return _name; }

/************************************************************************
* value_type getPrice();
*
*   ACCESSORS; This method will return the price
*------------------------------------------------------------------------
*   Parameter: none
*------------------------------------------------------------------------
*   Return: price(value_type)
*************************************************************************/
Item::value_type Item::getPrice() { return _price; }

/************************************************************************
* size_type getStock();
*
*   ACCESSORS; This method will return the stock
*------------------------------------------------------------------------
*   Parameter: none
*------------------------------------------------------------------------
*   Return: stock(size_type)
*************************************************************************/
int Item::getStock() { return _stock; }

/************************************************************************
* void setName(const string name);
*
*   Mutator; This method will update the Item_name attribute to the
*       parameter name value
*------------------------------------------------------------------------
*   Parameter: name (string) // IN –the Item_name for the new attribute
*------------------------------------------------------------------------
*   Return: none
*************************************************************************/
void Item::setName(const string name) { _name = name; }

/************************************************************************
* void setPrice(const value_type price);
*
*   Mutator; This method will update the Item_name attribute to the
*       parameter price value
*------------------------------------------------------------------------
*   Parameter: price (value_type) // IN –the Item_name for the new attribute
*------------------------------------------------------------------------
*   Return: none
*************************************************************************/
void Item::setPrice(const value_type price) { _price = price; }

/************************************************************************
* void setStock(const int stock);
*
*   Mutator; This method will update the Item_name attribute to the
*       parameter stock value
*------------------------------------------------------------------------
*   Parameter: stock (int) // IN –the Item_name for the new attribute
*------------------------------------------------------------------------
*   Return: none
*************************************************************************/
void Item::setStock(const int stock) { _stock = stock; }

/************************************************************************
* ostream& operator<<(std::ostream& outs, Item& target);
*
*   Friend; This method will display the Item target;
*------------------------------------------------------------------------
*   Parameter: ostream& outs
*              Item& target  // IN –the Item which would be display
*------------------------------------------------------------------------
*   Return: outs
*************************************************************************/
ostream& operator<<(std::ostream& outs, Item& target)
{
    outs << target._name <<"  " << target._price <<" " << target._stock << endl;
    return outs;
}

/************************************************************************
* void Item::print_info()
*
*   void; This method will display the Item information;
*------------------------------------------------------------------------
*   Parameter: None
*------------------------------------------------------------------------
*   Return: to screen
*************************************************************************/
void Item::print_info()
{
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);

    cout << "Item Name: " << getName() << endl;
    cout << "Price: $" << getPrice() << endl;
    cout << "Stock: "

         << getStock() << endl << endl;
}

/************************************************************************
* void Item::print_quantity()
*
*   void; This method will display the Item quantity;
*------------------------------------------------------------------------
*   Parameter: NONE
*------------------------------------------------------------------------
*   Return: to screen the info
*************************************************************************/
void Item::print_quantity()
{
    cout << "Item Name: " << getName() << endl;
    cout << "Quantity Sold: " << 100 - getStock() << endl << endl;
}

/************************************************************************
* void Item::operator== (const Item& RHS)
*
*   void; This method will compare the LHS and RHS items;
*------------------------------------------------------------------------
*   Parameter: Item RHS
*------------------------------------------------------------------------
*   Return: NONE
*************************************************************************/
bool Item::operator == (const Item& RHS) { return(_name.compare(RHS._name) == 0); }

/************************************************************************
* void Item::operator > (const Item& RHS)
*
*   void; This method will compare the LHS and RHS items;
*------------------------------------------------------------------------
*   Parameter: Item RHS
*------------------------------------------------------------------------
*   Return: NONE
*************************************************************************/
bool Item::operator > (const Item& RHS) { return(_name.compare(RHS._name) > 0); }
