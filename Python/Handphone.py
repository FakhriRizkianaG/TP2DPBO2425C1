from SpecHandphone import SpecHandphone

class Handphone(SpecHandphone):
    def __init__(self, id_produk="", nama="", harga=0,
                 processor="", ram=0, storage=0, battery=0,
                 manufaktur="", series="", tipe_os=""):
        super().__init__(id_produk, nama, harga, processor, ram, storage, battery)
        self.__manufaktur = manufaktur
        self.__series = series
        self.__tipe_os = tipe_os

    def get_manufaktur(self): return self.__manufaktur
    def set_manufaktur(self, manufaktur): self.__manufaktur = manufaktur

    def get_series(self): return self.__series
    def set_series(self, series): self.__series = series

    def get_tipe_os(self): return self.__tipe_os
    def set_tipe_os(self, tipe_os): self.__tipe_os = tipe_os
