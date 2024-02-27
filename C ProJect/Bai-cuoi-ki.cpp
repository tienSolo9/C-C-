#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
#include<bits/stdc++.h>
#include<conio.h>

char Ma_nv[20][20];
int j_nv = 0;

char Ma_kh[20][20];
int j_kh = 0;

char Ma_ncc[20][20];
int j_ncc = 0;

char Ma_sp[20][20];
int j_sp = 0;

char Ma[20][20];
int j = 0;

std::map<std::string, int> sl;
float tmp[12];

void gotoxy(short x,short y){
	static HANDLE h = NULL;
	if(!h){
		h=GetStdHandle(STD_OUTPUT_HANDLE);
	}
	COORD c ={x,y};
	SetConsoleCursorPosition(h,c);
}

struct date{
	int ngay;
	int thang;
	int nam;
};
struct nhaCungCap{
	char maNcc[20];
	char tenNcc[20];
	char sdt[12];
	char diaChi[50];
};
// san pham
struct sanPham{
	char maSp[20];
	char tenSp[20];
	char maNcc[20];
	nhaCungCap ncc;
	date ngayNhap;
	float giaBan;
	float giamGia;
	int soLuong;
};
struct nodeSanPham{
	sanPham *data;
	nodeSanPham *pNext;
};
struct SingleList{
	nodeSanPham *pHead;
};
// nha cung cap

struct NodenhaCungCap{
	nhaCungCap *data;
	NodenhaCungCap *pNext;
};
struct SingleListNCC{
	NodenhaCungCap *pHead;
};
// don hang
struct SP{
	char ma[20];
	int sl;	
};

struct donHang{
	char maDh[20];
	char maKh[20];
	char maNv[20];
	SP sp[20];
	char trangThai[20];
	int tongSoLoai;
	float tongDonHang;
	date thoiGian;
	
};

struct nodeDonHang{
	donHang data;
	nodeDonHang* next;
};
// nhan vien
struct nhanVien{
	char maNv[20];
	char tenNv[20];
	date Nsinh;
	char gTinh[5];
	char chucVu[10];
	float luong;
};

struct nodeNhanVien{
	nhanVien data;
	nodeNhanVien* next;
};
// khach hang
struct khachHang{
	char maKh[20];
	char tenKh[20];
	char sdt[12];
	char diaChi[50];
};
struct NodeKhachHang{
	khachHang *data;
	NodeKhachHang *pNext;
};
struct SingleListKh{
	NodeKhachHang *pHead;
};
//
typedef struct donHang Dh;
typedef struct nodeDonHang nodeDh;
typedef struct nhanVien nv;
typedef struct nodeNhanVien nodeNv;


int isValidString(char s[]){
	if(s[0] == ' ') return 0;
	
	for(int i = 0;i<strlen(s);i++){
		if (!isalpha(s[i]) && s[i] != ' ') return 0;
	}
	return 1;
}

int isValidNumber(char s[]){
	if(s[0] == ' ') return 0;
	
	for(int i = 0;i<strlen(s);i++){
		if (!isdigit(s[i]) && s[i] != ' ') return 0;
	}
	return 1;
}
// khach hang
void Initialize(SingleListKh *&list){
	list = new SingleListKh;
	list -> pHead=NULL;
}

khachHang *nhapkhachHang(int pos){	
	int check,i;	
	khachHang *kh =new khachHang();
	do{
		check = 1,i = 0;
		printf("nhap ma: ");
		fflush(stdin);
		gets(kh->maKh);	
		if(strcmp(kh->maKh,"") == 0 || kh->maKh[0] == ' '){
			check = 0;
		}
		else{
			while(i < j_kh and strcmp(Ma_kh[i],kh->maKh) != 0){
				i++;
			}
			if(i != j_kh){
				check = 0;
			}			
		}
	}while(check == 0);
	// sao chep id hoa don hien tai vao mang
	strcpy(Ma_kh[pos],kh->maKh);
	j_kh++;
	
	do{
		printf("nhap ten: ");
		fflush(stdin);
		gets(kh->tenKh);
	}while(strcmp(kh->tenKh,"") ==0 || isValidString(kh->tenKh) == 0);
	
	do{
		printf("nhap so dien thoai: ");
		fflush(stdin);
		gets(kh->sdt);
	}while(strcmp(kh->sdt,"")==0 || isValidNumber(kh->sdt)==0);
	
	do{
		printf("nhap dia chi: ");
		fflush(stdin);
		gets(kh->diaChi);
	}while(strcmp(kh->diaChi,"")==0);
	return kh;
}


khachHang *updateKhachHang(char pos[20]){		
	khachHang *kh =new khachHang();	
	strcpy(kh->maKh, pos);
	do{
	printf("nhap ten: ");
	fflush(stdin);
	gets(kh->tenKh);
	}while(strcmp(kh->tenKh,"")==0 || isValidString(kh->tenKh) == 0);
	
	do{
	printf("nhap so dien thoai: ");
	fflush(stdin);
	gets(kh->sdt);
	}while(strcmp(kh->sdt,"")==0 ||  isValidNumber(kh->sdt)==0);
	
	do{
	printf("nhap dia chi: ");
	fflush(stdin);
	gets(kh->diaChi);
	}while(strcmp(kh->diaChi,"")==0);
	return kh;
}

//tao ra 1 node chua du lieu khach hang
NodeKhachHang *CreateNode(khachHang *kh){
	NodeKhachHang *pNode = new NodeKhachHang;
		if(pNode != NULL){
			pNode->data=kh;
			pNode->pNext = NULL;
		}
		else{
			printf("cap phat bo nho that bai");
		}
		return pNode;
}

//them node khach hang vao cuoi danh sach
void InsertLast(SingleListKh *&List,khachHang *kh){
	NodeKhachHang *pNode=CreateNode(kh);
	if(List->pHead==NULL){
		List->pHead=pNode;
	}
	else{
		NodeKhachHang *pTmp=List->pHead;
		while(pTmp->pNext != NULL){
			pTmp = pTmp->pNext;
		}
		pTmp->pNext=pNode;//them cuoi	
	}
}

int countNodes(SingleListKh *List) {
    int count = 0;
    NodeKhachHang* current = List->pHead;
    while (current != NULL) {
        count++;
        current = current->pNext;
    }
    return count;
}

void printList(SingleListKh *List){
	int count = countNodes(List);
	NodeKhachHang *pTmp = List->pHead;
	if(pTmp == NULL){
		printf("\n\nKhong co gi de them\n");
		return;
	}
	while(pTmp != NULL){
		for(int i=1;i<=count;i++){
			khachHang *kh=pTmp->data; 
			gotoxy(1,i);
			printf( "%s", kh->maKh);
			gotoxy(10,i);
			printf( "%s", kh->tenKh);
			gotoxy(30,i);
			printf("%s", kh->sdt);
			gotoxy(50,i);
			printf( "%s", kh->diaChi);
		 pTmp = pTmp -> pNext;
		}
	}	
}

//in file
void printFile(SingleListKh *List){
	FILE *fptr;
// mo file de viet
fptr = fopen("DanhSachkhachHang.txt", "w");
	NodeKhachHang *pTmp = List->pHead;
	if(pTmp == NULL){
		printf("\n\nKhong co gi de them");
		return;
	}
	while(pTmp != NULL){
			khachHang *kh=pTmp->data; 
			// in ra file
			fprintf(fptr, "%s;%s;%s;%s\n", kh->maKh,kh->tenKh,kh->sdt,kh->diaChi);
		 pTmp = pTmp -> pNext;
	}
	//dong file
	fclose(fptr);
}

void readFile(SingleListKh *&List){
FILE* rFile = fopen("DanhSachkhachHang.txt","r");
	if(rFile == NULL){
		printf("(!) Khong mo duoc file\n");
		return;
	}
	
	while(!feof(rFile)){
		khachHang *kh = new khachHang();
		fscanf(rFile,"%[^;];%[^;];%[^;];%[^\n]\n", kh->maKh,kh->tenKh,kh->sdt,kh->diaChi);	
		if(strcmp(kh->maKh,"")==0){
			printf("File khong co gi\n");
			return;
		}	
		// doc khach hang
		InsertLast(List,kh);
		// khoi tao de check Id trung
		strcpy(Ma_kh[j_kh],kh->maKh);
		j_kh++;
	}

	fclose(rFile);
}
		
		//sap xep tu be den lon
