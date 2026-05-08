#include <stdio.h>
#include <string.h>

#define MAX 10

enum Status{
    NORMAL,
    WARNING,
    KRITIS
};

struct VitalSign{
    int sistolik;
    int diastolik;
    int heartRate;
    float suhu;
    int spo2;
};

struct Pasien{
    char nama[50];
    int umur;
    struct VitalSign vital;
};

enum Status cekTekananDarah(int sys, int dia){
    if(sys < 90 || dia < 60)
        return WARNING;
    else if(sys > 180 || dia > 120)
        return KRITIS;
    else if(sys >= 90 && sys <= 120 && dia >= 60 && dia <= 80)
        return NORMAL;
    else
        return WARNING;
}

enum Status cekHeartRate(int hr){
    if(hr < 40 || hr > 140)
        return KRITIS;
    else if(hr < 60 || hr > 100)
        return WARNING;
    else
        return NORMAL;
}

enum Status cekSuhu(float suhu){
    if(suhu < 35 || suhu > 40)
        return KRITIS;
    else if(suhu >= 37.5)
        return WARNING;
    else
        return NORMAL;
}

enum Status cekSpO2(int spo2){
    if(spo2 < 90)
        return KRITIS;
    else if(spo2 < 95)
        return WARNING;
    else
        return NORMAL;
}

void tampilStatus(enum Status s){
    switch(s){
        case NORMAL:
            printf("NORMAL");
            break;
        case WARNING:
            printf("WARNING");
            break;
        case KRITIS:
            printf("KRITIS");
            break;
    }
}

void analisisPasien(struct Pasien *p){

    enum Status td, hr, suhu, spo2;

    td = cekTekananDarah(
        p->vital.sistolik,
        p->vital.diastolik
    );

    hr = cekHeartRate(p->vital.heartRate);
    suhu = cekSuhu(p->vital.suhu);
    spo2 = cekSpO2(p->vital.spo2);

    printf("\n====================================");
    printf("\nHASIL MONITORING PASIEN");
    printf("\n====================================");

    printf("\nNama Pasien : %s", p->nama);
    printf("\nUmur        : %d tahun", p->umur);

    printf("\n\n[ Tekanan Darah ]");
    printf("\n%d/%d mmHg --> ",
           p->vital.sistolik,
           p->vital.diastolik);
    tampilStatus(td);

    printf("\n\n[ Heart Rate ]");
    printf("\n%d BPM --> ",
           p->vital.heartRate);
    tampilStatus(hr);

    printf("\n\n[ Suhu Tubuh ]");
    printf("\n%.1f C --> ",
           p->vital.suhu);
    tampilStatus(suhu);

    printf("\n\n[ SpO2 ]");
    printf("\n%d%% --> ",
           p->vital.spo2);
    tampilStatus(spo2);

    printf("\n\n========== AI MEDICAL ALERT ==========");

    if(td == KRITIS || hr == KRITIS ||
       suhu == KRITIS || spo2 == KRITIS){

        printf("\n!!! KONDISI KRITIS !!!");
        printf("\nSegera hubungi dokter atau ICU.");
    }

    else if(spo2 == WARNING && hr == WARNING){
        printf("\nKemungkinan kelelahan atau gangguan respirasi.");
    }

    else if(suhu == WARNING){
        printf("\nPasien terindikasi demam.");
    }

    else{
        printf("\nSemua tanda vital relatif stabil.");
    }

    int score = 100;

    if(td == WARNING) score -= 10;
    if(td == KRITIS) score -= 25;

    if(hr == WARNING) score -= 10;
    if(hr == KRITIS) score -= 25;

    if(suhu == WARNING) score -= 10;
    if(suhu == KRITIS) score -= 25;

    if(spo2 == WARNING) score -= 10;
    if(spo2 == KRITIS) score -= 30;

    printf("\n\nHealth Score : %d/100", score);

    if(score >= 85)
        printf("\nStatus Umum  : SEHAT");
    else if(score >= 60)
        printf("\nStatus Umum  : PERLU PEMANTAUAN");
    else
        printf("\nStatus Umum  : DARURAT MEDIS");

    printf("\n====================================\n");
}

int main(){

    struct Pasien pasien[MAX];

    int jumlah, i;

    printf("====================================\n");
    printf(" SMART VITAL SIGN MONITOR SYSTEM\n");
    printf(" FINPRO KEREN DARI KELOMPOK 1\n");
    printf("====================================\n");

    printf("Jumlah pasien : ");
    scanf("%d", &jumlah);

    for(i = 0; i < jumlah; i++){

        printf("\n\n===== INPUT DATA PASIEN %d =====\n", i+1);

        printf("Nama Pasien        : ");
        scanf("%s", pasien[i].nama);

        printf("Umur               : ");
        scanf("%d", &pasien[i].umur);

        printf("Tekanan Sistolik   : ");
        scanf("%d", &pasien[i].vital.sistolik);

        printf("Tekanan Diastolik  : ");
        scanf("%d", &pasien[i].vital.diastolik);

        printf("Heart Rate (BPM)   : ");
        scanf("%d", &pasien[i].vital.heartRate);

        printf("Suhu Tubuh (C)     : ");
        scanf("%f", &pasien[i].vital.suhu);

        printf("SpO2 (%%)            : ");
        scanf("%d", &pasien[i].vital.spo2);
    }

    for(i = 0; i < jumlah; i++){

        analisisPasien(&pasien[i]);

    }

    return 0;
}