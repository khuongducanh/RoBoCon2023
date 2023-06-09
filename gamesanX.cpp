#include <iostream>
#include <string.h>
#include <cstdlib>
#include <ctime>

using namespace std;

#define hang 15
#define cot 15
int a[100][100]; int n = 1; int o = 1;
int diemxuatphathang = 1;
int  diemxuatphatcot = 1;
char run; 
int nhan;
int diem = 0;
int rin = 2, ran = 2;


void background() {
	int i, j;	
	cout << "                  GAME SAN TIM X " << endl;
	cout << "Huong dan :  Nhap W(di thang)" << endl ;
	cout << "             Nhap A(re trai )" << endl;
	cout << "             Nhap D(re phai )" << endl;
	cout << "             Nhap S(di lui  )" << endl;
	cout << "Muc tieu : Di chuyen den dau X tren man hinh se duoc 10 diem , choi den khi nao 100 diem thi Win" << endl;
	cout << endl;
	cout << endl;
	cout << endl;	
	cout << endl;
	for (i = 0; i <= hang; i++) {
		for (j = 0; j <= cot; j++) {
			   cout << "  ";			
			if (i == diemxuatphathang && j == diemxuatphatcot) {
				cout << "[]";
			}
			if (i == 5 && j == 4) {
				cout << "X";
			}
		}
		cout << endl;
	}
	cout << endl ;
}



void dichuyen() {
	cout << endl;
	cout << "Nhap code : ";
	cin >> run;
	if (run == 'S') {
	   diemxuatphathang++;
	   if (diemxuatphathang >= 15) {
		   diemxuatphathang =  15;
	   }
	}

	if (run == 'W') {
		diemxuatphathang--;
		if (diemxuatphathang <= 2) {
			diemxuatphathang = 2;
		}
	}

	if (run == 'D') {
		diemxuatphatcot++;
		if (diemxuatphatcot >= 15) {
			diemxuatphatcot = 15;
		}
	}

	if (run == 'A') {
		diemxuatphatcot--;
		if (diemxuatphatcot <= 2) {
			diemxuatphatcot = 2;
		}
	}

	for (int i = 0; i <= hang; i++) {
		for (int j = 0; j <= cot; j++) {
			cout << "  ";
			if (run == 'S' && i == diemxuatphathang && j == diemxuatphatcot) {
				cout << "[]";
			 }
			if (run == 'W' && i == diemxuatphathang && j == diemxuatphatcot) {
				cout << "[]";
			}
			if (run == 'A' && i == diemxuatphathang && j == diemxuatphatcot) {
				cout << "[]";
			}
			if (run == 'D' && i == diemxuatphathang && j == diemxuatphatcot) {
				cout << "[]";
			}
			if (i == rin && j == ran) {
				cout << "X";
			}
			else if (rin == diemxuatphathang && ran == diemxuatphatcot) {
				
				diem = diem + 10 ;
				rin += 1;
				ran += 1;
				srand(time(NULL));
				int res1 = rand() % (15 - 1 + 1) + 1;
				int res2 = rand() % (15 - 1 + 1) + 1;
				rin = res1;
				ran = res2;
				if (ran >= 15) {
					ran = 15;
				}
				if (ran <= 3) {
					ran = 3;
				}
				if (rin >= 15) {
					rin = 15;
				}
				if (rin <= 3) {
					rin = 3;
				}
			 }
		}
		cout << endl;
	}	
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
}



int main() {
	  background();
	  cout << "Nhan 1 de bat dau choi  : " ;
	  cin >> nhan; 
	  if (nhan == 1) {
		  for (int i = 3; i >= 1; i--) {
			  cout << " " << i << endl  ;
			  if (i == 1) {
				  cout << "BAT DAU";
			  }
		  }
	  }
	  do {
	    dichuyen();
		cout << "Point :  " <<  diem << endl ;		 
		if (diem == 100) {
		  cout << "YOU WIN";
	    }				
	  } 
	  while (n > 0 && o > 0 && diem <= 100-10);
}
