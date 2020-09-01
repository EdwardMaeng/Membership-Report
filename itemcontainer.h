#ifndef ITEMCONTAINER_H
#define ITEMCONTAINER_H
/*****************************************************************
 *   AUTHOR          : Yi, Edward, Miguel, Crystal
 *   PROJECT 1       : Item Class
 *   CLASS           : CS008
 *   SECTION         : MW: 9:45AM - 11:10AM, TR:9:45AM - 11:50AM
 *   Due Date        : 4/9/2020
 ******************************************************************/
#include "item.h"

/****************************************************************
* ItemContainer Class
* This class represents a ItemContainer object. It has _data,
* _capacity and _size;
***************************************************************/
class ItemContainer
{
public:
    typedef std::size_t size_type;

    /****************************************
    **  CONSTRUCTORS & DESTRUCTOR  **
    *****************************************/
    ItemContainer();
    ItemContainer(const ItemContainer &RHS);
    ~ItemContainer();
    ItemContainer& operator =(const ItemContainer &RHS);

    /*******************************************
    **  ACCESSORS  **
    *******************************************/
    size_type Capacity(){ return _capacity; }
    size_type Size(){ return _size; }
    void print ();

    /*******************************************
    ** MODIFICATION MEMBER FUNCTIONS **
    *******************************************/
    void reserve(size_t n);
    void append (const Item& newItem);
    ItemContainer& remove (size_t pos);
    bool search_item(const string name) const;
    Item find(const string name) const;

    /*******************************************
    ** OPERATORS **
    *******************************************/
    void operator +=(const Item& addend);
    ItemContainer operator + (const Item& RHS);
    Item& operator[](size_t position);

    /*******************************************
    **  FRIEND FUNCTIONS  **
    *******************************************/
    friend std::istream& operator>>(std::istream& ins, ItemContainer& target);
    friend std::istream& operator>>(std::istream& ins, Item& newitem);
    friend std::ostream& operator<<(std::ostream& outs, ItemContainer& target);

private:
    Item* _data;            //IN/OUT - stores items in a dynamic array
    size_type _capacity;    //IN/OUT - capacity of container
    size_type _size;        //IN/OUT - size used of container
};

#endif // ITEMCONTAINER_H

/**************************************************************************
 * ItemContainer Class
 * This class represents a ItemContainer object. It has _data,
 * _capacity and _size
 **************************************************************************/

/****************************************
 **  CONSTRUCTORS  **
 *****************************************/

/*****************************************
 *  ItemContainer ();
 *   Constructor: intializes an empty container object
 *   Parameters: None
 *   Return: None
 *****************************************/

/****************************************
 **  BIG 3  **
 *****************************************/
/*****************************************
 * ~ItemContainer ();
 *   Destructor: Delete the memory allocated or return the
 *               dynamic memory to the heap when the object
 *               is no longer in use
 *   Parameters: None
 *   Return: None
 *****************************************/
/*****************************************
 * ItemContainer& operator = (const ItemContainer& RHS);
 *   Assignment operator: copying member variables from RHS to the
 *                        LHS container
 *   Parameters: constant ItemContainer in the right hand side
 *   Return: None
 *****************************************/
/*****************************************
 *  ItemContainer(const ItemContainer &RHS);
 *   Constructor: intializes new container with the given
 *   item container
 *   Parameters: ItemContainer RHS
 *   Return: None
 *****************************************/


/****************************************
 **  MUTATORS  **
 *****************************************/
/****************************************
 * void reserve (size_t n);
 *   Mutator: reallocate the capacity of the container
 *            if necessary
 *   Parameters: n as the size of the container
 *   Return: None
 *****************************************/
/****************************************
 * void append (const Item& entry);
 *   Mutator: insert the entry at the end of the container
 *   Parameters: entry to insert into the container
 *   Return: None
 *****************************************/
/****************************************
 * ItemContainer& remove (size_t pos);
 *   Mutator: remove the entry located at pos
 *   Parameters: size_t pos
 *   Return: container with item removed
 *****************************************/
/****************************************
 * Item find(const string name) const;
 *   Mutator: search if the item is in container
 *   Parameters: string name
 *   Return: return Item if found
 *****************************************/
/****************************************
 * bool search_item(const string name) const;
 *   Mutator: search if the item is in container
 *   Parameters: string name
 *   Return: return true if found
 *****************************************/


/*******************************************
 ** OPERATORS **
 *******************************************/
/****************************************
 * void operator +=(const Item& addend);
 *   Mutator: add the item in the container
 *   Parameters: Item& addend
 *   Return: None
 *****************************************/
/****************************************
 *  ItemContainer operator + (const Item& RHS);
 *   Mutator: add the item in the container
 *   Parameters: Item& RHS
 *   Return: None
 *****************************************/
/****************************************
 *  Item& operator[](size_t position);
 *   Mutator: return item located at position given
 *   Parameters: size_t position
 *   Return: return item located at position
 *****************************************/


/****************************************
 **  ACCESSORS  **
 *****************************************/
/****************************************
 * size_type Capacity()
 *   Accessor: returns the capacity of container
 *   Parameters: none
 *   Return: capacity
 *****************************************/
/****************************************
 * size_type size ()
 *   Accessor: returns the size of the container
 *   Parameters: None
 *   Return: Interger represeting the size
 *****************************************/
/*****************************************
 * void print ();
 *   Accessor: This will output the items in the container
 *   Parameters: None
 *   Return: None
 ******************************************/

/****************************************
 **  FRIEND FUNCTIONS  **
 *****************************************/
/*****************************************
 * friend std::istream& operator>>(std::istream& ins, ItemContainer& target);
 *   istream operator >> : reads in the target
 *   Parameters: istream ins and ItemContainer& target
 *   Return: None
 ******************************************/
/*****************************************
 * friend std::istream& operator>>(std::istream& ins, Item& newitem);
 *   istream operator >>: reads in the item
 *   Parameters: istream ins and Item& newitem
 *   Return: None
 ******************************************/
/*****************************************
 * friend std::ostream& operator<<(std::ostream& outs, ItemContainer& target);
 *   istream operator <<: This will output the items in the container
 *   Parameters: ostream& outs, ItemContainer& target
 *   Return: None
 ******************************************/
