/*****************************************************************
 *   AUTHOR          : Yi, Edward, Miguel, Crystal
 *   PROJECT 1       : MemberContainer Class
 *   CLASS           : CS008
 *   SECTION         : MW: 9:45AM - 11:10AM, TR:9:45AM - 11:50AM
 *   Due Date        : 4/9/2020
 ******************************************************************/

#include "report.h"

/*********************************************************
 * Report( )
 * -------------------------------------------------------
 * Postcondition: The Report has been initialized as an
 * empty report.
 *********************************************************/

Report::Report() { }

/*********************************************************
 * vector<string> daily_items_list(SaleContainer scontainer,
 * int m, int d, int y)
 * -------------------------------------------------------
 * Postcondition: Sales report that includes a list of
 * items names sold based on the given month, day, and year.
 *********************************************************/

vector<string> Report::daily_items_list(SaleContainer scontainer, int m, int d, int y)
{
    vector<string> item_list;

    for(size_t i = 0; i < scontainer.size( ); i++)
        if(scontainer[i].check_date(m, d, y))
             item_list.push_back(scontainer[i].getItem( ));

    return item_list;
}

/*********************************************************
 * vector<int> daily_quantities_list(SaleContainer
 * scontainer, int m, int d, int y)
 * -------------------------------------------------------
 * Postcondition: Sales report that includes a list of
 * items quantity sold based on the given month, day, and
 * year.
 *********************************************************/

vector<int> Report::daily_quantities_list(SaleContainer scontainer, int m, int d, int y)
{
    vector<int> quantities_list;

    for(size_t i = 0; i < scontainer.size( ); i++)
        if(scontainer[i].check_date(m, d, y))
             quantities_list.push_back(scontainer[i].getAmountSold( ));

    return quantities_list;
}

/*********************************************************
 * vector<string> daily_member_list(SaleContainer scontainer,
 * MemberContainer mcontainer, int m, int d, int y)
 * -------------------------------------------------------
 * Postcondition: Sales report that includes the names
 * of the members who shopped based on the given month,
 * day, and year.
 *********************************************************/

vector<string> Report::daily_member_list(SaleContainer scontainer, MemberContainer mcontainer, int m, int d, int y)
{
    vector<string> member_list;

    for(size_t i = 0; i < scontainer.size( ); i++)
        if(scontainer[i].check_date(m, d, y))
        {
            for(size_t j = 0; j < mcontainer.size( ); j++)
                if(mcontainer[j].get_member_number( ) == scontainer[i].getMembership( ))
                {
                    member_list.push_back(mcontainer[j].get_name( ));
                    break;
                }
        }

    return member_list;
}

/*********************************************************
 * vector<double> daily_price_list(SaleContainer scontainer,
 * MemberContainer mcontainer, int m, int d, int y)
 * -------------------------------------------------------
 * Postcondition: Sales report that includes the price
 * of the items sold based on the given month, day, and
 * year.
 *********************************************************/

vector<double> Report::daily_price_list(SaleContainer scontainer, MemberContainer mcontainer, int m, int d, int y)
{
    vector<double> price_list;

    for(size_t i = 0; i < scontainer.size( ); i++)
    {
        if(scontainer[i].check_date(m, d, y))
        {
            for(size_t j = 0; j < mcontainer.size( ); j++)
                if(mcontainer[j].get_member_number( ) == scontainer[i].getMembership( ))
                {
                    price_list.push_back(scontainer[i].getPrice( ));
                    break;
                }
        }
    }

    return price_list;
}

/*********************************************************
 * double daily_total_revenue(SaleContainer scontainer,
 * int m, int d, int y)
 * -------------------------------------------------------
 * Postcondition: Sales report that include the total
 * revenue based on the given month, day, and year.
 *********************************************************/

double Report::daily_total_revenue(SaleContainer scontainer, int m, int d, int y)
{
    double total_revenue = 0;

    for(size_t i = 0; i < scontainer.size( ); i++)
        if(scontainer[i].check_date(m, d, y))
            total_revenue += scontainer[i].total_revenue( );

    return total_revenue;
}

