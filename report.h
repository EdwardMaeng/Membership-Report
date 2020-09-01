#ifndef REPORT_H
#define REPORT_H

#include "salecontainer.h"
#include <vector>
#include <fstream>

using namespace std;

class Report
{
public:
    /****************************************
    **  TYPEDEFS  **
    *****************************************/
    typedef double value_type;
    typedef std::size_t size_type;

    /****************************************
    **  CONSTRUCTORS  **
    *****************************************/
    Report( );

    /****************************************
    **  DAILY SALES REPORT  **
    *****************************************/
    vector<string> daily_items_list(SaleContainer scontainer, int m, int d, int y);
    vector<int> daily_quantities_list(SaleContainer scontainer, int m, int d, int y);
    vector<string> daily_member_list(SaleContainer scontainer, MemberContainer mcontainer, int m, int d, int y);
    vector<double> daily_price_list(SaleContainer scontainer, MemberContainer mcontainer, int m, int d, int y);
    double daily_total_revenue(SaleContainer scontainer, int m, int d, int y);
    vector<int> daily_number_of_members(SaleContainer scontainer, MemberContainer mcontainer, int m, int d, int y);

    /****************************************
    **  YEARLY SALES REPORT  **
    *****************************************/
    vector<string> yearly_items_list(SaleContainer scontainer, int y);
    vector<int> yearly_quantities_list(SaleContainer scontainer, int y);
    vector<string> yearly_member_list(SaleContainer scontainer, MemberContainer mcontainer, int y); // *** new ***
    vector<double> yearly_price_list(SaleContainer scontainer, MemberContainer mcontainer, int y); // *** new ***
    double yearly_total_revenue(SaleContainer scontainer, MemberContainer mcontainer, int y);
    string yearly_best_item(SaleContainer scontainer, int y);
    string yearly_worst_item(SaleContainer scontainer, int y);

    /****************************************
    **  TOTAL PURCHASE (MEMBER NUMBER)  **
    *****************************************/
    vector<double> member_purcahses(SaleContainer scontainer, string membership);
    double member_total_purchase(SaleContainer scontainer, string membership);

    /****************************************
    **  TOTAL PURCHASE (ALL MEMBER NUMBER)  **
    *****************************************/
    vector<string> all_member_number(MemberContainer mcontainer);
    vector<string> all_member_name(MemberContainer mcontainer);
    vector<vector<double>> all_member_purchase(SaleContainer scontainer, MemberContainer mcontainer);
    vector<double> all_member_total_purchase(SaleContainer scontainer, MemberContainer mcontainer);
    double grand_total_purcahse(SaleContainer scontainer, MemberContainer mcontainer);
    string member_best_purcahse(SaleContainer scontainer, MemberContainer mcontainer);
    string member_worst_purchase(SaleContainer scontainer, MemberContainer mcontainer);

    /****************************************
    **  SWTICH TO PREFERRED OR BASIC  **
    *****************************************/
    bool switch_preferred(MemberContainer mcontainer, string membership);
    bool switch_basic(MemberContainer mcontainer, string membership);

    /****************************************
    **  REBATE FOR PREFERRED  **
    *****************************************/
    void print_rebate_preferred(MemberContainer mcontainer);

    /****************************************
    **  EACH ITEM SOLD  **
    *****************************************/
    vector<string> item_names(ItemContainer tcontainer); // *** new ***
    vector<int> item_quantity(ItemContainer tcontainer,
                              SaleContainer scontainer);
    vector<double> item_total_price(ItemContainer tcontainer,
                                    SaleContainer scontainer);

    /****************************************
    **  MEMBERSHIP DUES PER YEAR  **
    *****************************************/
    vector<string> member_types(MemberContainer mcontainer);

    void membership_dues_per_year(MemberContainer mcontainer, vector<string> &names,
                                  vector<string> &ids,
                                  vector<string> &type, vector<double> &dues);

    /****************************************
    **  MEMBERSHIP EXPIRES IN MONTH  **
    *****************************************/
    void memberships_expiring (MemberContainer mcontainer, vector<string> &id,
                               vector<string> &names,vector<string> &membership,
                               vector<double> &dues,int month, int year);

    /****************************************
    **  ITEMS NAMES  **
    *****************************************/
    vector<int> item_name_quantity_list(SaleContainer scontainer, string name);
    int item_name_quantity(ItemContainer tcontainer, string name);
    vector<double> item_name_sales_list(SaleContainer scontainer, string name);
    double item_name_total_price(ItemContainer tcontainer, string name);

