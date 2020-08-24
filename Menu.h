#include <string.h>
using namespace std;
class Menu {
private:

  class Pair {
public:

    string item;
    double price;
  };
  Pair *items;
  int size;
  int capacity;

public:

  Menu();
  Menu(int cap);
  void printMenu();
  void addItem(string item,
               double price);
  void updatePrice(string item,
                   double price);
  void addMenu(string menu);
  double getPrice(string item);
  double calcTotal();
};
