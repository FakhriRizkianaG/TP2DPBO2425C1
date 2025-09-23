#include <iostream>
#include <string>
using namespace std;

class SpecHandphone : public Produk {
private:
    string processor;
    int ram;
    int storage;
    int battery;

public:
    // Setter
    void setProcessor(const string &p) { processor = p; }
    void setRAM(int r) { ram = r; }
    void setStorage(int s) { storage = s; }
    void setBattery(int b) { battery = b; }

    // Getter
    string getProcessor() const { return processor; }
    int getRAM() const { return ram; }
    int getStorage() const { return storage; }
    int getBattery() const { return battery; }
};