    /****************************************
    **  SORT FUNCTIONS  **
    *****************************************/
    MemberContainer sort_by_ID(MemberContainer mcontainer);
    MemberContainer sort_by_member_name(MemberContainer mcontainer);
    ItemContainer sort_by_item_name(ItemContainer tcontainer);
    void swap(Member& m1, Member& m2);
    void swap(Item& t1, Item& t2);
    void sort_by_memberNum (MemberContainer mcontainer, SaleContainer& scontainer);

    /****************************************
    **  Print Functions  **
    *****************************************/
    void print(vector<string> in);
    void print(vector<double> in);
    void print(vector<int> in);
    void print(vector<vector<double>> in);

    /****************************************
    **  SAVE AND LOAD IN FILES  **
    *****************************************/
    void save_members (MemberContainer mcontainer);
    MemberContainer load_members ();
    void save_sales (string filename, MemberContainer mcontainer, SaleContainer scontainer);
    void load_sales(string filename, MemberContainer &mcontainer,ItemContainer &tcontainer, SaleContainer &scontainer);

    MemberContainer _preferred (MemberContainer mcontainer);
    MemberContainer _basics (MemberContainer mcontainer);
};

#endif // REPORT_H

/************
 * TYPEDEFS
 ************/

/*********************************************************
 * typedef ____ value_type
 * -------------------------------------------------------
 * salecontainer::value_type is the data type of the items in
 * the report class. It may be any of the C++ built-in types
 * (int, char, etc.), or a class with a default constructor,
 * an assignment operator, and a copy constructor.
 *********************************************************/

/*********************************************************
 * typedef ____ size_type
 * -------------------------------------------------------
 * salecontainer::size_type is the data type of any variable
 * that keeps track ofhow many items are in a report class.
 *********************************************************/

/***************
 * CONSTRUCTOR
 ***************/

/*********************************************************
 * Report( )
 * -------------------------------------------------------
 * Postcondition: The Report has been initialized as an
 * empty report.
 *********************************************************/

/***************
 * DAILY SALES
 ***************/

/*********************************************************
 * vector<string> daily_items_list(SaleContainer scontainer,
 * int m, int d, int y)
 * -------------------------------------------------------
 * Postcondition: Sales report that includes a list of
 * items names sold based on the given month, day, and year.
 *********************************************************/

/*********************************************************
 * vector<int> daily_quantities_list(SaleContainer
 * scontainer, int m, int d, int y)
 * -------------------------------------------------------
 * Postcondition: Sales report that includes a list of
 * items quantity sold based on the given month, day, and
 * year.
 *********************************************************/

/*********************************************************
 * vector<string> daily_member_list(SaleContainer scontainer,
 * MemberContainer mcontainer, int m, int d, int y)
 * -------------------------------------------------------
 * Postcondition: Sales report that includes the names
 * of the members who shopped based on the given month,
 * day, and year.
 *********************************************************/

/*********************************************************
 * vector<double> daily_price_list(SaleContainer scontainer,
 * MemberContainer mcontainer, int m, int d, int y)
 * -------------------------------------------------------
 * Postcondition: Sales report that includes the price
 * of the items sold based on the given month, day, and
 * year.
 *********************************************************/

/*********************************************************
 * double daily_total_revenue(SaleContainer scontainer,
 * int m, int d, int y)
 * -------------------------------------------------------
 * Postcondition: Sales report that include the total
 * revenue based on the given month, day, and year.
 *********************************************************/

/*********************************************************
 * vector<int> daily_number_of_members(SaleContainer
 * scontainer, MemberContainer mcontainer, int m, int d,
 * int y)
 * -------------------------------------------------------
 * Postcondition: Sales report that include number of
 * preferred members and basic members who shopped during
 * the given month, day, and year.
 *********************************************************/

/***************
 * YEARLY SALES
 ***************/

/*********************************************************
 * vector<string> yearly_items_list(SaleContainer
 * scontainer, int y)
 * -------------------------------------------------------
 * Postcondition: Yearly sales report that include a
 * list of the items names sold in the given year.
 *********************************************************/

/*********************************************************
 * vector<int> yearly_quantities_list(SaleContainer
 * scontainer, int y)
 * -------------------------------------------------------
 * Postcondition: Yearly sales report that include a
 * list of the items quantity sold in the given year.
 *********************************************************/

/*********************************************************
 * vector<string> yearly_member_list(SaleContainer
 * scontainer, MemberContainer mcontainer, int y)
 * -------------------------------------------------------
 * Postcondition: Sales report that includes the names
 * of the members who shopped based on the given the year.
 *********************************************************/

