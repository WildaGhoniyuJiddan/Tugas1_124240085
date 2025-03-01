#include <iostream>
#include <array>
using namespace std;

const int mx = 100;
struct Mahasiswa {
    string nama, kelas;
    int nim;
    float ipk;
};

Mahasiswa daftarM[mx];
int jumlahMahasiswa = 0;

void inputData() {
    int n;
    cout << "Berapa jumlah data yang ingin ditambahkan: "; cin >> n; 
    for (int i = jumlahMahasiswa; i < jumlahMahasiswa + n; i++) { 
        cout << "Masukkan data ke-" << i + 1 << endl;
        cout << "Masukkan Nama mahasiswa: ";
        cin >> daftarM[i].nama;
        cout << "Masukkan NIM mahasiswa: ";
        cin >> daftarM[i].nim;
        cout << "Masukkan Kelas: ";
        cin >> daftarM[i].kelas;
        cout << "Masukkan IPK: ";
        cin >> daftarM[i].ipk;
    }
    jumlahMahasiswa += n;
    cout << endl;
}


void tampilkanData() {
    if (jumlahMahasiswa == 0) {
        cout << "Tidak ada data mahasiswa.\n";
        return;
    }
    
    cout << "\nDaftar Mahasiswa:\n";
    for (int i = 0; i < jumlahMahasiswa; i++) {
        cout << "Nama: " << daftarM[i].nama << endl;
        cout << "NIM: " << daftarM[i].nim << endl;
        cout << "Kelas: " << daftarM[i].kelas << endl;
        cout << "Ipk: " << daftarM[i].ipk << endl;
    }
    cout << "\n";
}

void searching(){
    int nim;
    cout << "Masukkan NIM yang ingin dicari: ";
    cin >> nim;
    bool found = false;
    for (int i = 0; i < jumlahMahasiswa; i++) {
        if (daftarM[i].nim == nim) {
            cout << "\nData ditemukan!" << endl;
            cout << "Nama Lengkap\t: " << daftarM[i].nama << endl;
            cout << "NIM\t\t: " << daftarM[i].nim << endl;
            cout << "Kelas\t\t: " << daftarM[i].kelas << endl;
            cout << "IPK\t\t: " << daftarM[i].ipk << endl;
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Data tidak ditemukan." << endl;
    }
}
void sorting(){
    for (int i = 0; i < jumlahMahasiswa - 1; i++) {
        for (int j = 0; j < jumlahMahasiswa - i - 1; j++) {
            if (daftarM[j].nim > daftarM[j + 1].nim) {
                swap(daftarM[j], daftarM[j + 1]);
            }
        }
    }
    cout << "Data telah diurutkan berdasarkan NIM." << endl;
    tampilkanData();
}


int main() {
    int pilihan;
    do {
        cout << "\nMenu:\n";
        cout << "1. Input Data\n";
        cout << "2. Tampilkan Data\n";
        cout << "3. Searching\n";
        cout << "4. Sorting\n";
        cout << "5. Keluar\n";
        cout << "Pilihan: ";
        cin >> pilihan;
        
        switch (pilihan) {
            case 1:
                inputData();
                break;
            case 2:
                tampilkanData();
                break;
            case 3:
                searching();
                break;
            case 4:
                sorting();
                break;
            case 5: 
                cout << "Keluar dari program.\n";
                break;
            default:
                cout << "Pilihan tidak valid.\n";
        }
    } while (pilihan != 5);
    
    return 0;
}
