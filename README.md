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
