/*37. Write a program to design a class representing the information regarding digital library
(books, tape: book & tape should be separate classes having the base class as media ). The
class should have the functionality for adding new item, issuing, deposit etc. the program
should use the runtime polymorphism.*/

#include <iostream>
#include <string>

using namespace std;

 int SIZE = 100;

class Media {
protected:
    string title;
    string author;
    bool available;

public:
    Media( string& title,  string& author) : title(title), author(author), available(true) {}

    virtual void displayInfo() = 0;

    string getTitle()  {
        return title;
    }

    void issue() {
        if (available) {
            available = false;
            cout << "Item \"" << title << "\" has been issued." << endl;
        } else {
            cout << "Item \"" << title << "\" is already issued." << endl;
        }
    }

    void deposit() {
        if (!available) {
            available = true;
            cout << "Item \"" << title << "\" has been deposited." << endl;
        } else {
            cout << "Item \"" << title << "\" is already available." << endl;
        }
    }
};

class Book : public Media {
    int pages;

public:
    Book( string& title,  string& author, int pages) : Media(title, author), pages(pages) {}

    void displayInfo() override {
        cout << "Book: " << title << " by " << author << " (" << pages << " pages)" << endl;
    }
};

class Tape : public Media {
    int duration;

public:
    Tape( string& title,  string& author, int duration) : Media(title, author), duration(duration) {}

    void displayInfo() override {
        cout << "Tape: " << title << " by " << author << " (" << duration << " minutes)" << endl;
    }
};

class DigitalLibrary {
    Media* collection[SIZE];
    int count;

public:
    DigitalLibrary() : count(0) {}

    void addItem(Media* item) {
        if (count < SIZE) {
            collection[count++] = item;
            cout << "Item \"" << item->getTitle() << "\" has been added to the library." << endl;
        } else {
            cout << "Library collection is full. Unable to add item." << endl;
        }
    }

    void displayCollection() {
        cout << "Digital Library Collection:" << endl;
        for (int i = 0; i < count; ++i) {
            collection[i]->displayInfo();
        }
    }

    Media* searchItem( string& title) {
        for (int i = 0; i < count; ++i) {
            if (collection[i]->getTitle() == title) {
                return collection[i];
            }
        }
        return nullptr;
    }

    void issueItem( string& title) {
        Media* item = searchItem(title);
        if (item != nullptr) {
            item->issue();
        } else {
            cout << "Item \"" << title << "\" not found." << endl;
        }
    }

    void depositItem( string& title) {
        Media* item = searchItem(title);
        if (item != nullptr) {
            item->deposit();
        } else {
            cout << "Item \"" << title << "\" not found." << endl;
        }
    }
};

int main() {
    DigitalLibrary library;
    int choice;
    string title, author;
    int pages, duration;


    while (true) {

        cout << "\n\nDigital Library Menu:" << endl;
        cout << "1. Add an item" << endl;
        cout << "2. Display library collection" << endl;
        cout << "3. Issue an item" << endl;
        cout << "4. Deposit an item" << endl;
        cout << "0. Exit" << endl;
    
        cout << "\nEnter your choice: ";
        cin >> choice;
        cin.ignore();  // Ignore the newline character

        switch (choice) {
            case 1: {
                cout << "\nAdding an item to the library:" << endl;

                cout << "1. Add a book" << endl;
                cout << "2. Add a tape" << endl;
                cout << "Enter your choice: ";
                cin >> choice;
                cin.ignore();  // Ignore the newline character

                switch (choice) {
                    case 1: {
                        cout << "\nEnter the title: ";
                        getline(cin, title);
                        cout << "Enter the author: ";
                        getline(cin, author);
                        cout << "Enter the number of pages: ";
                        cin >> pages;
                        cin.ignore();  // Ignore the newline character

                        library.addItem(new Book(title, author, pages));
                        break;
                    }
                    case 2: {
                        cout << "\nEnter the title: ";
                        getline(cin, title);
                        cout << "Enter the author: ";
                        getline(cin, author);
                        cout << "Enter the duration (in minutes): ";
                        cin >> duration;
                        cin.ignore();  // Ignore the newline character

                        library.addItem(new Tape(title, author, duration));
                        break;
                    }
                    default:
                        cout << "\nInvalid choice. Please try again." << endl;
                }

                break;
            }
            case 2:
                library.displayCollection();
                break;
            case 3: {
                cout << "\n\nIssuing an item:" << endl;
                cout << "Enter the title of the item to issue: ";
                getline(cin, title);
                library.issueItem(title);
                break;
            }
            case 4: {
                cout << "\n\nDepositing an item:" << endl;
                cout << "Enter the title of the item to deposit: ";
                getline(cin, title);
                library.depositItem(title);
                break;
            }
            case 0:
                cout << "\n\nExiting the program. Goodbye!" << endl;
                return 0;
            default:
                cout << "\n\nInvalid choice. Please try again." << endl;
        }
    }
    return 0;
}

