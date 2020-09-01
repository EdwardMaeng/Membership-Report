/*****************************************************************
 *   AUTHOR          : Yi, Edward, Miguel, Crystal
 *   PROJECT 1       : MemberContainer Class
 *   CLASS           : CS008
 *   SECTION         : MW: 9:45AM - 11:10AM, TR:9:45AM - 11:50AM
 *   Due Date        : 4/9/2020
 ******************************************************************/

#include "membercontainer.h"
#include <iomanip>
#include <cassert>

/**************************************************************
 * MemberContainer::MemberContainer()
 * ____________________________________________________________
 * This function intializes an empty container object
 * ___________________________________________________________
 * Pre-Condition
 * None
 *
 * Post-Condition
 * Intializes a container object with capacity, and used to 0
 *************************************************************/
MemberContainer::MemberContainer(): data(nullptr), capacity(0),
     used(0), current_index(used), preferred(0), basic(0) { }

/**************************************************************
 * MemberContainer::MemberContainer(const value_type member)
 * ____________________________________________________________
 * This function intializes the container with one member
 * ___________________________________________________________
 * Pre-Condition
 * Member is given
 *
 * Post-Condition
 * Intializes a container with the given member
 *************************************************************/
MemberContainer::MemberContainer (const value_type member)  //IN - value type member
{
    used = 1;
    current_index = 0;
    capacity = 2*used;
    data = new value_type [capacity];
    *data = member;
    preferred = 0;
    basic = 0;
}

/**************************************************************
 * MemberContainer::~ MemberContainer()
 * ____________________________________________________________
 * This is the destructor function that will free the allocated
 * memory becuase is longer in use
 * ___________________________________________________________
 * Pre-Condition
 * None
 *
 * Post-Condition
 * Return the dynamic memory
 *************************************************************/
MemberContainer::~MemberContainer ()
{
    bool debug = false;
    if (debug)
        cout<<endl << "~ MemberContainer() Destructor"<<endl;
    delete [] data;
}

/**************************************************************
 * MemberContainer& MemberContainer::operator = (const MemberContainer& RHS)
 * ____________________________________________________________
 * This is assignment operator that will copy the member variables
 * from the RHS to the LHS MemberContainer
 * ___________________________________________________________
 * Pre-Condition
 * RHS MemberContainer is given
 *
 * Post-Condition
 * The LHS now is a copy of the RHS MemberContainer
 *************************************************************/
MemberContainer& MemberContainer::operator =
(const MemberContainer& RHS)//IN- MemberContainer to assign to LHS
{
    bool debug = false;
    if (debug)
        cout<<"MemberContainer& operator = ( ) Assignment "<<endl;

    if (data == RHS.data){
        return *this;
    }
    if (data != nullptr){
        delete [] data;
    }

    used = RHS.used;
    capacity = RHS.capacity;
    data = new value_type [RHS.capacity];
    current_index = RHS.current_index;
    preferred = RHS.preferred;
    basic = RHS.basic;
    std::copy(RHS.data, RHS.data + RHS.used, data);

    return *this;
}

/**************************************************************
 * MemberContainer::MemberContainer (const MemberContainer &source)
 * ____________________________________________________________
 * This is the copy constructor that will initialilze a new MemberContainer
 * with a copy of the source parameter
 * ___________________________________________________________
 * Pre-Condition
 * A source is given to copy from
 *
 * Post-Condition
 * A new MemberContainer is initialize with a copy of the source
 *************************************************************/
MemberContainer::MemberContainer (const MemberContainer &source)//IN-source MemberContainer to copy
//to the new MemberContainer created
{
    bool debug = false;
    if (debug)
        cout<<endl <<"MemberContainer(MemberContainer copy) COPY CTOR" <<endl;

    used = source.used;
    capacity = 2*source.used;
    data = new value_type [capacity];
    std::copy(source.data, source.data + source.used, data);
    preferred = source.preferred;
    basic = source.basic;
}

/**************************************************************
 * void MemberContainer::resize (size_t new_capacity)
 * ____________________________________________________________
 * This function resize the container to a double capacity
 * if its capaity is full, and to half size if its only
 * using 1/4 of its capacity
 * ___________________________________________________________
 * Pre-Condition
 * New capacity is provided
 *
 * Post-Condition
 * Reallocate if necessary
 *************************************************************/
