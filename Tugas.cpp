#include <iostream>
#include <string>

using namespace std;

struct Mahasiswa {
    string nama;
    int nim;
    // Mahasiswa* next;
};

// Mahasiswa* head = nullptr;
Mahasiswa mahasiswa1;

void inputData() {
    Mahasiswa* newMahasiswa = new Mahasiswa;
    cout << "Masukkan nama mahasiswa: ";
    cin >> newMahasiswa->nama;
    cout << "Masukkan NIM mahasiswa: ";
    cin >> newMahasiswa->nim;
    newMahasiswa1->next = head;
    head = newMahasiswa;
    cout << "Data berhasil ditambahkan!\n";
}

void tampilkanData() {
    if (head == nullptr) {
        cout << "Tidak ada data mahasiswa.\n";
        return;
    }
    
    Mahasiswa* current = head;
    cout << "\nDaftar Mahasiswa:\n";
    while (current != nullptr) {
        cout << "Nama: " << current->nama << " | NIM: " << current->nim << "\n";
        current = current->next;
    }
}

Mahasiswa* cariNama(string key) {
    Mahasiswa* current = head;
    while (current != nullptr) {
        if (current->nama == key) return current;
        current = current->next;
    }
    return nullptr;
}

void pencarianNama() {
    if (head == nullptr) {
        cout << "Tidak ada data mahasiswa untuk dicari.\n";
        return;
    }
    
    string nama;
    cout << "Masukkan nama mahasiswa yang dicari: ";
    cin >> nama;
    Mahasiswa* result = cariNama(nama);
    if (result) {
        cout << "Mahasiswa ditemukan: " << result->nama << " dengan NIM " << result->nim << "\n";
    } else {
        cout << "Mahasiswa tidak ditemukan.\n";
    }
}

// void sortingData() {
//     if (head == nullptr || head->next == nullptr) {
//         cout << "Tidak cukup data untuk sorting.\n";
//         return;
//     }
    
//     bool swapped;
//     do {
//         swapped = false;
//         Mahasiswa** ptr = &head;
//         while ((*ptr)->next != nullptr) {
//             if ((*ptr)->nim > (*ptr)->next->nim) {
//                 Mahasiswa* temp = (*ptr)->next;
//                 (*ptr)->next = temp->next;
//                 temp->next = *ptr;
//                 *ptr = temp;
//                 swapped = true;
//             }
//             ptr = &((*ptr)->next);
//         }
//     } while (swapped);
    
//     cout << "Data telah diurutkan berdasarkan NIM.\n";
// }

int main() {
    int pilihan;
    do {
        cout << "\nMenu Sistem Mahasiswa:\n";
        cout << "1. Input Data\n";
        cout << "2. Tampilkan Data\n";
        cout << "3. Searching\n";
        cout << "4. Sorting\n";
        cout << "5. Keluar\n";
        cout << "Pilihan: ";
        cin >> pilihan;
        
        switch (pilihan) {
            case 1: inputData(); break;
            case 2: tampilkanData(); break;
            case 3: pencarianNama(); break;
            case 4: sortingData(); break;
            case 5: cout << "Terima kasih telah menggunakan sistem ini!\n"; break;
            default: cout << "Pilihan tidak valid!\n";
        }
    } while (pilihan != 5);
    
    return 0;
}