void SortList(SingleListKh *&List){
	for (NodeKhachHang *pTmp=List->pHead; pTmp!=NULL;pTmp=pTmp->pNext){
		for (NodeKhachHang *pTmp2=pTmp->pNext; pTmp2!=NULL; pTmp2=pTmp2->pNext){
		khachHang *khTmp=pTmp->data;
		khachHang *khTmp1=pTmp->data;
		khachHang *khTmp2=pTmp2->data;
		if(strcmp(khTmp2->maKh,khTmp1->maKh)<0){
			//be den lon theo ma
				khTmp = pTmp2->data;
				pTmp2->data=pTmp->data;
				pTmp->data=khTmp;
			}
		}
	}
	printf("Da sap xep...\n");
}
//tim kiem
void searchNode(SingleListKh *&List , char ma[20]){
	int i=0;
	NodeKhachHang *pSerch = List ->pHead;
	khachHang *kh = new khachHang();
	if(pSerch == NULL){
		printf("Khong co gi trong danh sach\n");
	}
	else{
		NodeKhachHang *pPre = NULL;
		while(pSerch != NULL){
			kh = pSerch->data;
			if(strcmp(kh->maKh,ma)==0){
				gotoxy(0,i);
			printf( "ID");
			gotoxy(10,i);
			printf( "TEN");
			gotoxy(30,i);
			printf("SDT");
			gotoxy(50,i);
			printf("DIACHI");
			
				
			int j=1;
			gotoxy(0,j);
			printf( "%s", kh->maKh);
			gotoxy(10,j);
			printf( "%s", kh->tenKh);
			gotoxy(30,j);
			printf("%s", kh->sdt);
			gotoxy(50,j);
			printf( "%s", kh->diaChi);
			printf("\n");	
				break;
			}
			else{
				pSerch = pSerch->pNext;
				
			}
			if(pSerch==NULL){
				printf("Khong tim thay khach hang voi id da cho\n");
			}		
		}	
	}
}
void RemoveNode(SingleListKh *&List , char ma[20]){
	NodeKhachHang *pDel = List ->pHead;
	if(pDel == NULL){
		printf("khong co gi trong danh sach\n");
	}
	else{
		NodeKhachHang *pPre = NULL;
		while(pDel != NULL){
			khachHang *kh = pDel->data;
			if(strcmp(kh->maKh,ma)==0){
				break;
			}
			pPre = pDel;
			pDel = pDel->pNext;
		}
		if(pDel==NULL){
			printf("Khong tim thay khach hang voi id da cho\n");
		}
		else{
			if(pDel==List->pHead){
				List->pHead=List->pHead->pNext;
				pDel->pNext=NULL;
				delete pDel;
				pDel =NULL;
			}
			else{
				pPre->pNext=pDel->pNext;
				pDel->pNext = NULL;
				delete pDel;
				pDel =NULL;
			}
			printf("Da xoa khach hang ma %s\n",ma);
		}
	}
}
void updateNode(SingleListKh *&List ,char ma[20]){
	int i=0;
	NodeKhachHang *pUpdate = List ->pHead;
	khachHang *kh = new khachHang();
	if(pUpdate == NULL){
		printf("Khong co gi trong danh sach\n");
	}
	else{
		while(pUpdate != NULL){
			kh = pUpdate->data;
			if(strcmp(kh->maKh,ma)==0){	
				kh = updateKhachHang(ma);
				pUpdate->data = kh;				
				break;
			}
			pUpdate = pUpdate->pNext;			
		}
		if(pUpdate==NULL){
			printf("Khong tim thay nha cung cap voi id da cho\n");
		}	
	}
}
void menuKh(SingleListKh *&list){
	int i=0;
	int choice = 1;
	do{
		system("cls");	
		printf("[QUAN LI KHACH HANG]\n\n");
		printf("+--------------------------------------------+\n");
		printf("|1.Hien thi khach hang                       |\n");
		printf("|2.Cap nhat du lieu                          |\n");
		printf("|3.sap xep khach hang theo ma                |\n"); 
		printf("|4.tim khach hang                            |\n");
		printf("|5.xoa khach hang                            |\n");
		printf("|6.Nhap du lieu moi tu ban phim              |\n");
		printf("|0.thoat                                     |\n");
		printf("+--------------------------------------------+\n");
		printf("Nhap lua chon cua ban:");
		scanf("%d",&choice);
			switch(choice) {
		  case 1: 
		  	system("cls");	 	
			gotoxy(0,i);
			printf( "ID");
			gotoxy(10,i);
			printf( "TEN");
			gotoxy(30,i);
			printf("SDT");
			gotoxy(50,i);
			printf("DIACHI");
			printList(list);
			printf("\n");
			system("pause");	
		    break;
		  case 3://sap xep 
		  	system("cls");
		    SortList(list);
		    	system("pause");
		    break;
		  case 4://tim kiem
		  	system("cls");
		  	char ma[20];
		    printf("nhap ma khach hang can tim: ");
			scanf("%s",ma);
			system("cls");
			system("cls");
			searchNode(list,ma);
				system("pause");
		    break;
		  case 5://xoa
		  	char x[20];
		  	system("cls");
		    printf("nhap ma khach hang can xoa: ");
			scanf("%s",x);
		   	RemoveNode(list,x);
		   	system("pause");
		    break;
			case 6://them tay
		   system("cls");
		    char input[10];
		  	int n;
		  	do{
		    printf("so khach hang muon them ? : ");
			scanf("%s",&input);
			}while(isValidNumber(input)==0);
			n= atoi(input);
			for(int i =0;i<n;i++){
				khachHang *kh = nhapkhachHang(j_kh);
				InsertLast (list , kh);
			}
			system("cls");
		    break;  
		    case 2:
		    system("cls");
		    printf("nhap ma khach can sua: ");
			scanf("%s",x);
		    updateNode(list,x);
		    system("pause");
		    break;		    
		    case 0://in ra file
			system("cls");
			printf("Bam phim bat ky de quay lai menu chinh\n\n");
		    system("pause");
		    break;
		}		
	}while(choice != 0);	
	
}
// nhan vien
nodeNv* CreateNode(nv x){
	nodeNv* newNv = (nodeNv*) malloc(sizeof(nodeNv));
	newNv->data = x;
	newNv->next = NULL;
	return newNv;
}
void PrintList(nodeNv* head){
	if(head == NULL){
		printf("\t\t DANH SACH RONG !!!\n");
		return;
	}
	printf("+------------------------------------------------------------------------------------+\n");
	printf("|%-12s|%-20s|%-10s|%-10s|%-15s|%-12s|\n","ID","Ho va Ten","Ngay sinh","Gioi Tinh","Chuc Vu","Luong");
	nv x;
	for(nodeNv* p = head; p != NULL; p = p->next){
		x = p->data;
		printf("|%-12s|%-20s|%-2d/%-2d/%4d|%-10s|%-15s|%-12.2f|\n",x.maNv,x.tenNv,x.Nsinh.ngay,x.Nsinh.thang,x.Nsinh.nam,x.gTinh,x.chucVu,x.luong);		
	}	
	printf("+------------------------------------------------------------------------------------+\n");
}
int countNodes(nodeNv* head){
	int cnt = 0;
	nodeNv* temp = head;
	while(temp != NULL){
		temp = temp->next;
		cnt++;
	}
	return cnt;
}
void InsertLast(nodeNv*& head,nv x){
	nodeNv* newNv = CreateNode(x);
	if(head == NULL){
		head = newNv;
		return;
	}
	nodeNv* temp = head;
	while(temp->next != NULL){
		temp = temp->next;
	}
	temp->next = newNv;
}

void RemoveNode(nodeNv*& head,char ma[]){
	if(head == NULL){
		printf("Danh sach rong");
		return;
	}
	nodeNv* pBack = head; 
	nodeNv* p = NULL;

	while(pBack!=NULL && strcmp(pBack->data.maNv,ma)!=0){
		p = pBack;
		pBack = pBack->next;
	}
	if(pBack == NULL){
		printf("Khong tim thay\n");
	}
	else{
		if(p == NULL){
			head = head->next;
		}
		else{
			p->next = pBack->next;
		}	
		delete(pBack);
		printf("Da xoa nhan vien ma %s\n",ma);
	}
}


void searchNode(nodeNv*& head){
	nv x;
	int check = 0,c;
	char tam[50];
	
	printf("1.Theo ID\n");
	printf("2.Theo ten\n");
	printf("0.Huy thao tac\n");
	printf("Chon:");scanf("%d",&c);
	
	if(c==1){
		printf("Nhap Id can tim:");
		fflush(stdin);
		gets(tam);
		for(nodeNv* p = head;p!=NULL;p=p->next){
			nv x = p->data;
			if(strstr(x.maNv,tam)!=NULL){
				printf("|%-12s|%-20s|%-2d/%-2d/%4d|%-10s|%-15s|%-12.2f|\n",x.maNv,x.tenNv,x.Nsinh.ngay,x.Nsinh.thang,x.Nsinh.nam,x.gTinh,x.chucVu,x.luong);		
				check = 1;
			}
		}
	}
	else if(c==2){
		printf("Nhap Ten can tim:");
		fflush(stdin);
		gets(tam);
		for(nodeNv* p = head;p!=NULL;p=p->next){
			nv x = p->data;
			if(strstr(x.tenNv,tam)!=NULL){
				printf("|%-12s|%-20s|%-2d/%-2d/%4d|%-10s|%-15s|%-12.2f|\n",x.maNv,x.tenNv,x.Nsinh.ngay,x.Nsinh.thang,x.Nsinh.nam,x.gTinh,x.chucVu,x.luong);		
				check = 1;
			}
		}		
	}
	else{
		return;
	}
	if(check == 0){
		printf("Khong tim thay\n");
	}
}

void SortList(nodeNv*& head){
	nv x1,x2;
	if(head == NULL){
		printf("DANH SACH RONG!!\n");
		return;
	}	
	for(nodeNv* p = head;p->next !=NULL;p=p->next){
		for(nodeNv* q = p->next;q !=NULL;q=q->next){
			x1 = p->data;
			x2 = q->data;
			if(strcmp(x1.maNv,x2.maNv) > 0){
				p->data = x2;
				q->data = x1;
			}
		}
	}
	printf("Da sap xep tang dan theo ID\n");
}

void nhapNv(nv& x,int pos){
	int check,i;

	do{
		check = 1,i = 0;
		fflush(stdin);
		printf("Nhap ID:");gets(x.maNv);	
		if(strcmp(x.maNv,"") == 0 || x.maNv[0] == ' '){
			check = 0;
		}
		else{
			while(i < j_nv and strcmp(Ma_nv[i],x.maNv) != 0){
				i++;
			}
			if(i != j_nv){
				check = 0;
			}		
		}
	}while(check == 0);
	// sao chep id hoa don hien tai vao mang
	strcpy(Ma_nv[pos],x.maNv);
	j_nv++;
	do{
		printf("Nhap Ho va Ten:");gets(x.tenNv);
	}while(isValidString(x.tenNv) == 0 || strcmp(x.tenNv,"") == 0);

	do{
		printf("Nhap Ngay Sinh:");
		scanf("%d/%d/%d",&x.Nsinh.ngay,&x.Nsinh.thang,&x.Nsinh.nam);
	}while(x.Nsinh.ngay < 1 || x.Nsinh.ngay > 31 || x.Nsinh.thang < 1 || x.Nsinh.thang > 12 || x.Nsinh.nam < 2000 || x.Nsinh.nam > 2022);
	
	do{
		fflush(stdin);
		printf("Nhap Gioi Tinh:");gets(x.gTinh);
	}while(isValidString(x.gTinh) == 0 || strcmp(x.gTinh,"") == 0);
	
	do{
		printf("Nhap Chuc Vu:");gets(x.chucVu);
	}while(isValidString(x.chucVu) == 0 || strcmp(x.chucVu,"") == 0);
	
	char input[10];
	do{
		do{	 	
			printf("Nhap Luong:");
			scanf("%s",&input);   
		}while(isValidNumber(input)==0);
		x.luong  = atoi(input);  	                                   
	}while(x.luong<0);

}
void nhapDanhsach(nodeNv*& head){
	nv x;
	int n;
	char so[10];
	do{
	printf("Nhap so luong nhan vien:");scanf("%s",&so);
	n = atoi(so);
	}while(n<0 || isValidNumber(so)==0);
	// nhap
	for(int i = 0;i<n;i++){
		nhapNv(x,j_nv);
		InsertLast(head,x);
	}
}

