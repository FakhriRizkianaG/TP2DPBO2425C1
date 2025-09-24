public class SpecHandphone extends Produk {
    private String processor;
    private int ram;
    private int storage;
    private int battery;

    public SpecHandphone() {}

    public SpecHandphone(String idProduk, String nama, int harga,
                         String processor, int ram, int storage, int battery) {
        super(idProduk, nama, harga);
        this.processor = processor;
        this.ram = ram;
        this.storage = storage;
        this.battery = battery;
    }

    public String getProcessor() { return processor; }
    public void setProcessor(String processor) { this.processor = processor; }

    public int getRam() { return ram; }
    public void setRam(int ram) { this.ram = ram; }

    public int getStorage() { return storage; }
    public void setStorage(int storage) { this.storage = storage; }

    public int getBattery() { return battery; }
    public void setBattery(int battery) { this.battery = battery; }
}
