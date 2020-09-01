/*****************************************************************
 *   AUTHOR          : Yi, Edward, Miguel, Crystal
 *   PROJECT 1       : MemberContainer Class
 *   CLASS           : CS008
 *   SECTION         : MW: 9:45AM - 11:10AM, TR:9:45AM - 11:50AM
 *   Due Date        : 4/9/2020
 ******************************************************************/

#include "salecontainer.h"

/*********************************************************
 * SaleContainer( )
 * -------------------------------------------------------
 * Postcondition: The SaleContainer has been initialized
 * as an empty salecontainer.
 *********************************************************/

SaleContainer::SaleContainer(): _data(nullptr), _used(0), _capacity(0) { }

/*********************************************************
 * SaleContainer(const value_type Sale)
 * -------------------------------------------------------
 * Postcondition: The SaleContainer has been initialized
 * based on the given Sale. Used, capacity, and current
 * is initialized as well based on one sale.
 *********************************************************/

SaleContainer::SaleContainer(const value_type Sale)
{
    _used = 1;
    _current = 0;
    _capacity = 2 * _used;
    _data = new value_type [_capacity];
    *_data = Sale;
}

/*********************************************************
 * SaleContainer(value_type *data, size_type used,
 * size_type capacity, size_type current)
 * -------------------------------------------------------
 * Postcondition: The SaleContainer has been initialized
 * based on given data, used, capacity, and current.
 *********************************************************/

SaleContainer::SaleContainer(value_type *data, size_type used, size_type capacity, size_type current)
{
    _data = data;
    _used = used;
    _capacity = capacity;
    _current = current;
}

/*********************************************************
 * ~SaleContainer( )
 * -------------------------------------------------------
 * Postcondition: The destructor of the salecontainer class
 * that deletes any left over dynamic memory (data in
 * this case) in the end.
 *********************************************************/

SaleContainer::~SaleContainer( ) { delete[] _data; }

/*********************************************************
 * SaleContainer(const SaleContainer& other)
 * -------------------------------------------------------
 * Postcondition: The copy constructor of the salecontainer
 * class that copies another salecontiner to the salecontainer
 * currently getting accessed (this).
 *********************************************************/

SaleContainer::SaleContainer(const SaleContainer& other)
{
    _used = other._used;
    _capacity = other._capacity;
    _current = other._current;
    _data = new value_type[_capacity];
    copy(_data, other._data);
}

/*********************************************************
 * SaleContainer& operator =(const SaleContainer& other)
 * -------------------------------------------------------
 * Postcondition: The assignment operator of the
 * salecontainer class that copies another salecontainer to
 * the salecontainer currently getting accessed (this).
 *********************************************************/

SaleContainer& SaleContainer::operator =(const SaleContainer& other)
{
    if (this == &other)
        return *this;
    if (_data != nullptr)
        delete[] _data;

    _used = other._used;
    _capacity = other._capacity;
    _current = other._current;
    _data = new value_type[_capacity];
    copy(_data, other._data);

    return *this;
}

/*********************************************************
 * bool is_item( ) const
 * -------------------------------------------------------
 * Postcondition: A true return value indicates that there
 * is a valid "current" item that may be retrieved by
 * activating the current member function (listed below).
 * A false return value indicates that there is no valid
 * current item.
 *********************************************************/

bool SaleContainer::is_item( ) const
{
    if((_used > 0) && (_current < _used))
        return false;
    return true;
}

/*********************************************************
 * void resize(size_t n)
 * -------------------------------------------------------
 * Precondition: new_capacity equals capacity or new_capacity
 * is equal to 1/4 of capacity
 * Postcondition: If new_capacity equals capacity then the
 * capacity gets doubled. If new_capacity equals 1/4 of
 * capacity then the capacity goes 1/2 of original.
 *********************************************************/

void SaleContainer::resize(size_t new_capacity)
{
    if (new_capacity == _capacity)
    {
        _capacity *= 2;
        reallocate( );
    }
    else if (new_capacity == _capacity / 4)
    {
        _capacity *= 0.5;
        reallocate( );
    }
}

/*********************************************************
 * void insert(const value_type& entry)
 * -------------------------------------------------------
 * Postcondition: A new copy of entry has been inserted in
 * the salecontainer before the current item. If there was no
 * current item, then the new entry has been inserted at the
 * front of the salecontainer. In either case, the newly inserted
 * item is now the current item of the salecontainer.
 *********************************************************/

void SaleContainer::insert(const value_type &entry)
{
    resize(_used +1);

    if (_current == 0 || _current == _used)
        insert_head(entry);
    else if (is_item()) {
        size_type next = 0;
        value_type *new_array;
        new_array = new value_type[_capacity + 1];

        for (size_type index = 0; index <= _used; index++)
        {
            if (index == _current)
            {
                next = 1;
                new_array[index] = entry;
            }
            new_array[index + next] = _data[index];
        }
        _capacity++;
        _used ++;
        delete[] _data;
        _data = new_array;
    }
}

/*********************************************************
 * void attach(const value_type& entry)
 * -------------------------------------------------------
 * Postcondition: Uses insert tail to attach an entry
 * in the end of the salecontainer.
 *********************************************************/

void SaleContainer::attach(const value_type& entry) { insert_tail(entry); }

/*********************************************************
 * void insert_head(const value_type& entry)
 * -------------------------------------------------------
 * Postcondition: A new copy of entry has been inserted in
 * the salecontainer before the start of the salecontainer.
 * In this case, the newly inserted item is now the current
 * item of the salecontainer.
 *********************************************************/

