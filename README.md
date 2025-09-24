# TP2DPBO2425C1
TP 2 Frizkia (Fakhri Rizkiana)

# Janji
Saya Fakhri Rizkiana Sya'ban Kusnendar dengan NIM 2405534 mengerjakan<br> 
TP 2 dalam mata kuliah Desain dan Pemrograman<br>
Berorientasi Objek untuk keberkahanNya maka saya tidak<br>
melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.<br>

# Penjelasan Program
Program memiliki struktur sbb:<br>

<img width="1047" height="294" alt="image" src="https://github.com/user-attachments/assets/1452bad5-1835-4ae3-98e5-9d4bc0eb6f0e" />

<h3>Penjelasan Struktur</h3>
Ada 3 Class yang akan digunakan di dalam program ini, yaitu:

Pertama Class Produk [Produk dari toko] dengan atribut: <br>
id_produk(str) -> digunakan untuk identifikasi <br>
Nama(str) -> nama dari produk<br>
Harga(int) -> harga dari produk<br>
Images(str) -> gambar (khusus php)<br>

Kedua Class SpecHandphone [Spesifikasi Handphone] yang merupakan child dari Class Produk [Karena masih ada hubungan dengan produk] dengan atribut: <br>
Processor(str) -> processor dari handphone<br>
RAM(int) -> besar ram dari handphone<br>
Storage(int) -> besar penyimpanan dari handphone<br>
Battery(int) -> kapasitas baterai dari handphone<br>

Ketiga Class Handphone [Handphone itu sendiri]  yang merupakan child dari Class SpecHandphone [Karena Handphone dan spek handphone itu berhubungan dan memiliki banyak kemiripan] dengan atribut: 
Manufaktur(str) -> Tempat dibuatnya handphone<br>
Series(str) -> Seri dari handphone<br>
TipeOS(str) -> Tipe OS dari handphone tsb<br>

# Alur Program
Program ini akan dijalankan dengan menggunakan CLI untuk bahasa C++, Java, dan Python. Sedangkan untuk PHP akan dijalankan dengan menggunakan web.

<h3>Versi CLI</h3>
Untuk versi CLI, user akan dibawa ke sebuah menu<br>
<img width="267" height="159" alt="Screenshot 2025-09-24 211157" src="https://github.com/user-attachments/assets/adf86c02-af13-4fbb-95e4-0834a994619d" />

Jika user memilih satu, maka akan menampilkan data yang ada. (ini data sebelum ada tambahan dari user (data hardcode))<br>
<img width="1743" height="425" alt="Screenshot 2025-09-24 211209" src="https://github.com/user-attachments/assets/8b008cc1-007e-4af0-b33a-d12e76dfc024" />

Jika user memilih 2, maka user bisa menambahkan data handphone<br>
<img width="507" height="476" alt="Screenshot 2025-09-24 211215" src="https://github.com/user-attachments/assets/4cd47601-3593-4ec7-812b-c5d335587bdf" />

ada juga error handling untuk menangani input user tidak sesuai saat menambahkan data<br>
<img width="588" height="753" alt="Screenshot 2025-09-24 211223" src="https://github.com/user-attachments/assets/07951108-d0ab-4b7b-8564-aeaf9e946505" />

hasil data setelah ditambahkan<br>
<img width="1863" height="471" alt="Screenshot 2025-09-24 211232" src="https://github.com/user-attachments/assets/11443e68-2764-446f-8769-f9ee055cae13" />

ada juga error handling di bagian menu<br>
<img width="739" height="392" alt="Screenshot 2025-09-24 211241" src="https://github.com/user-attachments/assets/030198eb-3ba2-4c37-92de-a83cc7eb5a6a" />

ada juga fitur exit untuk exit program<br>
<img width="300" height="196" alt="Screenshot 2025-09-24 211248" src="https://github.com/user-attachments/assets/560b9bde-5772-433b-842b-12b9d92c30a7" />

<br>
<h3>Versi Web</h3>
untuk versi web, hanya menampilkan barang yang ada<br>
<img width="1919" height="1079" alt="Screenshot 2025-09-24 195111" src="https://github.com/user-attachments/assets/1f8eea87-fca8-4f41-992f-6f14554681a6" />