nv updateNv(char ma[]){
	nv x;
	strcpy(x.maNv,ma);
	
	do{
		printf("Nhap Ho va Ten:");gets(x.tenNv);
	}while(strcmp(x.tenNv,"")==0 || isValidString(x.tenNv) == 0);
	
	do{
		printf("Nhap Ngay Sinh:");
		scanf("%d/%d/%d",&x.Nsinh.ngay,&x.Nsinh.thang,&x.Nsinh.nam);
	}while(x.Nsinh.ngay < 1 || x.Nsinh.ngay > 31 || x.Nsinh.thang < 1 || x.Nsinh.thang > 12 || x.Nsinh.nam < 2000 || x.Nsinh.nam > 2022);

	do{
		fflush(stdin);
		printf("Nhap Gioi Tinh:");gets(x.gTinh);
	}while(strcmp(x.gTinh,"")==0 || isValidString(x.gTinh) == 0);
	
	do{
		printf("Nhap Chuc Vu:");gets(x.chucVu);
	}while(strcmp(x.chucVu,"")==0 || isValidString(x.chucVu) == 0);	
	
	char input[10];
	do{
		do{	 	
			printf("Nhap Luong:");
			scanf("%s",&input);   
		}while(isValidNumber(input)==0);
		x.luong  = atoi(input);  	                                   
	}while(x.luong<0);
	
	return x;
}
void updateNode(nodeNv*& head,char ma[]){
	if(head == NULL){
		printf("DANH SACH RONG!!!\n");
		return;
	}
	nodeNv* p = head;
	nv x;
	int i = 0;
	while(p!=NULL){
		if(strcmp(p->data.maNv,ma)==0){
			x = updateNv(ma);
			p->data = x;
			break;
		}
		p=p->next;
	}
	if(p==NULL){
		printf("Khong tim thay ma !!!\n");
	}
	else{
		printf("Da sua...\n");
	}	
}
void readFIleNV(nodeNv*& head){
	FILE* rFile = fopen("NhanVien.txt","r");
	if(rFile == NULL){
		printf("Khong mo duoc file\n");
		return;
	}
	nv x;
	while(!feof(rFile)){
		fscanf(rFile,"%[^;];%[^;];%d/%d/%d;%[^;];%[^;];%f\n",x.maNv,x.tenNv,&x.Nsinh.ngay,&x.Nsinh.thang,&x.Nsinh.nam,x.gTinh,x.chucVu,&x.luong);
		if(x.luong==0) return;
		InsertLast(head,x);
		// them mang de check bi sai
		strcpy(Ma_nv[j_nv],x.maNv);
		j_nv++;
	}
	fclose(rFile);
}
void PrintFile(nodeNv* head){
	FILE* oFile = fopen("NhanVien.txt","w");
	if(oFile == NULL){
		printf("Khong mo duoc file\n");
		return;
	}
	nv x;
	for(nodeNv* p = head; p != NULL; p = p->next){
		x = p->data;
		fprintf(oFile,"%s;%s;%d/%d/%d;%s;%s;%.3f\n",x.maNv,x.tenNv,x.Nsinh.ngay,x.Nsinh.thang,x.Nsinh.nam,x.gTinh,x.chucVu,x.luong);
	}
	fclose(oFile);
}

void menuNv(nodeNv*& head){
	int chon = 1;
	while(chon!=0){
		system("cls");
		printf("[QUAN LI NHAN VIEN]\n");
		printf("+-----------------------------------+\n");
		printf("|1.Hien thi                         |\n");
		printf("|2.Sap xep nhan vien                |\n");	
		printf("|3.Them                             |\n");
		printf("|4.Xoa                              |\n");
		printf("|5.Tim kiem                         |\n");
		printf("|6.Sua                              |\n");
		printf("|0.Thoat chuc nang                  |\n");
		printf("+-----------------------------------+\n");
		printf("Chon thao tac:");scanf("%d",&chon);
		
		switch(chon){		
			case 1:
				PrintList(head);
				system("pause");
				break;
			case 3:
				nv x;
				nhapDanhsach(head);	
				system("pause");
				break;			
			case 4:
				char tmp[20];
				fflush(stdin);
				printf("Nhap Ma can xoa:");gets(tmp);
				RemoveNode(head,tmp);
				system("pause");
				break;
			case 5:
				searchNode(head);
				system("pause");
				break;	
			case 6:
				printf("Nhap ma can sua:");
				char m[20];
				fflush(stdin);
				gets(tmp);
				updateNode(head,tmp);
				system("pause");
				break;	
			case 2:
				SortList(head);
				system("pause");
				break;
			default:
				chon = 0;
				system("cls");
				printf("Bam phim bat ky de quay lai menu chinh\n\n");
				system("pause");
		}
	}
}
// san pham
void Initialize(SingleList *&list){
	list = new SingleList;
	list -> pHead=NULL;
}

sanPham *nhapSanPham(SingleListNCC* list,int pos){	

	sanPham *sp = new sanPham();
	
	int check,i;
	do{
		check = 1,i = 0;
		printf("nhap ma: ");
		fflush(stdin);
		gets(sp->maSp);	
		if(strcmp(sp->maSp,"") == 0 || sp->maSp[0] == ' '){
			check = 0;
		}
		else{
			while(i < j_sp and strcmp(Ma_sp[i],sp->maSp) != 0){
				i++;
			}
			if(i != j_sp){
				check = 0;
			}			
		}
	}while(check == 0);
	// sao chep id hoa don hien tai vao mang
	strcpy(Ma_sp[pos],sp->maSp);
	j_sp++;	
	
	do{
	printf("nhap ten: ");
	fflush(stdin);
	gets(sp->tenSp);
	}while(strcmp(sp->tenSp,"")==0 || isValidString(sp->tenSp) == 0);
	

	NodenhaCungCap* p;
	do{
		p = list->pHead;
		check = 1;
		
		printf("nhap ma nha cung cap: ");
		fflush(stdin);
		gets(sp->maNcc);
		
		while(p!= NULL and strcmp(p->data->maNcc,sp->maNcc) != 0){
			p = p->pNext;
		}
		if(p == NULL){
			check = 0;
		}			
	}while(check == 0);
	char day[10],month[10],year[10];
	do{	
	printf("nhap ngay nhap: ");
	fflush(stdin);
	scanf("%s",&day);
	sp->ngayNhap.ngay = atoi(day);
	}while(sp->ngayNhap.ngay<=0 || sp->ngayNhap.ngay>31 || isValidNumber(day)==0);
	
	do{
	printf("nhap thang nhap: ");
	fflush(stdin);
	scanf("%s",&month);
	sp->ngayNhap.thang = atoi(month);
	}while(sp->ngayNhap.thang<=0 || sp->ngayNhap.thang>12|| isValidNumber(month)==0);
	
	do{
	printf("nhap nam nhap: ");
	fflush(stdin);
	scanf("%s",&year);
	sp->ngayNhap.nam = atoi(year);
	}while(sp->ngayNhap.nam<0 || isValidNumber(year)==0);
	
	char gia[20],giam[20],soluong[20];
	 
	do{
	printf("nhap don gia: ");
	scanf("%s",&gia);
	sp->giaBan = atof(gia);
	}while(gia<=0 || isValidNumber(gia)==0);
	
	do{
	printf("Uu dai : ");
	scanf("%s",&giam);
	sp->giamGia=atof(giam);
	}while(giam<0 || sp->giaBan<sp->giamGia || isValidNumber(giam)==0);
	
	
	do{
	printf("nhap so luong trong kho: ");
	scanf("%s",&soluong);
	sp->soLuong = atoi(soluong);	
	}while(soluong<0 || isValidNumber(soluong)==0);
	
	return sp;
}

sanPham *updateSanPham(SingleListNCC* list,char pos[20]){	
int check,i;
	sanPham *sp =new sanPham();
	strcpy(sp->maSp,pos);
	do{
	printf("nhap ten: ");
	fflush(stdin);
	gets(sp->tenSp);
	}while(strcmp(sp->tenSp,"")==0 || isValidString(sp->tenSp) == 0);
	

	NodenhaCungCap* p;
	do{
		p = list->pHead;
		check = 1;
		
		printf("nhap ma nha cung cap: ");
		fflush(stdin);
		gets(sp->maNcc);
		
		while(p!= NULL and strcmp(p->data->maNcc,sp->maNcc) != 0){
			p = p->pNext;
		}
		if(p == NULL){
			check = 0;
		}			
	}while(check == 0);
	char day[10],month[10],year[10];
	do{	
	printf("nhap ngay nhap: ");
	fflush(stdin);
	scanf("%s",&day);
	sp->ngayNhap.ngay = atoi(day);
	}while(sp->ngayNhap.ngay<=0 || sp->ngayNhap.ngay>31 || isValidNumber(day)==0);
	
	do{
	printf("nhap thang nhap: ");
	fflush(stdin);
	scanf("%s",&month);
	sp->ngayNhap.thang = atoi(month);
	}while(sp->ngayNhap.thang<=0 || sp->ngayNhap.thang>12|| isValidNumber(month)==0);
	
	do{
	printf("nhap nam nhap: ");
	fflush(stdin);
	scanf("%s",&year);
	sp->ngayNhap.nam = atoi(year);
	}while(sp->ngayNhap.nam<0 || isValidNumber(year)==0);
	
	char gia[20],giam[20],soluong[20];
	 
	do{
	printf("nhap don gia: ");
	scanf("%s",&gia);
	sp->giaBan = atof(gia);
	}while(gia<=0 || isValidNumber(gia)==0);
	
	do{
	printf("Uu dai : ");
	scanf("%s",&giam);
	sp->giamGia=atof(giam);
	}while(giam<0 || sp->giaBan<sp->giamGia || isValidNumber(giam)==0);
	
	
	do{
	printf("nhap so luong trong kho: ");
	scanf("%s",&soluong);
	sp->soLuong = atoi(soluong);	
	}while(soluong<0 || isValidNumber(soluong)==0);
	
	return sp;
}

