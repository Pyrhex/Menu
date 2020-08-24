#include <iostream>
#include <fstream>
#include "Menu.h"
using namespace std;

Menu::Menu() {
  size = 0;
  capacity = 10;
  items = new Pair[capacity];
}

Menu::Menu(int cap) {
  size = 0;
  capacity = cap;
  items = new Pair[capacity];
}

void Menu::printMenu() {
  cout << "------ Menu ------" << endl;

  for (int i = 0; i < size; i++) {
    cout << items[i].item << ": " << items[i].price << endl;
  }
}

void Menu::addItem(string item, double price) {
  items[size].item = item;
  items[size].price = price;
  size++;
}

void Menu::updatePrice(string item, double price) {
  for (int i = 0; i < size; i++) {
    if (items[i].item == item) {
      items[i].price = price;
    }
  }
}

double Menu::calcTotal() {
  double total = 0;

  for (int i = 0; i < size; i++) {
    total += items[i].price;
  }
  cout << "Your total is: " << fixed << setprecision(2) << total << endl;
  return total;
}

void Menu::addMenu(string menu) {
  fstream infile;
  string item;
  double price;

  infile.open(menu);

  while (infile >> item >> price) {
    addItem(item, price);
  }
  infile.close();
}

double Menu::getPrice(string item) {
  for (int i = 0; i < size; i++) {
    if (items[i].item == item) {
      return items[i].price;
    }
  }
  cout << "Item not found" << endl;
  return 0;
}
