public class Produk {
    private String idProduk;
    private String nama;
    private int harga;

    public Produk() {}

    public Produk(String idProduk, String nama, int harga) {
        this.idProduk = idProduk;
        this.nama = nama;
        this.harga = harga;
    }

    public String getIdProduk() { return idProduk; }
    public void setIdProduk(String idProduk) { this.idProduk = idProduk; }

    public String getNama() { return nama; }
    public void setNama(String nama) { this.nama = nama; }

    public int getHarga() { return harga; }
    public void setHarga(int harga) { this.harga = harga; }
}
