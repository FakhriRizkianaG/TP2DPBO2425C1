import java.util.ArrayList;
import java.util.Scanner;

public class Main {
    static Scanner sc = new Scanner(System.in);
    static ArrayList<Handphone> hpList = new ArrayList<>();

    public static void main(String[] args) {
        // Data Hardcode
        hpList.add(new Handphone("P001", "Galaxy S21", 15000000,
                "Snapdragon 888", 8, 256, 4000, "Samsung", "S", "Android"));
        hpList.add(new Handphone("P002", "iPhone 14", 18000000,
                "A15 Bionic", 6, 128, 3800, "Apple", "14", "iOS"));
        hpList.add(new Handphone("P003", "Pixel 7", 12000000,
                "Tensor G2", 8, 128, 4350, "Google", "7", "Android"));
        hpList.add(new Handphone("P004", "Xiaomi 13", 9000000,
                "Snapdragon 8 Gen 2", 12, 256, 4820, "Xiaomi", "13", "Android"));
        hpList.add(new Handphone("P005", "OnePlus 11", 11000000,
                "Snapdragon 8 Gen 2", 16, 256, 5000, "OnePlus", "11", "Android"));

        while (true) {
            System.out.println("\n=== MENU ===");
            System.out.println("[1] Tampilkan data");
            System.out.println("[2] Tambah data");
            System.out.println("[0] Exit");
            System.out.print("Pilih menu: ");
        
            String pilihan = sc.nextLine().trim();
        
            switch (pilihan) {
                case "1" -> tampilkanData();
                case "2" -> tambahData();
                case "0" -> {
                    System.out.println("Have a nice day :D");
                    return; // keluar dari main()
                }
                default -> System.out.println("[!] Pilihan tidak tersedia. Coba lagi.");
            }
        }
    }

    static void tampilkanData() {
        if (hpList.isEmpty()) {
            System.out.println("[!] Tidak ada data untuk ditampilkan.");
            return;
        }

        String[] header = {"ID", "Nama", "Series", "Manufaktur", "OS",
                "Processor", "RAM", "Storage", "Battery", "Harga"};
        ArrayList<String[]> rows = new ArrayList<>();

        for (Handphone h : hpList) {
            rows.add(new String[]{
                    h.getIdProduk(),
                    h.getNama(),
                    h.getSeries(),
                    h.getManufaktur(),
                    h.getTipeOS(),
                    h.getProcessor(),
                    h.getRam() + " GB",
                    h.getStorage() + " GB",
                    h.getBattery() + " mAh",
                    "Rp. " + String.valueOf(h.getHarga())
            });
        }

        int[] colWidth = new int[header.length];
        for (int i = 0; i < header.length; i++) {
            colWidth[i] = header[i].length();
            for (String[] row : rows) {
                if (row[i].length() > colWidth[i]) {
                    colWidth[i] = row[i].length();
                }
            }
        }

        printLine(colWidth);
        printRow(header, colWidth);
        printLine(colWidth);
        for (String[] row : rows) {
            printRow(row, colWidth);
        }
        printLine(colWidth);
    }

    static void printLine(int[] colWidth) {
        System.out.print("+");
        for (int w : colWidth) {
            System.out.print("-".repeat(w + 2) + "+");
        }
        System.out.println();
    }

    static void printRow(String[] row, int[] colWidth) {
        System.out.print("|");
        for (int i = 0; i < row.length; i++) {
            System.out.print(" " + String.format("%-" + colWidth[i] + "s", row[i]) + " |");
        }
        System.out.println();
    }

    static void tambahData() {
        String idProduk;
        while (true) {
            System.out.print("Masukkan ID Produk: ");
            idProduk = sc.nextLine().trim();
            if (idProduk.isEmpty()) {
                System.out.println("[!] ID tidak boleh kosong.");
                continue;
            }
            boolean exists = false;
            for (Handphone h : hpList) {
                if (h.getIdProduk().equals(idProduk)) {
                    exists = true;
                    break;
                }
            }
            if (exists) {
                System.out.println("[!] ID sudah ada, masukkan ID lain.");
                continue;
            }
            break;
        }

        System.out.print("Masukkan Nama        : ");
        String nama = sc.nextLine();
        System.out.print("Masukkan Series      : ");
        String series = sc.nextLine();
        System.out.print("Masukkan Manufaktur  : ");
        String manufaktur = sc.nextLine();
        System.out.print("Masukkan OS          : ");
        String os = sc.nextLine();
        System.out.print("Masukkan Processor   : ");
        String processor = sc.nextLine();

        int ram = inputInteger("Masukkan RAM (GB)    : ");
        int storage = inputInteger("Masukkan Storage (GB): ");
        int battery = inputInteger("Masukkan Battery(mAh): ");
        int harga = inputInteger("Masukkan Harga       : ");

        hpList.add(new Handphone(idProduk, nama, harga, processor, ram, storage, battery, manufaktur, series, os));
        System.out.println("[+] Data berhasil ditambahkan!");
    }

    static int inputInteger(String prompt) {
        while (true) {
            System.out.print(prompt);
            String input = sc.nextLine();
            try {
                return Integer.parseInt(input);
            } catch (NumberFormatException e) {
                System.out.println("[!] Input harus berupa angka. Coba lagi.");
            }
        }
    }
}
