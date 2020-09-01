/**********************************************************
 *  AUTHORS      : Jose Miguel Tamayo, Yi Zhuo, Edward Maeng, Crystal Tong
 *  PROJECT 1    : Super Warehouse
 *  CLASS        : CS 08
 *  SECTION      : M-TR: 9:45 - 11:05
 *  DUE DATE     : 4/8/20
 **********************************************************/
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <float.h>
#include "report.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    /********************************
     ** CONSTRUCTOR and DESTRUCTOR **
     ********************************/
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    /**************
     ** MUTATORS **
     **************/
    void on_add_member_button_clicked();
    void on_output_button_clicked();
    void on_delete_member_button_clicked();
    void on_add_item_button_clicked();
    void on_delete_item_button_clicked();
    void on_add_sale_button_clicked();
    void on_delete_sale_button_clicked();
    void on_daily_sales_report_button_clicked();
    void on_yearly_sales_report_button_clicked();
    void on_annual_fees_button_clicked();
    void on_switch_membership_report_button_clicked();
    void on_display_rebates_button_clicked();
    void on_save_all_members_into_a_file_button_clicked();
    void on_load_all_members_from_a_file_button_clicked();
    void on_display_all_purchases_button_of_single_member_button_clicked();
    void on_save_sales_and_items_button_clicked();
    void on_load_sales_and_items_button_clicked();
    void on_display_all_items_sold_button_clicked();
    void on_display_all_memberships_expiring_button_clicked();
    void on_display_specific_item_sold_button_clicked();

private:
    Ui::MainWindow *ui;              // PROC - Main Window object for GUI
    MemberContainer list_of_members; // PROC - list of members
    ItemContainer list_of_items;     // PROC - list of items
    SaleContainer list_of_sales;     // PROC - list of sales

    static const QString DISPLAY_MEMBERS_OPTION; // PROC - const string
                                                 //        to display
                                                 //        members
    static const QString DISPLAY_ITEMS_OPTION;   // PROC - const string
                                                 //        to display
                                                 //        members
    static const QString DISPLAY_SALES_OPTION;   // PROC - const string
                                                 //        to display
                                                 //        members
};
#endif // MAINWINDOW_H

/*****************************************************************
 * MainWindow Class
 * ______________________________________________________________
 *  The class 'MainWindow' is used for processing input from the GUI
 *  and outputting desired reports for a super warehouse containing
 *  members, items, and sales.
 ****************************************************************/


/********************************
 ** CONSTRUCTOR and DESTRUCTOR **
 ********************************/

/****************************************************************
* MainWindow(QWidget *parent = nullptr);
*   Constructor; default constructor for a mainwindow object for qtwidgets,
*
*   Parameters: parent (QWidget) // IN - parent of the mainwindow,
*                                //      unneccessary for this project
*   Return: none
***************************************************************/

/****************************************************************
* ~MainWindow();
*   Deonstructor; default Deconstructor for a mainwindow object for
*                 qtwidgets, deallocates dynamically allocated memory for
*                 the mainwindow.
*
*   Parameters: none
*   Return: none
***************************************************************/


/***********
 * MUTATORS
 ***********/

/*******************************************************************
*  void on_add_member_button_clicked();
*
*   Mutator; inserts str into current string at position pos
------------------------------------------------------------------
*   Parameter: pos (size_t)   // IN - starting index of current string into
*                             //      which str will be inserted
*              str (MyString) // IN - MyString object to be inserted into
*                             //      current string
------------------------------------------------------------------
*   Return: returns *this
*******************************************************************/