void SaleContainer::insert_head(const value_type& entry)
{
    SaleContainer answer (entry);
    answer += *this;
    *this = answer;
    _current = 0;
}

/*********************************************************
 * void remove_head( )
 * -------------------------------------------------------
 * Postcondition: The item in the front has been removed
 * from the salecontainer. Current Index starts the same
 * after.
 *********************************************************/

void SaleContainer::remove_head( )
{
    if (_used > 0) {
        _current = 0;
        remove_current();
    }
}

/*********************************************************
 * void insert_tail(const value_type& entry)
 * -------------------------------------------------------
 * Postcondition: A new copy of entry has been inserted in
 * the salecontainer after the end of the salecontainer.
 * In this case, the newly inserted item is now the current
 * item of the salecontainer.
 *********************************************************/

void SaleContainer::insert_tail(const value_type& entry)
{
    if(_used > 0)
        *this += entry;
    else
        insert_head(entry);
}

/*********************************************************
 * bool search(Sale sale)
 * -------------------------------------------------------
 * Postcondition: Goes through all the sales to find the
 * same sales based on the given one. If found a same
 * sale return true, else return false.
 *********************************************************/

bool SaleContainer::search(Sale sale)
{
    for (size_type index = 0; index <= _used; index++)
        if (_data[index] == sale)
            return true;
    return false;
}

/*********************************************************
 * void last_current( )
 * -------------------------------------------------------
 * Postcondition: The last item on the salecontainer becomes
 * the current item (but if the salecontainer is empty, then
 * there is no current item).
 *********************************************************/

void SaleContainer::last_current( )
{
    if (_used > 0)
        _current = _used -1;
}

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

void SaleContainer::remove_current( )
{
    assert(is_item());
    if (_current == _used -1) {
        _used--;
        _current = _used;
    }
    else {
        for (size_type index = _current; index < _used; index++)
            _data[index] = _data[index + 1];
        _used -= 1;
    }
    resize(_used);
}

/*********************************************************
 * void start( )
 * -------------------------------------------------------
 * Postcondition: The first item on the salecontainer becomes
 * the current item (but if the salecontainer is empty, then
 * there is no current item).
 *********************************************************/

void SaleContainer::start( )
{
    if (_used > 0 )
        _current = 0;  // current item the one at the front
}

/*********************************************************
 * void advance( )
 * -------------------------------------------------------
 * Precondition: is_item returns true.
 * Postcondition: If the current item was already the last
 * item in salecontainer, then there is no longer any current
 * item. Otherwise, the new current item is the item
 * immediately after the original current item.
 *********************************************************/

void SaleContainer::advance( )
{
    if (is_item())
        _current++;   // current item to be the next item
}

/*********************************************************
 * value_type current( ) const
 * -------------------------------------------------------
 * Precondition: is_item( ) returns true.
 * Postcondition: The item returned is the current item
 * in the salecontainer.
 *********************************************************/

SaleContainer::value_type SaleContainer::current( ) const
{
    assert (is_item());
    return _data[_current];   //return current item
}

/*********************************************************
 * value_type operator[](size_type index) const
 * -------------------------------------------------------
 * Postcondition: Overload subscript [] operator to use
 * a salecontainer object like an array (returns data[]).
 *********************************************************/

SaleContainer::value_type& SaleContainer::operator[](size_type index) { return _data[index]; }

/*********************************************************
 * void print( )
 * -------------------------------------------------------
 * Postcondition: Goes through all the sales and prints
 * all the information from sales class.
 *********************************************************/

void SaleContainer::print( )
{
    for (size_type index = 0; index < size( ); index++)
    {
        _data[index].print_info( );
        cout << endl;
    }
}

/*********************************************************
 * SaleContainer operator + (const Sale& add)
 * -------------------------------------------------------
 * Postcondition: Union + operator, which uses overloaded
 * += operator to appends all of the item from object add
 * to end of current (this object.
 *********************************************************/

SaleContainer SaleContainer:: operator + (const Sale & add)
{
    SaleContainer answer(*this);
    answer += add;
    *this = answer;
    return *this;
}

/*********************************************************
 * void operator += (const Sale& add)
 * -------------------------------------------------------
 * Postcondition: Overload += operator, which appends a sale
 * of the item from object addend to the end of current
 * (this) object.
 *********************************************************/

void SaleContainer::operator += (const Sale &add)
{
    resize(_used +1);
    *(_data + _used) = add;
    _current = _used;
    _used++;
}

/*********************************************************
 * void operator += (const SaleContainer& add)
 * -------------------------------------------------------
 * Postcondition: Overload += operator, which appends all
 * of the item from object addend to the end of current
 * (this) object.
 *********************************************************/

void SaleContainer::operator += (const SaleContainer &add)
{
    resize(_used + add._used);

    std::copy(add._data, add._data + add._used, _data + _used);
    _used += add._used;
    _current = _used - 1;
}

/*********************************************************
 * void reallocate( )
 * -------------------------------------------------------
 * Postcondition: Put the information to new dynamic array
 * and copy the information there as well. Delete the
 * orginial dynamic array and reallcate memory.
 *********************************************************/

void SaleContainer::reallocate( )
{
    value_type* new_data = new value_type[_capacity];

    copy(new_data, _data);

    delete[] _data;

    _data = new_data;
}

/*********************************************************
 * void copy(value_type *dest, value_type *src)
 * -------------------------------------------------------
 * Postcondition: Given the destination and soure dynamic
 * array. Copy the elements from source to destination.
 *********************************************************/

void SaleContainer::copy(value_type *dest, value_type *src)
{
    for(size_t i = 0; i < _used; i++)
    {
        *dest = *src;
        dest++;
        src++;
    }
}
