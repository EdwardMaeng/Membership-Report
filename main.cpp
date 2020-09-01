//#include "report.h"

//int main()
//{
//    Member member1("Edward", "12345", 0, true, 03, 13, 2020);
//    Member member2("Yi", "12346", 0, true, 03, 13, 2020);
//    Member member3("Miguel", "12347", 0, false, 03, 13, 2020);
//    Member member4("Crystal", "12348", 0, false, 03, 13, 2020);

//    MemberContainer m_test;
//    m_test.attach(member1);
//    m_test.attach(member2);
//    m_test.attach(member3);
//    m_test.attach(member4);
//    m_test.print( );

//    Item item1("Milk", 2.49, 100);
//    Item item2("Bread", 1.79, 100);
//    Item item3("Beef", 6.85, 100);
//    Item item4("DVD Player", 59.99, 100);
//    Item item5("Pork", 9.99, 100);
//    Item item6("Plant", 3.99, 100);
//    Item item7("Tape", 1.99, 100);
//    Item item8("Phone", 99.99, 100);
//    Item item9("Phone Case", 5.99, 100);
//    Item item10("Glue", 2.99, 100);
//    Item item11("Bottle", 1.99, 100);


//    ItemContainer t_test;
//    t_test.append(item1);
//    t_test.append(item2);
//    t_test.append(item3);
//    t_test.append(item4);
//    t_test.append(item5);
//    t_test.append(item6);
//    t_test.append(item7);
//    t_test.append(item8);
//    t_test.append(item9);
//    t_test.append(item10);
//    t_test.append(item11);
//    t_test.print( );

//    Sale sale1(m_test, t_test, "12345", "Milk", 2.49, 5, 03, 13, 2020);
//    Sale sale2(m_test, t_test, "12346", "Bread", 1.79, 5, 03, 13, 2020);
//    Sale sale3(m_test, t_test, "12347", "Beef", 6.85, 5, 03, 13, 2020);
//    Sale sale4(m_test, t_test, "12348", "DVD Player", 59.99, 5, 03, 13, 2020);

//    Sale sale5(m_test, t_test, "12345", "Pork", 9.99, 50, 03, 12, 2021); // for yearly sales test
//    Sale sale6(m_test, t_test, "12345", "Plant", 3.99, 5, 03, 13, 2021);
//    Sale sale7(m_test, t_test, "12346", "Tape", 1.99, 1, 03, 14, 2021);
//    Sale sale8(m_test, t_test, "12346", "Phone", 99.99, 5, 03, 15, 2021);
//    Sale sale9(m_test, t_test, "12347", "Phone Case", 5.99, 5, 03, 16, 2021);
//    Sale sale10(m_test, t_test, "12347", "Glue", 2.99, 5, 03, 16, 2021);
//    Sale sale11(m_test, t_test, "12348", "Bottle", 1.99, 5, 03, 17, 2022);


//    SaleContainer s_test;
//    s_test.attach(sale1);
//    s_test.attach(sale2);
//    s_test.attach(sale3);
//    s_test.attach(sale4);
//    s_test.attach(sale5);
//    s_test.attach(sale6);
//    s_test.attach(sale7);
//    s_test.attach(sale8);
//    s_test.attach(sale9);
//    s_test.attach(sale10);
//    s_test.attach(sale11);

//    s_test.print( );

//    Report r_test;
//    cout << "--- TESTING DAILY SALES ---" << endl;
//    cout << "Daily Items List: " << endl;
//    r_test.print(r_test.daily_items_list(s_test, 03, 13, 2020));

//    cout << "Daily Quantities List: " << endl;
//    r_test.print(r_test.daily_quantities_list(s_test, 03, 13, 2020));

//    cout << "Daily Member List: " << endl;
//    r_test.print(r_test.daily_member_list(s_test, m_test, 03, 13, 2020));

//    cout << "Daily Number of Members (1 is Preferred and 2 is Basic): " << endl;
//    r_test.print(r_test.daily_number_of_members(s_test, m_test, 03, 13, 2020));

//    cout << "Total Revenue: $" << r_test.daily_total_revenue(s_test, 03, 13, 2020) << endl;
//    cout << "--- END DAILY SALES ---" << endl << endl;


//    cout << "--- TESTING YEARLY SALES ---" << endl;
//    cout << "Yearly Items List (2021): " << endl;
//    r_test.print(r_test.yearly_items_list(s_test, 2021));

//    cout << "Yearly Quantities List (2021): " << endl;
//    r_test.print(r_test.yearly_quantities_list(s_test, 2021));

//    cout << "Total Revenue: $ " << r_test.yearly_total_revenue(s_test, m_test, 2021) << endl;

//    cout << "Best Item (2021): " << r_test.yearly_best_item(s_test, 2021) << endl;

//    cout << "Worst Item (2021): " << r_test.yearly_worst_item(s_test, 2021) << endl;
//    cout << "--- END YEARLY SALES ---" << endl << endl;

//    cout << "--- TESTING MEMBERSHIP # OR NAME ---" << endl;
//    cout << "Member Total Purchase (for 12345): $" << r_test.member_total_purchase(s_test, "12345") << endl;
//    cout << "Member Total Purchase (for 12346): $" << r_test.member_total_purchase(s_test, "12346") << endl;
//    cout << "Member Total Purchase (for 12347): $" << r_test.member_total_purchase(s_test, "12347") << endl;
//    cout << "Member Total Purchase (for 12348): $" << r_test.member_total_purchase(s_test, "12348") << endl;
//    cout << "--- END MEMBERSHIP # OR NAME ---" << endl << endl;

//    cout << "--- TESTING TOTAL PURCAHSE FOR ALL MEMBERS ---" << endl;
//    cout << "All of Member Numbers: " << endl;
//    r_test.print(r_test.all_member_number(m_test));

//    cout << "All of Total Purchases: " << endl;
//    r_test.print(r_test.all_member_total_purchase(s_test, m_test));

//    cout << "Grand Total Purcahse: " << r_test.grand_total_purcahse(s_test, m_test) << endl;

//    cout << "Best Total Purchase (Member #): " << r_test.member_best_purcahse(s_test, m_test) << endl;

//    cout << "Worst Total Purchase (Member #): " << r_test.member_worst_purchase(s_test, m_test) << endl;

//    cout << "--- END TOTAL PURCAHSE FOR ALL MEMBERS ---" << endl << endl;

//    cout << "--- TESTING SWITCH TO BASIC OR PREFERRED ---" << endl;
//    cout << "Should Edward swtich to basic? (YES = 1 and NO = 0): " << r_test.switch_basic(m_test, "12345") << endl;
//    cout << "Should Yi swtich to basic? (YES = 1 and NO = 0): " << r_test.switch_basic(m_test, "12346") << endl;
//    cout << "Should Miguel swtich to preferred? (YES = 1 and NO = 0): " << r_test.switch_preferred(m_test, "12347") << endl;
//    cout << "Should Crystal swtich to preferred? (YES = 1 and NO = 0): " << r_test.switch_preferred(m_test, "12348") << endl;
//    cout << "--- END SWITCH TO BASIC OR PREFERRED ---" << endl << endl;


//    cout << "------------ END TEST -------------" << endl;

//    return 0;
//}

//QT WIDGETS PART
#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
