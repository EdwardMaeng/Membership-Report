#include "mainwindow.h"
#include "ui_mainwindow.h"

const QString MainWindow::DISPLAY_MEMBERS_OPTION =
        QString("Display Members");
const QString MainWindow::DISPLAY_ITEMS_OPTION =
        QString("Display Items");
const QString MainWindow::DISPLAY_SALES_OPTION =
        QString("Display Sales");

/*****************************************************************
 *
 * CONSTRUCTOR MainWindow::MainWindow(QWidget *parent): Class MainWindow
 *________________________________________________________________
 *  This constructor initializes ranges for prices and stocks,
 *  as well as adds several items to the drop down menu. also sets up ui
 *________________________________________________________________
 *  PRE-CONDITIONS
 *     none
 *
 *  POST-CONDITIONS
 *     various options added to drop down menu, ui setup
 *****************************************************************/
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->item_price_input->setRange(0, DBL_MAX);
    ui->item_stock_input->setRange(0, INT_MAX);

    ui->output_choices->addItem(DISPLAY_MEMBERS_OPTION);
    ui->output_choices->addItem(DISPLAY_ITEMS_OPTION);
    ui->output_choices->addItem(DISPLAY_SALES_OPTION);
}

/*****************************************************************
 *
 * DECONSTRUCTOR MainWindow::~MainWindow(): Class MainWindow
 *________________________________________________________________
 *  This deallocates any dynamically allocated memory
 *________________________________________________________________
 *  PRE-CONDITIONS
 *     none
 *
 *  POST-CONDITIONS
 *     dynamic memory deallocated
 *****************************************************************/
MainWindow::~MainWindow()
{
    delete ui;
}

/*****************************************************************
 *
 *  Method on_add_member_button_clicked(): Class MainWindow
 *________________________________________________________________
 *  This function properly adds a member using input from the GUI
 *  into the list of members (MemberContainer)
 *________________________________________________________________
 *  PRE-CONDITIONS
 *     GUI input filled out
 *
 *  POST-CONDITIONS
 *     member added to list
 *****************************************************************/
void MainWindow::on_add_member_button_clicked()
{
    if(ui->member_name_input->text() != "" &&
       ui->member_id_input->text() != "" &&
       (ui->is_preferred_member_button->isChecked() ||
        ui->is_not_preferred_member_button->isChecked()))
    {
        string name;
        string membership_number;
        double amount_spent_by_member;
        bool is_preferred;
        int day;
        int month;
        int year;

        name = ui->member_name_input->text().toStdString();
        membership_number = ui->member_id_input->text().toStdString();
        amount_spent_by_member = 0;

        if(ui->is_preferred_member_button->isChecked())
            is_preferred = true;
        else
            is_preferred = false;
        day = ui->date_member_was_created_input->date().day();
        month = ui->date_member_was_created_input->date().month();
        year = ui->date_member_was_created_input->date().year();

        Member new_member(name, membership_number, amount_spent_by_member,
                          is_preferred, month, day, year);

        if(list_of_members.search_membership(
                    new_member.get_member_number( )))
        {
            ui->output_display->setText("Member ID already taken.");
        }
        else
        {
            if(list_of_members.size() == 0)
                list_of_members.insert_head(new_member);
            else
                list_of_members.attach(new_member);

            ui->output_display->setText("Member successfully added.");
        }
    }
}

/*****************************************************************
 *
 *  Method on_output_button_clicked(): Class MainWindow
 *________________________________________________________________
 *  This function outputs the list of members, items, or sales
 *  depending on which option is selected from the drop down menu
 *________________________________________________________________
 *  PRE-CONDITIONS
 *     none
 *
 *  POST-CONDITIONS
 *     list of members/items/sales displayed
 *****************************************************************/
