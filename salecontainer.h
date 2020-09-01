#ifndef SALECONTAINER_H
#define SALECONTAINER_H

/*****************************************************************
 *   AUTHOR          : Yi, Edward, Miguel, Crystal
 *   PROJECT 1       : MemberContainer Class
 *   CLASS           : CS008
 *   SECTION         : MW: 9:45AM - 11:10AM, TR:9:45AM - 11:50AM
 *   Due Date        : 4/9/2020
 ******************************************************************/

#include "sale.h"
#include <cstdlib>
#include <cassert>

class SaleContainer
{
public:
    /****************************************
    **  TYPEDEFS  **
    *****************************************/
    typedef Sale value_type;
    typedef std::size_t size_type;

    /****************************************
    **  CONSTRUCTORS  **
    *****************************************/
    SaleContainer( );
    SaleContainer(const value_type Sale);
    SaleContainer(value_type *data, size_type used, size_type capacity, size_type current);

    /****************************************
    **  BIG 3 **
    *****************************************/
    ~SaleContainer( ); // destructor
    SaleContainer(const SaleContainer& other); // copy constructor
    SaleContainer& operator =(const SaleContainer& other); // assingment operator

    /****************************************
    **  MEMBER FUNCTIONS  **
    *****************************************/
    bool is_item( ) const;
    void resize(size_t n);
    void insert(const value_type& entry);
    void attach(const value_type& entry);
    void insert_head(const value_type& entry);
    void insert_tail(const value_type& entry);
    void remove_head( );
    void remove_current( );

    /****************************************
    **  MUTATORS  **
    *****************************************/
    void last_current( );
    void start( );
    void advance( );

    /****************************************
    **  REALLOCATING MEMORY  **
    *****************************************/
    void reallocate( );
    void copy(value_type *dest, value_type *src);

    /****************************************
    **  ACCESSORS  **
    *****************************************/
    size_type size( ) const { return _used; }
    value_type current( ) const;
    value_type& operator[](size_type index);
    bool search(Sale sale);
    void print( );

    /****************************************
    **  OPERATORS  **
    *****************************************/
    SaleContainer operator + (const Sale& add);
    void operator += (const Sale &add);
    void operator += (const SaleContainer &add);

private:
    value_type *_data; // stores items in a dynamic array
    size_type _used; // number of items (used in the array)
    size_type _capacity; // used + 1 (capacity of the array)
    size_type _current; // index of the current item (based on *data)
};

/************
 * TYPEDEFS
 ************/

/*********************************************************
 * typedef ____ value_type
 * -------------------------------------------------------
 * salecontainer::value_type is the data type of the items in
 * the salecontainer. It may be any of the C++ built-in types
 * (int, char, etc.), or a class with a default constructor,
 * an assignment operator, and a copy constructor.
 *********************************************************/

/*********************************************************
 * typedef ____ size_type
 * -------------------------------------------------------
 * salecontainer::size_type is the data type of any variable
 * that keeps track ofhow many items are in a salecontainer.
 *********************************************************/

/**************
 * CONSTRUCTOR
 **************/

/*********************************************************
 * SaleContainer( )
 * -------------------------------------------------------
 * Postcondition: The SaleContainer has been initialized
 * as an empty salecontainer.
 *********************************************************/

/*********************************************************
 * SaleContainer(const value_type Sale)
 * -------------------------------------------------------
 * Postcondition: The SaleContainer has been initialized
 * based on the given Sale. Used, capacity, and current
 * is initialized as well based on one sale.
 *********************************************************/

/*********************************************************
 * SaleContainer(value_type *data, size_type used,
 * size_type capacity, size_type current)
 * -------------------------------------------------------
 * Postcondition: The SaleContainer has been initialized
 * based on given data, used, capacity, and current.
 *********************************************************/

/********
 * BIG 3
 ********/

/*********************************************************
 * ~SaleContainer( )
 * -------------------------------------------------------
 * Postcondition: The destructor of the salecontainer class
 * that deletes any left over dynamic memory (data in
 * this case) in the end.
 *********************************************************/

/*********************************************************
 * SaleContainer(const SaleContainer& other)
 * -------------------------------------------------------
 * Postcondition: The copy constructor of the salecontainer
 * class that copies another salecontiner to the salecontainer
 * currently getting accessed (this).
 *********************************************************/

/*********************************************************
 * SaleContainer& operator =(const SaleContainer& other)
 * -------------------------------------------------------
 * Postcondition: The assignment operator of the
 * salecontainer class that copies another salecontainer to
 * the salecontainer currently getting accessed (this).
 *********************************************************/

/***********
 * MUTATORS
 ***********/

/*********************************************************
 * bool is_item( ) const
 * -------------------------------------------------------
 * Postcondition: A true return value indicates that there
 * is a valid "current" item that may be retrieved by
 * activating the current member function (listed below).
 * A false return value indicates that there is no valid
 * current item.
 *********************************************************/

/*********************************************************
 * void resize(size_t n)
 * -------------------------------------------------------
 * Precondition: new_capacity equals capacity or new_capacity
 * is equal to 1/4 of capacity
 * Postcondition: If new_capacity equals capacity then the
 * capacity gets doubled. If new_capacity equals 1/4 of
 * capacity then the capacity goes 1/2 of original.
 *********************************************************/