nodeSanPham *CreateNode(sanPham *sp){
	nodeSanPham *pNode = new nodeSanPham;
		if(pNode != NULL){
			pNode->data=sp;
			pNode->pNext = NULL;
		}
		else{
			printf("cap phat bo nho that bai");
		}
		return pNode;
}

//them node san pham vao cuoi danh sach
void InsertLast(SingleList *&List,sanPham *sp){
	nodeSanPham *pNode=CreateNode(sp);
	if(List->pHead==NULL){
		List->pHead=pNode;
	}
	else{
		nodeSanPham *pTmp=List->pHead;
		while(pTmp->pNext != NULL){
			pTmp = pTmp->pNext;
		}
		pTmp->pNext=pNode;//them cuoi
	}
}


//in file
void printFile(SingleList *List){
	FILE *fptr;
// mo file de viet
	fptr = fopen("DanhSachSanPham.txt", "w");
	nodeSanPham *pTmp = List->pHead;
	if(pTmp == NULL){
		printf("\n\nKhong co gi de them");
		return;
	}
	while(pTmp != NULL){
			sanPham *sp=pTmp->data; 
			// in ra file
			fprintf(fptr, "%s;%s;%s;%d;%d;%d;%.2f;%.2f;%d\n", sp->maSp,sp->tenSp,sp->maNcc,sp->ngayNhap.ngay,sp->ngayNhap.thang,sp->ngayNhap.nam,sp->giaBan,sp->giamGia,sp->soLuong);
		 pTmp = pTmp -> pNext;
	}
	//dong file
	fclose(fptr);
}

void readFileSP(SingleList *&List){
	FILE* rFile = fopen("DanhSachSanPham.txt","r");
	if(rFile == NULL){
		printf("(!) Khong mo duoc file\n");
		return;
	}

	while(!feof(rFile)){
		sanPham *sp = new sanPham();
		fscanf(rFile,"%[^;];%[^;];%[^;];%d;%d;%d;%f;%f;%d\n",sp->maSp,sp->tenSp,sp->maNcc,&sp->ngayNhap.ngay,&sp->ngayNhap.thang,&sp->ngayNhap.nam,&sp->giaBan,&sp->giamGia,&sp->soLuong);		
		if(strcmp(sp->maSp,"")==0){
			printf("File khong co gi\n");
			return;
		}	
		InsertLast(List,sp);
		// khoi tao de them khong bi trung ID
		strcpy(Ma_sp[j_sp],sp->maSp);
		j_sp++;
	}
	fclose(rFile);
}	
NodenhaCungCap *CreateNodeNCC(nhaCungCap *ncc){
	NodenhaCungCap *pNode = new NodenhaCungCap;
		if(pNode != NULL){
			pNode->data=ncc;
			pNode->pNext = NULL;
		}
		else{
			printf("cap phat bo nho that bai");
		}
		return pNode;
}

		
//be den lon theo gia
void SortList(SingleList *&List){
	for (nodeSanPham *pTmp=List->pHead; pTmp!=NULL;pTmp=pTmp->pNext){
		for (nodeSanPham *pTmp2=pTmp->pNext; pTmp2!=NULL; pTmp2=pTmp2->pNext){
		sanPham *spTmp=pTmp->data;
		sanPham *spTmp1=pTmp->data;
		sanPham *spTmp2=pTmp2->data;
		if(spTmp2->giaBan < spTmp1->giaBan){
			
				spTmp = pTmp2->data;
				pTmp2->data=pTmp->data;
				pTmp->data=spTmp;
			}
		}
	}
	printf("Da sap xep...\n");
}

void searchNode(SingleList *&List , SingleListNCC *&ListNCC,char ma[20]){
	int i=0;
	nodeSanPham *pSerch = List ->pHead;
	sanPham *sp = new sanPham();
	if(pSerch == NULL){
		printf("Khong co gi trong danh sach\n");
	}
	else{
		nodeSanPham *pPre = NULL;
		while(pSerch != NULL){
			sp = pSerch->data;
			if(strcmp(sp->maSp,ma)==0){
			gotoxy(0,i);
			printf( "ID");
			gotoxy(10,i);
			printf( "TEN");
			gotoxy(30,i);
			printf("NCC");
			gotoxy(40,i);
			printf("Ten NCC");
			gotoxy(60,i);
			printf("NGAYNHAP");
			gotoxy(80,i);
			printf("GIABAN");
			gotoxy(95,i);
			printf("GIAMGIA");
			gotoxy(110,i);
			printf("SOLUONG");
				
			int j=1;
		// in ra file
			gotoxy(0,j);
			printf( "%s", sp->maSp);
			gotoxy(10,j);
			printf( "%s", sp->tenSp);
			gotoxy(30,j);
			printf("%s", sp->maNcc);
			gotoxy(40,j);
			for (NodenhaCungCap *pTmpNCC = ListNCC->pHead; pTmpNCC != NULL;pTmpNCC = pTmpNCC -> pNext){
				nhaCungCap *NCC=pTmpNCC->data; 
				if(strcmp(NCC->maNcc,sp->maNcc)==0){
					printf("%s", NCC->tenNcc);
					break;
				}				
			}			
			gotoxy(60,j);
			printf( "%d/%d/%d", sp->ngayNhap.ngay,sp->ngayNhap.thang,sp->ngayNhap.nam);
			gotoxy(80,j);
			printf("%.2f", sp->giaBan);
			gotoxy(95,j);
			printf("%.2f", sp->giamGia);
			gotoxy(110,j);
			printf("%d\n", sp->soLuong);
				break;
			}
			else{
				pSerch = pSerch->pNext;
				
			}
			if(pSerch==NULL){
				printf("Khong tim thay san pham voi id da cho\n");
			}
			
		}
		
	}
}

void RemoveNode(SingleList *&List , char ma[20]){
	nodeSanPham *pDel = List ->pHead;
	if(pDel == NULL){
		printf("khong co gi trong danh sach\n");
	}
	else{
		nodeSanPham *pPre = NULL;
		while(pDel != NULL){
			sanPham *sp = pDel->data;
			if(strcmp(sp->maSp,ma)==0){
				break;
			}
			pPre = pDel;
			pDel = pDel->pNext;
		}
		if(pDel==NULL){
			printf("Khong tim thay san pham voi id da cho\n");
		}
		else{
			if(pDel==List->pHead){
				List->pHead=List->pHead->pNext;
				pDel->pNext=NULL;
				delete pDel;
				pDel =NULL;
			}
			else{
				pPre->pNext=pDel->pNext;
				pDel->pNext = NULL;
				delete pDel;
				pDel =NULL;
			}
			printf("Da xoa san pham ma %s\n",ma);
		}
	}
}
int countNodes(SingleList *List) {
    int count = 0;
    nodeSanPham* current = List->pHead;
    while (current != NULL) {
        count++;
        current = current->pNext;
    }
    return count;
}
void printList(SingleList *List,SingleListNCC *ListNCC){
	int count = countNodes(List);
	nodeSanPham *pTmp = List->pHead;
	
	if(pTmp == NULL){
		printf("\n\nKhong co gi de them\n");
		return;
	}
	while(pTmp != NULL ){
		for(int i=1;i<=count;i++){
			sanPham *sp=pTmp->data; 
			// in ra file
			gotoxy(0,i);
			printf( "%s", sp->maSp);
			gotoxy(10,i);
			printf( "%s", sp->tenSp);
			gotoxy(30,i);
			printf("%s", sp->maNcc);
			gotoxy(40,i);
			for (NodenhaCungCap *pTmpNCC = ListNCC->pHead; pTmpNCC != NULL;pTmpNCC = pTmpNCC -> pNext){
				nhaCungCap *NCC=pTmpNCC->data; 
				if(strcmp(NCC->maNcc,sp->maNcc)==0){
					printf("%s", NCC->tenNcc);
					break;
				}
				
			}
					
			gotoxy(60,i);
			printf( "%d/%d/%d", sp->ngayNhap.ngay,sp->ngayNhap.thang,sp->ngayNhap.nam);
			gotoxy(80,i);
			printf("%.2f", sp->giaBan);
			gotoxy(95,i);
			printf(" %.2f", sp->giamGia);
			gotoxy(110,i);
			printf("%d", sp->soLuong);
		 pTmp = pTmp -> pNext;
		}
	}	
}

void updateNode(SingleList *&List ,SingleListNCC* ListNCC,char ma[20]){
	int i =0;
	nodeSanPham *pUpdate = List ->pHead;
	sanPham *sp = new sanPham();
	if(pUpdate == NULL){
		printf("Khong co gi trong danh sach\n");
	}
	else{
		while(pUpdate != NULL){
			sp = pUpdate->data;
			if(strcmp(sp->maSp,ma)==0){			
				sp = updateSanPham(ListNCC,ma);
				pUpdate->data = sp;				
				break;
			}
			pUpdate = pUpdate->pNext;			
		}
		if(pUpdate==NULL){
			printf("Khong tim thay nha cung cap voi id da cho\n");
		}
		else{
			printf("Da sua...\n");
		}	
	}
}

