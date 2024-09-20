#include "Album.h"
#include <iostream>
using namespace std;

int Album::totalAlbums = 0;
double Album::totalSales = 0;

Album::Album(const string& title, const string& artist, double price, int copies) 
    :title(title), artist(artist), price(price), copies(copies) {
        totalAlbums += copies;
}
bool Album::purchase() {
    if (copies > 0) {
        copies--;
        totalSales += price;
        totalAlbums--;
        return true;
    }
    return false;
}
double Album::getTotalSales(const vector<Album>& albums) {
    double totalSales = 0;
    for (const auto& album : albums) {
        totalSales += album.price;
    }
    return totalSales;
}
void Album::purchaseAlbum() {
}
int Album::getTotalAlbums() {
    return totalAlbums;
}
double Album::getPrice() const
{
    return price;
}

string Album::getTitle() const
{
    return title;
}

string Album::getArtist() const
{
    return artist;
}
int Album::getCopiesAvailable() const
{
    return copies;
}

