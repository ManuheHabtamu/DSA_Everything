#include <iostream>
#include <string>
#define tax_rate_p 0.15
const double tax_rate=0.15;
using namespace std;
//Name Manuhe Habtamu Mekonnen  ugr/2808/16
int main()
{
    cout<<"Greetings, This is a c++ program functioning to analyze product sales and inventory for a store.";
    cout<<"C++ is one of the high language that uses compiler so that its converted to machine language before being executed."<<endl;

    //Declare product details and initialization
    string product_name("");        //Direct initialization
    int init_inventory;
    float product_price;
    int items_sold;
    int product_category {0};       //Direct initialization
    init_inventory, product_price, items_sold = 0;

    // declare variables for computed values(implicit initialization)
    int new_inventory;
    float total_sales;
    string inventory_status;

    //input from the user
    cout<<"Enter the product name: "<<endl;
    cin>>product_name;
    cout<<"Enter the product Category (the product category must be within the valid range from 1 to 5): "<<endl;
    cin>>product_category;
    cout<<"Enter the initial inventory quantity: "<<endl;
    cin>>init_inventory;
    cout<<"Enter the product price($): "<<endl;
    cin>>product_price;
    cout<<"Enter the number of items sold: "<<endl;
    cin>>items_sold;

    //performing calculations::
    new_inventory = init_inventory - items_sold;
    total_sales = items_sold*product_price;
    inventory_status= ( new_inventory > 10) ? "Sufficient Inventory" : "Low Inventory";

    // declatype and auto part(The Helper variables)
    decltype(init_inventory) helper_init_inventory=init_inventory;
    auto copy_total_sales= total_sales;
//starts here
    //Implement Flow Control
    if (product_category<=5 & product_category>=1){
        cout<<"\nSuitable category and "<<endl;
    }
    else{
        cout<<"It is not a suitable category. PICK A VALID RANGE FROM 1 T0 5.\n\n"<<endl;
        return 0;
    }
    switch (product_category){
        case 1:
            cout<<"ITS CATEGORY 1: ELECTRONICS\n"<<endl;
            break;
        case 2:
            cout<<"ITS CATEGORY 2: GROCERIES\n"<<endl;
            break;
        case 3:
            cout<<"ITS CATEGORY 3: CLOTHING\n"<<endl;
            break;
        case 4:
            cout<<"ITS CATEGORY 4: STATIONERY\n"<<endl;
            break;
        case 5:
            cout<<"ITS CATEGORY 5: MISCELLANEOUS\n"<<endl;
            break;
        }

    // the for loop part
    for (int i=1;i<items_sold+1;i++){
        cout<<"Item no: "<<i<<"\t\t\t\t\t"<<" product price: "<<product_price<<"$"<<endl;
    }
    cout<<"------------------------------------------------------------------------------------------"<<endl;
    cout<<"Total items: "<<items_sold<<"\t\t\t\t\t"<<" Total sales amount: "<<total_sales<<"$\n"<<endl;
    //Summary Outputs part
    cout<<"Tax rate from the preprocessor define is "<< tax_rate_p<< " and tax rate from the constant is: "<<tax_rate<<"\n"<<endl;
    cout<< "Product name: "<<product_name<<"\n"<<endl;
    cout<< "Product category: "<<product_category<<"\n"<<endl;
    cout<< "initial inventory: "<<init_inventory<<"\n"<<endl;
    cout<< "Product price: "<<product_price<<"$\n"<<endl;
    cout<< "Items sold: "<<items_sold<<"\n"<<endl;

    cout<<"The computed new inventory is: "<<new_inventory<< " and the total sales amount is: "<<total_sales<<"$\n"<<endl;

    cout<<"The inventory status is "<<inventory_status<<"\n"<<endl;

    cout<<"The helper values are respectively: "<< copy_total_sales<<"$ and "<< helper_init_inventory<<endl;
    }








