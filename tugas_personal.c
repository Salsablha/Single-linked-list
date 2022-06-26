#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct datakaryawan {

    int nip;
    char nama[30];
    char tempat_lahir[30];
    int tanggal_lahir;
    char jabatan[50];
    struct datakaryawan *next;
}*head, *tail, *current;

void pushHead(int nip, char nama[], char tempat_lahir[], int tanggal_lahir, char jabatan[])
{
    current = (struct datakaryawan*) malloc(sizeof(struct datakaryawan));
    current->nip = nip;
    strcpy(current->nama, nama);
    strcpy(current->tempat_lahir, tempat_lahir);
    current->tanggal_lahir = tanggal_lahir;
    strcpy(current->jabatan, jabatan);

    if(head == NULL){
        head = tail = current;
    }
    else{
        current->next = head;
        head = current;
    }
}

void viewdata()
{
    current = head;
    while(current != NULL){
    printf("--------------------------\n");
    printf("NIP :%d \n", current->nip);
    printf("Nama :%s \n", current->nama);
    printf("Tempat Lahir :%s \n", current->tempat_lahir);
    printf("Tanggal Lahir :%d \n", current->tanggal_lahir);
    printf("Jabatan :%s \n", current->jabatan);
    printf("--------------------------\n");
    current = current->next;
    }
}

void hapusdata()
{
    struct node *temp;
    while(head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp);
    }
printf("Semua Data Sudah Dihapus\n");
}

int tambahdata()
{
    int jumlah, i, nip, tanggal_lahir;
    char nama[30], tempat_lahir[30], jabatan[50];
    system("clear");
    printf("Masukkan Jumlah Data : ");
    scanf("%d", &jumlah);
    if(jumlah > 5){
        printf("Data yang di masukkan maksimal 5\n");
        return 0;
    }

    else{
        for(i=1; i<=jumlah; i++){
            printf("Masukkan Data Ke %d : \n", i);
            printf("NIP : ");
            scanf("%d", &nip);

            printf("Nama : ");
            scanf("%s", &nama);
            int Nama = strlen(nama);
            if (Nama > 30){
                printf("Nama Maksimal 30 Karakter\n");
                return 0;
            }

            printf("Tempat Lahir : ");
            scanf("%s", &tempat_lahir);
            int Tempat_lahir = strlen(tempat_lahir);
            if (Tempat_lahir > 30){
                printf("Tempat Lahir Maksimal 30 Karakter\n");
                return 0;
            }

            printf("Tanggal Lahir (ddmmyyyy): ");
            scanf("%d", &tanggal_lahir);
            
            printf("Jabatan : ");
            scanf("%s", &jabatan);
            int Jabatan = strlen(jabatan);
            if (Jabatan > 50){
                printf("Jabatan Maksimal 30 Karakter");
                return 0;
            }
            printf("--------------------------\n");
    pushHead(nip, nama, tempat_lahir, tanggal_lahir, jabatan);
        }

    }
}

int main()
{
    int menu;
    begin :
    printf("--- Menu Data Karyawan ---\n");
    printf("1. Tambah Data Karyawan \n");
    printf("2. Menampilkan Data Karyawan \n");
    printf("3. Hapus Data Karyawan \n");
    printf("4. Keluar \n");
    printf("Input Nomor Menu : ");
    scanf("%d", &menu);

    switch(menu){
    case 1:
    tambahdata();
    goto begin;
    break;
    case 2:
    viewdata();
    goto begin;
    break;
    case 3:
    hapusdata();
    goto begin;
    break;
    case 4:
    printf("Selesai\n");
    goto akhir;
    default :
    printf("Pilihan tidak tersedia\n");
    break;
    }
    akhir:
    return 0;
}