void menuSp(SingleList *&list,SingleListNCC *&listNCC){
	int choice = 1,i = 0;
	do{
		printf("[QUAN LI SAN PHAM]\n\n");
		printf("+--------------------------------------------+\n");
		printf("|1.Hien thi san pham                         |\n");
		printf("|2.Cap nhat du lieu san pham                 |\n");
		printf("|3.sap xep san pham theo ma                  |\n"); 
		printf("|4.tim san pham                              |\n");
		printf("|5.xoa san pham                              |\n");
		printf("|6.Nhap du lieu moi tu ban phim              |\n");
		printf("|0.thoat                                     |\n");
		printf("+--------------------------------------------+\n");
		printf("Nhap lua chon cua ban:");
		scanf("%d",&choice);
	  	int n;
	  	switch(choice) {
		  case 1: //them san pham
		  	system("cls");	
			gotoxy(0,i);
			printf( "ID");
			gotoxy(10,i);
			printf( "TEN");
			gotoxy(30,i);
			printf("NCC");
			gotoxy(40,i);
			printf("Ten NCC");
			gotoxy(60,i);
			printf("NGAYNHAP");
			gotoxy(80,i);
			printf("GIABAN");
			gotoxy(95,i);
			printf("GIAMGIA");
			gotoxy(110,i);
			printf("SOLUONG");
			printList(list,listNCC);
			printf("\n");
			system("pause");	
		    break;
		  case 3://sap xep 
		  	system("cls");
		    SortList(list);
		    system("pause");
		    break;
		  case 4://tim kiem
		  	system("cls");
		  	char ma[20];
		    printf("nhap ma san pham can tim: ");
			scanf("%s",ma);
			system("cls");
			searchNode(list,listNCC,ma);
				system("pause");
		    break;
		  case 5://xoa
		  	char x[20];
		  	system("cls");
		    printf("nhap ma san pham can xoa: ");
			scanf("%s",x);
		   	RemoveNode(list,x);
		   	system("pause");
		    break; 
			case 6:
		   system("cls");
		  	int n;
		    printf("so san pham muon them ? : ");
			scanf("%d",&n);
			for(int i =0;i<n;i++){
				sanPham *sp = nhapSanPham(listNCC,j_sp);
				InsertLast (list , sp);
			}
			system("cls");
			break;
			case 2:
			system("cls");
			printf("nhap ma san pham can sua: ");
			scanf("%s",x);
			updateNode(list,listNCC,x);
			system("pause");
			break;		
		    case 0://in ra file
			system("cls");
			printf("Bam phim bat ky de quay lai menu chinh\n\n");
		    system("pause");
		    break;
		}
		system("cls");
	}while(choice != 0);	
}

// nha cung cap
void Initialize(SingleListNCC *&list){
	list = new SingleListNCC;
	list -> pHead=NULL;
}
void InsertLastNCC(SingleListNCC *&List,nhaCungCap *ncc){
	NodenhaCungCap *pNode=CreateNodeNCC(ncc);
	if(List->pHead==NULL){
		List->pHead=pNode;
	}
	else{
		NodenhaCungCap *pTmp=List->pHead;
		while(pTmp->pNext != NULL){
			pTmp = pTmp->pNext;
		}
		pTmp->pNext=pNode;//them cuoi
	}
}

nhaCungCap *nhapnhaCungCap(int pos){	
	nhaCungCap *ncc =new nhaCungCap();
	int check,i;
	do{
		check = 1, i = 0;
		fflush(stdin);		
		printf("nhap ma: ");
		gets(ncc->maNcc);
		if(strcmp(ncc->maNcc,"")==0 || ncc->maNcc[0] == ' '){
			check = 0;
		}
		else{
			while(i < j_ncc and strcmp(Ma_ncc[i],ncc->maNcc) != 0){
				i++;
			}
			if(i != j_ncc){
				check = 0;
			}
		}	
	}while(check == 0);
	// sao chep id hien tai vao mang
	strcpy(Ma_ncc[pos],ncc->maNcc);
	j_ncc++;	
	
	do{
	printf("nhap ten: ");
	fflush(stdin);
	gets(ncc->tenNcc);
	}while(strcmp(ncc->tenNcc,"") == 0 || isValidString(ncc->tenNcc) == 0);
	
	do{
	printf("nhap so dien thoai: ");
	fflush(stdin);
	gets(ncc->sdt);
	}while(strcmp(ncc->sdt,"")==0 || isValidNumber(ncc->sdt)==0);
	
	do{
	printf("nhap dia chi: ");
	fflush(stdin);
	gets(ncc->diaChi);
	}while(strcmp(ncc->diaChi,"")==0 || isValidString(ncc->diaChi)==0);
	return ncc;
}

nhaCungCap *UpdateNhaCungCap(char pos[20]){	
	nhaCungCap *ncc =new nhaCungCap();
	strcpy(ncc->maNcc,pos);
	
	do{
	printf("nhap ten: ");
	fflush(stdin);
	gets(ncc->tenNcc);
	}while(strcmp(ncc->tenNcc,"")==0 || isValidString(ncc->tenNcc) == 0);
	
	do{
	printf("nhap so dien thoai: ");
	fflush(stdin);
	gets(ncc->sdt);
	}while(strcmp(ncc->sdt,"")==0 || isValidNumber(ncc->sdt)==0) ;
	
	do{
	printf("nhap dia chi: ");
	fflush(stdin);
	gets(ncc->diaChi);
	}while(strcmp(ncc->diaChi,"")==0);
	return ncc;
}

NodenhaCungCap *CreateNode(nhaCungCap *ncc){
	NodenhaCungCap *pNode = new NodenhaCungCap;
		if(pNode != NULL){
			pNode->data=ncc;
			pNode->pNext = NULL;
		}
		else{
			printf("cap phat bo nho that bai");
		}
		return pNode;
}
void InsertLast(SingleListNCC *&List,nhaCungCap *ncc){
	NodenhaCungCap *pNode=CreateNode(ncc);
	if(List->pHead==NULL){
		List->pHead=pNode;
	}
	else{
		NodenhaCungCap *pTmp=List->pHead;
		while(pTmp->pNext != NULL){
			pTmp = pTmp->pNext;
		}
		pTmp->pNext=pNode;//them cuoi
	}
}

int countNodes(SingleListNCC *List) {
    int count = 0;
    NodenhaCungCap* current = List->pHead;
    while (current != NULL) {
        count++;
        current = current->pNext;
    }
    return count;
}
void printList(SingleListNCC *List){
	int count = countNodes(List);
	NodenhaCungCap *pTmp = List->pHead;
	if(pTmp == NULL){
		printf("\n-khong co gi de them\n");
		return;
	}
	while(pTmp != NULL){
		for(int i=1;i<=count;i++){
			nhaCungCap *ncc=pTmp->data; 
			// in ra file
			gotoxy(1,i);
			printf( "%s", ncc->maNcc);
			gotoxy(10,i);
			printf( "%s", ncc->tenNcc);
			gotoxy(30,i);
			printf("%s", ncc->sdt);
			gotoxy(50,i);
			printf( "%s", ncc->diaChi);
		 pTmp = pTmp -> pNext;
		}
	}	
}
void printFile(SingleListNCC *List){
	FILE *fptr;
// mo file de viet
fptr = fopen("DanhSachnhaCungCap.txt", "w");
	NodenhaCungCap *pTmp = List->pHead;
	if(pTmp == NULL){
		printf("\n-khong co gi de them");
		return;
	}
	while(pTmp != NULL){
			nhaCungCap *ncc=pTmp->data; 
			// in ra file
			fprintf(fptr, "%s;%s;%s;%s\n", ncc->maNcc,ncc->tenNcc,ncc->sdt,ncc->diaChi);
		 pTmp = pTmp -> pNext;
	}
	//dong file
	fclose(fptr);
}
void readFileNCC(SingleListNCC *&List){
FILE* rFile = fopen("DanhSachnhaCungCap.txt","r");
	if(rFile == NULL){
		printf("(!) -khong mo duoc file\n");
		return;
	}
	
	while(!feof(rFile)){
		nhaCungCap *ncc = new nhaCungCap();
		fscanf(rFile,"%[^;];%[^;];%[^;\n];%[^;\n]\n", ncc->maNcc,ncc->tenNcc,ncc->sdt,ncc->diaChi);	
		if(strcmp(ncc->maNcc,"")==0){
			printf("file trong\n");
			return;
		}	
		// doc nha cung cap
		InsertLast(List,ncc);
		// khoi tao de them khong bi trung ID
		strcpy(Ma_ncc[j_ncc],ncc->maNcc);
		j_ncc++;
	}	
	fclose(rFile);
}