void MainWindow::on_output_button_clicked()
{
    int month;
    int day;
    int year;
    ui->output_display->setText("");

    if(ui->output_choices->currentText() == DISPLAY_MEMBERS_OPTION)
    {
        for(size_t i = 0; i < list_of_members.size(); i ++)
        {
            ui->output_display->insertPlainText(
                        QString::fromStdString(
                            list_of_members[i].get_name()) + " ");
            ui->output_display->insertPlainText(
                        QString::fromStdString(
                            list_of_members[i].get_member_number()) + " ");
            ui->output_display->insertPlainText(
                        "$" + QString::number(
                            list_of_members[i].get_amount_spent()) + " ");

            if(list_of_members[i].get_preferred_member())
                ui->output_display->insertPlainText("Preferred Member ");
            else
                ui->output_display->insertPlainText("General Member ");

            list_of_members[i].get_exp_date(month, day, year);
            ui->output_display->insertPlainText(QString::number(month) +
                                                "/" + QString::number(day)
                                                + "/" +
                                                QString::number(year) +
                                                " ");
            ui->output_display->insertPlainText("$" +
                        QString::number(
                            list_of_members[i].get_rebate_amount()));

            if(i != list_of_members.size() - 1)
                ui->output_display->insertPlainText("\n");
        }
    }
    else if(ui->output_choices->currentText() == DISPLAY_ITEMS_OPTION)
    {
        for(size_t i = 0; i < list_of_items.Size(); i ++)
        {
            ui->output_display->insertPlainText(
                        QString::fromStdString(
                            list_of_items[i].getName()) + " ");
            ui->output_display->insertPlainText(
                        "$" + QString::number(
                            list_of_items[i].getPrice()) + " ");
            ui->output_display->insertPlainText(
                        QString::number(
                            list_of_items[i].getStock()));

            if(i != list_of_items.Size() - 1)
                ui->output_display->insertPlainText("\n");
        }
    }
    else if(ui->output_choices->currentText() == DISPLAY_SALES_OPTION)
    {
        Report sort;
        sort.sort_by_memberNum(list_of_members, list_of_sales);
        double total;
        total = 0;
        for(size_t i = 0; i < list_of_sales.size(); i ++)
        {
            int month;
            int day;
            int year;
            string name;

            for(size_t j = 0; j < list_of_members.size(); j ++)
            {
                if(list_of_members[j].get_member_number() ==
                        list_of_sales[i].getMembership())
                    name = list_of_members[j].get_name();
            }

            ui->output_display->insertPlainText(
                        QString::fromStdString(
                            list_of_sales[i].getMembership()) + " - ");
            ui->output_display->insertPlainText(
                        QString::fromStdString(name) + " - ");
            ui->output_display->insertPlainText(
                        QString::fromStdString(
                            list_of_sales[i].getItem()) + " - ");
            ui->output_display->insertPlainText(
                        QString::number(
                            list_of_sales[i].getAmountSold()) + " - ");
            ui->output_display->insertPlainText(
                        "$" + QString::number(
                            list_of_sales[i].getPrice()) + " - ");
            total += list_of_sales[i].getPrice();

            list_of_sales[i].getDate(month, day, year);
            ui->output_display->insertPlainText(
                        QString::number(month) + "/" +
                        QString::number(day) + "/" +
                        QString::number(year));
            ui->output_display->insertPlainText("\n");
        }

        ui->output_display->insertPlainText("\nGrand Total: $" +
                                            QString::number(total));
    }
}

/*****************************************************************
 *
 *  Method on_delete_member_button_clicked(): Class MainWindow
 *________________________________________________________________
 *  This function deletes a specific member from the list of members
 *________________________________________________________________
 *  PRE-CONDITIONS
 *     GUI input filled out
 *
 *  POST-CONDITIONS
 *     member deleted from list
 *****************************************************************/
