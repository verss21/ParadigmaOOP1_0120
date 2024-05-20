#include <iostream>
#include <vector>
using namespace std;

class Dokter;
class pasien { //asosiasi
public:
	string nama;
	vector<Dokter*> daftar_dokter;
	pasien(string pNama) :nama(pNama) {
		cout << "Pasien \"" << nama << "\" ada\n";
	}
	~pasien() {
		cout << "Pasien \"" << nama << "\" tidak ada\n";
	}
	void tambahDokter(Dokter*);
	void cetakDokter();
};

class Dokter {
public:
	string nama;
	vector<pasien*> daftar_pasien;

	Dokter(string pNama) : nama(pNama) {
		cout << "Dokter \"" << nama << "\" ada\n";
};

	~Dokter() {
	cout << "Dokter \"" << nama << "\" tidak ada\n";
}

void tambahPasien(pasien*);
void cetakPasien();
};

void pasien::tambahDokter(Dokter* pDokter) {
	daftar_dokter.push_back(pDokter);
}
void pasien::cetakDokter() {
	cout << "Daftar dokter yang menangani pasien \"" << this->nama << "\":\n";
	for (auto& a : daftar_dokter) { //auto digunakan dalam perulangan for untuk secara otomatis menentukan tipe data dari elemen yang diitera
		cout << a->nama << "\n";
	}
	cout << endl;
}

void Dokter::tambahPasien(pasien* pPasien) {
	daftar_pasien.push_back(pPasien);
	pPasien->tambahDokter(this);
}

void Dokter::cetakPasien() {
	cout << "Daftar pasien dari dokter \"" << this->nama << "\":\n";
	for (auto& a : daftar_pasien) {
		cout << a->nama << "\n";
	}
	cout << endl;
}

int main() {
	Dokter* varDokter1 = new Dokter("dr.Budi");
	Dokter* varDokter2 = new Dokter("dr.Tomo");
	pasien* varPasien1 = new pasien("Andi");
	pasien* varPasien2 = new pasien("Lia");

	varDokter1->tambahPasien(varPasien1);
	varDokter1->tambahPasien(varPasien2);
	varDokter2->tambahPasien(varPasien1);

	varDokter1->cetakPasien();
	varDokter2->cetakPasien();
	varPasien1->cetakDokter();
	varPasien2->cetakDokter();

	delete varPasien1;
	delete varPasien2;
	delete varDokter1;
	delete varDokter2;

	return 0;

}