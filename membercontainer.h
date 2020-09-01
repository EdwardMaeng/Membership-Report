#ifndef MEMBERCONTAINER_H
#define MEMBERCONTAINER_H

/*****************************************************************
 *   AUTHOR          : Yi, Edward, Miguel, Crystal
 *   PROJECT 1       : MemberContainer Class
 *   CLASS           : CS008
 *   SECTION         : MW: 9:45AM - 11:10AM, TR:9:45AM - 11:50AM
 *   Due Date        : 4/9/2020
 ******************************************************************/

#include "member.h"
#include <cstdlib>  // Provides size_t
#include <string>

class MemberContainer
{
public:
    /****************************************
    **  TYPEDEFS  **
    *****************************************/
    typedef Member value_type;
    typedef std::size_t size_type;

    /****************************************
    **  CONSTRUCTORS  **
    *****************************************/
    MemberContainer ();
    MemberContainer (const value_type member);

    /****************************************
    **  BIG 3  **
    *****************************************/
    ~MemberContainer ();                                      //destructor
    MemberContainer& operator = (const MemberContainer& RHS); //assginment operator
    MemberContainer (const MemberContainer &copyThis);        //copy constructor

    /****************************************
    **  MUTATORS  **
    *****************************************/
    void resize (size_t n);
    void insert (const value_type& entry);
    void attach (const value_type& entry);
    void insert_head (const value_type& entry);
    void remove_head ();
    void insert_tail (const value_type& entry);
    bool search_membership (string membership);

    /****************************************
     **  MOVING CURRENT  **
     *****************************************/
    void last_current ();
    void remove_current ( );
    void start ( );
    void advance ( );

    /****************************************
     **  SORT FUNCTIONS  **
     *****************************************/
    void sort_by_memberType ( );
    void sort_by_name ( );
    void sort_by_TypeName( );
    void swap(Member& m1, Member& m2);

    /****************************************
    **  ACCESSORS  **
    *****************************************/
    Member& find(const string membership) const;
    size_type size( ) const{ return used;}
    value_type current( ) const;
    value_type& operator[](size_type index);
    bool is_item( ) const;
    size_type getPreferred( );
    size_type getBasic( );
    void print ();

    /****************************************
    **  OPERATORS  **
    *****************************************/
    MemberContainer operator + (const Member& add);
    void operator += (const Member &add);
    void operator += (const MemberContainer &add);

private:
    value_type *data;          //IN/OUT - stores items in a dynamic array
    size_type used;           //IN/OUT - number of items (used in the array)
    size_type capacity;       //IN/OUT - used + 1 (capacity of the array)
    size_type current_index;  //IN/OUT - index of the current item (based on *data)
    size_type preferred,      //IN/OUT - type of membership
    basic;
};

#endif // MEMBERCONTAINER_H

/**************************************************************************
 * MemberContainer Class
 *     This class contains all member data in order one after other.
 *     It allows to step through the member information one at a time to mdify them.
 *     It also control precisely where members are inserted and
 *     removed within the container.
 **************************************************************************/


/****************************************
 **  CONSTRUCTORS  **
 *****************************************/

/*****************************************
 *  MemberContainer ();
 *   Constructor: intializes an empty container object
 *   Parameters: None
 *   Return: None
 *****************************************/
/*****************************************
 *  MemberContainer (const value_type member);
 *   Constructor: intializes new container with the given
 *   member
 *   Parameters: value type member
 *   Return: None
 *****************************************/

/****************************************
 **  BIG 3  **
 *****************************************/
/*****************************************
 * ~MemberContainer ();
 *   Destructor: Delete the memory allocated or return the
 *               dynamic memory to the heap when the object
 *               is no longer in use
 *   Parameters: None
 *   Return: None
 *****************************************/
/*****************************************
 * MemberContainer& operator = (const MemberContainer& RHS);
 *   Assignment operator: copying member variables from RHS to the
 *                        LHS string
 *   Parameters: constant MemberContainer in the right hand side
 *   Return: None
 *****************************************/
/*****************************************
 *  MemberContainer (const MemberContainer &copyThis);
 *   Copy Constructor: Intialize a new MemberContainer with a copy of the
 *                     MemberContainer parameter
 *   Parameters: constant MemberContainer to be copied
 *   Return: None
 *****************************************/


/****************************************
 **  MUTATORS  **
 *****************************************/
/****************************************
 * void resize (size_t n);
 *   Mutator: reallocate the capacity of the container
 *            if necessary
 *   Parameters: n as the size of the container
 *   Return: None
 *****************************************/