/*********************************************************
 * vector<int> daily_number_of_members(SaleContainer
 * scontainer, MemberContainer mcontainer, int m, int d,
 * int y)
 * -------------------------------------------------------
 * Postcondition: Sales report that include number of
 * preferred members and basic members who shopped during
 * the given month, day, and year.
 *********************************************************/

vector<int> Report::daily_number_of_members(SaleContainer scontainer, MemberContainer mcontainer, int m, int d, int y)
{
    vector<int> member_list;
    int basic = 0, preferred = 0;

    for(size_t i = 0; i < scontainer.size( ); i++)
        if(scontainer[i].check_date(m, d, y))
        {
            for(size_t j = 0; j < mcontainer.size( ); j++)
                if(mcontainer[j].get_member_number( ) == scontainer[i].getMembership( ))
                {
                    if(mcontainer[j].get_preferred_member( ))
                        preferred++;
                    else
                        basic++;
                    break;
                }
        }

    member_list.push_back(preferred);
    member_list.push_back(basic);

    return member_list;
}

/*********************************************************
 * vector<string> yearly_items_list(SaleContainer
 * scontainer, int y)
 * -------------------------------------------------------
 * Postcondition: Yearly sales report that include a
 * list of the items names sold in the given year.
 *********************************************************/

vector<string> Report::yearly_items_list(SaleContainer scontainer, int y)
{
    vector<string> item_list;

    for(size_t i = 0; i < scontainer.size( ); i++)
        if(scontainer[i].check_year(y))
             item_list.push_back(scontainer[i].getItem( ));

    return item_list;
}

/*********************************************************
 * vector<int> yearly_quantities_list(SaleContainer
 * scontainer, int y)
 * -------------------------------------------------------
 * Postcondition: Yearly sales report that include a
 * list of the items quantity sold in the given year.
 *********************************************************/

vector<int> Report::yearly_quantities_list(SaleContainer scontainer, int y)
{
    vector<int> quantities_list;

    for(size_t i = 0; i < scontainer.size( ); i++)
        if(scontainer[i].check_year(y))
             quantities_list.push_back(scontainer[i].getAmountSold( ));

    return quantities_list;
}

/*********************************************************
 * vector<string> yearly_member_list(SaleContainer
 * scontainer, MemberContainer mcontainer, int y)
 * -------------------------------------------------------
 * Postcondition: Sales report that includes the names
 * of the members who shopped based on the given the year.
 *********************************************************/

vector<string> Report::yearly_member_list(SaleContainer scontainer, MemberContainer mcontainer, int y)
{
    vector<string> member_list;

    for(size_t i = 0; i < scontainer.size( ); i++)
        if(scontainer[i].check_year(y))
        {
            for(size_t j = 0; j < mcontainer.size( ); j++)
                if(mcontainer[j].get_member_number( ) == scontainer[i].getMembership( ))
                {
                    member_list.push_back(mcontainer[j].get_name( ));
                    break;
                }
        }

    return member_list;
}

/*********************************************************
 * vector<double> yearly_price_list(SaleContainer
 * scontainer, MemberContainer mcontainer, int y)
 * -------------------------------------------------------
 * Postcondition: Sales report that includes the price
 * of the items sold based on the given the year.
 *********************************************************/

vector<double> Report::yearly_price_list(SaleContainer scontainer, MemberContainer mcontainer, int y)
{
    vector<double> price_list;

    for(size_t i = 0; i < scontainer.size( ); i++)
    {
        if(scontainer[i].check_year(y))
        {
            for(size_t j = 0; j < mcontainer.size( ); j++)
                if(mcontainer[j].get_member_number( ) == scontainer[i].getMembership( ))
                {
                    price_list.push_back(scontainer[i].getPrice( ));
                    break;
                }
        }
    }

    return price_list;
}

/*********************************************************
 * double yearly_total_revenue(SaleContainer scontainer,
 * MemberContainer mcontainer, int y)
 * -------------------------------------------------------
 * Postcondition: Yearly sales report that includes the
 * total revenue for the given year
 *********************************************************/