void MemberContainer::resize (size_t new_capacity)  //IN - new capacity
{
    value_type *new_array;

    if (new_capacity >= capacity){
        capacity *= 2;
        new_array = new value_type [capacity];
        std::copy(data, data + used, new_array);
        delete [] data ;
        data = new_array;
    }
    else if (new_capacity == capacity/4) {
        capacity *= 0.5;
        new_array = new value_type [capacity];
        std::copy(data, data + used, new_array);
        delete [] data;
        data = new_array;
    }
}

/**************************************************************
 * void MemberContainer::insert (const value_type& entry)
 * ____________________________________________________________
 * This function inserts the entry before the current item
 * or at the front if there is not current item
 * ___________________________________________________________
 * Pre-Condition
 * Entry is provided and space is available
 *
 * Post-Condition
 * Insert the entry into the container
 *************************************************************/
void MemberContainer::insert (const value_type& entry)  //IN - entry to insert
{
    // PROC - This will verify the Capacity used in container
    //        If space available put the entry before the current item
    //
    resize (used +1);
    if (current_index == 0 || current_index == used) {
        insert_head (entry);
    }
    else if (is_item()) {

        size_type next = 0;

        value_type *new_array;
        new_array = new value_type [capacity + 1];

        for (size_type index = 0; index <= used; index++)
        {
            if (index == current_index) {
                next = 1;
                new_array [index] = entry;
            }
            new_array [index + next] = data [index];
        }
        capacity++;
        used++;
        delete [] data;
        data = new_array;
    }

    if(entry.get_preferred_member( ))
        preferred++;
    else
        basic++;
}

/**************************************************************
 * void MemberContainer::attach (const value_type& entry)
 * ____________________________________________________________
 * This function inserts the entry after the current item
 * or at the end if there is no current item
 * ___________________________________________________________
 * Pre-Condition
 * Entry is provided and space is available
 *
 * Post-Condition
 * Insert the entry into the container
 *************************************************************/
void MemberContainer::attach (const value_type& entry)  // IN - entry to attach
{
    insert_tail(entry);
}

/**************************************************************
 * void MemberContainer::insert_head (const value_type& entry)
 * ____________________________________________________________
 * This function inserts entry at the front of the container
 * ___________________________________________________________
 * Pre-Condition
 * Entry given
 *
 * Post-Condition
 * container is increased with an item at the front
 *************************************************************/
void MemberContainer::insert_head (const value_type& entry)  // IN - entry to insert
{
    // PROC - insert entry at the front of the container
    MemberContainer answer (entry);
    answer += *this;
    *this = answer;
    current_index = 0;

    if(entry.get_preferred_member( ))
        preferred++;
    else
        basic++;
}

/**************************************************************
 * void MemberContainer::remove_head ()
 * ____________________________________________________________
 * This function removes the entry of the container
 * ___________________________________________________________
 * Pre-Condition
 * None
 *
 * Post-Condition
 * container no longer contains item
 *************************************************************/
void MemberContainer::remove_head ( )
{
    // PROC - set current item as the one at the front and
    //        call remove current to remove item
    if (used > 0) {
        current_index = 0;
        remove_current( );
    }
}

/**************************************************************
 * void MemberContainer::insert_tail (const value_type& entry)
 * ____________________________________________________________
 * This function inserts the entry at the end of the MemberContainer
 * ___________________________________________________________
 * Pre-Condition
 * Entry given
 *
 * Post-Condition
 * MemberContainer increased with an entry at the end
 *************************************************************/
void MemberContainer::insert_tail (const value_type& entry) //IN - entry to insert
{
    //PRO - add entry at the end, set it as current item and
    //      increase the size
    if(!search_membership(entry.get_member_number( )))
    {
        if(used > 0)
            *this += entry;
        else
            insert_head(entry);

        if(entry.get_preferred_member())
            preferred++;
        else
            basic++;
    }
    else {
        cout << "Used Membership Number (Please choose another membership number)" << endl;
    }
}

/**************************************************************
 * bool MemberContainer::search_membership (string memebership)
 * ____________________________________________________________
 * This function looks for member in the container
 * ___________________________________________________________
 * Pre-Condition
 * membership given
 *
 * Post-Condition
 * Return true if member is found else return false
 *************************************************************/

