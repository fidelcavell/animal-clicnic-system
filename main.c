#include "header.h"

int main(int argc, char *argv[]) {
	List L, Data;
	AddressParent AP;
	AddressChild AC;

	char MenuAdmin, MenuDokter;
	int IdDokter, DeadCount = 1, i;
	string UserName, Password, Nama;
	string IdHewan, JenisHewan, JenisKelamin, IdRiwayat, Diagnosa, Obat, Status;
	char Tanggal[10], TanggalPeriksa[10];
	
	CreateEmpty(&L);
	CreateEmpty(&Data);
	InsertFirstParent(&Data, MakeDataParent("**", "**", -1, "**", "**-**-****"));
	
	do{
		system("cls");
		printf("\n\n\t------ [ Klinik Hewan - Cinta Satwa ] ------\n");
		printf("\n\tUserName : "); fflush(stdin); gets(UserName);
		printf("\tPassword : "); fflush(stdin); gets(Password);
		CekLogin(L, UserName, Password);
		
		if(CekLogin(L, UserName, Password) == 1){
			do{
				TampilMenuAdmin();
				MenuAdmin = getch();
				
				switch(MenuAdmin){
					case '1' : 
						printf("\n\n\t-------- [ Tambah Data Dokter ] --------");
						do{
							printf("\n\tInput UserName [Min 4 Character]  : "); fflush(stdin); gets(UserName);
							if(strlen(UserName) < 4){
								printf("\n\t\tUserName harus memiliki minimal 4 character [!]\n");
							} else if(!isUnikUserName(L, UserName)){
								printf("\n\t\tUserName %s sudah digunakan [!]\n", UserName);
							} else{
								break;
							}
						} while(strlen(UserName) < 4 || !isUnikUserName(L, UserName));
						
						do{
							printf("\tInput Password [Min 8 Charcter]   : "); fflush(stdin); gets(Password);
							if(strlen(Password) < 8){
								printf("\n\t\tPassword harus memiliki minimal 8 character [!]\n\n");
							}
						} while(strlen(Password) < 8);
						
						do{
							printf("\n\n\tInput Id Dokter                   : "); scanf("%d", &IdDokter);
							if(!isUnik(L, IdDokter)){
								printf("\n\t\tId Dokter harus unik [!]");
							} else if(IdDokter <= 0){
								printf("\n\t\tId Dokter tidak boleh negatif atau NOL [!]");
							} else{
								break;
							}
						} while(!isUnik(L, IdDokter) || IdDokter <= 0);
						
						do{
							printf("\tInput Nama Dokter                 : "); fflush(stdin); gets(Nama);
							if(strlen(Nama) < 1 || strcmpi(Nama, "-") == 0){
								printf("\n\t\tNama Dokter tidak boleh kosong atau '-' [!]\n\n");
							}
						} while(strlen(Nama) < 1 || strcmpi(Nama, "-") == 0);
						
						do{
							printf("\tInput Tanggal Gabung [DD-MM-YYYY] : "); scanf("%s", Tanggal);
							if(strlen(Tanggal) < 10 || strlen(Tanggal) > 10){
								printf("\n\t\tFormat Salah [!]\n");
							} else if(Tanggal[2] != '-' || Tanggal[5] != '-'){
								printf("\n\t\tFormat Salah [!]\n");
							} else if(Tanggal[0] >= '3' && Tanggal[1] >= '2'){
								printf("\n\t\tFormat Salah [!]\n");
							} else if(Tanggal[0] == '0' && Tanggal[1] == '0'){
								printf("\n\t\tFormat Salah [!]\n");
							} else if(Tanggal[3] == '0' && Tanggal[4] == '0'){
								printf("\n\t\tFormat Salah [!]\n");
							} else if(Tanggal[3] >= '1' && Tanggal[4] >= '3'){
								printf("\n\t\tFormat Salah [!]\n");
							} else{
								break;
							}
						} while(true);
						
						InsertLastParent(&L, MakeDataParent(UserName, Password, IdDokter, Nama, Tanggal));
						
						printf("\n\n\tData Dokter dengan Id - %d, berhasil ditambahkan [!]", IdDokter);
						break;
						
					case '2' :
						if(isEmpty(L)){
							printf("\n\n\tData Dokter masih kosong [!]");
						} else{
							printf("\n\n\t-------- [ Tampil Data Dokter ] --------");
							AP = L.FirstParent;
							while(AP != NULL){
								PrintParent(AP);
								AP = AP->Next;
							}
						}
						break;
						
					case '3' :
						printf("\n\n\t-------- [ Cari Data Dokter ] --------");
						printf("\n\tInput Id Dokter : "); scanf("%d", &IdDokter);
						
						if(FindParent(L, IdDokter) == NULL){
							printf("\n\n\tData Dokter tidak ditemukan [!]");
						} else{
							PrintParent(FindParent(L, IdDokter));
							printf("\n\n\t\t");
							PrintAllChild(FindParent(L, IdDokter));
						}
						break;
						
					case '4' :		
						printf("\n\n\t-------- [ Ubah Data Dokter ] --------");
						printf("\n\tInput Id Dokter : "); scanf("%d", &IdDokter);
						
						if(FindParent(L, IdDokter) == NULL){
							printf("\n\n\tData Dokter tidak ditemukan [!]");
						} else{
							
							AP = FindParent(L, IdDokter);
							
							do{
								printf("\n\tInput UserName [Min 4 Character]  : "); fflush(stdin); gets(UserName);
								if(strlen(UserName) < 4){
									printf("\n\t\tUserName harus memiliki minimal 4 character [!]\n");
								} else if(!isUnikUserName(L, UserName)){
									printf("\n\t\tUserName %s sudah digunakan [!]\n", UserName);
								} else{
									break;
								}
							} while(strlen(UserName) < 4 || !isUnikUserName(L, UserName));
						
							do{
								printf("\tInput Password [Min 8 Charcter]   : "); fflush(stdin); gets(Password);
								if(strlen(Password) < 8){
									printf("\n\t\tPassword harus memiliki minimal 8 character [!]\n\n");
								}
							} while(strlen(Password) < 8);
							
							do{
								printf("\n\n\tInput Id Dokter                   : "); scanf("%d", &IdDokter);
								if(!isUnik(L, IdDokter)){
									printf("\n\t\tId Dokter harus unik [!]\n\n");
								} else if(IdDokter <= 0){
									printf("\n\t\tId Dokter tidak boleh negatif atau NOL [!]");
								} else{
									break;
								}
							} while(!isUnik(L, IdDokter) || IdDokter <= 0);
							
							do{
								printf("\tInput Nama Dokter                 : "); fflush(stdin); gets(Nama);
								if(strlen(Nama) < 1 || strcmpi(Nama, "-") == 0){
									printf("\n\t\tNama Dokter tidak boleh kosong atau '-' [!]\n\n");
								}
							} while(strlen(Nama) < 1 || strcmpi(Nama, "-") == 0);
							
							do{
								printf("\tInput Tanggal Gabung [DD-MM-YYYY] : "); scanf("%s", Tanggal);
								if(strlen(Tanggal) < 10 || strlen(Tanggal) > 10){
									printf("\n\t\t\tFormat Salah [!]\n");
								} else if(Tanggal[2] != '-' || Tanggal[5] != '-'){
									printf("\n\t\t\tFormat Salah [!]\n");
								} else if(Tanggal[0] >= '3' && Tanggal[1] >= '2'){
									printf("\n\t\t\tFormat Salah [!]\n");
								} else if(Tanggal[0] == '0' && Tanggal[1] == '0'){
									printf("\n\t\tFormat Salah [!]\n");
								} else if(Tanggal[3] == '0' && Tanggal[4] == '0'){
									printf("\n\t\tFormat Salah [!]\n");
								} else if(Tanggal[3] >= '1' && Tanggal[4] >= '3'){
									printf("\n\t\tFormat Salah [!]\n");
								} else{
									break;
								}
							} while(true);
							
							AP->Dp = MakeDataParent(UserName, Password, IdDokter, Nama, Tanggal);
							
							printf("\n\n\tBerhasil Ubah Data Dokter [!]");
						}
						break;
						
					case '5' :		
						if(isEmpty(L)){
							printf("\n\n\tData Dokter masih kosong [!]");
						} else{
							printf("\n\n\t------- [ Hapus Data Dokter ] -------");
							printf("\n\tInput Id Dokter : "); scanf("%d", &IdDokter);
							
							if(FindParent(L, IdDokter) == NULL){
								printf("\n\n\tId Dokter tidak ditemukan [!]");
							} else{
						
								DeleteAtParent(&L, IdDokter);
								printf("\n\n\tBerhasil Delete Data Dokter dengan Id - %d [!]", IdDokter);
							}
						}
						break;
						
					case '6' :
						printf("\n\n\t-------- [ Pendaftaran Pemeriksaan Hewan ] --------");
						printf("\n\tInput Id Dokter yang menangani : "); scanf("%d", &IdDokter);
						
						if(FindParent(L, IdDokter) == NULL){
							printf("\n\n\tId Dokter tidak ditemukan [!]");
						} else{
							AP = FindParent(L, IdDokter);
							
							do{
								printf("\n\n\tInput Id Hewan                     : "); fflush(stdin); gets(IdHewan);
								if(strcmpi(IdHewan, "-") == 0 || strlen(IdHewan) < 1){
									printf("\n\t\tId Hewan tidak boleh kosong atau '-' [!]");
								} else if(isUnikIdHewan(L, IdHewan) != NULL){
									printf("\n\t\tId Hewan sudah digunakan [!]");
								} else{
									break;
								}
							} while(strcmpi(IdHewan, "-") == 0 || strlen(IdHewan) < 1 || isUnikIdHewan(L, IdHewan) != NULL);
							
							do{
								printf("\n\n\tInput Id Riwayat Periksa           : "); fflush(stdin); gets(IdRiwayat);
								if(strcmpi(IdRiwayat, "-") == 0 || strlen(IdRiwayat) < 1){
									printf("\n\t\tId Riwayat tidak boleh kosong atau '-' [!]");
								} else if(isUnikIdRiwayat(L, IdRiwayat) != NULL){
									printf("\n\t\tId Riwayat sudah digunakan [!]");
								} else{
									break;
								}
							} while(strcmpi(IdRiwayat, "-") == 0 || strlen(IdRiwayat) < 1);
							
							do{
								printf("\tInput Tanggal Periksa [DD-MM-YYYY] : "); scanf("%s", TanggalPeriksa);
								if(strlen(TanggalPeriksa) < 10 || strlen(TanggalPeriksa) > 10){
									printf("\n\t\t\tFormat Salah [!]\n");
								} else if(TanggalPeriksa[2] != '-' || TanggalPeriksa[5] != '-'){
									printf("\n\t\t\tFormat Salah [!]\n");
								} else if(TanggalPeriksa[0] >= '3' && TanggalPeriksa[1] >= '2'){
									printf("\n\t\t\tFormat Salah [!]\n");
								} else if(TanggalPeriksa[0] == '0' && TanggalPeriksa[1] == '0'){
									printf("\n\t\t\tFormat Salah [!]\n");
								} else if(TanggalPeriksa[3] == '0' && TanggalPeriksa[4] == '0'){
	 								printf("\n\t\t\tFormat Salah [!]\n");
								} else if(TanggalPeriksa[3] >= '1' && TanggalPeriksa[4] >= '3'){
								printf("\n\t\t\tFormat Salah [!]\n");
								} else{
									break;
								}
							} while(true);
							
							do{
								printf("\tInput Nama Hewan                   : "); fflush(stdin); gets(Nama);
								if(strcmpi(Nama, "-") == 0 || strlen(Nama) < 1){
									printf("\n\t\tNama Hewan tidak boleh kosong atau '-' [!]\n\n");
								}
							} while(strcmpi(Nama, "-") == 0 || strlen(Nama) < 1);
			
							do{
								printf("\tInput Tanggal lahir [DD-MM-YYYY]   : "); scanf("%s", Tanggal);
								if(strlen(Tanggal) < 10 || strlen(Tanggal) > 10){
									printf("\n\t\t\tFormat Salah [!]\n");
								} else if(Tanggal[2] != '-' || Tanggal[5] != '-'){
									printf("\n\t\t\tFormat Salah [!]\n");
								} else if(Tanggal[0] >= '3' && Tanggal[1] >= '2'){
									printf("\n\t\t\tFormat Salah [!]\n");
								} else if(Tanggal[0] == '0' && Tanggal[1] == '0'){
									printf("\n\t\tFormat Salah [!]\n");
								} else if(Tanggal[3] == '0' && Tanggal[4] == '0'){
									printf("\n\t\tFormat Salah [!]\n");
								} else if(Tanggal[3] >= '1' && Tanggal[4] >= '3'){
									printf("\n\t\tFormat Salah [!]\n");
								} else{
									break;
								}
							} while(true);
								
							do{
								printf("\tInput Jenis Kelamin                : "); fflush(stdin); gets(JenisKelamin);
								if(strcmpi(JenisKelamin, "Jantan") == 0 || strcmpi(JenisKelamin, "Betina") == 0){
									break;
								} else{
								printf("\n\t\tJenis Kelamin harus Jantan atau Betina [!]\n\n");
								}
							} while(strcmpi(JenisKelamin, "Jantan") != 0 || strcmpi(JenisKelamin, "Betina") != 0);
							
							do{
								printf("\tInput Jenis Hewan                  : "); fflush(stdin); gets(JenisHewan);
								if(strcmpi(JenisHewan, "Anjing") == 0 || strcmpi(JenisHewan, "Burung") == 0 || strcmpi(JenisHewan, "Kucing") == 0){
									break;
								} else{
									printf("\n\t\tJenis Hewan harus Anjing atau Burung atau Kucing [!]\n\n");
								}
							} while(strcmpi(JenisHewan, "Anjing") != 0 || strcmpi(JenisHewan, "Burung") != 0 || strcmpi(JenisHewan, "Kucing") != 0);
							
							
							if(isUnikIdHewan(Data, IdHewan) == NULL){
								InsertLastChild(&L, AP, MakeDataChild(IdHewan, Nama, Tanggal, JenisHewan, JenisKelamin, "Hidup", IdRiwayat, TanggalPeriksa, "-", "-"));
								Sorting(&L, AP);
								AP = Data.FirstParent;
								InsertLastChild(&Data, AP, MakeDataChild(IdHewan, Nama, Tanggal, JenisHewan, JenisKelamin, "Hidup", IdRiwayat, TanggalPeriksa, "-", "-"));
								Sorting(&Data, AP);
							} else{
								AC = isUnikIdHewan(Data, IdHewan);
								InsertLastChild(&L, AP, MakeDataChild(AC->Dc.IdHewan, AC->Dc.NamaHewan, AC->Dc.TanggalLahir, AC->Dc.JenisHewan, AC->Dc.JenisKelamin, "Hidup", IdRiwayat, TanggalPeriksa, "-", "-"));
								Sorting(&L, AP);
							}
	
							printf("\n\n\tBerhasil Input Pemeriksaan [!]");
						}
						break;
						
					case '7' :
						printf("\n\n\t------ [ Tampil Data Master Hewan ] ------");
						AP = Data.FirstParent;
						AC = AP->FirstChild;
						while(AC != NULL){
							PrintChild(AC);
							AC = AC->Next;
						}
						break;
						
					case '8' :
						printf("\n\n\t-------- [ Laporan Pemeriksan ] --------");
						AP = L.FirstParent;
						while(AP != NULL){
							PrintAllChild(AP);
							AP = AP->Next;
						}
						break;
						
					case 27 : 
						printf("\n\n\t[Loading........]");
						printf("\n\n\tLogOut berhasil [!]");
						break;
						
					default :
						printf("\n\n\tMenu tidak ditemukan [!]");
						break;
						
				} getch();
				
			} while(MenuAdmin != 27);
			
			
			
	//---------------------------------------------------------------------------------------		
			
			
		} else if(CekLogin(L, UserName, Password) == 2){
			
			do{
				AP = CheckDokter(L, UserName, Password);
				TampilMenuDokter(AP->Dp.NamaDokter);
				MenuDokter = getch();
				
				switch(MenuDokter){
					case '1' :
						printf("\n\n\t-------- [ Periksa Hewan ] --------");
						printf("\n\tInput Id Riwayat : "); fflush(stdin); gets(IdRiwayat);
						if(FindIdRiwayat(L, AP, IdRiwayat) == NULL){
							printf("\n\n\tId Riwayat tidak ditemukan [!]");
						} else{
							AC = FindIdRiwayat(L, AP, IdRiwayat);
							printf("\n\tId Riwayat      : %s", AC->Dc.IdRiwayat);
							printf("\n\tTanggal Periksa : %.10s", AC->Dc.TanggalPeriksa);
							
							do{
								printf("\n\tDiagnosa        : "); fflush(stdin); gets(Diagnosa);
								if(strcmpi(Diagnosa, "-") == 0 || strlen(Diagnosa) < 1){
									printf("\n\t\tDiagnosa tidak boleh kosong atau '-' [!]\n");
								}
							} while(strcmpi(Diagnosa, "-") == 0 || strlen(Diagnosa) < 1);
							
							do{
								printf("\tObat            : "); fflush(stdin); gets(Obat);
								if(strcmpi(Obat, "-") == 0 || strlen(Obat) < 1){
									printf("\n\t\tObat tidak boleh kosong atau '-' [!]\n\n");
								}
							} while(strcmpi(Obat, "-") == 0 || strlen(Obat) < 1);
							
							do{
								printf("\tStatus          : "); fflush(stdin); gets(Status);
								if(strcmpi(Status, "Mati") == 0 || strcmpi(Status, "Hidup") == 0){
									break;
								} else{
									printf("\n\t\tStatus harus 'Hidup' atau 'Mati' [!]\n\n");
								}
							} while(strcmpi(Status, "Mati") != 0 || strcmpi(Status, "Hidup") != 0);
							
							if(strcmpi(Status, "Mati") == 0){
								DeleteAtChild(&L, AP, AC);
								AP = Data.FirstParent;
								DeleteAtChild(&Data, AP, AC);
								
							} else{
								AC->Dc = MakeDataChild(AC->Dc.IdHewan, AC->Dc.NamaHewan, AC->Dc.TanggalLahir, AC->Dc.JenisHewan, AC->Dc.JenisKelamin, Status, AC->Dc.IdRiwayat, AC->Dc.TanggalPeriksa, Diagnosa, Obat);
							}
							printf("\n\n\tBerhasil Update Data Hewan [!]");
						
						}
						break;
						
					case '2' :
						printf("\n\n\t-------- [ Tampil Data Hewan ] --------");
						PrintAllChild(AP);
						break;
						
					case '3' :
						printf("\n\n\t-------- [ Laporan Dokter ] --------");
						printf("\n\tInput Id Dokter : "); scanf("%d", &IdDokter);
						if(FindParent(L, IdDokter) == NULL){
							printf("\n\n\tData Dokter tidak ditemukan [!]");
						} else{
							if(!HaveChild(FindParent(L, IdDokter))){
								printf("\n\n\tData Hewan masih kosong [!]");
							} else{
								PrintAllChild(FindParent(L, IdDokter));
							}
							
						}
						break;
						
					case 27 :
						printf("\n\n\t[Loading........]");
						printf("\n\n\tLogOut berhasil [!]");
						break;
						
					default :
						printf("\n\n\tMenu tidak ditemukan [!]");
						break;
						
				} getch();
				
				
			} while(MenuDokter != 27);
			
			
	//---------------------------------------------------------------------------------------
	
			
		} else if(CekLogin(L, UserName, Password) == 0){
			printf("\n\n\tKeluar Program......");
			
		} else{
			printf("\n\n\tUserName dan Password anda salah [!]");	
		}
		getch();
		
		
	} while(CekLogin != 0);
	
	
	
	return 0;
}
