#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <limits>
#include "Produk.cpp"
#include "SpecHandphone.cpp"
#include "Handphone.cpp"
using namespace std;

// Cetak garis tabel
void printLine(const vector<size_t> &colWidth) {
    cout << "+";
    for (size_t w : colWidth) {
        cout << string(w + 2, '-') << "+";
    }
    cout << "\n";
}

// Fungsi untuk menampilkan tabel
void tampilkanData(const vector<Handphone> &hp) {
    if (hp.empty()) {
        cout << "\n[!] Tidak ada data untuk ditampilkan.\n";
        return;
    }

    vector<vector<string>> table;
    table.push_back({"ID Produk", "Nama", "Series", "Manufaktur", "OS", "Processor", "RAM", "Storage", "Battery", "Harga"});
    for (const auto &h : hp) {
        table.push_back({
            h.getIdProduk(),
            h.getNama(),
            h.getSeries(),
            h.getManufaktur(),
            h.getTipeOS(),
            h.getProcessor(),
            to_string(h.getRAM()) + " GB",
            to_string(h.getStorage()) + " GB",
            to_string(h.getBattery()) + " mAh",
            "Rp." + to_string(h.getHarga())
        });
    }

    // Hitung lebar kolom
    vector<size_t> colWidth(table[0].size(), 0);
    for (size_t col = 0; col < table[0].size(); col++) {
        for (size_t row = 0; row < table.size(); row++) {
            colWidth[col] = max(colWidth[col], table[row][col].size());
        }
    }

    // Cetak tabel
    printLine(colWidth);
    cout << "|";
    for (size_t col = 0; col < table[0].size(); col++) {
        cout << " " << left << setw(colWidth[col]) << table[0][col] << " |";
    }
    cout << "\n";
    printLine(colWidth);
    for (size_t row = 1; row < table.size(); row++) {
        cout << "|";
        for (size_t col = 0; col < table[row].size(); col++) {
            cout << " " << left << setw(colWidth[col]) << table[row][col] << " |";
        }
        cout << "\n";
    }
    printLine(colWidth);
}

// Fungsi input integer dengan validasi
int inputInteger(const string &prompt) {
    int value;
    while (true) {
        cout << prompt;
        cin >> value;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "[!] Input harus berupa angka. Coba lagi.\n";
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return value;
        }
    }
}

// Fungsi untuk menambah data
void tambahData(vector<Handphone> &hp) {
    Handphone baru;
    string id;

    // Cek duplikat ID
    while (true) {
        cout << "Masukkan ID Produk: ";
        getline(cin, id);
        bool duplikat = false;
        for (const auto &h : hp) {
            if (h.getIdProduk() == id) {
                duplikat = true;
                cout << "[!] ID sudah ada, masukkan ID lain.\n";
                break;
            }
        }
        if (!duplikat && !id.empty()) break;
    }
    baru.setIdProduk(id);

    string nama, series, manufaktur, os, processor;
    cout << "Masukkan Nama        : "; getline(cin, nama);
    cout << "Masukkan Series      : "; getline(cin, series);
    cout << "Masukkan Manufaktur  : "; getline(cin, manufaktur);
    cout << "Masukkan OS          : "; getline(cin, os);
    cout << "Masukkan Processor   : "; getline(cin, processor);

    int ram = inputInteger("Masukkan RAM (GB)   : ");
    int storage = inputInteger("Masukkan Storage(GB): ");
    int battery = inputInteger("Masukkan Battery(mAh): ");
    int harga = inputInteger("Masukkan Harga       : ");

    baru.setNama(nama);
    baru.setSeries(series);
    baru.setManufaktur(manufaktur);
    baru.setTipeOS(os);
    baru.setProcessor(processor);
    baru.setRAM(ram);
    baru.setStorage(storage);
    baru.setBattery(battery);
    baru.setHarga(harga);

    hp.push_back(baru);
    cout << "[+] Data berhasil ditambahkan!\n";
}

int main() {
    vector<Handphone> hp;

    // Tambah 5 data default
    Handphone h1, h2, h3, h4, h5;

    h1.setIdProduk("P001"); h1.setNama("Galaxy S21"); h1.setSeries("S"); h1.setManufaktur("Samsung");
    h1.setTipeOS("Android"); h1.setProcessor("Snapdragon 888");
    h1.setRAM(8); h1.setStorage(256); h1.setBattery(4000); h1.setHarga(15000000);

    h2.setIdProduk("P002"); h2.setNama("iPhone 14"); h2.setSeries("14"); h2.setManufaktur("Apple");
    h2.setTipeOS("iOS"); h2.setProcessor("A15 Bionic");
    h2.setRAM(6); h2.setStorage(128); h2.setBattery(3800); h2.setHarga(18000000);

    h3.setIdProduk("P003"); h3.setNama("Pixel 7"); h3.setSeries("7"); h3.setManufaktur("Google");
    h3.setTipeOS("Android"); h3.setProcessor("Tensor G2");
    h3.setRAM(8); h3.setStorage(128); h3.setBattery(4350); h3.setHarga(12000000);

    h4.setIdProduk("P004"); h4.setNama("Xiaomi 13"); h4.setSeries("13"); h4.setManufaktur("Xiaomi");
    h4.setTipeOS("Android"); h4.setProcessor("Snapdragon 8 Gen 2");
    h4.setRAM(12); h4.setStorage(256); h4.setBattery(4820); h4.setHarga(9000000);

    h5.setIdProduk("P005"); h5.setNama("OnePlus 11"); h5.setSeries("11"); h5.setManufaktur("OnePlus");
    h5.setTipeOS("Android"); h5.setProcessor("Snapdragon 8 Gen 2");
    h5.setRAM(16); h5.setStorage(256); h5.setBattery(5000); h5.setHarga(11000000);

    hp = {h1, h2, h3, h4, h5};

    int pilihan;
    do {
        cout << "\n=== MENU ===\n";
        cout << "[1] Tampilkan data\n";
        cout << "[2] Tambah data\n";
        cout << "[0] Exit\n";
        cout << "Pilih menu: ";

        cin >> pilihan;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "[!] Input tidak valid. Masukkan angka 0, 1, atau 2.\n";
            continue;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (pilihan) {
            case 1: tampilkanData(hp); break;
            case 2: tambahData(hp); break;
            case 0: cout << "Have a nice day :D\n"; break;
            default: cout << "[!] Pilihan tidak tersedia.\n"; break;
        }
    } while (pilihan != 0);

    return 0;
}
