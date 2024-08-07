#include "header.h"

void TampilMenuAdmin(){
	system("cls");
	printf("\n\n\t---------- [ Admin ] ----------");
	printf("\n\t[1]. Tambah Data Dokter");  
	printf("\n\t[2]. Tampil Data Dokter");	
	printf("\n\t[3]. Cari Data Dokter");	
	printf("\n\t[4]. Ubah Data Dokter");	
	printf("\n\t[5]. Hapus Data Dokter"); 	
	printf("\n\t[6]. Pendaftaran Pemeriksaan Hewan"); 
	printf("\n\t[7]. Tampil Data Master Hewan");					
	printf("\n\t[8]. Laporan Pemeriksaan Hewan");	
	
	printf("\n\n\t[ESC]. LogOut");
	printf("\n\t>>>> ");
}

void TampilMenuDokter(string NamaDokter){
	system("cls");
	printf("\n\n\t---------- [ Dokter ] ----------");
	printf("\n\n\tWelcome, Dr. %s", NamaDokter);
	printf("\n\n\t[1]. Periksa Hewan");			
	printf("\n\t[2]. Tampil Data Hewan");
	printf("\n\t[3]. Laporan Dokter");		
	printf("\n\n\t[ESC]. LogOut");
	printf("\n\t>>>> ");
}

int CekLogin(List L, string UserName, string Password){
	if(strcmp(UserName, "admincintasatwa") == 0 && strcmp(Password, "admincintasatwa") == 0){
		return 1;
	} else if(strcmp(UserName, "exit") == 0 && strcmp(Password, "exit") == 0){
		return 0;
	} else if(CheckDokter(L, UserName, Password) != NULL){
		return 2;
	} else{
		return 3;
	}
}

AddressParent CheckDokter(List L, string UserName, string Password){
	AddressParent P;
	
	P = L.FirstParent;
	
	while(P != NULL){
		if(strcmp(P->Dp.UserName, UserName) == 0 && strcmp(P->Dp.Password, Password) == 0){
			return P;
			break;
		}
		P = P->Next;
	}
	return NULL;
}

AddressChild isUnikIdHewan(List L, string IdHewan){
	AddressParent P;
	AddressChild C;
	
	P = L.FirstParent;
	
	while(P != NULL){
		C = P->FirstChild;
		while(C != NULL){
			if(strcmpi(C->Dc.IdHewan, IdHewan) == 0){
				return C;
				break;
			}
			C = C->Next;
		}
		P = P->Next;
	}
	return NULL;
}

AddressChild isUnikIdRiwayat(List L, string IdRiwayat){
	AddressParent P;
	AddressChild C;
	
	P = L.FirstParent;
	while(P != NULL){
		C = P->FirstChild;
		while(C != NULL){
			if(strcmpi(C->Dc.IdRiwayat, IdRiwayat) == 0){
				return C;
				break;
			}
			C = C->Next;
		}
		P = P->Next;
	}
	return NULL;
}

AddressChild FindIdRiwayat(List L, AddressParent AP, string IdRiwayat){
	AddressChild C;
	C = AP->FirstChild;
	
	while(C != NULL){
		if(strcmpi(C->Dc.IdRiwayat, IdRiwayat) == 0){
			return C;
			break;
		}
		C = C->Next;
	}
}

bool isUnikUserName(List L, string UserName){
	AddressParent P;
	
	P = L.FirstParent;
	
	while(P != NULL){
		if(strcmpi(P->Dp.UserName, UserName) == 0){
			return false;
		}
		P = P->Next;
	}
	return true;
}

bool isUnik(List L, int IdDokter){
	AddressParent P;
	
	P = L.FirstParent;
	
	while(P != NULL){
		if(P->Dp.IdDokter == IdDokter){
			return false;
		}
		P = P->Next;
	}
	return true;
}

bool isEmpty(List L){
	return (L.FirstParent == NULL);
}


