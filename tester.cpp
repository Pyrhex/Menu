#include <iostream>
#include "Menu.h"
using namespace std;
int main() {
  string restaurant;

  cout << "Please enter restaurant name: ";
  cin >> restaurant;
  cout << endl;

  Menu menu;

  menu.addMenu(restaurant + ".txt");

  // menu.printMenu();
  Menu order;
  string item;
  int amount;

  cout << "Enter '0 Done' when finished ordering" << endl;

  while (true) {
    cout << "What item would you like to add: ";


    cin >> amount >> item;

    if ((item == "Done") || (amount == 0)) {
      break;
    }

    for (int i = 0; i < amount; i++) {
      order.addItem(item, menu.getPrice(item));
    }
  }
  cout << "What you have ordered: " << endl;
  order.printMenu();

  order.calcTotal();
}
