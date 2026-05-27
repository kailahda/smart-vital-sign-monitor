# smart-vital-sign-monitor

# **Pendahuluan**
Perkembangan teknologi di bidang kesehatan mendorong kebutuhan akan suatu sistem monitorng pasien yang bisa dengan cepat, akurat, dan efisien. Salah satu aspek yang penting --> pemantauan tanda vital pasien untuk mengetahui kondisi kesehatan pasien. Tanda vital atau vital sign semacam tekanan darah, detak jantung, suhu tubuh, serta saturasi oksigen merupakan parameter utama yang digunakan tenaga medis dalam mengevaluasi kondisi pasien. Oleh karena itu, kelompok kami memutuskan bahwa diperlukannya suatu sistem monitoriing yang mampu melakukan analisis kondisi pasien dan memberikan alert atau peringatan apabila ditemukan kondisi yang tidak normal. Project "Smart Vital Sign Monitor System" ini dibuat sebagai simulasi sistem monitoring kesehatan yang berbasis bahasa pemrograman C. Programnya dirancang untuk menerima data vital dari pasien kemudian dari data tersebut akan dianalisis kondisi kesehatannya lalu menampilha visualisasi data  serta memberikan alert medis yang disesuaikan berdasarkan parameter vital dari pasien.

Tujuan Project
Tujuan dari project ini adalah:
1. Mengimplementasikan konsep dasar pemrograman bahasa C pada studi kasus biomedical engineering.
2. Membuat sistem monitoring tanda vital pasien sederhana.
3. Melakukan klasifikasi kondisi pasien berdasarkan parameter kesehatan.
4. Menampilkan visualisasi data kesehatan menggunakan ASCII graph.
5. Mengembangkan sistem peringatan medis sederhana berbasis rule-based analysis.

# **Penjelasan Kode**
```c
#include, #define MAX
enum Status
struct VitalSign
struct Pasien
cekTekananDarah()
cekHeartRate()
```
Penggunaan `enum Status` digunakan untuk mendefinisikan 3 kemungkinan kondisi, yaitu `NORMAL`, `WARNING`, dan `KRITIS`. Enum ini dipakai di seluruh program sebagai "bahasa bersama" antar fungsinya. Selain itu, penggunaan `struct VitalSign` adalah blueprint data tanda vital satu pasien, antara lain seperti sistolik, diastolik, heart rate, suhu, dan SpO2 yang dapat disimpan dalam satu wadah. Penggunaan `struct Pasien` ini untuk menggabungkan identitas pasien (nama, umur) dengan data vitalnya (menggunakan `struct VitalSign` sebagai nested struct di dalamnya).

Kemudian, penggunaan `cekTekananDarah(int sys, int dia)` ini untuk menerima nilai sistolik dan diastolik lalu mengembalikan status menggunakan logika `if-else`, antara lain:
- Sistolik > 180 atau diastolik > 120 → **KRITIS**
- Sistolik < 90 atau diastolik < 60 → **WARNING**
- Sistolik 90–120 dan diastolik 60–80 → **NORMAL**
- Selain itu → **WARNING**

Lalu, penggunaan `cekHeartRate(int hr)` menerima detak jantung dalam BPM lalu mengembalikan status seperti berikut:
- BPM < 40 atau > 140 → **KRITIS**
- BPM < 60 atau > 100 → **WARNING**
- BPM 60–100 → **NORMAL**

# **Penjelasan Kode2**
```c
cekSuhu()
cekSpO2()
tampilStatus()
tampilBar()
```

Fungsi `cekSuhu(float suhu)` digunakan untuk mengklasifikasikan suhu menjadi 3 kemungkinan kondisi berdasarkan penggunaan `enum Status` : 
- Suhu < 35°C atau > 40°C -> **KRITIS**
- Suhu ≥ 37.5°C -> **WARNING**
- Selain itu -> **NORMAL**
Kondisi `KRITIS` yang didapatkan setelah cek suhu menandakan pasien mengalami hipotermia(<35°C) atau hipetermia(>40°C), kondisi `WARNING` menunjukkan bahwa pasien sedang mengalami demam, sementara kondisi `NORMAL` menunjukkan keadaan pasien yang baik-baik saja.

Fungsi `cekSpO2(int spo2)` akan mengklasifikasi nilai spo2 menjadi 3 kemungkinan kondisi berdasarkan penggunaan `enum Status` :
- SpO2 < 90% -> **KRITIS**
- SpO2 < 95% -> **WARNING**
- Spo2 ≥ 95% -> **NORMAL**
Kondisi `KRITIS` hasil cek nilai SpO2/Saturasi Oksigen Perifer, menunjukkan pasien mengalami hipoksia berat dan butuh perhatian medis segera, kondisi `WARNING` menunjukkan pasien mengalami hipoksia ringan dan perlu waspada, sementara kondisi `NORMAL` menunjukkan kondisi pasien yang baik-baik saja.

