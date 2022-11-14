#include <iostream>
#include <vector>
#include <string>

using namespace std;
class CashRegister {
    public:
        CashRegister();
        void clear(); // Removes everything from the transaction
        void Scan_item(string Add_Item, double Add_Price, int Add_Quantity); // Scan in the item with these parameters
        double Get_total(); // Returns the total
        int Get_count(); // Returns the quantity
        void Void_One_Item(string Item_Name); // Removes the  no longer desired  product with product name as a parameter
        void Display_all(); // Displays the entire transaction
        void Type_item(); //If the gun is broken cashier has to type in the product
    private:
        vector<string> Product_Name; // Product_Names
        vector<double> Product_Price; // Product_Prices
        vector<int> Product_Quantity; // Product_Quantity
        double Total; // holds the total for the entire transaction
};
CashRegister::CashRegister(){// Sets everything to 0 and clears the lists

    clear();

}
void CashRegister::clear(){ // Sets everything to 0 and clears the lists

    Product_Name.clear(); //
    Product_Price.clear();
    Product_Quantity.clear();
    Total = 0;
}
void CashRegister::Type_item(){ // If item is not on file or the gun fails
    string Item_Name; // Will hold the item name
    double Item_Price; // Will hold item price
    int Item_Quantity; // Will Item Quantity

    cout << "Please type in the product name." << endl;

    getline(cin, Item_Name); // Asking user to enter in product name

    cout << "Please type in the product price." << endl;

    cin >> Item_Price; // Asking user to enter in product price

    cout << "Please type in the product quantity." << endl;

    cin >>  Item_Quantity; // // Asking user to enter in product quantity


    Product_Name.push_back(Item_Name); // Adds it Product_Name List
    Product_Price.push_back(Item_Price);  // Adds it Product_Price List
    Product_Quantity.push_back(Item_Quantity);  // Adds it Product_Quantity List

    cout << "Product added successfully.\n";
}
void CashRegister::Scan_item(string Add_Item, double Add_Price, int Add_Quantity){

    Product_Name.push_back(Add_Item);  // Add_Item is put in the Product_Name List
    Product_Price.push_back(Add_Price); // Add_Price is put in the Product_Price
    Product_Quantity.push_back(Add_Quantity); // Add_Quantity is put in the Product_Quantity

}

double CashRegister::Get_total(){ // Returns the total transaction

    for(int i = 0; i < Product_Price.size(); ++i){ // Going through the product price list
        Total = Total + (Product_Price[i] * Product_Quantity[i]); // Total = total plus Product_Price * Product_Quantity
    }

    return Total;
}

int CashRegister::Get_count(){
    int Total_Quantity = 0; // Total_Quantity = 0

    for(int i = 0; i < Product_Quantity.size(); ++i){ // going through Product_Quantity list
        Total_Quantity = Total_Quantity + Product_Quantity[i]; // Adding Total_Quantity with all of Product_Quantity lists
    }

    return Total_Quantity; // Returns Total amount of items

}

void CashRegister::Void_One_Item(string Item_Name){  // Removes the  no longer desired  product with product name as a parameter

   for(size_t i = 0; i < Product_Name.size(); ++i){
      if(Product_Name[i] == Item_Name){ // Looking for the Item name in product name vector

        Product_Name.erase(Product_Name.begin() + i); //   Removes the Name
        Product_Price.erase(Product_Price.begin() + i); // Removes the Price
        Product_Quantity.erase(Product_Quantity.begin() + i); // Removes the Quantity
        cout << "Item found and is know removed.\n";
        return; // leaves the loop
      }
      }
       cout << "Item isn't found and noting is removed.\n";

}

void CashRegister::Display_all(){ // Displays the entire transaction
    int Styel = 1; // So the list can start off at one
    double individual_totals = 0; // individual_totals in the list

    cout << "Receipt for the following:\n";

        for(int i = 0; i < Product_Name.size(); ++ i){ // Going through all the products
            individual_totals = Product_Price[i] * Product_Quantity[i]; //  individual_totals = Price[i] * Quantity[i]
            cout << Styel << ": " << Product_Name[i] << " at " << Product_Price[i] << " for " << Product_Quantity[i] << " is: $" << individual_totals << endl; // Out putting Product names, prices, quantities
            Styel++;
}
    cout << "Your total for today is: $" << Get_total() << endl; // Calling Get Total to get the total
}

int main(){
    CashRegister One;

    One.Scan_item("Dell Computer", 199.99, 2); // Adding Dell Computer which cost 199.99 and wanted 2 of them
    One.Scan_item("Red Carpet", 50.99, 3); // Adding which cost 50.99 and wanted 3 of them
    One.Scan_item("Car Charger", 10.59, 2); // Adding which cost 10.59 and wanted 2 of them

    cout << "Here is your total amount of items so far:: " << One.Get_count() << endl; // returning total amount of item they trying to by

    One.Scan_item("Fan", 17.99 , 1); // // Adding Phone Fan which coat 17.99 and wanted 1

    One.Void_One_Item("Red Carpet"); // Removes Red Carpet form the transaction

    One.Scan_item("Phone Charger 4ft", 6.17, 2); // Adding Phone Charger 4ft which cost $6.17 and wanted 2 of them
    One.Scan_item("TJ Coding Classes", 1.99, 4); // Adding TJ Coding Classes which cost $1.99 and wanted 4 of them

    cout << "ERROR PLEASE ENTER IN MANUALLY. ITEM NOT ON FILE.\n" << endl;

    One.Type_item(); // Typing in manually since the item is not on file

    One.Void_One_Item("Slow Timer"); // Tries to remove Slow Time

    One.Display_all(); // Displays the entire transaction

    return 0;
}