double Report::yearly_total_revenue(SaleContainer scontainer, MemberContainer mcontainer, int y)
{
    double total_revenue = 0;

    for(size_t i = 0; i < scontainer.size( ); i++)
        if(scontainer[i].check_year(y))
            total_revenue += scontainer[i].total_revenue( );

    return total_revenue;
}

/*********************************************************
 * string yearly_best_item(SaleContainer scontainer, int y)
 * -------------------------------------------------------
 * Postcondition: Yearly sales report that includes the
 * best item for the given year (highlights the best
 * performing items for the user).
 *********************************************************/

string Report::yearly_best_item(SaleContainer scontainer, int y)
{
    vector<string> item_list = yearly_items_list(scontainer, y);
    vector<int> quantities_list = yearly_quantities_list(scontainer, y);
    size_t track = 0;
    int best = quantities_list[track];

    for(size_t i = 1; i < item_list.size( ); i++)
    {
        if(quantities_list[i] > best)
        {
            best = quantities_list[i];
            track = i;
        }
    }

    return(item_list[track]);
}

/*********************************************************
 * string yearly_worst_item(SaleContainer scontainer, int y)
 * -------------------------------------------------------
 * Postcondition: Yearly sales report that includes the
 * worst item for the given year (highlights the worst
 * performing items for the user).
 *********************************************************/

string Report::yearly_worst_item(SaleContainer scontainer, int y)
{
    vector<string> item_list = yearly_items_list(scontainer, y);
    vector<int> quantities_list = yearly_quantities_list(scontainer, y);
    size_t track = 0;
    int worst = quantities_list[track];

    for(size_t i = 1; i < item_list.size( ); i++)
    {
        if(quantities_list[i] < worst)
        {
            worst = quantities_list[i];
            track = i;
        }
    }

    return(item_list[track]);
}

/*********************************************************
 * vector<double> member_purcahses(SaleContainer
 * scontainer, string membership)
 * -------------------------------------------------------
 * Postcondition: List of the total purchases per member
 * based on the given membership number.
 *********************************************************/

vector<double> Report::member_purcahses(SaleContainer scontainer, string membership)
{
    vector<double> purchase_list;

    for(size_t i = 0; i < scontainer.size( ); i++)
        if(scontainer[i].getMembership( ) == membership)
            purchase_list.push_back(scontainer[i].total_price( ));

    return purchase_list;
}

/*********************************************************
 * double member_total_purchase(SaleContainer scontainer,
 * string membership)
 * -------------------------------------------------------
 * Postcondition: Reports the grand total purchases per member
 * based on the given membership number.
 *********************************************************/

double Report::member_total_purchase(SaleContainer scontainer, string membership)
{
    double total_purcahse = 0;

    for(size_t i = 0; i < scontainer.size( ); i++)
        if(scontainer[i].getMembership( ) == membership)
            total_purcahse += scontainer[i].total_price( );

    return total_purcahse;
}

/*********************************************************
 * vector<string> all_member_number(MemberContainer mcontainer)
 * -------------------------------------------------------
 * Postcondition: List of all membership numbers (sorted
 * based on their numbers).
 *********************************************************/

vector<string> Report::all_member_number(MemberContainer mcontainer)
{
    vector<string> number_list;

    mcontainer.start( );

    for(size_t i = 0; i < mcontainer.size( ); i++)
    {
        number_list.push_back(mcontainer.current( ).get_member_number( ));
        mcontainer.advance( );
    }

    return number_list;
}

/*********************************************************
 * vector<string> all_member_name(MemberContainer mcontainer)
 * -------------------------------------------------------
 * Postcondition: List of all member names (sorted
 * based on their names).
 *********************************************************/

vector<string> Report::all_member_name(MemberContainer mcontainer)
{
    vector<string> name_list;

    mcontainer.start( );

    for(size_t i = 0; i < mcontainer.size( ); i++)
    {
        name_list.push_back(mcontainer.current( ).get_name( ));
        mcontainer.advance( );
    }

    return name_list;
}

