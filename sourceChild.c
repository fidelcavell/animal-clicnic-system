#include "header.h"

void PrintChild(AddressChild AC){
	printf("\n\n\t\tId Hewan      : %s", AC->Dc.IdHewan);
	printf("\n\t\tNama Hewan    : %s", AC->Dc.NamaHewan);
	printf("\n\t\tTanggal Lahir : %.10s", AC->Dc.TanggalLahir);
	printf("\n\t\tJenis Hewan   : %s", AC->Dc.JenisHewan);
	printf("\n\t\tJenis Kelamin : %s", AC->Dc.JenisKelamin);
	
}

void PrintRiwayat(AddressChild AC){
	printf("\n\n\t\t-------- [Riwayat Hewan] --------");
	printf("\n\t\tIdRiwayat       : %s", AC->Dc.IdRiwayat);
	printf("\n\t\tTanggal Periksa : %.10s", AC->Dc.TanggalPeriksa);
	printf("\n\t\tDiagnosa        : %s", AC->Dc.Diagnosa);
	printf("\n\t\tObat            : %s", AC->Dc.Obat);
}

void PrintAllChild(AddressParent AP){
	AddressChild C;
	
	C = AP->FirstChild;
	while(C != NULL){
		
		PrintChild(C);
		PrintRiwayat(C);
		C = C->Next;
	}
}

AddressChild AlokasiChild(DataChild Dc){
	AddressChild AC;
	
	AC = (AddressChild)malloc(sizeof(Child));
	
	AC->Next = NULL;
	AC->Dc = Dc;
	
	return AC;
}

DataChild MakeDataChild(string IdHewan, string NamaHewan, char TanggalLahir[10], string JenisHewan, string JenisKelamin, string Status, string IdRiwayat, char TanggalPeriksa[10], string Diagnosa, string Obat){
	DataChild Dc;
	int i;
	
	strcpy(Dc.IdHewan, IdHewan);
	strcpy(Dc.NamaHewan, NamaHewan);
	strcpy(Dc.JenisHewan, JenisHewan);
	strcpy(Dc.JenisKelamin, JenisKelamin);
	strcpy(Dc.Status, Status);
	
	strcpy(Dc.IdRiwayat, IdRiwayat);
	strcpy(Dc.Diagnosa, Diagnosa);
	strcpy(Dc.Obat, Obat);
	
	for(i = 0; i != 10; i++){
		Dc.TanggalPeriksa[i] = TanggalPeriksa[i];
	}
	
	for(i = 0; i != 10; i++){
		Dc.TanggalLahir[i] = TanggalLahir[i];
	}
	
	return Dc;
}

void InsertFirstChild(List *L, AddressParent AP, DataChild Dc){
	if(AP != NULL){
		AddressChild Baru;
		Baru = AlokasiChild(Dc);
		Baru->Next = AP->FirstChild;
		AP->FirstChild = Baru;
		
	}
}

void InsertLastChild(List *L, AddressParent AP, DataChild Dc){
	
	if(AP != NULL){
		if(!HaveChild(AP)){
			InsertFirstChild(&(*L), AP, Dc);
			
		} else{
			AddressChild Temp, Baru;
			Temp = AP->FirstChild;
			Baru = AlokasiChild(Dc);
			
			while(Temp->Next != NULL){
				Temp = Temp->Next;
			}
			Temp->Next = Baru;
			
		}
	}
}

void Sorting(List *L, AddressParent AP){
	AddressChild C, Temp;
	DataChild Sort;
	int i, Count = 0;
	
	C = AP->FirstChild;
	
	while(C != NULL){
		Count++;
		C = C->Next;
	}
	
	for(i = 0; i < Count; i++){
		Temp = AP->FirstChild;
		
		while(Temp->Next != NULL){
			if(strcmpi(Temp->Dc.JenisHewan, Temp->Next->Dc.JenisHewan) > 0){
				Sort = Temp->Dc;
				Temp->Dc = Temp->Next->Dc;
				Temp->Next->Dc = Sort;
			}
			Temp = Temp->Next;
		}
	}
}
							
void DeleteAtChild(List *L, AddressParent AP, AddressChild AC){
	AddressChild C, Temp;
	
	C = AP->FirstChild;

	if(strcmpi(C->Dc.IdRiwayat, AC->Dc.IdRiwayat) == 0){
		AP->FirstChild = AP->FirstChild->Next;
		free(C);
	} else{
		while(strcmpi(C->Next->Dc.IdRiwayat, AC->Dc.IdRiwayat) == 0){
			
			Temp = C->Next;
			C->Next = C->Next->Next;
				
			free(Temp);

			C = C->Next;
		}
	}
	

}
	



