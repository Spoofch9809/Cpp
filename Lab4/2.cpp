#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Book_info {
private:
    string title;
    string author;
    int quantity;
public:
    Book_info() : quantity(0) {}
    Book_info(string& t, string& a, int q) : title(t), author(a), quantity(q) {}
    string& getTitle(){
        return title;
    }
    string& getAuthor(){
        return author;
    }
    int getQuantity() {
        return quantity;
    }
    void setTitle(string t) {
        title = t;
    }
    void setAuthor(string a) {
        author = a;
    }
    void setQuatity(int q) {
        quantity = q;
    }
};

class Inventory {
private:
    vector<Book_info> books;
public:
    void addBook(Book_info& book) {
        books.push_back(book);
    }
    void removeBook(string title) {
        books.erase(remove_if(books.begin(), books.end(),
                            [&title]( Book_info& book) { return book.getTitle() == title; }),
                    books.end());
    }

    // Find book by title
    Book_info* findBook(string title) {
        auto it = find_if(books.begin(), books.end(),
            [&title](Book_info& book) { return book.getTitle() == title; });
        if (it != books.end()) {
            return &(*it);
        } else {
            return nullptr;
        }
    }
    void printInventory () {
        if (books.empty()) {
            cout << "Inventory is empty.\n";
        } else {
            for (auto& book : books) {
                cout << "Title: " << book.getTitle() << ", Author: " << book.getAuthor()
                          << ", Quantity: " << book.getQuantity() << "\n";
            }
        }
    }
};

int main() {
    Inventory inventory;

    char choice;
    while (true) {
        cout << "Enter command (a: add, r: remove, s: search, l: list, q: quit):";
        cin >> choice;

        switch (choice) {
            case 'a': {
                string title, author;
                int quantity;

                cout << "Enter title: ";
                cin.ignore(); 
                getline(cin, title);

                cout << "Enter author: ";
                getline(cin, author);

                cout << "Enter quantity: ";
                while (!(cin >> quantity) || quantity < 0) {
                    cout << "Invalid input. Please enter a non-negative integer for quantity: ";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }

                Book_info newBook(title, author, quantity);
                inventory.addBook(newBook);
                break;
            }
            case 'r': {
                string title;
                cout << "Enter book title to remove: ";
                cin.ignore(); 
                getline(cin, title);

                Book_info* foundBook = inventory.findBook(title);
                if (foundBook != nullptr) {
                    cout << "Book removed -> Title: " << foundBook->getTitle() << ", Author: " << foundBook->getAuthor()
                            << ", Quantity: " << foundBook->getQuantity() << "\n";
                    inventory.removeBook(title);
                } else {
                    cout << "Book not found.\n";
                }
                break;
            }

            case 's': {
                string title;
                cout << "Enter book title to search: ";
                cin.ignore(); 
                getline(cin, title);

                Book_info* foundBook = inventory.findBook(title);
                if (foundBook != nullptr) {
                    cout << "Book found:\n";
                    cout << "Title: " << foundBook->getTitle() << ", Author: " << foundBook->getAuthor()
                              << ", Quantity: " << foundBook->getQuantity() << "\n";
                } else {
                    cout << "Book not found.\n";
                }
                break;
            }

            case 'l':
                inventory.printInventory();
                break;

            case 'q':
                cout << "Exiting program.\n";
                break;

            default:
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input. Please enter a whole number for quantity.\n";
        }
    }

    return 0;
}


