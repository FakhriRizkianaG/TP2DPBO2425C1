public class Handphone extends SpecHandphone {
    private String manufaktur;
    private String series;
    private String tipeOS;

    public Handphone() {}

    public Handphone(String idProduk, String nama, int harga,
                     String processor, int ram, int storage, int battery,
                     String manufaktur, String series, String tipeOS) {
        super(idProduk, nama, harga, processor, ram, storage, battery);
        this.manufaktur = manufaktur;
        this.series = series;
        this.tipeOS = tipeOS;
    }

    public String getManufaktur() { return manufaktur; }
    public void setManufaktur(String manufaktur) { this.manufaktur = manufaktur; }

    public String getSeries() { return series; }
    public void setSeries(String series) { this.series = series; }

    public String getTipeOS() { return tipeOS; }
    public void setTipeOS(String tipeOS) { this.tipeOS = tipeOS; }
}
