#include <iostream>
#include <string>
using namespace std;

class Produk {
private:
    string id_produk;
    string nama;
    int harga;

public:
    // Setter
    void setIdProduk(const string &id) { id_produk = id; }
    void setNama(const string &nm) { nama = nm; }
    void setHarga(int h) { harga = h; }

    // Getter
    string getIdProduk() const { return id_produk; }
    string getNama() const { return nama; }
    int getHarga() const { return harga; }
};