void MainWindow::on_delete_member_button_clicked()
{
    int index;
    index = -1;

    if(ui->member_name_input->text() != "" &&
       ui->member_id_input->text() != "")
    {
        for(size_t i = 0 ; i < list_of_members.size(); i ++)
        {
            if(ui->member_name_input->text().toStdString() ==
               list_of_members[i].get_name() &&
               ui->member_id_input->text().toStdString() ==
               list_of_members[i].get_member_number())
            {
                index = i;
            }
        }

        if(index != -1)
        {
            list_of_members.start();
            for(size_t i = 0; i < index; i ++)
                list_of_members.advance();
            list_of_members.remove_current();
            ui->output_display->setText("Member successfully deleted");
        }
        else
        {
            ui->output_display->setText("Member does not exist");
        }
    }
}

/*****************************************************************
 *
 *  Method on_add_item_button_clicked(): Class MainWindow
 *________________________________________________________________
 *  This function adds an item to the list of items based on GUI input
 *________________________________________________________________
 *  PRE-CONDITIONS
 *     GUI input filled out
 *
 *  POST-CONDITIONS
 *    item added to list of items
 *****************************************************************/
void MainWindow::on_add_item_button_clicked()
{
    if(ui->item_name_input->text() != "" &&
       ui->item_stock_input->value() > 0)
    {
        string item_name;
        double item_price;
        int item_stock;
        bool item_exists;

        item_name = ui->item_name_input->text().toStdString();
        item_price = ui->item_price_input->value();
        item_stock = ui->item_stock_input->value();
        item_exists = false;

        Item new_item(item_name, item_price, item_stock);

        //NOTE: adding another item of the same name as an existing item
        //      does not update the quantity.
        for(size_t i = 0; i < list_of_items.Size(); i ++)
            if(list_of_items[i].getName() == item_name &&
                    list_of_items[i].getPrice() == item_price)
            {
                item_exists = true;
                list_of_items[i].setStock(
                            list_of_items[i].getStock() + item_stock);
                ui->output_display->setText("Item already exists, "
                                            "increasing quantity.");
            }
        if(!item_exists)
        {
            list_of_items += new_item;
            ui->output_display->setText("New Item Successfully Added.");
        }
    }
}

/*****************************************************************
 *
 *  Method on_delete_item_button_clicked(): Class MainWindow
 *________________________________________________________________
 *  This function deletes an item from the list based on input from GUI
 *________________________________________________________________
 *  PRE-CONDITIONS
 *     GUI input filled out
 *
 *  POST-CONDITIONS
 *    item deleted from list of items
 *****************************************************************/
void MainWindow::on_delete_item_button_clicked()
{
    int index;
    index = -1;

    if(ui->item_name_input->text() != "")
    {
        for(size_t i = 0 ; i < list_of_items.Size(); i ++)
        {
            if(ui->item_name_input->text().toStdString() ==
               list_of_items[i].getName())
            {
                index = i;
            }
        }

        if(index != -1)
        {
            list_of_items.remove(index);
            ui->output_display->setText("Item successfully deleted.");
        }
        else
            ui->output_display->setText("Item does not exist,"
                                        " cannot delete.");
    }
}

/*****************************************************************
 *
 *  Method on_add_sale_button_clicked(): Class MainWindow
 *________________________________________________________________
 *  This function adds a sale to the list of sales based on GUI input
 *________________________________________________________________
 *  PRE-CONDITIONS
 *     GUI input filled out
 *
 *  POST-CONDITIONS
 *    sale added to list of sales
 *****************************************************************/
void MainWindow::on_add_sale_button_clicked()
{
    if(ui->member_id_input->text() != "" &&
       ui->item_name_input->text() != "" &&
       ui->item_stock_input->value() > 0)
    {
        string member_id;
        string item_name;
        double price;
        int quantity;
        int month;
        int day;
        int year;

        member_id = ui->member_id_input->text().toStdString();
        item_name = ui->item_name_input->text().toStdString();
        price = ui->item_price_input->value();
        quantity = ui->item_stock_input->value();
        month = ui->date_sold_input->date().month();
        day = ui->date_sold_input->date().day();
        year = ui->date_sold_input->date().year();

        Sale new_sale(list_of_members, list_of_items, member_id,
                      item_name, price, quantity, month, day, year);

        if(new_sale.getItem() != "")
        {
            list_of_sales.attach(new_sale);
            ui->output_display->setText("Sale successfully added.");
        }
    }
}

