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
    Handphone henpun;

    // Tambah 5 data hardcode dengan 1 objek
    henpun.setIdProduk("P001"); henpun.setNama("Galaxy S21"); henpun.setSeries("S"); henpun.setManufaktur("Samsung");
    henpun.setTipeOS("Android"); henpun.setProcessor("Snapdragon 888");
    henpun.setRAM(8); henpun.setStorage(256); henpun.setBattery(4000); henpun.setHarga(15000000);
    hp.push_back(henpun);

    henpun.setIdProduk("P002"); henpun.setNama("iPhone 14"); henpun.setSeries("14"); henpun.setManufaktur("Apple");
    henpun.setTipeOS("iOS"); henpun.setProcessor("A15 Bionic");
    henpun.setRAM(6); henpun.setStorage(128); henpun.setBattery(3800); henpun.setHarga(18000000);
    hp.push_back(henpun);

    henpun.setIdProduk("P003"); henpun.setNama("Pixel 7"); henpun.setSeries("7"); henpun.setManufaktur("Google");
    henpun.setTipeOS("Android"); henpun.setProcessor("Tensor G2");
    henpun.setRAM(8); henpun.setStorage(128); henpun.setBattery(4350); henpun.setHarga(12000000);
    hp.push_back(henpun);

    henpun.setIdProduk("P004"); henpun.setNama("Xiaomi 13"); henpun.setSeries("13"); henpun.setManufaktur("Xiaomi");
    henpun.setTipeOS("Android"); henpun.setProcessor("Snapdragon 8 Gen 2");
    henpun.setRAM(12); henpun.setStorage(256); henpun.setBattery(4820); henpun.setHarga(9000000);
    hp.push_back(henpun);

    henpun.setIdProduk("P005"); henpun.setNama("OnePlus 11"); henpun.setSeries("11"); henpun.setManufaktur("OnePlus");
    henpun.setTipeOS("Android"); henpun.setProcessor("Snapdragon 8 Gen 2");
    henpun.setRAM(16); henpun.setStorage(256); henpun.setBattery(5000); henpun.setHarga(11000000);
    hp.push_back(henpun);

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
