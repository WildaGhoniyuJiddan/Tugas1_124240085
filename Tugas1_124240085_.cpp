#include <iostream>
#include <algorithm>
using namespace std;

const int mx = 100;
struct Barang {
    string nama;
    int jumlah;
    float harga;
};

Barang daftarBarang[mx];
int jumlahBarang = 0;

void inputData() {
    int n;
    cout << "\nBerapa jumlah barang yang ingin ditambahkan: "; cin >> n;
    cin.ignore();
    for (int i = jumlahBarang; i < jumlahBarang + n; i++) {
        cout << "\nMasukkan data ke-" << i + 1 << endl;
        cout << "Nama Barang: "; getline(cin, daftarBarang[i].nama);
        cout << "Jumlah: "; cin >> daftarBarang[i].jumlah;
        cout << "Harga: "; cin >> daftarBarang[i].harga;
        cin.ignore();
    }
    jumlahBarang += n;
    system("cls");
}

void tampilkanData() {
    system("cls");
    if (jumlahBarang == 0) {
        cout << "Tidak ada data barang.\n";
        return;
    }

    // Bubble Sort untuk mengurutkan barang berdasarkan nama
    for (int i = 0; i < jumlahBarang - 1; i++) {
        for (int j = 0; j < jumlahBarang - i - 1; j++) {
            if (daftarBarang[j].nama > daftarBarang[j + 1].nama) {
                swap(daftarBarang[j], daftarBarang[j + 1]);
            }
        } 
    }

    cout << "\nDaftar Barang:\n";
    for (int i = 0; i < jumlahBarang; i++) {
        cout << "Nama: " << daftarBarang[i].nama 
             << "\nJumlah: " << daftarBarang[i].jumlah 
             << "\nHarga: " << daftarBarang[i].harga << "\n\n";
    }
}


void cariHarga() { //Sequential Search
    float hargaCari;
    cout << "\nMasukkan harga yang akan dicari: "; cin >> hargaCari;
    bool ditemukan = false;
    for (int i = 0; i < jumlahBarang; i++) {
        if (daftarBarang[i].harga == hargaCari) {
            cout << "\nBarang ditemukan:\nNama: " << daftarBarang[i].nama << "\nJumlah: " << daftarBarang[i].jumlah << "\nHarga: " << daftarBarang[i].harga << "\n\n";
            ditemukan = true;
        }
    }
    if (!ditemukan) cout << "Data tidak ditemukan.\n";
    system("pause");
}

void cariNama() {
    string namac;
    cout << "Masukkan nama barang yang akan dicari: ";
    getline(cin, namac);

    int kiri = 0, kanan = jumlahBarang - 1;
    while (kiri <= kanan) {
        int tengah = (kiri + kanan) / 2;
        if (daftarBarang[tengah].nama == namac) {
            cout << "\nBarang ditemukan:\nNama: " << daftarBarang[tengah].nama
                 << "\nJumlah: " << daftarBarang[tengah].jumlah
                 << "\nHarga: " << daftarBarang[tengah].harga << "\n\n";
                 system("pause");
            return;
        } else if (daftarBarang[tengah].nama < namac) {
            kiri = tengah + 1;
        } else {
            kanan = tengah - 1;
        }
    }
    cout << "Data tidak ditemukan.\n";
    system("pause");
}


void cariData() {
    int pilihan;
    do {
        system("cls");
        cout << "\nPilih metode pencarian:\n1. Berdasarkan Harga\n2. Berdasarkan Nama\n3. Kembali ke Menu\nPilih menu: ";
        cin >> pilihan;
        cin.ignore();
        switch (pilihan) {
            case 1: cariHarga(); break;
            case 2: cariNama(); break;
            case 3: return;
            default: cout << "Pilihan tidak valid.\n";
        }
    } while (pilihan != 3);
}

bool kembaliMenu() {
    char pilihan;
    cout << "Apakah anda ingin kembali ke menu? (y/t): "; cin >> pilihan;
    return pilihan == 'y' || pilihan == 'Y';
}

int main() {
    int pilihan;
    do {
        system("cls");
        cout << "===============================\n";
        cout << "\n           Menu              \n";
        cout << "===============================\n";
        cout << "\n1. Input Data Barang";
        cout << "\n2. Tampilkan Data Barang";
        cout << "\n3. Cari Data Barang";
        cout << "\n4. Keluar";
        cout << "\nMasukkan pilihan: ";
        cin >> pilihan;
        switch (pilihan) {
            case 1: inputData(); break;
            case 2: tampilkanData(); break;
            case 3: cariData(); break;
            case 4: cout << "Keluar dari program.\n"; return 0;
            default: cout << "Pilihan tidak valid.\n";
        }
    } while (kembaliMenu());
    return 0;
}