/*********************************************************
 * vector<double> yearly_price_list(SaleContainer
 * scontainer, MemberContainer mcontainer, int y)
 * -------------------------------------------------------
 * Postcondition: Sales report that includes the price
 * of the items sold based on the given the year.
 *********************************************************/

/*********************************************************
 * double yearly_total_revenue(SaleContainer scontainer,
 * MemberContainer mcontainer, int y)
 * -------------------------------------------------------
 * Postcondition: Yearly sales report that includes the
 * total revenue for the given year
 *********************************************************/

/*********************************************************
 * string yearly_best_item(SaleContainer scontainer, int y)
 * -------------------------------------------------------
 * Postcondition: Yearly sales report that includes the
 * best item for the given year (highlights the best
 * performing items for the user).
 *********************************************************/

/*********************************************************
 * string yearly_worst_item(SaleContainer scontainer, int y)
 * -------------------------------------------------------
 * Postcondition: Yearly sales report that includes the
 * worst item for the given year (highlights the worst
 * performing items for the user).
 *********************************************************/

/*********************************
 * TOTAL PURCHASE (MEMBER NUMBER)
 *********************************/

/*********************************************************
 * vector<double> member_purcahses(SaleContainer
 * scontainer, string membership)
 * -------------------------------------------------------
 * Postcondition: List of the total purchases per member
 * based on the given membership number.
 *********************************************************/

/*********************************************************
 * double member_total_purchase(SaleContainer scontainer,
 * string membership)
 * -------------------------------------------------------
 * Postcondition: Reports the grand total purchases per member
 * based on the given membership number.
 *********************************************************/

/*************************************
 * TOTAL PURCHASE (ALL MEMBER NUMBER)
 *************************************/

/*********************************************************
 * vector<string> all_member_number(MemberContainer mcontainer)
 * -------------------------------------------------------
 * Postcondition: List of all membership numbers (sorted
 * based on their numbers).
 *********************************************************/

/*********************************************************
 * vector<string> all_member_name(MemberContainer mcontainer)
 * -------------------------------------------------------
 * Postcondition: List of all member names (sorted
 * based on their names).
 *********************************************************/

/*********************************************************
 * vector<vector<double>> all_member_purchase(SaleContainer
 *  scontainer, MemberContainer mcontainer)
 * -------------------------------------------------------
 * Postcondition: Total purchases that print total purchases
 * by all the members sorted by membership number.
 *********************************************************/

/*********************************************************
 * vector<double> all_member_total_purchase(SaleContainer
 * scontainer, MemberContainer mcontainer)
 * -------------------------------------------------------
 * Postcondition: Total purchases that print grand total
 * purchases by each of the members sorted by membership
 * number.
 *********************************************************/

/*********************************************************
 * double grand_total_purcahse(SaleContainer scontainer,
 * MemberContainer mcontainer)
 * -------------------------------------------------------
 * Postcondition: Total purchases that print grand total
 * purchases by all of the members.
 *********************************************************/

/*********************************************************
 * string member_best_purcahse(SaleContainer scontainer,
 * MemberContainer mcontainer)
 * -------------------------------------------------------
 * Postcondition: Total purchase that includes the best
 * purchase from the sorted members.
 *********************************************************/

/*********************************************************
 * string member_worst_purchase(SaleContainer scontainer,
 * MemberContainer mcontainer)
 * -------------------------------------------------------
 * Postcondition: Total purchase that includes the worst
 * purchase from the sorted members.
 *********************************************************/

/******************************
* SWTICH TO PREFERRED OR BASIC
*******************************/

/*********************************************************
 * bool switch_preferred(MemberContainer mcontainer,
 * string membership)
 * -------------------------------------------------------
 * Postcondition: Returns true if it would be beneficial
 * for a basic customer to switch to preferred status.
 * Displays list of members, some information about them,
 * and whether they should switch memberships.
 *********************************************************/

/*********************************************************
 * bool switch_basic(MemberContainer mcontainer, string
 * membership)
 * -------------------------------------------------------
 * Postcondition: Returns true if it would be beneficial
 * for a preferred customer to switch to basic status.
 * Displays list of members, some information about them,
 * and whether they should switch memberships.
 *********************************************************/

/***********************
* REBATE FOR PREFERRED
************************/

/*********************************************************
 * void print_rebate_preferred(MemberContainer mcontainer)
 * -------------------------------------------------------
 * Postcondition: A report that prints out the rebate of
 * all the preferred members sorted by membership number.
 *********************************************************/

/****************
* EACH ITEM SOLD
*****************/

/*********************************************************
 * vector<string> item_names(ItemContainer tcontainer)
 * -------------------------------------------------------
 * Postcondition: A report that include a list of all the
 * item names.
 *********************************************************/

