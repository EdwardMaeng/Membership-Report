#include "itemcontainer.h"
#include <cstring>
#include <string.h>
#include <assert.h>

/****************************************************************
* ItemContainer Class
* This class represents a ItemContainer object. It has _data,
* _capacity and _size;
****************************************************************/

/******************************
** CONSTRUCTOR  **
******************************/
/****************************************************************
* ItemContainer ();
* Constructor; Initialize class attributes
* Parameters: none
* Return: none
***************************************************************/
ItemContainer::ItemContainer(): _capacity(10), _size(0)
{ _data = new Item[_capacity]; }

/****************************************************************
* Item(const ItemContainer &right)
* Constructor; Initialize class attributes
* Parameters: RHS(ItemContainer&)//IN- copy from right
* Return: none
***************************************************************/
ItemContainer::ItemContainer(const ItemContainer &RHS)
{
    _capacity = RHS._capacity;
    _size = RHS._size;
    _data = new Item[_capacity];

    for(size_t i = 0; i < _size; i++)
        _data[i] = RHS._data[i];
}

/****************************************************************
* ~ItemContainer ();
* Destructor; It does not perform any specific function
* Parameters: none
* Return: none
***************************************************************/
ItemContainer::~ItemContainer() { delete[] _data; }

/************************************************************************
* operator =(const ItemContainer right);
*
*   This method will copy from the right ItemContainer
*------------------------------------------------------------------------
*   Parameter: RHS(ItemContainer&)//IN- copy from right
*------------------------------------------------------------------------
*   Return: *this(ItemContainer&)
*************************************************************************/
ItemContainer& ItemContainer::operator =(const ItemContainer &RHS)
{
    Item *new_container;
    if (_data == RHS._data){
        return *this;
    }
    if (_data != nullptr){
        delete [] _data;
    }

    _size = RHS._size;
    _capacity = 2*RHS._size;
    new_container = new Item[RHS._capacity];
    _data = new_container;
    std::copy(RHS._data, RHS._data + RHS._size, _data);

    return *this;
}

/************************************************************************
*  operator[](size_t position) const;
*
*   This method will return the position element of data;
*------------------------------------------------------------------------
*   Parameter: position(size_t)//IN- give the position element
*------------------------------------------------------------------------
*   Return: _data[position](Item)
*************************************************************************/
Item& ItemContainer:: operator[](size_t position)
{
    assert(position < _size);
    return _data[position];
}

/************************************************************************
* void append (const Item& newItem);
*
*   This method will add the newItem to the end of _data;
*------------------------------------------------------------------------
*   Parameters: newItem(Item&) //IN- give the newItem to addpend
*------------------------------------------------------------------------
*   Return: none
*************************************************************************/
void ItemContainer::append (const Item& newItem)
{
    if(_size == _capacity)
        reserve(_size+1);

    _data[_size] = newItem;
    _size ++;
}

/**************************************************************************
* void reserve(size_t n);
*
*   This method will add the newItem to the end of _data;
*------------------------------------------------------------------------
*   Parameters: n(size_t) //IN- give the new _capacity to _data
*------------------------------------------------------------------------
*   Return: none
*************************************************************************/
void ItemContainer::reserve(size_t n)
{
    Item* result = _data;
    _data = new Item[n];

    for(size_t i = 0; i < _size; i++)
        _data[i] = result[i];

    _capacity = n;
    delete[] result;
}

/**************************************************************************
* void operator +=(const Item& addend);
*
*   This method will add the newItem to the end of _data;
*------------------------------------------------------------------------
*   Parameters: addend(const Item&) //IN- add the addend
*------------------------------------------------------------------------
*   Return: none
***************************************************************/
void ItemContainer::operator +=(const Item& addend) { *this = *this + addend; }

/**************************************************************************
* ItemContainer operator +(const Item &RHS);
*
*   This method will add the newItem to the end of _data;
*------------------------------------------------------------------------
*   Parameters: RHS(const Item&) //IN- add the RHS
*------------------------------------------------------------------------
*   Return: result(ItemContainer)
*************************************************************************/
ItemContainer ItemContainer::operator +(const Item &RHS)
{
    ItemContainer result = *this;
    result.append(RHS);
    return result;
}

/************************************************************************
* ItemContainer& remove (size_t pos);
*
*   This method will remove the pos element from _data
*------------------------------------------------------------------------
*   Parameter: pos(size_t)//IN- the position which will remove from _data
*------------------------------------------------------------------------
*   Return: *this(ItemContainer&)
*************************************************************************/
ItemContainer& ItemContainer::remove (size_t pos)
{
    size_t i;
    for(i = pos; i < _size - 1; i++)
        if(i>= pos)
            _data[i]=_data[i+1];
    _size--;
    return *this;
}

/************************************************************************
* Item find (const string name) const;
*
*   This method will look for the name from _data
*------------------------------------------------------------------------
*   Parameter: name(string)//IN- the name which serach from _data
*------------------------------------------------------------------------
*   Return: _data[i](Item) if found, Item() if not found.
*************************************************************************/
Item ItemContainer::find(const string name) const {
    if(_size > 0)
    {
        for(size_t i = 0; i < _size; i++)
            if (_data[i].getName() == name)
                return _data[i];
    }
    return Item( );
}

/************************************************************************
* bool search_item (const string name) const;
*
*   This method will return true if found, return false if does not found
*------------------------------------------------------------------------
*   Parameter: name(string)//IN- the name which serach from _data
*------------------------------------------------------------------------
*   Return: true if found, false if not found.
*************************************************************************/
bool ItemContainer::search_item(const string name) const
{
    if(_size > 0)
    {
        for(size_t i = 0;i < _size; i++)
            if (_data[i].getName() == name)
                return true;
    }
    return false;
}

/************************************************************************
* void print ();
*
*   This method will display all the elements of _data
*------------------------------------------------------------------------
*   Parameter: none
*------------------------------------------------------------------------
*   Return: none
*************************************************************************/
void ItemContainer::print ()
{
    for (size_type index = 0; index < _size; index++){
        cout <<_data[index]<<" ";
    }
     cout << endl;
}