Untuk mencetak tampilan status/kondisi pasien, coding ini menggunakan 2 fungsi : `tampilStatus(enum Status s)` dan `tampilBar(char label[], int value, int max)`. 

`tampilStatus(enum Status s)` akan menerima nilai enum dan mencetak status menggunakan `switch-case`. Fungsi ini akan dipanggil saat melakukan analisis pasien, status akan ditampilkan untuk setiap parameter yang ada.

`tampilBar(char label[], int value, int max)` akan menampilkan grafik batang ASCII untuk setiap parameter. 
**Cara kerjanya:**
**1. Hitung panjang bar**
`panjangBar = (value * 20)/max`
**2. Cetak #**
_#_ akan dicetak sebanyak panjangBar menggunakan `for loop`
**3. Cetak spasi kosong**
Spasi kosong akan dicetak untuk sisa bar menggunakan `for loop` kedua

# **Fungsi Analisis Pasien**
Fungsi analisis pasien, yaitu void `analisisPasien(struct Pasien *p)` adalah fungsi yang menerima pointer ke struct pasien di mana nilai tidak dikembalikan, melainkan hanya menampilkan output sehingga efisien secara memori. Data atau struct pasien dengan ukuran yang cukup besar, meliputi nama, umur, dan 5 data tanda vital menjadi penyebab penggunaan pointer *p. Tanpa pointer, program harus menyalin seluruh data  ke dalam fungsi setiap kali dipanggil sehingga boros memori. Dengan pointer, fungsi cukup menerima alamat memori tempat data pasien disimpan, lalu langsung membacanya dari sana.

**Cara kerjanya:**
**1. Panggil semua fungsi klasifikasi**
```c
td = cekTekananDarah(p->vital.sistolik, p->vital.diastolik);
hr = cekHeartRate(p->vital.heartRate);
suhu = cekSuhu(p->vital.suhu);
spo2 = cekSpO2(p->vital.spo2);
```
Hasil klasifikasi disimpan ke variabel lokal `td`, `hr`, `suhu`, `spo2`.

**2. Tampilkan hasil tiap parameter**
Memanggil `tampilStatus()` untuk mencetak NORMAL/WARNING/KRITIS di samping nilai masing-masing parameter.

**3. Tampilkan Visual Graph**
Memanggil `tampilBar()` untuk 5 parameter bersamaan, yaitu sistolik, diastolik, heart rate, suhu, dan SpO2.

**4. Alert Cerdas**
- Jika ada parameter KRITIS: cetak peringatan darurat
- Jika SpO2 dan HR keduanya WARNING: indikasi kelelahan atau gangguan respirasi
- Jika hanya suhu WARNING: indikasi demam
- Jika semua aman: kondisi stabil

**5. Hitung Health Score**
Dimulai dari 100 lalu dikurangi berdasarkan jumlah dan tingkat keparahan parameter yang bermasalah
- WARNING: -10 poin
- KRITIS: -25 atau -30 poin
- Score ≥ 85 (SEHAT), ≥ 60 (PERLU PEMANTAUAN), < 60 (DARURAT MEDIS)





























  ```c
  statusKeseluruhan()
  tampilRekap()
  main()
  ```
Bagian kode inilah yang bertugas untuk menentukan status akhir pasien dan kemudian menampilkan rekapnya secara keseluruhan serta mengatur alur utama dari programnya.

a.  ```c enum Status statusKeseluruhan(struct Pasien *p)```
Function ini menentukan status akhir untuk seorang pasien berdasarkan kondisi kondisi terburuk di antara seluruh parameternya. Misal saru parameter dianggap kritis maka itu sudah cukup untuk menjadikan pasien dikategorikan kritis secara keseluruhan terlepas dari kondisi parameter lainnya.
- Jika ada satu parameter KRITIS --> pasien KRITIS
- Jiika ada satu parameter WARNING --> pasien WARNING
- Jika semua NORMAL --> pasien NORMAL
Function ini digunakan oleh tampilanRekap().

b. ```c void tampilRekap(struct Pasien pasien[], int jumlah```
Ini yang akan menampilkan ringkasan kondisi seluruh pasien dalam satu tampilan setelah semua analisis individual selesai. Cara kerjanya secara sederhana itu dengan loop seluruh pasien menggunakan `for` kemudian memanggil `statusKeseluruhan()` lalu menghitung jumlah pasien sesuai kategori dan menampilkan ACII barnya.

c. main()
Function ini merupakan titik masuk eksekusi programnya --> mengatur seluruh alur dari input hingga output akhir. ALur kerjanya secara sederhana adalah ia pertama akan menampilkan header program -> input jumlah pasien -> melakukan loop input data pasien -> memanggil `analisisPasien()` untuk tiap pasien -> menampilkan rekap akhir menggunakan tampilRekap().

