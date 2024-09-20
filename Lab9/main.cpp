#include <iostream>
#include <vector>
#include "Album.h"

using namespace std;

void printInventory(const vector<Album>& inventory) {
    cout << "Available Albums:\n";
    for (size_t i = 0; i < inventory.size(); ++i) {
        const Album& album = inventory[i];
        cout << "" << (i + 1) << ". " << album.getTitle() << " by " << album.getArtist()
                  << " - Price: $" << album.getPrice() << " (" << album.getCopiesAvailable() << " copies available)" << endl;
    }
}

int main() {
    vector<Album> albums;
    albums.emplace_back("Abbey Road", "The Beatles", 19.99, 5);
    albums.emplace_back("The Dark Side of the Moon", "Pink Floyd", 21.99, 3);
    albums.emplace_back("Hotel California", "Eagles", 15.99, 4);
    albums.emplace_back("Back in Black", "AC/DC", 20.99, 2);
    albums.emplace_back("Rumours", "Fleetwood Mac", 16.99, 3);
    albums.emplace_back("Thriller", "Michael Jackson", 18.99, 5);
    albums.emplace_back("The Wall", "Pink Floyd", 22.99, 2);
    albums.emplace_back("Led Zeppelin IV", "Led Zeppelin", 17.99, 3);
    
    char choice;
    while(choice != '4') {
        cout << "\n1. List all available albums\n2. Purchase an album\n3. View sales statistics\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case '1':
                printInventory(albums);
                break;
            case '2': {
                int albumNumber;
                cout << "Enter the number of the album you want to purchase: ";
                cin >> albumNumber;

                if (albumNumber >= 1 && albumNumber - 1 < albums.size()) {
                    int albumIndex = albumNumber - 1;
                    if (albums[albumIndex].purchase()) {
                        cout << "Purchase successful! Enjoy your music.\n";
                    } else {
                        cout << "Purchase failed. This album is out of stock.\n";
                    }
                } else {
                    cout << "Invalid album index.\n";
                }
                if (albumNumber < 1) {
                    cout << "Album ran out of stock!! " << endl;
                }
                break;
            }
            case '3':
                cout << "Total Albums in inventory: " << Album::getTotalAlbums() << endl;
                cout << "Total Sales: $" << Album::totalSales << endl;
                break;
            case '4':
                cout << "Exiting the music store. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }

    };

    return 0;
}