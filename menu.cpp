#include <iostream>
#include <conio.h>
#include <stdlib.h>
using namespace std;

// ----------------------------
// Deklarasi Array dan Variabel
// ----------------------------
const int MAKS_DATA = 100;
int data[MAKS_DATA];
int jumlahData = 0;

// ----------------------------
// Fungsi Menu Utama
// ----------------------------
void dMenu(){
    system("cls");
    cout << "Aplikasi Sorting Bubble" << "\n";       
    cout << "1. Memasukkan Data" << "\n";            
    cout << "2. Menampilkan Data" << "\n";            
    cout << "3. Sorting (Bubble Sort)" << "\n";           
    cout << "4. Sepatah Kata" << "\n";            
    cout << "5. Exit" << "\n";           
    cout << "Masukkan angka :";        
}

// ----------------------------
// Fungsi Input Data
// ----------------------------
void inputData() {
    system("cls");
    cout << "Masukkan jumlah data (maksimal " << MAKS_DATA << "): ";
    cin >> jumlahData;

    if (jumlahData > MAKS_DATA || jumlahData <= 0) {
        cout << "Jumlah data tidak valid!" << endl;
        jumlahData = 0;
        getch();
        return;
    }

    for(int i = 0; i < jumlahData; i++) {
        cout << "Data ke-" << i+1 << ": ";
        cin >> data[i];
    }
    getch();
}

// ----------------------------
// Fungsi Tampil Data
// ----------------------------
void tampilData() {
    system("cls");
    if (jumlahData == 0) {
        cout << "Belum ada data yang dimasukkan.";
    } else {
        cout << "Data saat ini:\n";
        for(int i = 0; i < jumlahData; i++) {
            cout << data[i] << " ";
        }
    }
    cout << "\n";
    getch();
}

// ----------------------------
// Fungsi Bubble Sort
// ----------------------------
void bubbleSort() {
    for(int i = 0; i < jumlahData - 1; i++) {
        for(int j = 0; j < jumlahData - i - 1; j++) {
            if(data[j] > data[j + 1]) {
                int temp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = temp;
            }
        }
    }
}

// ----------------------------
// Fungsi Sorting Menu
// ----------------------------
void sortingData() {
    system("cls");

    if (jumlahData == 0) {
        cout << "Belum ada data untuk disorting.";
        getch();
        return;
    }

    bubbleSort();
    cout << "Data telah disorting dengan metode Bubble Sort:\n";
    for(int i = 0; i < jumlahData; i++) {
        cout << data[i] << " ";
    }
    cout << "\n";
    getch();
}

// ----------------------------
// Fungsi Sepatah Kata
// ----------------------------
void sepatahKata(){
    system("cls");
    cout << "Indonesia Harus Bisa, Kita Juara\n@poliban";
    getch();
}

// ----------------------------
// Fungsi Main
// ----------------------------
int main() {
    char pl;
    do {
        dMenu();
        pl = getch();
        switch (pl) {
            case '1':
                inputData();
                break;
            case '2':
                tampilData();
                break;
            case '3':
                sortingData();
                break;
            case '4':
                sepatahKata();
                break;
            case '5':
                break;
            default:
                system("cls");
                cout << "Pilihan Tidak Tersedia";
                getch();
                break;
        }
    } while (pl != '5');
    return 0;
}