/*****************************************************************
 *
 *  Method on_delete_sale_button_clicked(): Class MainWindow
 *________________________________________________________________
 *  This function deletes a sale from the list of sales based on GUI input
 *________________________________________________________________
 *  PRE-CONDITIONS
 *     GUI input filled out
 *
 *  POST-CONDITIONS
 *    sale deleted from list of sales
 *****************************************************************/
void MainWindow::on_delete_sale_button_clicked()
{
    if(ui->member_id_input->text() != "" &&
       ui->item_name_input->text() != "" &&
       ui->item_stock_input->value() > 0)
    {
        string member_id;
        string item_name;
        double price;
        int quantity;
        int month;
        int day;
        int year;
        int index;
        index = -1;

        member_id = ui->member_id_input->text().toStdString();
        item_name = ui->item_name_input->text().toStdString();
        price = ui->item_price_input->value();
        quantity = ui->item_stock_input->value();
        month = ui->date_sold_input->date().month();
        day = ui->date_sold_input->date().day();
        year = ui->date_sold_input->date().year();

        Sale target(list_of_members, list_of_items, member_id,
                      item_name, price, quantity, month, day, year);

        for(size_t i = 0; i < list_of_sales.size(); i ++)
            if(list_of_sales[i] == target)
                index = i;

        if(index > -1)
        {
            list_of_sales.start();
            for(size_t i = 0; i < index; i ++)
                list_of_sales.advance();

            if(list_of_sales.current() == target)
            {
                list_of_sales.remove_current();
                ui->output_display->setText("Sale successfuly deleted.");
            }
        }
        else
        {
            ui->output_display->setText("Sale not found.");
        }
    }
}

/*****************************************************************
 *
 *  Method on_daily_sales_report_button_clicked(): Class MainWindow
 *________________________________________________________________
 *  This function displays a report of sales from a selected day
 *________________________________________________________________
 *  PRE-CONDITIONS
 *     GUI input filled out
 *
 *  POST-CONDITIONS
 *    displays a report of sales from a selected day
 *****************************************************************/
void MainWindow::on_daily_sales_report_button_clicked()
{
    Report daily;
    int day;
    int month;
    int year;
    vector<string> items;
    vector<int> quantities;
    vector<string> members;
    vector<double> prices;
    double total_revenue;
    vector<int> num_members;

    day = ui->daily_sales_report_date_input->date().day();
    month = ui->daily_sales_report_date_input->date().month();
    year = ui->daily_sales_report_date_input->date().year();

    items = daily.daily_items_list(list_of_sales, month, day, year);
    quantities = daily.daily_quantities_list(list_of_sales, month, day,
                                             year);
    members = daily.daily_member_list(list_of_sales, list_of_members,
                                      month, day, year);
    prices = daily.daily_price_list(list_of_sales, list_of_members, month,
                                    day, year);
    total_revenue = daily.daily_total_revenue(list_of_sales, month, day,
                                              year);
    num_members = daily.daily_number_of_members(list_of_sales,
                                                list_of_members, month,
                                                day, year);

    ui->output_display->setText("");
    if(items.size() > 0)
    {
        for(size_t i = 0; i < items.size(); i ++)
        {
            ui->output_display->insertPlainText(
                        QString::fromStdString(items[i]) + " - ");
            ui->output_display->insertPlainText("$" +
                        QString::number(prices[i]) + " - ");
            ui->output_display->insertPlainText(
                        QString::number(quantities[i]) + " - ");
            ui->output_display->insertPlainText(
                        QString::fromStdString(members[i]) + "\n");
        }

        ui->output_display->insertPlainText(
                    "\nTotal revenue for the day: $" + QString::number(
                        total_revenue));
        ui->output_display->insertPlainText("\nTotal Preferred Members: "
                                            + QString::number(
                                                num_members[0]));
        ui->output_display->insertPlainText("\nTotal Basic Members: "
                                            + QString::number(
                                                num_members[1]));
    }
    else
    {
        ui->output_display->setText("No sales made on that day.");
    }
}