bool MemberContainer::search_membership (string membership) //IN - membership
{
    if(used > 0)
    {
        for (size_type index = 0; index <= used; index++)
            if (data[index].get_member_number( ) == membership)
                return true;
    }
    return false;
}

/**************************************************************
 * void MemberContainer::last_current ()
 * ____________________________________________________________
 * This function set the last item as the current item
 * ___________________________________________________________
 * Pre-Condition
 * None
 *
 * Post-Condition
 * Current item is the last in container
 *************************************************************/
void MemberContainer::last_current ()
{
    if (used > 0)
        current_index = used -1;   // current to be the last item
}

/**************************************************************
 * void MemberContainer::remove_current ( )
 * ____________________________________________________________
 * This function removes the current item
 * or at the end if there is not current item
 * ___________________________________________________________
 * Pre-Condition
 * There is a current item selected
 *
 * Post-Condition
 * MemberContainer no longer contains item
 *************************************************************/
void MemberContainer::remove_current ( )
{
    assert(is_item());

    if(data[current_index].get_preferred_member())
        preferred--;
    else
        basic--;

    if (current_index == used -1) {
        used--;
        current_index = used;
    }
    else {
        for (size_type index = current_index; index < used; index++)
            data [index] = data [index + 1];
        used -= 1;
    }
    resize (used);
}

/**************************************************************
 * void MemberContainer::start()
 * ____________________________________________________________
 * This function sets the first item as the current
 * ___________________________________________________________
 * Pre-Condition
 * None
 *
 * Post-Condition
 * Set the first item as current
 *************************************************************/
void MemberContainer::start ( )
{
    if (used > 0 )
        current_index = 0;  // current item the one at the front
}

/**************************************************************
 * void MemberContainer::advance ( )
 * ____________________________________________________________
 * This function set the next item as the current item
 * ___________________________________________________________
 * Pre-Condition
 * Verify current is within the container
 *
 * Post-Condition
 * Current item is set to be the next item in container
 *************************************************************/
void MemberContainer::advance ( )
{
    if (is_item())
        current_index++;   // current item to be the next item
}

/**************************************************************
 * MemberContainer::value_type MemberContainer::current ( ) const
 * ____________________________________________________________
 * This function returns the item at current position
 * ___________________________________________________________
 * Pre-Condition
 * None
 *
 * Post-Condition
 * return item at current position if is within MemberContainer
 *************************************************************/
MemberContainer::value_type MemberContainer::current( ) const
{
    assert (is_item());
    return data [current_index];   //return current item
}

/**************************************************************
 * MemberContainer::value_type& MemberContainer::operator[](size_type index)
 * ____________________________________________________________
 * This function returns the item at current index position
 * ___________________________________________________________
 * Pre-Condition
 * Index is provided
 *
 * Post-Condition
 * return item at current position if is within MemberContainer
 *************************************************************/
MemberContainer::value_type& MemberContainer::operator[](size_type index)
{ return data [index]; }

/**************************************************************
 * bool MemberContainer::is_item( ) const
 * ____________________________________________________________
 * This function verifies if item is in container
 * ___________________________________________________________
 * Pre-Condition
 * None
 *
 * Post-Condition
 * return true if it is in container else return false
 *************************************************************/
bool MemberContainer::is_item( ) const
{
    if ((used > 0) && (current_index < used)){
        return true;    //return true if current item is within sequence
    }
    return false;
}

/**************************************************************
 * Member& MemberContainer::find(const string membership) const
 * ____________________________________________________________
 * This function look for a member who holds the provided membership
 * ___________________________________________________________
 * Pre-Condition
 * Membership ID provided
 *
 * Post-Condition
 * return member object of the member holding the membership
 *************************************************************/
Member& MemberContainer::find(const string membership) const
{
    if(used > 0)
    {
        for(size_t i = 0; i < used; i++)
            if (data[i].get_member_number() == membership)
                return data[i];
    }
    //return Member( );
}

/**************************************************************
 * void MemberContainer::sort_by_memberType ( )
 * ____________________________________________________________
 * This function sort the members in member type order
 * ___________________________________________________________
 * Pre-Condition
 * None
 *
 * Post-Condition
 * sort the members in member type order
 *************************************************************/
void MemberContainer::sort_by_memberType ( )
{
    for(size_t i = 0; i < used; i++)
        for(size_t j = 0; j < used; j++)
            if(data[j].get_preferred_member() > data[i].get_preferred_member())
                swap(data[i], data[j]);
}

