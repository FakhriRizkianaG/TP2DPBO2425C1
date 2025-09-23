#include <iostream>
#include <string>
using namespace std;

class Handphone : public SpecHandphone {
private:
    string manufaktur;
    string series;
    string tipeOS;

public:
    // Setter
    void setManufaktur(const string &m) { manufaktur = m; }
    void setSeries(const string &s) { series = s; }
    void setTipeOS(const string &os) { tipeOS = os; }

    // Getter
    string getManufaktur() const { return manufaktur; }
    string getSeries() const { return series; }
    string getTipeOS() const { return tipeOS; }
};
