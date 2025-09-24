from Produk import Produk

class SpecHandphone(Produk):
    def __init__(self, id_produk="", nama="", harga=0,
                 processor="", ram=0, storage=0, battery=0):
        super().__init__(id_produk, nama, harga)
        self.__processor = processor
        self.__ram = ram
        self.__storage = storage
        self.__battery = battery

    def get_processor(self): return self.__processor
    def set_processor(self, processor): self.__processor = processor

    def get_ram(self): return self.__ram
    def set_ram(self, ram): self.__ram = ram

    def get_storage(self): return self.__storage
    def set_storage(self, storage): self.__storage = storage

    def get_battery(self): return self.__battery
    def set_battery(self, battery): self.__battery = battery