/*********************************************************
 * vector<vector<double>> all_member_purchase(SaleContainer
 *  scontainer, MemberContainer mcontainer)
 * -------------------------------------------------------
 * Postcondition: Total purchases that print total purchases
 * by all the members sorted by membership number.
 *********************************************************/

vector<vector<double>> Report::all_member_purchase(SaleContainer scontainer, MemberContainer mcontainer)
{
    vector<string> number_list = all_member_number(mcontainer);
    vector<vector<double>> purchase_list;

    for(size_t i = 0; i < number_list.size( ); i++)
        purchase_list.push_back(member_purcahses(scontainer, number_list.at(i)));

    return purchase_list;
}

/*********************************************************
 * vector<double> all_member_total_purchase(SaleContainer
 * scontainer, MemberContainer mcontainer)
 * -------------------------------------------------------
 * Postcondition: Total purchases that print grand total
 * purchases by each of the members sorted by membership
 * number.
 *********************************************************/

vector<double> Report::all_member_total_purchase(SaleContainer scontainer, MemberContainer mcontainer)
{
    vector<string> number_list = all_member_number(mcontainer);
    vector<double> purchase_list;

    for(size_t i = 0; i < number_list.size( ); i++)
        purchase_list.push_back(member_total_purchase(scontainer, number_list.at(i)));

    return purchase_list;
}

/*********************************************************
 * double grand_total_purcahse(SaleContainer scontainer,
 * MemberContainer mcontainer)
 * -------------------------------------------------------
 * Postcondition: Total purchases that print grand total
 * purchases by all of the members.
 *********************************************************/

double Report::grand_total_purcahse(SaleContainer scontainer, MemberContainer mcontainer)
{
    vector<double> purchase_list = all_member_total_purchase(scontainer, mcontainer);
    double grand_total = 0;

    for(size_t i = 0; i < purchase_list.size( ); i++)
        grand_total += purchase_list.at(i);

    return grand_total;
}

/*********************************************************
 * string member_best_purcahse(SaleContainer scontainer,
 * MemberContainer mcontainer)
 * -------------------------------------------------------
 * Postcondition: Total purchase that includes the best
 * purchase from the sorted members.
 *********************************************************/

string Report::member_best_purcahse(SaleContainer scontainer, MemberContainer mcontainer)
{
    vector<string> number_list = all_member_number(mcontainer);
    vector<double> purchase_list = all_member_total_purchase(scontainer, mcontainer);
    size_t track = 0;

    if(purchase_list.size() > 0)
    {
        double best = purchase_list.at(track);

        for(size_t i = 1; i < purchase_list.size( ); i++)
        {
            if(purchase_list.at(i) > best)
            {
                best = purchase_list.at(i);
                track = i;
            }
        }

        return(number_list.at(track));
    }

    return "";
}

/*********************************************************
 * string member_worst_purchase(SaleContainer scontainer,
 * MemberContainer mcontainer)
 * -------------------------------------------------------
 * Postcondition: Total purchase that includes the worst
 * purchase from the sorted members.
 *********************************************************/

string Report::member_worst_purchase(SaleContainer scontainer, MemberContainer mcontainer)
{
    vector<string> number_list = all_member_number(mcontainer);
    vector<double> purchase_list = all_member_total_purchase(scontainer, mcontainer);
    size_t track = 0;

    if(purchase_list.size() > 0)
    {
        double worst = purchase_list.at(track);

        for(size_t i = 1; i < purchase_list.size( ); i++)
        {
            if(purchase_list.at(i) < worst)
            {
                worst = purchase_list.at(i);
                track = i;
            }
        }

        return(number_list.at(track));
    }

    return "";
}

/*********************************************************
 * bool switch_preferred(MemberContainer mcontainer,
 * string membership)
 * -------------------------------------------------------
 * Postcondition: Returns true if it would be beneficial
 * for a basic customer to switch to preferred status.
 * Displays list of members, some information about them,
 * and whether they should switch memberships.
 *********************************************************/

