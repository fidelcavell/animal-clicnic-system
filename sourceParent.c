#include "header.h"

void CreateEmpty(List *L){
	L->FirstParent = NULL;
}

AddressParent AlokasiParent(DataParent Dp){
	AddressParent AP;
	
	AP = (AddressParent)malloc(sizeof(Parent));
	AP->Dp = Dp;
	AP->Next = NULL;
	AP->FirstChild = NULL;
	
	return AP;
}

AddressParent FindParent(List L, int Id){
	AddressParent P;
	
	P = L.FirstParent;
	
	while(P != NULL){
		if(P->Dp.IdDokter == Id){
			return P;
		}
		P = P->Next;
	}
	
	return NULL;
}

DataParent MakeDataParent(string UserName, string Password, int IdDokter, string NamaDokter, char TanggalGabung[10]){
	DataParent Dp;
	int i;
	
	strcpy(Dp.UserName, UserName);
	strcpy(Dp.Password, Password);
	Dp.IdDokter = IdDokter;
	strcpy(Dp.NamaDokter, NamaDokter);
	
	for(i = 0; i != 10; i++){
		Dp.TanggalGabung[i] = TanggalGabung[i];
	}
	
	return Dp;
}

void InsertFirstParent(List *L, DataParent Dp){
	AddressParent P;
	
	P = AlokasiParent(Dp);
	P->Next = L->FirstParent;
	L->FirstParent = P;
}

void InsertLastParent(List *L, DataParent Dp){
	AddressParent P, Last;
	
	P = AlokasiParent(Dp);
	
	if(isEmpty(*L)){
		InsertFirstParent(L, Dp);
	} else{
		Last = L->FirstParent;
		
		while(Last->Next != NULL){
			Last = Last->Next;
		}
		Last->Next = P;
	}
}

void DeleteFirstParent(List *L){
	AddressParent P;
	
	P = L->FirstParent;
	
	if(!isEmpty(*L)){
		
		DeleteAllChild(P);
		
		L->FirstParent = L->FirstParent->Next;
		free(P);
	}
}
		
void DeleteAtParent(List *L, int Id){
	AddressParent P, Hapus;
	
	P = L->FirstParent;
	
	if(!isEmpty(*L)){
		
		if(P->Dp.IdDokter == Id){
			DeleteFirstParent(L);
		} else{
			
			while(P->Next != NULL){
				if(P->Next->Dp.IdDokter == Id){
					Hapus = P->Next;
					P->Next = P->Next->Next;
					
					DeleteAllChild(Hapus);
					
					free(Hapus);
					break;
				}
				P = P->Next;
			}
		}
	}
}

void DeleteAllChild(AddressParent AP){
	AddressChild P;
	
	while(HaveChild(AP)){
		P = AP->FirstChild;
		AP->FirstChild = AP->FirstChild->Next;
		
		free(P);
	}
}

void PrintParent(AddressParent AP){
	printf("\n\tId Dokter      : %d", AP->Dp.IdDokter);
	printf("\n\tUserName       : %s", AP->Dp.UserName);
	printf("\n\tPassword       : %s", AP->Dp.Password);
	printf("\n\tNama Dokter    : %s", AP->Dp.NamaDokter);
	printf("\n\tTanggal Gabung : %.10s", AP->Dp.TanggalGabung);
}

void PrintAll(List L){
	AddressParent P;
	int i = 0;
	
	P = L.FirstParent;
	
	while(P != NULL){
		i++;
		printf("\n\n\t[ Data Dokter ke - %d ]", i);
		PrintParent(P);
		
		printf("\n\n\t\t------- [ Data Hewan ] -------");
		PrintAllChild(P);
		printf("\n");
		
		P = P->Next;
	}
}

bool HaveChild(AddressParent AP){
	return AP->FirstChild != NULL;
}