void SortList(SingleListNCC *&List){
	for (NodenhaCungCap *pTmp=List->pHead; pTmp!=NULL;pTmp=pTmp->pNext){
		for (NodenhaCungCap *pTmp2=pTmp->pNext; pTmp2!=NULL; pTmp2=pTmp2->pNext){
		nhaCungCap *nccTmp=pTmp->data;
		nhaCungCap *nccTmp1=pTmp->data;
		nhaCungCap *nccTmp2=pTmp2->data;
		if(strcmp(nccTmp2->maNcc,nccTmp1->maNcc)<0){
			//be den lon theo ma
				nccTmp = pTmp2->data;
				pTmp2->data=pTmp->data;
				pTmp->data=nccTmp;
			}
		}
	}
	printf("Da sap xep...\n");
}
void searchNode(SingleListNCC *&List , char ma[20]){
	int i=0;
	NodenhaCungCap *pSerch = List ->pHead;
	nhaCungCap *ncc = new nhaCungCap();
	if(pSerch == NULL){
		printf("-khong co gi trong danh sach\n");
	}
	else{
		NodenhaCungCap *pPre = NULL;
		while(pSerch != NULL){
			ncc = pSerch->data;
			if(strcmp(ncc->maNcc,ma)==0){
			gotoxy(0,i);
			printf( "ID");
			gotoxy(10,i);
			printf( "TEN");
			gotoxy(30,i);
			printf("SDT");
			gotoxy(50,i);
			printf("DIACHI");
				
			int j=1;
			gotoxy(0,j);
			printf( "%s", ncc->maNcc);
			gotoxy(10,j);
			printf( "%s", ncc->tenNcc);
			gotoxy(30,j);
			printf("%s", ncc->sdt);
			gotoxy(50,j);
			printf( "%s", ncc->diaChi);
			printf("\n");	
				break;
			}
			else{
				pSerch = pSerch->pNext;
				
			}
			if(pSerch==NULL){
				printf("-khong tim thay nha cung cap voi id da cho\n");
			}	
		}
	}
}
void RemoveNode(SingleListNCC *&List , char ma[20]){
	NodenhaCungCap *pDel = List ->pHead;
	if(pDel == NULL){
		printf("khong co gi co danh sach\n");
	}
	else{
		NodenhaCungCap *pPre = NULL;
		while(pDel != NULL){
			nhaCungCap *ncc = pDel->data;
			if(strcmp(ncc->maNcc,ma)==0){
				break;
			}
			pPre = pDel;
			pDel = pDel->pNext;
		}
		if(pDel==NULL){
			printf("khong tim thay nha cung cap voi id da cho\n");
		}
		else{
			if(pDel==List->pHead){
				List->pHead=List->pHead->pNext;
				pDel->pNext=NULL;
				delete pDel;
				pDel =NULL;
			}
			else{
				pPre->pNext=pDel->pNext;
				pDel->pNext = NULL;
				delete pDel;
				pDel =NULL;
			}
			printf("Da xoa nha cung cap ma %s\n",ma);
		}
		
	}
}
void updateNode(SingleListNCC *&List ,char ma[20]){
	int i =0;
	NodenhaCungCap *pUpdate = List ->pHead;
	nhaCungCap *ncc = new nhaCungCap();
	if(pUpdate == NULL){
		printf("Khong co gi trong danh sach\n");
	}
	else{
		while(pUpdate != NULL){
			ncc =pUpdate->data;
			if(strcmp(ncc->maNcc,ma)==0){
				ncc = UpdateNhaCungCap(ma);
				pUpdate->data = ncc;				
				break;
			}
			else{
			pUpdate = pUpdate->pNext;	
			}
		}
		if(pUpdate==NULL){
			printf("Khong tim thay nha cung cap voi id da cho\n");
		}	
		else{
			printf("Da sua...\n");
		}
	}
}
void menuNCC(SingleListNCC *list){
	int i=0,choice = 1;
	do{
		system("cls");
		printf("[QUAN LI NHA CUNG CAP]\n\n");	
		printf("+--------------------------------------------+\n");
		printf("|1.Hien thi cac nha cung cap                 |\n");
		printf("|2.Cap nhat thong tin nha cung cap           |\n");
		printf("|3.sap xep nha cung cap theo ma              |\n"); 
		printf("|4.tim nha cung cap                          |\n");
		printf("|5.xoa nha cung cap                          |\n");
		printf("|6.Nhap du lieu moi tu ban phim              |\n");
		printf("|0.thoat                                     |\n");
		printf("+--------------------------------------------+\n");
		printf("Nhap lua chon cua ban:");
		scanf("%d",&choice);
			switch(choice) {
	  		case 1:
	  			system("cls");	
				gotoxy(0,i);
				printf( "ID");
				gotoxy(10,i);
				printf( "TEN");
				gotoxy(30,i);
				printf("SDT");
				gotoxy(50,i);
				printf("DIACHI");
				printList(list);
				printf("\n");
				system("pause");	
	    		break;
		  	case 3:
			  	system("cls");
			    SortList(list);
			    system("pause");
		    	break;
		  	case 4://tim kiem
			  	system("cls");
			  	char ma[20];
			    printf("nhap ma nha cung cap can tim: ");
				scanf("%s",ma);
				system("cls");
				system("cls");
				searchNode(list,ma);
				system("pause");
		 	   break;
		 	case 5://xoa
			  	char x[20];
			  	system("cls");
			    printf("nhap ma nha cung cap can xoa: ");
				scanf("%s",x);
			   	RemoveNode(list,x);
			   	system("pause");
			    break; 
			case 6:
			   	system("cls");
			  	int n;
			    printf("so nha cung cap muon them ? : ");
				scanf("%d",&n);
				for(int i =0;i<n;i++){
					nhaCungCap *ncc = nhapnhaCungCap(j_ncc);
					InsertLast (list , ncc);
				}
				system("cls");
			    break; 
		    case 2:
			    system("cls");
			    printf("nhap ma nha cung cap can sua: ");
				scanf("%s",x);
			    updateNode(list,x);
			    system("pause");
			    break;		
			case 0:
				system("cls");
				printf("Bam phim bat ky de quay lai menu chinh\n\n");
				system("pause"); 
				break;
		}	
	}while(choice != 0);	
}

// don hang
nodeDh* createNode(Dh x){
	nodeDh* newDh = new nodeDh();
	newDh->data = x;
	newDh->next = NULL;
	return newDh;
}
sanPham* layTT(SingleList *List,SP& x){
	nodeSanPham* p = List->pHead;
	while(p!=NULL){
		if(strcmp(p->data->maSp,x.ma)==0){
			return p->data;
		}
		p=p->pNext;
	}
	return NULL;
}
void PrintLine(Dh x,SingleList* List){
	printf("|%-12s|%-13s|%-13s|%-2d/%-2d/%-4d|%-20s|",x.maDh,x.maKh,x.maNv,x.thoiGian.ngay,x.thoiGian.thang,x.thoiGian.nam,x.trangThai);	
	for(int i = 0;i<x.tongSoLoai;i++){
		// lay tt san pham
		sanPham* thongTin = layTT(List,x.sp[i]);
		float thanhTien = float (thongTin->giaBan - thongTin->giamGia) * x.sp[i].sl;
		if(thongTin!=NULL){
			printf("%-12s|%-12s|%-10.2f|%-10.2f|%-5d|%-12.2f|\n",thongTin->maSp,thongTin->tenSp,thongTin->giaBan,thongTin->giamGia,x.sp[i].sl,thanhTien);
			if(i==x.tongSoLoai-1) break;
			printf("|%13s%14s%14s%11s%21s","|","|","|","|","|");			
		}
	}
	printf("|-------------------------------------------------------------------------------------------------------------------------------------------|\n");
	printf("|%-72s|%54s%-12.2f|\n","Tong Tien","|",x.tongDonHang);
}

void PrintList(nodeDh* head,SingleList* List){
	if(head == NULL){
		printf("\t\t DANH SACH RONG !!!\n");
		return;
	}
	printf("						   DANH SACH DON HANG\n");
	printf("|-------------------------------------------------------------------------------------------------------------------------------------------|\n");
		printf("|%-12s|%-13s|%-13s|%-10s|%-20s|%-12s|%-12s|%-10s|%-10s|%-5s|%-12s|\n"
			,"Ma don","Ma khach hang","Ma nhan vien","Thoi Gian","Trang Thai","Ma sp","Ten sp","Gia","Giam Gia","SL","Thanh Tien");	
	Dh x;
	for(nodeDh* p = head; p != NULL; p = p->next){
		x = p->data;
		PrintLine(x,List);
		printf("|-------------------------------------------------------------------------------------------------------------------------------------------|\n");
	}	
}


int countNodes(nodeDh* head){
	int cnt = 0;
	nodeDh* temp = head;
	while(temp != NULL){
		temp = temp->next;
		cnt++;
	}
	return cnt;
}
void InsertLast(nodeDh*& head,Dh x){
	nodeDh* newDh = createNode(x); 
	if(head == NULL){
		head = newDh;
		return;
	}
	nodeDh* temp = head;
	while(temp->next != NULL){
		temp = temp->next;
	}
	temp->next = newDh;
}

void RemoveNode(nodeDh*& head,char ma[]){
	if(head == NULL){
		printf("Danh sach rong");
		return;
	}
	nodeDh* pBack = head; 
	nodeDh* p = NULL;

	while(pBack!=NULL && strcmp(pBack->data.maDh,ma)!=0){
		p = pBack;
		pBack = pBack->next;
	}
	if(pBack == NULL){
		printf("Khong tim thay\n");
	}
	else{
		if(p == NULL){
			head = head->next;
			delete(pBack);
		}
		else{
			p->next = pBack->next;
			delete(pBack);
		}	
		printf("Da xoa don hang ma %s\n",ma);
	}
}

void searchNode(nodeDh*& head,SingleList* List){
	Dh x;
	int check = 0,c;
	char tam[50];
	
	printf("1.Theo ID hoa don\n");
	printf("2.Theo Id khach hang\n");
	printf("0.Huy thao tac\n");
	printf("Chon:");scanf("%d",&c);
	
	if(c==1){
		printf("Nhap Id tim:");
		fflush(stdin);
		gets(tam);
		printf("|-------------------------------------------------------------------------------------------------------------------------------------------|\n");
		printf("|%-12s|%-13s|%-13s|%-10s|%-20s|%-12s|%-12s|%-10s|%-10s|%-5s|%-12s|\n"
			,"Ma don","Ma khach hang","Ma nhan vien","Thoi Gian","Trang Thai","Ma sp","Ten sp","Gia","Giam Gia","SL","Thanh Tien");	
		for(nodeDh* p = head;p!=NULL;p=p->next){
			x = p->data;
			if(strstr(x.maDh,tam)!=NULL){
				PrintLine(x,List);
				printf("|-------------------------------------------------------------------------------------------------------------------------------------------|\n");
			check = 1;
			}
		}
	}
	else if(c==2){
		printf("-Nhap ID khach hang can tim:");
		fflush(stdin);
		gets(tam);
		printf("|------------------------------------------------------------------------------------------------------------------------------------|\n");
		printf("|%-12s|%-13s|%-13s|%-10s|%-20s|%-12s|%-12s|%-10s|%-10s|%-5s|%-12s|\n"
			,"Ma don","Ma khach hang","Ma nhan vien","Thoi Gian","Trang Thai","Ma sp","Ten sp","Gia","Giam Gia","SL","Thanh Tien");	
		for(nodeDh* p = head;p!=NULL;p=p->next){
			x = p->data;
			if(strstr(x.maKh,tam)!=NULL){
				PrintLine(x,List);
				printf("|------------------------------------------------------------------------------------------------------------------------------------|\n");
				check = 1;	
			}
		}		
	}
	if(check == 0){
		system("cls");
		printf("Khong tim thay thong tin\n");
	}
}



