class Produk:
    def __init__(self, id_produk="", nama="", harga=0):
        self.__id_produk = id_produk
        self.__nama = nama
        self.__harga = harga

    # Getter & Setter
    def get_id_produk(self): return self.__id_produk
    def set_id_produk(self, id_produk): self.__id_produk = id_produk

    def get_nama(self): return self.__nama
    def set_nama(self, nama): self.__nama = nama

    def get_harga(self): return self.__harga
    def set_harga(self, harga): self.__harga = harga