/****************************************
 * void insert (const value_type& entry);
 *   Mutator: insert the entry before or at the front
 *   Parameters: entry to insert into the container
 *   Return: None
 *****************************************/
/****************************************
 * void attach (const value_type& entry);
 *   Mutator: attach the entry after or at the end
 *   Parameters: entry to attach into the container
 *   Return: None
 *****************************************/
/****************************************
 * void insert_head (const value_type& entry);
 *   Mutator: insert the entry at the front
 *   Parameters: entry to insert into the container
 *   Return: None
 *****************************************/
/****************************************
 * void remove_head (const value_type& entry);
 *   Mutator: remove the entry from the container
 *   Parameters: entry to remove from the container
 *   Return: None
 *****************************************/
/****************************************
 * void insert_tail (const value_type& entry);
 *   Mutator: insert the entry at the end of the container
 *   Parameters: entry to insert into the container
 *   Return: None
 *****************************************/
/****************************************
 * bool search_membership (string membership);
 *   Mutator: search if the membership is hold
 *            by any other member
 *   Parameters: string membership
 *   Return: return true is it exists, else false
 *****************************************/

/****************************************
 **  MOVING CURRENT  **
 *****************************************/
/****************************************
 * void last_current ();
 *   Current: set the last item as the current item
 *   Parameters: None
 *   Return: None
 *****************************************/
/****************************************
 * void remove_current ( );
 *   Current: remove the item at current position
 *   Parameters: None
 *   Return: None
 *****************************************/
/****************************************
 * void start ( );
 *   Current: set the first item as the current item
 *   Parameters: None
 *   Return: None
 *****************************************/
/****************************************
 * void advance ( );
 *   Current: set the next item as the current item
 *   Parameters: None
 *   Return: None
 *****************************************/


/****************************************
 **  SORT FUNCTIONS  **
 *****************************************/
/****************************************
 * void sort_by_memberType ( );
 *   Sort: sort the members in memberType order
 *   Parameters: None
 *   Return: None
 *****************************************/
/****************************************
 * void sort_by_name ( );
 *   Sort: sort the members by name
 *   Parameters: None
 *   Return: None
 *****************************************/
/****************************************
 * void sort_by_TypeName( );
 *   Sort: group the members by type and then
 *         sort them in name order
 *   Parameters: None
 *   Return: None
 *****************************************/
/****************************************
 * void swap(Member& m1, Member& m2));
 *   Sort: swap m1 with m2
 *   Parameters: member objects
 *   Return: None
 *****************************************/


/****************************************
 **  ACCESSORS  **
 *****************************************/
/****************************************
 * Member& find(const string membership)  const;
 *   Accessor: returns the member with membership given
 *   Parameters: string membership
 *   Return: Member
 *****************************************/
/****************************************
 * size_type size ()
 *   Accessor: returns the size of the container
 *   Parameters: None
 *   Return: Interger represeting the size
 *****************************************/
/****************************************
 * value_type current( ) const;
 *   Accessor: returns the current item
 *   Parameters: None
 *   Return: item at current position
 *****************************************/
/****************************************
 * value_type operator[](size_type index) const;
 *   Accessor: returns the current item
 *   Parameters: index in the sequence
 *   Return: Returns item at current[index] position
 *****************************************/
/*****************************************
 * bool is_item( ) const;
 *   Accessor: This check if current index is within the container
 *   Parameters: None
 *   Return: true if current index is within the container
 ******************************************/
/*****************************************
 * size_type getPreferred ();
 *   Accessor: returns the type of membership preferred
 *   Parameters: None
 *   Return: size_type to represent preferred
 ******************************************/
/*****************************************
 * size_type getBasic( );
 *   Accessor: returns the type of membership basic
 *   Parameters: None
 *   Return: size_type to represent basic
 ******************************************/
/*****************************************
 * void print ();
 *   Accessor: This will output the items in the container
 *   Parameters: None
 *   Return: None
 ******************************************/


/*******************************************
 **  OPERATORS  **
 *******************************************/
/********************************************
 * MemberContainer operator + (const Member& add);
 *   Operator: Adds member into the container
 *   Parameters: Member to add
 *   Return: container with new add member
 **********************************************/
/*********************************************
 * void operator += (const Member& add);
 *   Operator: Adds member into the container
 *   Parameters: Member to add
 *   Return: container with new add member
 **********************************************/
/*********************************************
 * void operator += (const MemberContainer& add);
 *   Operator: adds items from MemberContainer in rhs to the lhs
 *   Parameters: MemberContainer to add
 *   Return: The lhs contianer with all the items
 **********************************************/