/*****************************************************************
 *
 *  Method on_yearly_sales_report_button_clicked(): Class MainWindow
 *________________________________________________________________
 *  This function displays a report of sales from a selected year
 *________________________________________________________________
 *  PRE-CONDITIONS
 *     GUI input filled out
 *
 *  POST-CONDITIONS
 *    displays a report of sales from a selected year
 *****************************************************************/
void MainWindow::on_yearly_sales_report_button_clicked()
{
    Report yearly;
    int year;
    vector<string> items;
    vector<int> quantities;
    vector<string> members;
    vector<double> prices;
    double total_revenue;
    string best_item;
    string worst_item;

    year = ui->daily_sales_report_date_input->date().year();
    items = yearly.yearly_items_list(list_of_sales, year);
    quantities = yearly.yearly_quantities_list(list_of_sales, year);
    members = yearly.yearly_member_list(list_of_sales, list_of_members,
                                        year);
    prices = yearly.yearly_price_list(list_of_sales, list_of_members,
                                      year);
    total_revenue = yearly.yearly_total_revenue(list_of_sales,
                                                list_of_members, year);
    best_item = yearly.yearly_best_item(list_of_sales, year);
    worst_item = yearly.yearly_worst_item(list_of_sales, year);

    ui->output_display->setText("");
    for(size_t i = 0; i < items.size(); i ++)
    {
        ui->output_display->insertPlainText(
                    QString::fromStdString(items[i]) + " - ");
        ui->output_display->insertPlainText(
                    "$" + QString::number(prices[i]) + " - ");
        ui->output_display->insertPlainText(
                    QString::number(quantities[i]) + " - ");
        ui->output_display->insertPlainText(
                    QString::fromStdString(members[i]) + "\n");
    }

    ui->output_display->insertPlainText("\nTotal Revenue: $" +
                                        QString::number(total_revenue));
    ui->output_display->insertPlainText("\nBest Item: " +
                                        QString::fromStdString(best_item));
    ui->output_display->insertPlainText("\nWorst Item: " +
                                      QString::fromStdString(worst_item));
}

/*****************************************************************
 *
 *  Method on_annual_fees_button_clicked(): Class MainWindow
 *________________________________________________________________
 *  This function displays annual fees of each member
 *________________________________________________________________
 *  PRE-CONDITIONS
 *     none
 *
 *  POST-CONDITIONS
 *     displays annual fees of each member
 *****************************************************************/
void MainWindow::on_annual_fees_button_clicked()
{
    Report annual_fees;
    vector<string> names;
    vector<string> ids;
    vector<string> type;
    vector<double> dues;

    annual_fees.membership_dues_per_year(list_of_members, names, ids,
                                         type, dues);

    ui->output_display->setText("");
    for(size_t i = 0; i < names.size(); i ++)
    {
        ui->output_display->insertPlainText(
                    QString::fromStdString(names[i]) + " - ");
        ui->output_display->insertPlainText(
                    QString::fromStdString(ids[i]) + " - ");
        ui->output_display->insertPlainText(
                    QString::fromStdString(type[i]) + " - ");
        ui->output_display->insertPlainText(
                    "$" + QString::number(dues[i]) + "\n");
    }
}

/*****************************************************************
 *
 *  Method on_switch_membership_report_button_clicked(): Class MainWindow
 *________________________________________________________________
 *  This function displays whether each member should switch membership
 *  type
 *________________________________________________________________
 *  PRE-CONDITIONS
 *     none
 *
 *  POST-CONDITIONS
 *     displays whether each member should switch membership
 *     type
 *****************************************************************/