bool Report::switch_preferred(MemberContainer mcontainer, string membership)
{
    if(mcontainer.search_membership(membership) && !mcontainer.find(membership).get_preferred_member( ))
    {
        if(mcontainer.find(membership).get_amount_spent( ) * 0.05 >= 15)
            return true;
        else
            return false;
    }
    return false;
}

/*********************************************************
 * bool switch_basic(MemberContainer mcontainer, string
 * membership)
 * -------------------------------------------------------
 * Postcondition: Returns true if it would be beneficial
 * for a preferred customer to switch to basic status.
 * Displays list of members, some information about them,
 * and whether they should switch memberships.
 *********************************************************/

bool Report::switch_basic(MemberContainer mcontainer, string membership)
{
    if(mcontainer.search_membership(membership) && mcontainer.find(membership).get_preferred_member( ))
    {
        if(mcontainer.find(membership).get_rebate_amount( ) < 15)
            return true;
        else
            return false;
    }
    return false;
}

/*********************************************************
 * void print_rebate_preferred(MemberContainer mcontainer)
 * -------------------------------------------------------
 * Postcondition: A report that prints out the rebate of
 * all the preferred members sorted by membership number.
 *********************************************************/

void Report::print_rebate_preferred(MemberContainer mcontainer)
{
    for(size_t i = 0; i < mcontainer.size( ); i++)
        if(mcontainer[i].get_preferred_member( ))
            mcontainer[i].print_rebate( );
}

/*********************************************************
 * vector<string> item_names(ItemContainer tcontainer)
 * -------------------------------------------------------
 * Postcondition: A report that include a list of all the
 * item names.
 *********************************************************/

vector<string> Report::item_names(ItemContainer tcontainer)
{
    vector<string> item_list;

    for(size_t i = 0; i < tcontainer.Size( ); i++)
        item_list.push_back(tcontainer[i].getName( ));

    return item_list;
}

/*********************************************************
 * vector<int> item_quantity(ItemContainer tcontainer)
 * -------------------------------------------------------
 * Postcondition: A report that include a list of all the
 * item quantity.
 *********************************************************/

vector<int> Report::item_quantity(ItemContainer tcontainer,
                                  SaleContainer scontainer)
{
    vector<string> item_list = item_names(tcontainer);
    vector<int> item_quantity;
    int amount = 0;

    for(size_t i = 0; i < item_list.size( ); i++)
    {
        for(size_t j = 0; j < scontainer.size( ); j++)
        {
            if(item_list.at(i) == scontainer[j].getItem( ))
            {
                amount += scontainer[j].getAmountSold( );
            }
        }
        item_quantity.push_back(amount);
        amount = 0;
    }

    return item_quantity;
}

/*********************************************************
 * vector<double> item_total_price(ItemContainer tcontainer)
 * -------------------------------------------------------
 * Postcondition: A report that include a list of all the
 * item total price.
 *********************************************************/

vector<double> Report::item_total_price(ItemContainer tcontainer,
                                        SaleContainer scontainer)
{
    vector<string> item_list = item_names(tcontainer);
    vector<double> item_price;
    int amount = 0;

    for(size_t i = 0; i < item_list.size( ); i++)
    {
        for(size_t j = 0; j < scontainer.size( ); j++)
        {
            if(item_list.at(i) == scontainer[j].getItem( ))
            {
                amount += scontainer[j].getAmountSold( );
            }
        }
        item_price.push_back(amount * tcontainer[i].getPrice( ));
        amount = 0;
    }

    return item_price;
}

/*********************************************************
 * vector<string> member_types(MemberContainer mcontainer)
 * -------------------------------------------------------
 * Postcondition: A report that include a list of all the
 * member types (preferred or basic).
 *********************************************************/

vector<string> Report::member_types(MemberContainer mcontainer)
{
    vector<string> member_types;

    for(size_t i = 0; i < mcontainer.size( ); i++)
    {
        if(mcontainer[i].get_preferred_member( ))
            member_types.push_back("Preferred");
        else
            member_types.push_back("Basic");
    }

    return member_types;
}

