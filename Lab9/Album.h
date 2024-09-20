#ifndef ALBUM_H
#define ALBUM_H
#include <string>

using namespace std;

class Album {
public:
    Album(const string& title, const string& artist, double price, int copiesAvailable);

    // Getters
    string getTitle() const;
    string getArtist() const;
    double getPrice() const;
    int getCopiesAvailable() const;
    static int getTotalAlbums();
    static double getTotalSales(const vector<Album>& albums);

    // Purchase method
    void purchaseAlbum();
    bool purchase();

    // Static data members
    static int totalAlbums;
    static double totalSales;
private:
    string title;
    string artist;
    double price;
    int copies;
};
#endif