void nhapDh(Dh& x,nodeNv* headNv,SingleList *List,SingleListKh *ListKh,int pos){
	int check,i;
	printf("nhap\n");

	do{
		check = 1,i = 0;
		fflush(stdin);
		printf("-ID don hang:");gets(x.maDh);
		
		if(strcmp(x.maDh,"") == 0 || x.maDh[0] == ' '){
			check = 0;
		}
		else{
			while(i < j and strcmp(Ma[i],x.maDh) != 0){
				i++;
			}
			if(i != j){
				check = 0;
			}			
		}
	}while(check == 0);
	// sao chep id hoa don hien tai vao mang
	strcpy(Ma[pos],x.maDh);
	j++;
	
	NodeKhachHang* p;
	do{
		p = ListKh->pHead;
		check = 1;
		
		printf("-ID khach hang:");
		gets(x.maKh);
		while(p!= NULL and strcmp(p->data->maKh,x.maKh) != 0){
			p = p->pNext;
		}
		if(p == NULL){
			check = 0;
		}			
	}while(check == 0);
	
	nodeNhanVien* pNv;
	do{
		pNv = headNv;
		check = 1;
		
		printf("-ID nhan vien:");
		gets(x.maNv);
		while(pNv!= NULL and strcmp(pNv->data.maNv,x.maNv) != 0){
			pNv = pNv->next;
		}
		if(pNv == NULL){
			check = 0;
		}			
	}while(check == 0);	
	
	do{
		printf("-Trang thai:");gets(x.trangThai);
	}while(isValidString(x.trangThai) == 0 || strcmp(x.trangThai,"") == 0);
	
	printf("-Ngay:");scanf("%d",&x.thoiGian.ngay);
	printf("-Thang:");scanf("%d",&x.thoiGian.thang);
	printf("-Nam:");scanf("%d",&x.thoiGian.nam);

	do{
		printf("-So luong loai Sp:");scanf("%d",&x.tongSoLoai);
	}while(x.tongSoLoai <= 0);

	x.tongDonHang = 0;
	nodeSanPham *q = NULL;
	for(int i = 0;i<x.tongSoLoai;i++){
		do{
			q = List->pHead;
			check = 1;
			fflush(stdin);
			printf("+ID san pham thu %d:",i+1);
			gets(x.sp[i].ma);	
			while(q!= NULL and strcmp(q->data->maSp,x.sp[i].ma) != 0){
				q = q->pNext;
			}
			// duyet den cuoi ma chua thay ma kh ton tai thi nhap lai
			if(q == NULL){
				check = 0;
			}
		}while(check == 0);
			
		do{
			printf("+So luong:");scanf("%d",&x.sp[i].sl);
		}while(x.sp[i].sl <= 0);
		
		// dem so luong moi loai
		sl[x.sp[i].ma] += x.sp[i].sl;
		// lay thong tin cua sp
		q->data = layTT(List,x.sp[i]);
		if(q->data != NULL){
			x.tongDonHang += (float) x.sp[i].sl * (q->data->giaBan - q->data->giamGia);
		}
	}
}

void nhapDanhsach(nodeDh*& head,nodeNv* headNv,SingleList* List,SingleListKh * ListKh){
	// kiem tra
	Dh x;
	int n;
	printf("-Nhap so luong don hang:");scanf("%d",&n);
	
	while(n<0){
		printf("+Nhap lai:");scanf("%d",&n);
	}
	// nhap
	for(int i = 0;i<n;i++){
		nhapDh(x,headNv,List,ListKh,j);
		InsertLast(head,x);
	}
}

Dh updateDh(char ma[],nodeNv* headNv,SingleList *List,SingleListKh *ListKh){
	Dh x;
	strcpy(x.maDh,ma);
	
	int check;
	NodeKhachHang* p;
	do{
		p = ListKh->pHead;
		check = 1;
		
		printf("-ID khach hang:");
		gets(x.maKh);
		while(p!= NULL and strcmp(p->data->maKh,x.maKh) != 0){
			p = p->pNext;
		}
		if(p == NULL){
			check = 0;
		}			
	}while(check == 0);

	nodeNhanVien* pNv;
	do{
		pNv = headNv;
		check = 1;
		
		printf("-ID nhan vien:");
		gets(x.maNv);
		while(pNv!= NULL and strcmp(pNv->data.maNv,x.maNv) != 0){
			pNv = pNv->next;
		}
		if(pNv == NULL){
			check = 0;
		}			
	}while(check == 0);	

	do{
		printf("-Trang thai:");gets(x.trangThai);
	}while(isValidString(x.trangThai) == 0 || strcmp(x.trangThai,"") == 0);
	
	char ngay[10],thang[10],nam[10],soluong[10];
	do{
	printf("-Ngay:");scanf("%s",&ngay);
	x.thoiGian.ngay = atoi(ngay);
	}while(isValidNumber(ngay)==0);
	do{
	printf("-Thang:");scanf("%s",&thang);
	x.thoiGian.thang = atoi(thang);
	}while(isValidNumber(thang)==0);
	
	do{
	printf("-Nam:");scanf("%s",&nam);
	x.thoiGian.nam= atoi(nam);
	}while(isValidNumber(nam)==0);
	do{
		printf("-So luong loai Sp:");
		scanf("%s",&soluong);
		x.tongSoLoai=atoi(soluong);
	}while(x.tongSoLoai <= 0 || isValidNumber(soluong)==0);
	
	x.tongDonHang = 0;
	nodeSanPham *q = NULL;
	for(int i = 0;i<x.tongSoLoai;i++){
		do{
			q = List->pHead;
			check = 1;
			fflush(stdin);
			printf("+ID san pham thu %d:",i+1);
			gets(x.sp[i].ma);	
			while(q!= NULL and strcmp(q->data->maSp,x.sp[i].ma) != 0){
				q = q->pNext;
			}
			// duyet den cuoi ma chua thay ma kh ton tai thi nhap lai
			if(q == NULL){
				check = 0;
			}
		}while(check == 0);
			
		do{
			printf("+So luong:");scanf("%d",&x.sp[i].sl);
		}while(x.sp[i].sl <= 0);
			
		// lay thong tin cua sp
		q->data = layTT(List,x.sp[i]);
		if(q->data != NULL){
			x.tongDonHang += (float) x.sp[i].sl * (q->data->giaBan - q->data->giamGia);
		}
	}
	return x;
}
void updateNode(nodeDh*& head,char ma[],nodeNv* headNv,SingleList *List,SingleListKh *ListKh){
	if(head == NULL){
		printf("DANH SACH RONG!!!\n");
		return;
	}
	nodeDh* p = head;
	Dh x;
	int i = 0;
	while(p!=NULL){
		if(strcmp(p->data.maDh,ma)==0){
			x = updateDh(ma,headNv,List,ListKh);
			p->data = x;
			break;
		}
		p=p->next;
	}
	if(p==NULL){
		printf("Khong tim thay ma !!!\n");
	}	
	else{
		printf("Da sua..\n");
	}
}
void readFIleDh(nodeDh*& head,SingleList* List){
	FILE* rFile = fopen("DonHang.txt","r");
	if(rFile == NULL){
		printf("Khong mo duoc file\n");
		return;
	}
	
	while(!feof(rFile)){
		// khoi tao gtri
		Dh x;
		x.tongDonHang = 0;
		// doc
		fscanf(rFile,"%[^;];%[^;];%[^;];%[^;];%d/%d/%d;%d",x.maDh,x.maKh,x.maNv,x.trangThai,&x.thoiGian.ngay,&x.thoiGian.thang,&x.thoiGian.nam,&x.tongSoLoai);
		if(x.thoiGian.thang > 12 || x.thoiGian.thang < 1){
			return;
		}
		// doan nay de kiem soat neu file rong thi chuong trinh dich ( tam thoi may t chay the) thi se cho thang = 0 nen return luon k thuc hien doan duoi
		for(int i = 0;i<x.tongSoLoai;i++){
			fscanf(rFile,";%[^;];%d",x.sp[i].ma,&x.sp[i].sl);
			sl[x.sp[i].ma] += x.sp[i].sl;
			sanPham* thongTin = layTT(List,x.sp[i]);
			if(thongTin != NULL){
				x.tongDonHang += (float) x.sp[i].sl * (thongTin->giaBan - thongTin->giamGia);
			}			
		}
		
		strcpy(Ma[j],x.maDh);
		j++;
		InsertLast(head,x);    
		fscanf(rFile,"\n");
	}
	fclose(rFile);
}
void PrintFile(nodeDh* head){
	FILE* oFile = fopen("DonHang.txt","w");
	if(oFile == NULL){
		printf("Khong mo duoc file\n");
		return;
	}
	for(nodeDh* p = head; p != NULL; p = p->next){
		Dh x = p->data;
		fprintf(oFile,"%s;%s;%s;%s;%d/%d/%d;%d",x.maDh,x.maKh,x.maNv,x.trangThai,x.thoiGian.ngay,x.thoiGian.thang,x.thoiGian.nam,x.tongSoLoai);
		// viet ma sp, sl ra file
		for(int i = 0;i<x.tongSoLoai;i++){			
			fprintf(oFile,";%s;%d",x.sp[i].ma,x.sp[i].sl);
		}                
		fprintf(oFile,"\n");                                          
	}	
	fclose(oFile);
}