/*********************************************************
 * vector<int> item_name_quantity_list(SaleContainer
 * scontainer, string name)
 * -------------------------------------------------------
 * Postcondition: A report that include a list of quantity
 * based on the given item name.
 *********************************************************/

vector<int> Report::item_name_quantity_list(SaleContainer scontainer, string name)
{
    vector<int> item_quantity;

    for(size_t i = 0; i < scontainer.size( ); i++)
        if(scontainer[i].getItem( ) == name)
            item_quantity.push_back(scontainer[i].getAmountSold( ));

    return item_quantity;
}

/*********************************************************
 * int item_name_quantity(ItemContainer tcontainer, string
 * name)
 * -------------------------------------------------------
 * Postcondition: A report that include the total quantity
 * based on the given item name.
 *********************************************************/

int Report::item_name_quantity(ItemContainer tcontainer, string name)
{
    for(size_t i = 0; i < tcontainer.Size( ); i++)
        if(tcontainer[i].getName( ) == name)
            return(100 - tcontainer[i].getStock( ));

    return 0;
}

/*********************************************************
 * vector<double> item_name_sales_list(SaleContainer
 * scontainer, string name)
 * -------------------------------------------------------
 * Postcondition: A report that include a list of sales
 * based on the given item name.
 *********************************************************/

vector<double> Report::item_name_sales_list(SaleContainer scontainer, string name)
{
    vector<double> item_sales;

    for(size_t i = 0; i < scontainer.size( ); i++)
        if(scontainer[i].getItem( ) == name)
            item_sales.push_back(scontainer[i].total_price( ));

    return item_sales;
}

/*********************************************************
 * double item_name_total_price(ItemContainer tcontainer,
 * string name)
 * -------------------------------------------------------
 * Postcondition: A report that include the total sales
 * based on the given item name.
 *********************************************************/

double Report::item_name_total_price(ItemContainer tcontainer, string name)
{
    for(size_t i = 0; i < tcontainer.Size( ); i++)
        if(tcontainer[i].getName( ) == name)
            return((100 - tcontainer[i].getStock( )) * tcontainer[i].getPrice( ));

    return 0;
}

/*********************************************************
 * MemberContainer sort_by_ID(MemberContainer mcontainer)
 * -------------------------------------------------------
 * Postcondition: Sorts a list of members by their ID
 * (based on the given member container).
 *********************************************************/

MemberContainer Report::sort_by_ID(MemberContainer mcontainer)
{
    MemberContainer temp = mcontainer;

    for(size_t i = 0; i < temp.size( ); i++)
        for(size_t j = 0; j < temp.size( ); j++)
            if(temp[j] > temp[i])
                swap(temp[i], temp[j]);
    return temp;
}

/*********************************************************
 * MemberContainer sort_by_member_name(MemberContainer
 * mcontainer)
 * -------------------------------------------------------
 * Postcondition: Sorts a list of members by their names
 * (based on the given member container).
 *********************************************************/

MemberContainer Report::sort_by_member_name(MemberContainer mcontainer)
{
    MemberContainer temp = mcontainer;

    for(size_t i = 0; i < temp.size( ); i++)
        for(size_t j = 0; j < temp.size( ); j++)
            if(temp[j].greater_than_name(temp[i]))
                swap(temp[i], temp[j]);
    return temp;
}

/*********************************************************
 * ItemContainer sort_by_item_name(ItemContainer tcontainer)
 * -------------------------------------------------------
 * Postcondition: Sorts a list of items by their names
 * (based on the given items container).
 *********************************************************/

ItemContainer Report::sort_by_item_name(ItemContainer tcontainer)
{
    ItemContainer temp = tcontainer;

    for(size_t i = 0; i < temp.Size( ); i++)
        for(size_t j = 0; j < temp.Size( ); j++)
            if(temp[j] > temp[i])
                swap(temp[i], temp[j]);
    return temp;
}

/*********************************************************
 * void swap(Member& m1, Member& m2)
 * -------------------------------------------------------
 * Postcondition: Swaps two members based on the given
 * member #1 and member #2.
 *********************************************************/