/*********************************************************
 * void insert(const value_type& entry)
 * -------------------------------------------------------
 * Postcondition: A new copy of entry has been inserted in
 * the salecontainer before the current item. If there was no
 * current item, then the new entry has been inserted at the
 * front of the salecontainer. In either case, the newly inserted
 * item is now the current item of the salecontainer.
 *********************************************************/

/*********************************************************
 * void attach(const value_type& entry)
 * -------------------------------------------------------
 * Postcondition: Uses insert tail to attach an entry
 * in the end of the salecontainer.
 *********************************************************/

/*********************************************************
 * void insert_head(const value_type& entry)
 * -------------------------------------------------------
 * Postcondition: A new copy of entry has been inserted in
 * the salecontainer before the start of the salecontainer.
 * In this case, the newly inserted item is now the current
 * item of the salecontainer.
 *********************************************************/

/*********************************************************
 * void insert_tail(const value_type& entry)
 * -------------------------------------------------------
 * Postcondition: A new copy of entry has been inserted in
 * the salecontainer after the end of the salecontainer.
 * In this case, the newly inserted item is now the current
 * item of the salecontainer.
 *********************************************************/

/*********************************************************
 * void remove_head( )
 * -------------------------------------------------------
 * Postcondition: The item in the front has been removed
 * from the salecontainer. Current Index starts the same
 * after.
 *********************************************************/

/*********************************************************
 * void remove_current( )
 * -------------------------------------------------------
 * Precondition: size( ) < CAPACITY.
 * Postcondition: A new copy of entry has been inserted in
 * the salecontainer after the current item. If there was no
 * current item, then the new entry has been attached to the
 * end of the salecontainer. In either case, the newly inserted
 * item is now the current item of the salecontainer.
 *********************************************************/

/*****************
 * MOVING CURRENT
 *****************/

/*********************************************************
 * void last_current( )
 * -------------------------------------------------------
 * Postcondition: The last item on the salecontainer becomes
 * the current item (but if the salecontainer is empty, then
 * there is no current item).
 *********************************************************/

/*********************************************************
 * void start( )
 * -------------------------------------------------------
 * Postcondition: The first item on the salecontainer becomes
 * the current item (but if the salecontainer is empty, then
 * there is no current item).
 *********************************************************/

/*********************************************************
 * void advance( )
 * -------------------------------------------------------
 * Precondition: is_item returns true.
 * Postcondition: If the current item was already the last
 * item in salecontainer, then there is no longer any current
 * item. Otherwise, the new current item is the item
 * immediately after the original current item.
 *********************************************************/

/************
 * ACCESSORS
 ************/

/*********************************************************
 * size_type size( ) const
 * -------------------------------------------------------
 * Postcondition: The return value is the number of items
 * in the salecontainer.
 *********************************************************/

/*********************************************************
 * value_type current( ) const
 * -------------------------------------------------------
 * Precondition: is_item( ) returns true.
 * Postcondition: The item returned is the current item
 * in the salecontainer.
 *********************************************************/

/*********************************************************
 * value_type operator[](size_type index) const
 * -------------------------------------------------------
 * Postcondition: Overload subscript [] operator to use
 * a salecontainer object like an array (returns data[]).
 *********************************************************/

/*********************************************************
 * bool search(Sale sale)
 * -------------------------------------------------------
 * Postcondition: Goes through all the sales to find the
 * same sales based on the given one. If found a same
 * sale return true, else return false.
 *********************************************************/

/*********************************************************
 * void print( )
 * -------------------------------------------------------
 * Postcondition: Goes through all the sales and prints
 * all the information from sales class.
 *********************************************************/

/*************
 * OPERATORS
 *************/

/*********************************************************
 * SaleContainer operator + (const Sale& add)
 * -------------------------------------------------------
 * Postcondition: Union + operator, which uses overloaded
 * += operator to appends all of the item from object add
 * to end of current (this object.
 *********************************************************/

/*********************************************************
 * void operator += (const Sale& add)
 * -------------------------------------------------------
 * Postcondition: Overload += operator, which appends a sale
 * of the item from object addend to the end of current
 * (this) object.
 *********************************************************/

/*********************************************************
 * void operator += (const SaleContainer& add)
 * -------------------------------------------------------
 * Postcondition: Overload += operator, which appends all
 * of the item from object addend to the end of current
 * (this) object.
 *********************************************************/

/**********************
 * REALLOCATING MEMORY
 *********************/

/*********************************************************
 * void reallocate( )
 * -------------------------------------------------------
 * Postcondition: Put the information to new dynamic array
 * and copy the information there as well. Delete the
 * orginial dynamic array and reallcate memory.
 *********************************************************/

/*********************************************************
 * void copy(value_type *dest, value_type *src)
 * -------------------------------------------------------
 * Postcondition: Given the destination and soure dynamic
 * array. Copy the elements from source to destination.
 *********************************************************/

#endif // SALECONTAINER_H
