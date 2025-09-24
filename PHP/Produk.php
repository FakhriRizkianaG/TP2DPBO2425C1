<?php
class Produk {
    private $id_produk;
    private $nama;
    private $harga;
    private $image;

    public function __construct($id_produk = "", $nama = "", $harga = 0, $image = "") {
        $this->id_produk = $id_produk;
        $this->nama = $nama;
        $this->harga = $harga;
        $this->image = $image;
    }

    public function getIdProduk() { return $this->id_produk; }
    public function setIdProduk($id_produk) { $this->id_produk = $id_produk; }

    public function getNama() { return $this->nama; }
    public function setNama($nama) { $this->nama = $nama; }

    public function getHarga() { return $this->harga; }
    public function setHarga($harga) { $this->harga = $harga; }

    public function getImage() { return $this->image; }
    public function setImage($image) { $this->image = $image; }
}
?>