void Report::swap(Member& m1, Member& m2)
{
    Member temp = m1;
    m1 = m2;
    m2 = temp;
}

/*********************************************************
 * void swap(Item& t1, Item& t2)
 * -------------------------------------------------------
 * Postcondition: Swaps two items based on the given
 * item #1 and item #2.
 *********************************************************/

void Report::swap(Item& t1, Item& t2)
{
    Item temp = t1;
    t1 = t2;
    t2 = temp;
}

/*********************************************************
 * void print(vector<string> in)
 * -------------------------------------------------------
 * Postcondition: Prints a list of string vector.
 *********************************************************/

void Report::print(vector<string> in)
{
    for(size_t i = 0; i < in.size( ); i++)
        cout << i+1 << ". " << in.at(i) << "   ";
    cout << endl;
}

/*********************************************************
 * void print(vector<double> in)
 * -------------------------------------------------------
 * Postcondition: Prints a list of double vector.
 *********************************************************/

void Report::print(vector<double> in)
{
    for(size_t i = 0; i < in.size( ); i++)
        cout << i+1 << ". $" << in.at(i) << "   ";
    cout << endl;
}

/*********************************************************
 * void print(vector<int> in)
 * -------------------------------------------------------
 * Postcondition: Prints a list of int vector.
 *********************************************************/

void Report::print(vector<int> in)
{
    for(size_t i = 0; i < in.size( ); i++)
        cout << i+1 << ". " << in.at(i) << "   ";
    cout << endl;
}

/*********************************************************
 * void print(vector<vector<double>> in)
 * -------------------------------------------------------
 * Postcondition: Prints a list of vector which has
 * a vector double
 *********************************************************/

void Report::print(vector<vector<double>> in)
{
    for(size_t i = 0; i < in.size( ); i++)
    {
        cout << "(" << i+1 << ")" << endl;
        for(size_t j = 0; j < in.at(i).size( ); j++)
            cout << j+1 << ". $" << in.at(i).at(j) << "   ";
        cout << endl;
    }
    cout << endl;
}

void Report::membership_dues_per_year (MemberContainer mcontainer, vector<string> &names,
                                       vector<string> &ids, vector<string> &type,
                                       vector<double> &dues)
{
    mcontainer.sort_by_TypeName() ;
    type = member_types (mcontainer);
    names = all_member_name(mcontainer);
    ids = all_member_number(mcontainer);
    for(size_t i = 0; i < mcontainer.size( ); i++)
    {
        if(mcontainer[i].get_preferred_member( )){
            dues.push_back(75);
        }
        else {
            dues.push_back(60);
        }
    }
}

void Report::memberships_expiring(MemberContainer mcontainer, vector<string> &id, vector<string> &names,
                                  vector<string> &membership, vector<double> &dues, int month, int year)
{
    for(size_t i = 0; i < mcontainer.size( ); i++)
    {
        if(mcontainer[i].get_month( ) == month
                && mcontainer[i].get_year( ) < year) {
            id.push_back(mcontainer[i].get_member_number());
            names.push_back(mcontainer[i].get_name());
            if(mcontainer[i].get_preferred_member( )){
                membership.push_back("Preferred");
                dues.push_back(75);
            }
            else{
                dues.push_back(60);
                membership.push_back("Basic");
            }
        }
    }
}

void Report::save_members (MemberContainer mcontainer)
{
    ofstream ofile;
    string name, _type, ID;
    bool type;
    int m,d,y;

    ofile.open ("warehouse shoppers.txt");          //declare ofstream object

    if (ofile.fail()){               //message for failure to open the file
        cout <<" File failed to open..."<<endl;
        return;
    }

    for (size_type i = 0; i < mcontainer.size(); ++i) {
        mcontainer[i].get_exp_date(m,d,y);
        type = mcontainer[i].get_preferred_member();
        ID = mcontainer[i].get_member_number();
        name = mcontainer[i].get_name();

        if (type == 0){
            _type = "Preferred";
        }
        else {
            _type = "Basic";
        }

        ofile  << name << endl << ID << endl << _type << endl
               << m << "/" << d << "/" << y << endl;
    }

    cout << endl;
    ofile.close();                  //close the file
    cout <<"-----------Members saved-------------"<<endl;
}

