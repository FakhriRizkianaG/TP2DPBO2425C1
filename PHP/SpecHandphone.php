<?php
require_once "Produk.php";

class SpecHandphone extends Produk {
    private $processor;
    private $ram;
    private $storage;
    private $battery;

    public function __construct($id_produk = "", $nama = "", $harga = 0, $image = "",
                                $processor = "", $ram = 0, $storage = 0, $battery = 0) {
        parent::__construct($id_produk, $nama, $harga, $image);
        $this->processor = $processor;
        $this->ram = $ram;
        $this->storage = $storage;
        $this->battery = $battery;
    }

    public function getProcessor() { return $this->processor; }
    public function setProcessor($processor) { $this->processor = $processor; }

    public function getRam() { return $this->ram; }
    public function setRam($ram) { $this->ram = $ram; }

    public function getStorage() { return $this->storage; }
    public function setStorage($storage) { $this->storage = $storage; }

    public function getBattery() { return $this->battery; }
    public function setBattery($battery) { $this->battery = $battery; }
}
?>
