#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/*
	---------------------------------------------
	|	Anggota Kelompok :						|
	|	1. Fidel Fausta Cavell ~ 210711302		|
	|	2. Bryan Maximillan ~ 210711010			|
	|	3. Hendryanto ~ 210711292				|
	|	4. Angel ~ 210711280					|
	---------------------------------------------
*/

typedef char string [50];

typedef struct Child* AddressChild;
typedef struct Parent* AddressParent;

typedef struct DataChild{
	string IdHewan;
	string NamaHewan;
	char TanggalLahir[10];
	string JenisHewan;
	string JenisKelamin;
	string Status;
	
	string IdRiwayat;
	char TanggalPeriksa[10];
	string Diagnosa;
	string Obat;
	
} DataChild;

typedef struct DataParent{
	string UserName;
	string Password;
	int IdDokter;
	string NamaDokter;
	char TanggalGabung[10];
} DataParent;

typedef struct Child{
	DataChild Dc;
	AddressChild Next;
} Child;

typedef struct Parent{
	DataParent Dp;
	AddressChild FirstChild;
	AddressParent Next;
} Parent;

typedef struct{
	AddressParent FirstParent;
} List;


// SOURCE :
void TampilMenuAdmin();
void TampilMenuDokter(string NamaDokter);

int CekLogin(List L, string UserName, string Password);

AddressParent CheckDokter(List L, string UserName, string Password);

AddressChild isUnikIdHewan(List L, string IdHewan);
AddressChild isUnikIdRiwayat(List L, string IdRiwayat);

AddressChild FindIdRiwayat(List L, AddressParent AP, string IdRiwayat);

bool isUnikUserName(List L, string UserName);
bool isUnik(List L, int IdDokter);
bool isEmpty(List L);



// SOURCE PARENT ~ Dokter :
void CreateEmpty(List *L);

AddressParent AlokasiParent(DataParent Dp);
AddressParent FindParent(List L, int Id);

DataParent MakeDataParent(string UserName, string Password, int IdDokter, string NamaDokter, char TanggalGabung[10]);

void InsertFirstParent(List *L, DataParent Dp);
void InsertLastParent(List *L, DataParent Dp);

void DeleteFirstParent(List *L);
void DeleteAtParent(List *L, int Id);

void DeleteAllChild(AddressParent AP);

void PrintParent(AddressParent AP);
void PrintAll(List L);

bool HaveChild(AddressParent AP);


// SOURCE CHILD ~ Hewan :
void PrintChild(AddressChild AC);
void PrintAllChild(AddressParent AP);
void PrintRiwayat(AddressChild AC);

AddressChild AlokasiChild(DataChild Dc);
AddressChild FindStatHewan(List L, string Status);

DataChild MakeDataChild(string IdHewan, string NamaHewan, char TanggalLahir[10], string JenisHewan, string JenisKelamin, string Status, string IdRiwayat, char TanggalPeriksa[10], string Diagnosa, string Obat);

void InsertFirstChild(List *L, AddressParent AP, DataChild Dc);
void InsertLastChild(List *L, AddressParent AP, DataChild Dc);

void Sorting(List *L, AddressParent AP);

void DeleteAtChild(List *L, AddressParent AP, AddressChild AC);