MemberContainer Report::load_members()
{
    ifstream file;
    MemberContainer m_temp;
    string name,lastname, ID, _type;
    bool type;
    int m,d,y;
    char slash;

    file.open("warehouse shoppers.txt");
    if (file.fail()){            //message for failure to open the file
        cout <<" File failed to open..."<<endl;
    }
    cout << " Reading file " <<endl;
    if (file.is_open()){
        while (file >> name){
            file >> lastname >> ID >> _type
                    >> m>> slash >> d >> slash >> y;
            if (_type == "Preferred"){
                type = 0;
            }
            else {
                type = 1;
            }
            name += " " + lastname;
            Member member1 (name, ID,0, type, m,d,y);
            m_temp.attach(member1);
        }
    }

    file.close();                //close the file
    cout <<"-----------Members loaded-----------"<<endl;
    return m_temp;
}

void Report::save_sales (string filename, MemberContainer mcontainer, SaleContainer scontainer)
{
    ofstream ofile;
    ofile.open (filename);          //declare ofstream object
    string ID;
    int quantity;
    string itemName, temp;
    double price;
    int m,d,y;

    if (ofile.fail()){               //message for failure to open the file
        cout <<" File failed to open..."<<endl;
        return;
    }

    for (size_type i = 0; i < scontainer.size(); ++i) {
        scontainer[i].getDate(m,d,y);
        itemName = scontainer[i].getItem();
        ID =  mcontainer[i].get_member_number();
        price = scontainer[i].getPrice();
        quantity = scontainer[i].getAmountSold();
        ofile << m << "/" << d << "/" << y <<endl
              << ID << endl << itemName <<endl
              << price << " " <<quantity <<endl;
    }

    cout << endl;
    ofile.close();                  //close the file
    cout <<"---------Sales saved---------"<<endl;

}

void Report::load_sales (string filename, MemberContainer& mcontainer,ItemContainer& tcontainer,SaleContainer &scontainer)
{
    ifstream file;
    string ID;
    int quantity;
    string itemName, temp;
    double price;
    int m,d,y;
    char slash;

    file.open(filename);
    if (file.fail()){            //message for failure to open the file
        cout <<" File failed to open..."<<endl;
        return;
    }
    cout << " Test reading file " <<endl;
    if (file.is_open()){
        while (file >> m ){
            file >> slash >> d >> slash >> y >> ID;
            getline (file, itemName, '\n');
            getline (file, itemName, '\n');

            file >> price >> quantity;

            Item item1(itemName, price, quantity);
            tcontainer.append(item1);
            Sale sale1(mcontainer, tcontainer, ID, itemName, price, quantity, m, d, y);
            scontainer.attach(sale1);
        }
    }
    file.close();                //close the file
    cout <<"----------Sales loaded---------"<<endl;

}

MemberContainer Report::_preferred (MemberContainer mcontainer)
{
    MemberContainer temp = mcontainer;
    for(size_t i = 0; i < temp.size( ); i++)
            if(temp[i].get_preferred_member())
                temp.attach(temp[i]);
    return temp;
}

MemberContainer Report::_basics (MemberContainer mcontainer)
{
    MemberContainer temp = mcontainer;
    for(size_t i = 0; i < temp.size( ); i++)
            if(!temp[i].get_preferred_member())
                temp.attach(temp[i]);
    return temp;
}

void Report::sort_by_memberNum (MemberContainer mcontainer, SaleContainer& scontainer)
{
    SaleContainer temp ;
    mcontainer = sort_by_ID(mcontainer);
    for(size_t i = 0; i < mcontainer.size( ); i++)
        for(size_t j = 0; j < scontainer.size( ); j++)
            if (mcontainer[i].get_member_number() == scontainer[j].getMembership() ){
                temp.attach(scontainer[j]);
            }
    scontainer = temp;
}