/**************************************************************
 * void MemberContainer::sort_by_name ( )
 * ____________________________________________________________
 * This function sort the members in name order
 * ___________________________________________________________
 * Pre-Condition
 * None
 *
 * Post-Condition
 * sort the members in name order
 *************************************************************/
void MemberContainer::sort_by_name ( )
{
    for(size_t i = 0; i < used; i++)
        for(size_t j = 0; j < used; j++)
            if(data[j].get_name() > data[i].get_name())
                swap(data[i], data[j]);
}

/**************************************************************
 * void MemberContainer::sort_by_TypeName ( )
 * ____________________________________________________________
 * This function sort the members in type order and then by name
 * ___________________________________________________________
 * Pre-Condition
 * None
 *
 * Post-Condition
 * sort the members in type and name order
 *************************************************************/
void MemberContainer::sort_by_TypeName ( )
{
    MemberContainer basics;
    MemberContainer preferred;

    for(size_t i = 0; i < used; i++){
        if(data[i].get_preferred_member()){
            preferred.attach(data[i]);
        }
        else {
            basics.attach(data[i]);
        }
    }
    basics.sort_by_name();
    preferred.sort_by_name();

    basics += preferred;
    *this = basics;
}
/**************************************************************
 * void MemberContainer::swap(Member& m1, Member& m2)
 * ____________________________________________________________
 * This function swap two members
 * ___________________________________________________________
 * Pre-Condition
 * None
 *
 * Post-Condition
 * swap the two members
 *************************************************************/
void MemberContainer::swap(Member& m1, Member& m2)
{
    Member temp = m1;
    m1 = m2;
    m2 = temp;
}

/**************************************************************
 * MemberContainer::size_type MemberContainer::getPreferred( )
 * ____________________________________________________________
 * This function returns the membership type
 * ___________________________________________________________
 * Pre-Condition
 * None
 *
 * Post-Condition
 * return preferred member
 *************************************************************/
MemberContainer::size_type MemberContainer::getPreferred( ) { return preferred; }

/**************************************************************
 * MemberContainer::size_type MemberContainer::getBasic( )
 * ____________________________________________________________
 * This function returns the membership type
 * ___________________________________________________________
 * Pre-Condition
 * None
 *
 * Post-Condition
 * return basic member
 *************************************************************/
MemberContainer::size_type MemberContainer::getBasic( ) { return basic; }

/**************************************************************
 * MemberContainer::print ()
 * ____________________________________________________________
 * This function prints the member information
 * ___________________________________________________________
 * Pre-Condition
 * None
 *
 * Post-Condition
 * print out the member information
 *************************************************************/
void MemberContainer::print ()
{
    for (size_type index = 0; index < size(); index++){
        data[index].print_info();
        cout << endl;
    }
}

/**************************************************************
 * MemberContainer MemberContainer::operator + (const Member& add)
 * ____________________________________________________________
 * This function adds a member to the container
 * ___________________________________________________________
 * Pre-Condition
 * an add member is provided
 *
 * Post-Condition
 * return contianer with the new member
 *************************************************************/
MemberContainer MemberContainer:: operator + (const Member & add)
{
    //PROC - use operator += to add member into the container
    MemberContainer answer (*this);
    answer += add;
    *this = answer;
    return *this;
}

/**************************************************************
 * void MemberContainer::operator += (const Member& add)
 * ____________________________________________________________
 * This function adds a member to the container
 * ___________________________________________________________
 * Pre-Condition
 * an add member is provided
 *
 * Post-Condition
 * return contianer with the new member
 *************************************************************/
void MemberContainer::operator += (const Member& add)
{
    resize(used +1);
    *(data + used) = add;
    current_index = used;
    used ++;
}

/**************************************************************
 * void MemberContainer::operator += (const MemberContainer& add)
 * ____________________________________________________________
 * This function adds sequence on RHS into the LHS
 * ___________________________________________________________
 * Pre-Condition
 * an add MemberContainer is provided
 *
 * Post-Condition
 * return LHS MemberContainer with all items
 *************************************************************/
void MemberContainer::operator += (const MemberContainer &add)
{
    resize (used + add.used);

    std::copy(add.data, add.data + add.used, data + used);
    used += add.used;
    current_index = used - 1;
}