void MainWindow::on_switch_membership_report_button_clicked()
{
    Report switch_membership;
    ui->output_display->setText("");
    for(size_t i = 0; i < list_of_members.size(); i ++)
    {
        ui->output_display->insertPlainText(
                    QString::fromStdString(
                        list_of_members[i].get_name()) + " ");
        ui->output_display->insertPlainText(
                    QString::fromStdString(
                        list_of_members[i].get_member_number()) + " ");

        if(list_of_members[i].get_preferred_member())
        {
            ui->output_display->insertPlainText("Preffered - ");

            if(switch_membership.switch_basic(
                        list_of_members,
                        list_of_members[i].get_member_number()))
                ui->output_display->insertPlainText(
                            "Should switch to basic membership\n");
            else
                ui->output_display->insertPlainText(
                            "No need to switch membership\n");
        }
        else
        {
            ui->output_display->insertPlainText("Basic - ");

            if(switch_membership.switch_preferred(
                        list_of_members,
                        list_of_members[i].get_member_number()))
                ui->output_display->insertPlainText(
                            "Should switch to preferred membership\n");
            else
                ui->output_display->insertPlainText(
                            "No need to switch membership\n");
        }

    }
}

/*****************************************************************
 *
 *  Method on_display_rebates_button_clicked(): Class MainWindow
 *________________________________________________________________
 *  This function displays each members rebates
 *________________________________________________________________
 *  PRE-CONDITIONS
 *     none
 *
 *  POST-CONDITIONS
 *     displays each members rebates
 *****************************************************************/
void MainWindow::on_display_rebates_button_clicked()
{
    Report sort;
    list_of_members = sort.sort_by_ID(list_of_members);
    ui->output_display->setText("");
    for(size_t i = 0; i < list_of_members.size(); i ++)
    {
        if(list_of_members[i].get_preferred_member())
        {
            ui->output_display->insertPlainText(
                        QString::fromStdString(
                            list_of_members[i].get_name()) + " ");
            ui->output_display->insertPlainText(
                        QString::fromStdString(
                            list_of_members[i].get_member_number()) + " ");
            ui->output_display->insertPlainText(
                        "$" + QString::number(
                            list_of_members[i].get_rebate_amount())
                        + "\n");
        }
    }
}

/*****************************************************************
 *
 *  Method on_save_all_members_into_a_file_button_clicked():
 *  Class MainWindow
 *________________________________________________________________
 *  This function saves all members into a file
 *________________________________________________________________
 *  PRE-CONDITIONS
 *     none
 *
 *  POST-CONDITIONS
 *     saves all members into a file
 *****************************************************************/
void MainWindow::on_save_all_members_into_a_file_button_clicked()
{
    Report save;
    save.save_members(list_of_members);
    ui->output_display->setText("Members successfully saved.");
}

/*****************************************************************
 *
 *  Method on_load_all_members_from_a_file_button_clicked():
 *  Class MainWindow
 *________________________________________________________________
 *  This function loads all members from a file
 *________________________________________________________________
 *  PRE-CONDITIONS
 *     none
 *
 *  POST-CONDITIONS
 *     loads all members from a file
 *****************************************************************/
void MainWindow::on_load_all_members_from_a_file_button_clicked()
{
    Report load;
    list_of_members = load.load_members();
    ui->output_display->setText(
                "Members successfully loaded from a file.");
}

/*****************************************************************
 *
 *  Method
 *  on_display_all_purchases_button_of_single_member_button_clicked():
 *  Class MainWindow
 *________________________________________________________________
 *  This function displays all purchases of a single member
 *________________________________________________________________
 *  PRE-CONDITIONS
 *     GUI input filled
 *
 *  POST-CONDITIONS
 *     displays all purchases of a single member
 *****************************************************************/
