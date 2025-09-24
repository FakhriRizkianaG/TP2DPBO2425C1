from Produk import Produk
from SpecHandphone import SpecHandphone
from Handphone import Handphone

def print_line(col_width):
    print("+" + "+".join("-" * (w + 2) for w in col_width) + "+")

def tampilkan_data(hp_list):
    if not hp_list:
        print("\n[!] Tidak ada data untuk ditampilkan.\n")
        return

    table = [["ID Produk", "Nama", "Series", "Manufaktur", "OS", "Processor",
              "RAM", "Storage", "Battery", "Harga"]]
    for h in hp_list:
        table.append([
            h.get_id_produk(),
            h.get_nama(),
            h.get_series(),
            h.get_manufaktur(),
            h.get_tipe_os(),
            h.get_processor(),
            f"{h.get_ram()} GB",
            f"{h.get_storage()} GB",
            f"{h.get_battery()} mAh",
            "Rp. " + str(h.get_harga())
        ])

    col_width = [max(len(row[i]) for row in table) for i in range(len(table[0]))]

    print_line(col_width)
    print("|" + "|".join(f" {table[0][i].ljust(col_width[i])} " for i in range(len(table[0]))) + "|")
    print_line(col_width)
    for row in table[1:]:
        print("|" + "|".join(f" {row[i].ljust(col_width[i])} " for i in range(len(row))) + "|")
    print_line(col_width)

def input_integer(prompt):
    while True:
        try:
            return int(input(prompt))
        except ValueError:
            print("[!] Input harus berupa angka. Coba lagi.")

def tambah_data(hp_list):
    id_produk = ""
    while True:
        id_produk = input("Masukkan ID Produk: ").strip()
        if not id_produk:
            print("[!] ID tidak boleh kosong.")
            continue
        if any(h.get_id_produk() == id_produk for h in hp_list):
            print("[!] ID sudah ada, masukkan ID lain.")
            continue
        break

    nama = input("Masukkan Nama        : ")
    series = input("Masukkan Series      : ")
    manufaktur = input("Masukkan Manufaktur  : ")
    os = input("Masukkan OS          : ")
    processor = input("Masukkan Processor   : ")
    ram = input_integer("Masukkan RAM (GB)    : ")
    storage = input_integer("Masukkan Storage (GB): ")
    battery = input_integer("Masukkan Battery(mAh): ")
    harga = input_integer("Masukkan Harga       : ")

    baru = Handphone(id_produk, nama, harga, processor, ram, storage, battery, manufaktur, series, os)
    hp_list.append(baru)
    print("[+] Data berhasil ditambahkan!")

def main():
    hp_list = []
    temp = Handphone("P001", "Galaxy S21", 15000000, "Snapdragon 888", 8, 256, 4000, "Samsung", "S", "Android")
    hp_list.append(temp)
    temp = Handphone("P002", "iPhone 14", 18000000, "A15 Bionic", 6, 128, 3800, "Apple", "14", "iOS")
    hp_list.append(temp)
    temp = Handphone("P003", "Pixel 7", 12000000, "Tensor G2", 8, 128, 4350, "Google", "7", "Android")
    hp_list.append(temp)
    temp = Handphone("P004", "Xiaomi 13", 9000000, "Snapdragon 8 Gen 2", 12, 256, 4820, "Xiaomi", "13", "Android")
    hp_list.append(temp)
    temp = Handphone("P005", "OnePlus 11", 11000000, "Snapdragon 8 Gen 2", 16, 256, 5000, "OnePlus", "11", "Android")
    hp_list.append(temp)

    while True:
        print("\n=== MENU ===")
        print("[1] Tampilkan data")
        print("[2] Tambah data")
        print("[0] Exit")
        pilihan = input("Pilih menu: ")

        if pilihan == "1":
            tampilkan_data(hp_list)
        elif pilihan == "2":
            tambah_data(hp_list)
        elif pilihan == "0":
            print("Have a nice day :D")
            break
        else:
            print("[!] Pilihan tidak tersedia. Coba lagi.")

if __name__ == "__main__":
    main()