/*********************************************************
 * vector<int> item_quantity(ItemContainer tcontainer)
 * -------------------------------------------------------
 * Postcondition: A report that include a list of all the
 * item quantity.
 *********************************************************/

/*********************************************************
 * vector<double> item_total_price(ItemContainer tcontainer)
 * -------------------------------------------------------
 * Postcondition: A report that include a list of all the
 * item total price.
 *********************************************************/

/**************************
* MEMBERSHIP DUES PER YEAR
***************************/

/*********************************************************
 * vector<string> member_list(MemberContainer mcontainer)
 * -------------------------------------------------------
 * Postcondition: A report that include a list of all the
 * member names.
 *********************************************************/

/*********************************************************
 * vector<string> member_types(MemberContainer mcontainer)
 * -------------------------------------------------------
 * Postcondition: A report that include a list of all the
 * member types (preferred or basic).
 *********************************************************/

/*********************************************************
 * void membership_dues_per_year(MemberContainer mcontainer,
 * vector<string> &basic_names, vector<string> &preferred_names,
 * vector<string> &basic_membership, vector<string>
 * &preferred_membership, vector<double> &basic_dues,
 * vector<double> &preferred_dues, bool name_type)
 * -------------------------------------------------------
 * Postcondition: A report that includes the amount per year
 * paid by each member for the membership dues.
 *********************************************************/

/*****************************
* MEMBERSHIP EXPIRES IN MONTH
******************************/

/*********************************************************
 * void memberships_expiring(MemberContainer mcontainer,
 * vector<string> &id, vector<string> &names, vector<string>
 * &membership, vector<double> &dues, int month)
 * -------------------------------------------------------
 * Postcondition: A report that include a list of all
 * members whose memberships expire that month as well
 * as their dues amount.
 *********************************************************/

/************
* ITEM NAMES
*************/

/*********************************************************
 * vector<int> item_name_quantity_list(SaleContainer
 * scontainer, string name)
 * -------------------------------------------------------
 * Postcondition: A report that include a list of quantity
 * based on the given item name.
 *********************************************************/

/*********************************************************
 * int item_name_quantity(ItemContainer tcontainer, string
 * name)
 * -------------------------------------------------------
 * Postcondition: A report that include the total quantity
 * based on the given item name.
 *********************************************************/

/*********************************************************
 * vector<double> item_name_sales_list(SaleContainer
 * scontainer, string name)
 * -------------------------------------------------------
 * Postcondition: A report that include a list of sales
 * based on the given item name.
 *********************************************************/

/*********************************************************
 * double item_name_total_price(ItemContainer tcontainer,
 * string name)
 * -------------------------------------------------------
 * Postcondition: A report that include the total sales
 * based on the given item name.
 *********************************************************/

/****************
* SORT FUNCTIONS
*****************/

/*********************************************************
 * MemberContainer sort_by_ID(MemberContainer mcontainer)
 * -------------------------------------------------------
 * Postcondition: Sorts a list of members by their ID
 * (based on the given member container).
 *********************************************************/

/*********************************************************
 * MemberContainer sort_by_member_name(MemberContainer
 * mcontainer)
 * -------------------------------------------------------
 * Postcondition: Sorts a list of members by their names
 * (based on the given member container).
 *********************************************************/

/*********************************************************
 * ItemContainer sort_by_item_name(ItemContainer tcontainer)
 * -------------------------------------------------------
 * Postcondition: Sorts a list of items by their names
 * (based on the given items container).
 *********************************************************/

/*********************************************************
 * void swap(Member& m1, Member& m2)
 * -------------------------------------------------------
 * Postcondition: Swaps two members based on the given
 * member #1 and member #2.
 *********************************************************/

/*********************************************************
 * void swap(Item& t1, Item& t2)
 * -------------------------------------------------------
 * Postcondition: Swaps two items based on the given
 * item #1 and item #2.
 *********************************************************/

/*****************
* PRINT FUNCTIONS
******************/

/*********************************************************
 * void print(vector<string> in)
 * -------------------------------------------------------
 * Postcondition: Prints a list of string vector.
 *********************************************************/

/*********************************************************
 * void print(vector<double> in)
 * -------------------------------------------------------
 * Postcondition: Prints a list of double vector.
 *********************************************************/

/*********************************************************
 * void print(vector<int> in)
 * -------------------------------------------------------
 * Postcondition: Prints a list of int vector.
 *********************************************************/

/*********************************************************
 * void print(vector<vector<double>> in)
 * -------------------------------------------------------
 * Postcondition: Prints a list of vector which has
 * a vector double
 *********************************************************/