void
MainWindow::
on_display_all_purchases_button_of_single_member_button_clicked()
{
    ui->output_display->setText("");
    for(size_t i = 0; i < list_of_sales.size(); i ++)
    {
        int month;
        int day;
        int year;
        string name;

        for(size_t j = 0; j < list_of_members.size(); j ++)
        {
            if(list_of_members[j].get_member_number() ==
                    list_of_sales[i].getMembership())
                name = list_of_members[j].get_name();
        }

        if((ui->by_name_radio_button->isChecked() &&
            ui->member_name_input->text().toStdString() == name) ||
           (ui->by_id_radio_button->isChecked() &&
            ui->member_id_input->text().toStdString() ==
            list_of_sales[i].getMembership()))
        {
            ui->output_display->insertPlainText(
                        QString::fromStdString(
                            list_of_sales[i].getMembership()) + " - ");
            ui->output_display->insertPlainText(
                        QString::fromStdString(name) + " - ");
            ui->output_display->insertPlainText(
                        QString::fromStdString(
                            list_of_sales[i].getItem()) + " - ");
            ui->output_display->insertPlainText(
                        "$" + QString::number(
                            list_of_sales[i].getPrice()) + " - ");

            list_of_sales[i].getDate(month, day, year);
            ui->output_display->insertPlainText(
                        QString::number(month) + "/" +
                        QString::number(day) + "/" +
                        QString::number(year));
            ui->output_display->insertPlainText("\n");
        }
    }
}

/*****************************************************************
 *
 *  Method
 *  on_save_sales_and_items_button_clicked():
 *  Class MainWindow
 *________________________________________________________________
 *  This function saves all sales and items to a specific file
 *________________________________________________________________
 *  PRE-CONDITIONS
 *     GUI input filled
 *
 *  POST-CONDITIONS
 *     saves all sales and items to a specific file
 *****************************************************************/
void MainWindow::on_save_sales_and_items_button_clicked()
{
    Report save;
    string filename;
    filename = ui->save_sales_filename_input->text().toStdString();
    if(filename != "")
    {
        save.save_sales(filename, list_of_members, list_of_sales);
        ui->output_display->setText("Sales and Items saved.");
    }
}

/*****************************************************************
 *
 *  Method
 *  on_load_sales_and_items_button_clicked():
 *  Class MainWindow
 *________________________________________________________________
 *  This function load all sales and items from a specific file
 *________________________________________________________________
 *  PRE-CONDITIONS
 *     GUI input filled
 *
 *  POST-CONDITIONS
 *     load all sales and items from a specific file
 *****************************************************************/
void MainWindow::on_load_sales_and_items_button_clicked()
{
    Report load;
    string filename;
    filename = ui->load_sales_filename_input->text().toStdString();
    if(filename != "")
    {
        load.load_sales(filename, list_of_members, list_of_items,
                        list_of_sales);
        ui->output_display->setText("Sales and Items loaded.");
    }
}

/*****************************************************************
 *
 *  Method
 *  on_display_all_items_sold_button_clicked():
 *  Class MainWindow
 *________________________________________________________________
 *  This function displays all items sold, their quantities, and their
 *  total prices
 *________________________________________________________________
 *  PRE-CONDITIONS
 *     none
 *
 *  POST-CONDITIONS
 *     displays all items sold, their quantities, and their
 *     total prices
 *****************************************************************/
void MainWindow::on_display_all_items_sold_button_clicked()
{
    Report all_items;
    vector<string> item_names;
    vector<int> item_quantities;
    vector<double> item_total_price;

    list_of_items = all_items.sort_by_item_name(list_of_items);
    item_names = all_items.item_names(list_of_items);
    item_quantities = all_items.item_quantity(list_of_items,
                                              list_of_sales);
    item_total_price = all_items.item_total_price(list_of_items,
                                                  list_of_sales);

    if(item_names.size() == 0)
        ui->output_display->setText("No items sold");
    else
    {
        ui->output_display->setText("");
        ui->output_display->insertPlainText(
                    "All items sold and their quantities:\n\n");
        for(size_t i = 0; i < item_names.size(); i ++)
        {
            ui->output_display->insertPlainText(
                        QString::fromStdString(item_names[i]) + " - ");
            ui->output_display->insertPlainText(
                        QString::number(item_quantities[i]) + " - $");
            ui->output_display->insertPlainText(
                        QString::number(item_total_price[i]) + "\n");
        }
    }
}

