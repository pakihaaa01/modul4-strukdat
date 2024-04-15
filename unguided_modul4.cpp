#include <iostream>
#include <string>
using namespace std;

// Deklarasi struktur Node
struct Node {
    string nama;
    string nim;
    Node* next;
};

// Deklarasi kelas LinkedList
class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = nullptr;
    }

    // Fungsi untuk menambahkan node di awal linked list
    void addFront(string nama, string nim) {
        Node* newNode = new Node;
        newNode->nama = nama;
        newNode->nim = nim;
        newNode->next = head;
        head = newNode;
        cout << "Data telah ditambahkan." << endl;
    }

    // Fungsi untuk menambahkan node di belakang linked list
    void addBack(string nama, string nim) {
        Node* newNode = new Node;
        newNode->nama = nama;
        newNode->nim = nim;
        newNode->next = nullptr;

        if (head == nullptr) {
            head = newNode;
            cout << "Data telah ditambahkan." << endl;
            return;
        }

        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
        cout << "Data telah ditambahkan." << endl;
    }

    // Fungsi untuk menambahkan node di tengah linked list
    void addMiddle(int pos, string nama, string nim) {
        Node* newNode = new Node;
        newNode->nama = nama;
        newNode->nim = nim;

        if (pos == 1) {
            newNode->next = head;
            head = newNode;
            cout << "Data telah ditambahkan." << endl;
            return;
        }

        Node* temp = head;
        for (int i = 1; i < pos - 1; i++) {
            if (temp == nullptr) {
                cout << "Posisi yang dimaksud tidak valid." << endl;
                return;
            }
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
        cout << "Data telah ditambahkan." << endl;
    }

    // Fungsi untuk mengubah data di depan linked list
    void modifyFront(string nama, string nim) {
        if (head == nullptr) {
            cout << "Linked list kosong. Tidak ada data yang dapat diubah." << endl;
            return;
        }
        cout << "Data " << head->nama << " telah diganti dengan data " << nama << "." << endl;
        head->nama = nama;
        head->nim = nim;
    }

    // Fungsi untuk mengubah data di belakang linked list
    void modifyBack(string nama, string nim) {
        if (head == nullptr) {
            cout << "Linked list kosong. Tidak ada data yang dapat diubah." << endl;
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        cout << "Data " << temp->nama << " telah diganti dengan data " << nama << "." << endl;
        temp->nama = nama;
        temp->nim = nim;
    }

    // Fungsi untuk mengubah data di tengah linked list
    void modifyMiddle(int pos, string nama, string nim) {
        if (head == nullptr) {
            cout << "Linked list kosong. Tidak ada data yang dapat diubah." << endl;
            return;
        }
        Node* temp = head;
        int count = 0;
        while (temp != nullptr) {
            count++;
            if (count == pos) {
                cout << "Data " << temp->nama << " telah diganti dengan data " << nama << "." << endl;
                temp->nama = nama;
                temp->nim = nim;
                return;
            }
            temp = temp->next;
        }
        cout << "Posisi yang dimaksud tidak valid." << endl;
    }


    // Fungsi untuk menghapus data di depan linked list
    void deleteFront() {
        if (head == nullptr) {
            cout << "Linked list kosong. Tidak ada data yang dapat dihapus." << endl;
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
        cout << "Data depan berhasil dihapus." << endl;
    }

    // Fungsi untuk menghapus data di tengah linked list
    void deleteMiddle(int pos) {
        if (head == nullptr) {
            cout << "Linked list kosong. Tidak ada data yang dapat dihapus." << endl;
            return;
        }
        Node* temp = head;
        Node* prev = nullptr;
        int count = 0;
        while (temp != nullptr) {
            count++;
            if (count == pos) {
                if (prev == nullptr) { // jika yang dihapus adalah head
                    head = head->next;
                } else {
                    prev->next = temp->next;
                }
            cout << "Data " << temp->nama << " berhasil dihapus." << endl;
                delete temp;
                return;
            }
            prev = temp;
            temp = temp->next;
        }
        cout << "Posisi yang dimaksud tidak valid." << endl;
    }


    // Fungsi untuk menghapus data di belakang linked list
    void deleteBack() {
        if (head == nullptr) {
            cout << "Linked list kosong. Tidak ada data yang dapat dihapus." << endl;
            return;
        }
        if (head->next == nullptr) {
            cout << "Data " << head->nama << " berhasil dihapus." << endl;
            delete head;
            head = nullptr;
            return;
        }
        Node* temp = head;
        while (temp->next->next != nullptr) {
            temp = temp->next;
        }
        cout << "Data " << temp->next->nama << " berhasil dihapus." << endl;
        delete temp->next;
        temp->next = nullptr;
    }

    // Fungsi untuk menampilkan seluruh data mahasiswa dalam linked list
    void display() {
        if (head == nullptr) {
            cout << "Linked list kosong." << endl;
            return;
        }
        Node* temp = head;
        cout << "Data Mahasiswa:" << endl;
        cout << "Nama <=====> \tNIM" << endl;
        while (temp != nullptr) {
            cout << "Nama: " << temp->nama << "\tNIM: " << temp->nim << endl;
            temp = temp->next;
        }
        cout << endl;
    }

    // Fungsi untuk menghapus seluruh data dalam linked list
    void clear() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
        cout << "Seluruh data berhasil dihapus." << endl;
    }
};

int main() {
    LinkedList list;
    int choice, pos;
    string nama, nim;

    cout << "PROGRAM SINGLE LINKED LIST NON-CIRCULAR" << endl;
    do {
        cout << "1. Tambah Depan" << endl;
        cout << "2. Tambah Belakang" << endl;
        cout << "3. Tambah Tengah" << endl;
        cout << "4. Ubah Depan" << endl;
        cout << "5. Ubah Belakang" << endl;
        cout << "6. Ubah Tengah" << endl;
        cout << "7. Hapus Depan" << endl;
        cout << "8. Hapus Tengah" << endl;
        cout << "9. Hapus Belakang" << endl;
        cout << "10. Tampilkan" << endl;
        cout << "11. Hapus List" << endl;
        cout << "0. Keluar" << endl;
        cout << "Pilih Operasi: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Masukkan Nama : ";
                cin >> nama;
                cout << "Masukkan NIM : ";
                cin >> nim;
                list.addFront(nama, nim);
                break;
            case 2:
                cout << "Masukkan Nama : ";
                cin >> nama;
                cout << "Masukkan NIM : ";
                cin >> nim;
                list.addBack(nama, nim);
                break;
            case 3:
                cout << "Masukkan nama : ";
                cin >> nama;
                cout << "Masukkan NIM : ";
                cin >> nim;
                cout << "Masukkan posisi: ";
                cin >> pos;
                list.addMiddle(pos, nama, nim);
                break;
            case 4:
                cout << "Masukkan nama baru mahasiswa depan: ";
                cin >> nama;
                cout << "Masukkan NIM baru mahasiswa depan: ";
                cin >> nim;
                list.modifyFront(nama, nim);
                break;
            case 5:
                cout << "Masukkan nama : ";
                cin >> nama;
                cout << "Masukkan NIM : ";
                cin >> nim;
                list.modifyBack(nama, nim);
                break;
            case 6:
                cout << "Masukkan nama baru mahasiswa: ";
                cin >> nama;
                cout << "Masukkan NIM baru mahasiswa: ";
                cin >> nim;
                cout << "Masukkan posisi: ";
                cin >> pos;
                list.modifyMiddle(pos, nama, nim);
                break;
            case 7:
                list.deleteFront();
                break;
            case 8:
                cout << "Masukkan posisi : ";
                cin >> pos;
                list.deleteMiddle(pos);
                break;
            case 9:
                list.deleteBack();
                break;
            case 10:
                list.display();
                break;
            case 11:
                list.clear();
                break;
            case 0:
                cout << "Program selesai." << endl;
                break;
            default:
                cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
        }
    } while (choice != 0);

    return 0;
}
