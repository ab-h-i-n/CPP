#include <iostream>
#include <string>
using namespace std;

class Book {
private:
    string author;
    string title;
    double price;
    string publisher;
    int stockPosition;

public:

    Book(){}
    Book(const string& author, const string& title, double price, const string& publisher, int stockPosition)
        : author(author), title(title), price(price), publisher(publisher), stockPosition(stockPosition) {}

    string& getAuthor()  {
        return author;
    }

    string& getTitle()  {
        return title;
    }

    double getPrice()  {
        return price;
    }

    string& getPublisher()  {
        return publisher;
    }

    int getStockPosition()  {
        return stockPosition;
    }
};

class Stock {
private:
    Book* books;
    int size;

public:
    Stock(int size) : size(size) {
        books = new Book[size];
    }

    void addBook(int index, const string& author, const string& title, double price, const string& publisher, int stockPosition) {
        if (index >= 0 && index < size) {
            if (books[index].getTitle().empty()) {
                books[index] = Book(author, title, price, publisher, stockPosition);
                cout << "Book added to the inventory." << endl;
            } else {
                cout << "A book already exists at index " << index << "." << endl;
            }
        } else {
            cout << "Invalid index for adding a book." << endl;
        }
    }

    void searchBook(const string& title, const string& author) {
        bool found = false;
        for (int i = 0; i < size; i++) {
            if (!books[i].getTitle().empty() && books[i].getTitle() == title && books[i].getAuthor() == author) {
                found = true;
                cout << "Book found in the inventory." << endl;
                cout << "Author: " << books[i].getAuthor() << endl;
                cout << "Title: " << books[i].getTitle() << endl;
                cout << "Price: $" << books[i].getPrice() << endl;
                cout << "Publisher: " << books[i].getPublisher() << endl;
                int stockPosition = books[i].getStockPosition();
                if (stockPosition > 0) {
                    int numCopies;
                    cout << "Enter the number of copies required: ";
                    cin >> numCopies;
                    if (numCopies <= stockPosition) {
                        double totalCost = numCopies * books[i].getPrice();
                        cout << "Total cost: $" << totalCost << endl;
                    } else {
                        cout << "Sorry! " << numCopies << " copies are not in stock." << endl;
                    }
                } else {
                    cout << "Sorry! This book is out of stock." << endl;
                }
                break;
            }
        }
        if (!found) {
            cout << "Book not found in the inventory." << endl;
        }
    }

    ~Stock() {
        delete[] books;
    }
};

int main() {
    int size;
    cout << "Enter the size of the inventory: ";
    cin >> size;

    Stock stock(size);

    int choice;
    do {
        cout << "\n-----------------------" << endl;
        cout << "Bookshop Inventory System" << endl;
        cout << "-----------------------" << endl;
        cout << "1. Add a book" << endl;
        cout << "2. Search a book" << endl;
        cout << "0. Exit" << endl;
        cout << "-----------------------" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int index;
                string author, title, publisher;
                double price;
                int stockPosition;
                cout << "\nEnter the index for the book: ";
                cin >> index;
                cout << "Enter the author: ";
                cin >> author;
                cout << "Enter the title: ";
                cin >> title;
                cout << "Enter the price: $";
                cin >> price;
                cout << "Enter the publisher: ";
                cin >> publisher;
                cout << "Enter the stock position: ";
                cin >> stockPosition;
                stock.addBook(index, author, title, price, publisher, stockPosition);
                break;
            }
            case 2: {
                string title, author;
                cout << "\nEnter the title of the book: ";
                cin >> title;
                cout << "Enter the author of the book: ";
                cin >> author;
                stock.searchBook(title, author);
                break;
            }
            case 0:
                cout << "\nExiting the program..." << endl;
                break;
            default:
                cout << "\nInvalid choice. Please try again." << endl;
                break;
        }
    } while (choice != 0);

    return 0;
}