/*****************************************************************
 *
 *  Method
 *  on_display_all_memberships_expiring_button_clicked():
 *  Class MainWindow
 *________________________________________________________________
 *  This function displays all memberships expiring in the input
 *  month and year
 *________________________________________________________________
 *  PRE-CONDITIONS
 *     GUI input filled
 *
 *  POST-CONDITIONS
 *     displays all memberships expiring in the input
 *  month and year
 *****************************************************************/
void MainWindow::on_display_all_memberships_expiring_button_clicked()
{
    Report expire;
    int month;
    int year;
    vector<string> ids;
    vector<string> names;
    vector<string> memberships;
    vector<double> dues;

    month = ui->expiration_date_input->date().month();
    year = ui->expiration_date_input->date().year();
    expire.memberships_expiring(list_of_members, ids, names, memberships,
                                dues, month, year);

    ui->output_display->setText("");
    ui->output_display->insertPlainText("Membersips expiring on " +
                                        QString::number(month) + "/" +
                                        QString::number(year) + ":\n\n");
    for(size_t i = 0; i < ids.size(); i ++)
    {
        ui->output_display->insertPlainText(
                    QString::fromStdString(ids[i]) + " - ");
        ui->output_display->insertPlainText(
                    QString::fromStdString(names[i]) + " - ");
        ui->output_display->insertPlainText(
                    QString::fromStdString(memberships[i]) + " - $");
        ui->output_display->insertPlainText(
                    QString::number(dues[i]) + "\n");
    }
}

/*****************************************************************
 *
 *  Method
 *  on_display_specific_item_sold_button_clicked():
 *  Class MainWindow
 *________________________________________________________________
 *  This function displays how much a specific item was sold and
 *  total price
 *________________________________________________________________
 *  PRE-CONDITIONS
 *     GUI input filled
 *
 *  POST-CONDITIONS
 *     displays how much a specific item was sold and
 *  total price
 *****************************************************************/
void MainWindow::on_display_specific_item_sold_button_clicked()
{
    string item_name;
    Report all_items;
    vector<string> item_names;
    vector<int> item_quantities;
    vector<double> item_total_price;

    item_name = ui->specific_item_input->text().toStdString();

    if(item_name != "")
    {
        list_of_items = all_items.sort_by_item_name(list_of_items);
        item_names = all_items.item_names(list_of_items);
        item_quantities = all_items.item_quantity(list_of_items,
                                                  list_of_sales);
        item_total_price = all_items.item_total_price(list_of_items,
                                                      list_of_sales);

        if(item_names.size() == 0)
            ui->output_display->setText("No items sold");
        else
        {
            ui->output_display->setText("");
            ui->output_display->insertPlainText(
                        "Specific item sold and it's quantity:\n\n");


            for(size_t i = 0; i < item_names.size(); i ++)
            {
//                if(item_names[i][(item_names[i].size() - 1)] == '\n')
                    item_names[i].pop_back();
                if(item_names[i] == item_name)
                {
                    ui->output_display->insertPlainText(
                                QString::fromStdString(item_names[i])
                                + " - ");
                    ui->output_display->insertPlainText(
                                QString::number(item_quantities[i])
                                + " - $");
                    ui->output_display->insertPlainText(
                                QString::number(item_total_price[i])
                                + "\n");
                }
            }
        }
    }
    else
        ui->output_display->setText("Item name empty.");
}
