<?php
require_once "SpecHandphone.php";

class Handphone extends SpecHandphone {
    private $manufaktur;
    private $series;
    private $tipeOS;

    public function __construct($id_produk = "", $nama = "", $harga = 0, $image = "",
                                $processor = "", $ram = 0, $storage = 0, $battery = 0,
                                $manufaktur = "", $series = "", $tipeOS = "") {
        parent::__construct($id_produk, $nama, $harga, $image, $processor, $ram, $storage, $battery);
        $this->manufaktur = $manufaktur;
        $this->series = $series;
        $this->tipeOS = $tipeOS;
    }

    public function getManufaktur() { return $this->manufaktur; }
    public function setManufaktur($manufaktur) { $this->manufaktur = $manufaktur; }

    public function getSeries() { return $this->series; }
    public function setSeries($series) { $this->series = $series; }

    public function getTipeOS() { return $this->tipeOS; }
    public function setTipeOS($tipeOS) { $this->tipeOS = $tipeOS; }
}
?>