void SortList(nodeDh*& head){
	Dh x1,x2,tam;
	int c;
	
	printf("- Sap xep ID tang dan\n");
	
	for(nodeDh* p = head;p->next !=NULL;p=p->next){
		for(nodeDh* q = p->next;q !=NULL;q=q->next){
			x1 = p->data;
			x2 = q->data;
			if(strcmp(x1.maDh,x2.maDh) > 0){
				p->data = x2;
				q->data = x1;
			}
		}
	}
		printf("-> Da sap xep\n");	
}
void menuDh(nodeDh*& head,nodeNv* headNv,SingleList*& List,SingleListKh* ListKh){
	int chon = 1;
	while(chon!=0){
		system("cls");
		printf("[QUAN LI DON HANG]\n");
		printf("+-----------------------------------+\n");
		printf("|1.Hien thi                         |\n");
		printf("|2.Sap xep                          |\n");
		printf("|3.Them                             |\n");
		printf("|4.Xoa                              |\n");
		printf("|5.Tim kiem                         |\n");
		printf("|6.Cap nhat thong tin               |\n");
		printf("|0.Thoat chuc nang                  |\n");
		printf("+-----------------------------------+\n");
		printf("Chon thao tac:");scanf("%d",&chon);
		
		switch(chon){	
			case 1:
				system("cls");
				PrintList(head,List);
				system("pause");
				break;
			case 3:
				if(List->pHead != NULL){
					nhapDanhsach(head,headNv,List,ListKh);
				}
				else{
					printf("(!) Khong co thong tin danh sach san pham\n- Vui long them thong tin sp de xuat hoa don\n\n");
				}
				system("pause");
				break;			
			case 4:
				char tmp[20];
				fflush(stdin);
				printf("Nhap Ma can xoa:");gets(tmp);
				RemoveNode(head,tmp);
				system("pause");
				break;
			case 5:
				searchNode(head,List);
				system("pause");
				break;	
			case 6:
				printf("Nhap Ma can sua:");
				char m[20];
				fflush(stdin);
				gets(m);
				updateNode(head,m,headNv,List,ListKh);
				system("pause");
				break;	
			case 2:
				SortList(head);
				system("pause");
				break;
			case 0:
				system("cls");
				printf("Bam phim bat ky de quay lai menu chinh\n\n");
				system("pause");
		}
	}
}
// doanh thu
void KhoiTao(nodeDh* head,float tong[]){
	for(nodeDh* p= head;p!=NULL;p=p->next){
		int thang = p->data.thoiGian.thang;
		tong[thang-1] += p->data.tongDonHang;
		
		tmp[thang-1] += p->data.tongDonHang;
	}	
}
void maxdt(float tong[]){
	float max = tong[0];
	int index = 1;
	for (int i=1;i<12;i++){
		if(tong[i]>max){
			max=tong[i];
			index=i+1;
		}
	}
	printf("Thang co doanh thu cao nhat la thang %d voi doanh thu la: %.2f",index,max);
}

void mindt(float tong[]){
	float min = tong[0];
	int index = 1;
	for (int i=1;i<12;i++){
		if(tong[i]<min){
			min=tong[i];
			index=i+1;
		}
	}
	printf("Thang co doanh thu thap nhat la thang :");
	for(int i = 0;i<12;i++){
		if(tong[i]==0){
			printf("%d ",i+1);
		}
	}
	
	if(min > 0){
		printf(" %d",index);
		printf("\nDoanh thu : %.2f",min);
	}
	else{
		printf("\nDoanh thu : 0");
	}
}

float totaldtcanam(float tong[]){
	float sum = 0;
	for(int i = 0;i<12;i++){
		sum += tong[i];
	}
	return sum;
}

void avgcanam(float tong[]){
	float avgdt = totaldtcanam(tong)/12;
	printf("Trung binh doanh thu cua ca nam la: %.2f",avgdt);
}

void tongdtcanam(float tong[]){
	float tongcanam = totaldtcanam(tong);
	printf("Doanh thu cua ca nam la: %.2f",tongcanam);
}

void SpBanChayNhat(){
	int max = 0;
	for(auto &pair : sl){
		if(max < pair.second) max = pair.second;
	}
	for(auto &pair : sl){
		if(max == pair.second) std::cout << "San pham ban chay nhat:"<< pair.first << ", so luong:" << max << std::endl;
	}
}

void printFiledt(float tong[]) {
    FILE *fptr = fopen("Doanhthu.txt","w");
	if(fptr == NULL){
		printf("Khong mo duoc file\n");
		return;
	}
	for (int i=0;i<12;i++){
		fprintf(fptr,"%d;%.2f\n", i+1, tong[i]);
	}
    fclose(fptr);
}

void readFileDt(float tong[]){
	FILE* rFile = fopen("Doanhthu.txt","r");
	if(rFile == NULL){
		printf("Khong mo duoc file\n");
		return;
	}
	int i = 0,tmp;
	while(!feof(rFile)){	
		fscanf(rFile,"%d;%f\n",&tmp,&tong[i]);
		i++;
	}
}

void printDt(float tong[]){
	for (int i=0;i<12;i++){
		printf("|%-12d|%-10.2f|\n",i+1,tong[i]);
	}	
}
void menuDt(nodeDh* head) {
	float tongThang[12]= {};
	KhoiTao(head,tongThang);
	int chon = 1;
	do {
        system("cls");
        printf("[QUAN LI DOANH THU]\n\n");
        printf("+-----------------------------------+\n");
        printf("|1. Xuat doanh thu 12 thang         |\n");
        printf("|2. Tong doanh thu ca nam           |\n");
        printf("|3. Trung binh doanh thu ca nam     |\n");
        printf("|4. Thang co doanh thu lon nhat     |\n");
        printf("|5. Thang co doanh thu nho nhat     |\n");
        printf("|6. San pham ban chay nhat          |\n");
        printf("|0. Thoat                           |\n");
        printf("+-----------------------------------+\n");
        printf("Hay nhap lua chon cua ban: ");
        scanf("%d", &chon);
        switch (chon) {
        	case 1: // xuat doanh thu cac thang
            printDt(tongThang);
			printf("\n");
			system("pause");
            break;
        	case 2://Tong doanh thu ca nam
        	tongdtcanam(tongThang);
        	printf("\n\n");
        	system("pause");
            break;
       		 case 3: // trung binh doanh thu ca nam
            avgcanam(tongThang);
            printf("\n\n");
            system("pause");
            break;
       		 case 4: // doanh thu lon nhat
            maxdt(tmp);
            printf("\n\n");
            system("pause");
            break;
       		case 5: // doanh thu nho nhat
            mindt(tongThang);
            printf("\n\n");
            system("pause");
            break;
            case 6:
            SpBanChayNhat();
            printf("\n");
            system("pause");
        	case 0:
			system("cls");
			printf("Bam phim bat ky de quay lai menu chinh\n\n");
            system("pause");
            break;
    	}
    } while (chon);
}

void ReadAll(SingleListNCC *&ListNCC,SingleListKh *&ListKH,SingleList *&List,nodeNv*& headnv,nodeDh*& headDh){
		readFileNCC(ListNCC);
		readFile(ListKH);
		readFileSP(List);	
		readFIleNV(headnv);
		readFIleDh(headDh,List);
	}
void bigMenu(SingleListNCC* listNCC,SingleList* list,SingleListKh* listKh,nodeDh* head,nodeNv* headNv){
	int chon;
	int sure=0;
	int z=0;
	do{
		system("cls");
		printf("+-------------------------------------+\n");
		printf("|1.Quan ly khach hang                 |\n");
		printf("|2.Quan ly nhan vien                  |\n");
		printf("|3.Quan ly san pham                   |\n");
		printf("|4.Quan ly nha cung cap               |\n");
		printf("|5.Quan ly don hang                   |\n");
		printf("|6.Quan ly doanh thu                  |\n");
		printf("|7.Luu toan bo File                   |\n");
		printf("|0. Thoat chuong trinh                |\n");
		printf("+-------------------------------------+\n");
		char choice[10];
		do{
		printf("- Chon thao tac:");scanf("%s",&choice);
		chon = atoi(choice);
		}while(isValidNumber(choice)==0);
		switch(chon){
			case 1:
				system("cls");
				menuKh(listKh);
				sure=0;
				break;
			case 2:
				system("cls");
				menuNv(headNv);
				sure=0;
				break;
			case 3:
				system("cls");
				menuSp(list,listNCC);
				sure=0;
				break;	
			case 4:
				system("cls");
				menuNCC(listNCC);
				sure=0;
				break;
			case 5:
				system("cls");
				menuDh(head,headNv,list,listKh);
				sure=0;
				break;	
			case 6:
				system("cls");
				menuDt(head);
				sure=0;
				break;		
			case 7:
				system("cls");
				PrintFile(headNv);
				PrintFile(head);
				printFile(list);
				printFile(listNCC);
				printFile(listKh);
				printFiledt(tmp);
				system("cls");
				printf("(!) Dang luu du lieu [");
				for (int i = 0; i < 30; i++) {
					printf("|");
					Sleep(10);
				}
				printf("]\n");
				printf( "(!) LUU DU LIEU THANH CONG\n");
				sure=1;				
				system("pause");
				break;
			case 0:			
				if(sure==1){
					z=1;
					printf("Da thoat chuong trinh");
					break;
				}
				else{
				printf("Hay nho luu file de thoat chuong trinh\n");
				system("pause");
				break;	
			}
		}
		
	}while(chon !=0 || z==0);
}

void Dangnhap(){
	
	char pwd [30];
	char pass[30]="admin"; 
	do{
	int i=0;
	char ch;
	pwd [30];
	printf("Enter Password: ");
	while((ch=_getch())!=13) {
	pwd[i] = ch;
	i++;
	printf("*");
	}
	pwd[i]='\0';	
	if(strcmp(pwd,pass)!=0){
		printf("\nSai mat khau\n");
	}
	}while(strcmp(pwd,pass)!=0);
}

int main(){
	Dangnhap();	
	//san pham	
	SingleList *list;
	Initialize(list);
	//khach hang
	SingleListKh *listKh;
	Initialize(listKh);
	// nha cung cap
	SingleListNCC *listNCC;
	Initialize(listNCC);
	// don hang
	nodeDh* headDh = NULL;
	// nhan vien
	nodeNv* headNv = NULL;
	// menu 
	ReadAll(listNCC,listKh,list,headNv,headDh);
	bigMenu(listNCC,list,listKh,headDh,headNv);	
}
