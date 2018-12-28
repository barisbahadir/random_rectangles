#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <fstream>

using namespace std;

#define UZAYGENISLIK 30
#define UZAYYUKSEKLIK 40

class uzay
{
	public:
		int uzay[UZAYYUKSEKLIK][UZAYGENISLIK];
		int agirlikMerkeziX;
		int agirlikMerkeziY;
			class box {
				public:
					class coord
					{
						public:
							double x;
							double y;
					}koord;
				double x, y;
				double bitisX, bitisY;
				int genislik;
				int yukseklik;
				double agirlik_mX;
				double agirlik_mY;
				int kutle;
				int hacim;
				int yogunluk;
			}kutu[20];
	
	///////////////////////////	
	
int dolulukKontrol(int xx, int yy, int gen, int yuks)
	{
		int tamamenBos = 0;
		int tamamenDolu = 0;

		int yukseklik = yy + yuks;
		int genislik = xx + gen;
		
		for(int i=yy; i <= yukseklik; i++)
		{
			for(int j=xx; j <= genislik; j++)
			{
				if (uzay[j][i] == 0)
				{
					tamamenBos++;
				}
				else
				{
					"Hataya rastlandi.";
				}
			}
		}
	
	return tamamenBos;
}	
	//////////////////////////////////
		

	///////////////////////////////////// DiKDORTGEN URETEN FONKSiYON BASI
int kutuNo=0;
void dikdortgenUret(int xx, int yy, int gen, int yuks, int dikdortgenYogunlugu) 
{
		int genis = gen + 1;
		int yuksek = yuks + 1;
		
		int maxDegerX=xx+gen;
		int maxDegerY=yy+yuks;
		
		if(dolulukKontrol(xx, yy, gen, yuks) == genis * yuksek && maxDegerX<=UZAYGENISLIK && maxDegerY<=UZAYYUKSEKLIK)
		{
			
			kutu[kutuNo].x = xx;
			kutu[kutuNo].y = yy;
			kutu[kutuNo].genislik = gen;
			kutu[kutuNo].yukseklik = yuks;
			kutu[kutuNo].bitisX = xx + gen;
			kutu[kutuNo].bitisY = yy + yuks;
			kutu[kutuNo].agirlik_mX = xx + ((double)gen/2);
			kutu[kutuNo].agirlik_mY = yy + ((double)yuks/2);
			kutu[kutuNo].hacim = gen * yuks;
			kutu[kutuNo].yogunluk = dikdortgenYogunlugu;
			kutu[kutuNo].kutle = kutu[kutuNo].yogunluk * kutu[kutuNo].hacim;
			
		///////////// MATRÝSTE TÜM NOKTALARI 1 YAPIYOR. SEBEBÝ: DOLU OLDUÐU ANLAÞILSIN.
		
		int yukseklik = yy + yuks;
		int genislik = xx + gen;
		
		for(int i=yy; i <= yukseklik; i++)
		{
			for(int j=xx; j <= genislik; j++)
			{
				uzay[i][j] = 1;
			}
		}
		
		/////////////
			
			
		cout << "DIKDORTGEN NO: " << kutuNo+1 << endl;	
		cout << "Uretilen Dikdortgenin Baslangic Koordinatlari: (" << kutu[kutuNo].x << "," << kutu[kutuNo].y <<")"<< endl;
		cout << "Uretilen Dikdortgenin Genisligi: " << kutu[kutuNo].genislik << endl;
		cout << "Uretilen Dikdortgenin Yuksekligi: " << kutu[kutuNo].yukseklik << endl;
		cout << "Uretilen Dikdortgenin Bitis Koordinatlari: (" << kutu[kutuNo].bitisX << "," << kutu[kutuNo].bitisY <<")"<< endl;	
		cout << "Agirlik Merkezi: X=" << kutu[kutuNo].agirlik_mX << " Y="<< kutu[kutuNo].agirlik_mY << endl << endl;

	/*	cout << "Kutlesi: " << kutu[kutuNo].kutle;
		cout << "\tHacmi: " << kutu[kutuNo].hacim;
		cout << "\tYogunlugu: " << kutu[kutuNo].yogunluk << endl << endl;    */
		
		kutuNo++;
		}
		
		else
		{
			cout << " X X X ----- DIKDORTGEN YERLESTIRILEMEDI. ORADA BASKA DIKDORTGEN MEVCUT. ----- X X X " << endl<<endl; 
		}
	
}
	
///////////////////////////////////// DiKDORTGEN URETEN FONKSiYON SONU

void agirlikMerkeziEkranaYazdir()
{
	uzay[agirlikMerkeziY][agirlikMerkeziX] = 3;
}
	
///////////////////// TüM UZAYI EKRANA YAZDIRAN FONKSÝYONUMUZ

void koordinatlariEkranaYazdir()
{
		cout << endl;
		cout << "KOORDINATLAR YAZDIRILDI: " << endl<<endl;
		for(int i=0; i<UZAYYUKSEKLIK; i++)
		{
			for(int j=0; j<UZAYGENISLIK; j++)
			{
				cout << uzay[i][j] << " ";
			}
			cout << endl;
		}
}

///////////////////// DOSYAYA YAZDIRAN FONKSÝYONUMUZ

void koordinatlariDosyayaYazdir()
{
	ofstream dosyaYaz;
	dosyaYaz.open("Koordinatlar.txt");
	dosyaYaz << "Koordinatlar su sekildedir: " << endl<<endl;
	for(int i=0; i<kutuNo; i++)
	{
		dosyaYaz << "Kutu " << i+1 << ": BASLANGIC noktasi: (" << kutu[i].x << "," << kutu[i].y << ")"<< " \n\tBITIS noktasi: (" << kutu[i].bitisX << "," << kutu[i].bitisY << ")" << endl <<endl;
	}
	dosyaYaz << endl << "YERLESTIRILEN " << kutuNo << " KUTUNUN AGIRLIK MERKEZI: (" << agirlikMerkeziX << "," << agirlikMerkeziY << ") olarak hesaplanmýþtýr." << endl;
	dosyaYaz.close();
}

///////////////////// AÐIRLIK MERKEZÝNÝ HESAPLAYIP EKRANA YAZDIRAN FONKSÝYONUMUZ
	
void agirlikMerkeziYazdir()
{
	int hesapPayX=0;
	int hesapPayY=0;
	int hesapPaydaX=0;
	int hesapPaydaY=0;

	for(int i=0; i<kutuNo; i++)
	{
		hesapPayX += kutu[i].kutle * kutu[i].agirlik_mX;
		hesapPaydaX += kutu[i].kutle;
		hesapPayY += kutu[i].kutle * kutu[i].agirlik_mY;
		hesapPaydaY += kutu[i].kutle;
	}
	
	agirlikMerkeziX = hesapPayX / hesapPaydaX;
	agirlikMerkeziY = hesapPayY / hesapPaydaY;
	
	cout << "******************************************" << endl << endl;
	cout <<	"Uzayin Agirlik Merkezi: (" << agirlikMerkeziX << "," << agirlikMerkeziY << ")'dir." << endl;

}

}uzay1;

int random(int min, int max) //bu fonksiyon rastgele x, y deðerleri üretecek.
{
    srand(time(NULL));
	unsigned int seed = rand();
    srand(seed);
    return rand() % (max - min) + min;
}

void bekle(int saniye) //BELGELERIN SAYFA SAYISI BAZ ALINARAK YAZDIRMA HIZ SETLEMESI
{
clock_t endwait; 
endwait = clock () + saniye * CLOCKS_PER_SEC ; 
while (clock() < endwait) {} 
}

int main()
{
	uzay uzay1;
	
	///////////////////////////////   uzay tanýmý yapýldý. bu kýsým tüm satýr sütunlarý sýfýrlýyor.
	
	for(int i=0; i<UZAYYUKSEKLIK; i++)	
	{
		for(int j=0; j<UZAYGENISLIK; j++)
		{
			uzay1.uzay[i][j] = 0;
		}
	}
	
	///////////////////////////////
	
	int kutuAdedi = 0;
	int maxKutuBoyutu = 0;
	int varsayilanYogunluk = 0;
	
	cout << "Kutu adedi giriniz: "; cin>> kutuAdedi; cout << endl;
		if(kutuAdedi<1)
		{
			cout << "Hatali giris yaptiniz. Program KAPATILIYOR!" << endl;
			return 0;	
		}

	cout << "Kutu boyutunu giriniz: "; cin>> maxKutuBoyutu; cout << endl;	
		if(maxKutuBoyutu < 1)
		{
			cout << "Hatali giris yaptiniz. Program KAPATILIYOR." << endl;
			return 0;
		}
		
	cout << "Varsayilan kutu yogunlugunu giriniz: "; cin >> varsayilanYogunluk; cout << endl;
		if(varsayilanYogunluk <1)
		{
			cout << "Hatali giris yaptiniz. Program KAPATILIYOR." << endl;
			return 0;
		}
	
	//////////////////////////////// DIKDORTGEN URETIYORUZ.
		
	while(uzay1.kutuNo < kutuAdedi)
	{
		uzay1.dikdortgenUret(random(0,UZAYGENISLIK-5),random(0,UZAYYUKSEKLIK-4),random(1,maxKutuBoyutu),random(1,maxKutuBoyutu-1),varsayilanYogunluk);
		bekle(1);
	}
	
	///////////////////////////////
	
	/* AGIRLIK MERKEZI TEST EDÝLECEÐÝ ZAMAN AKTÝF EDÝLECEK.
		uzay1.dikdortgenUret(random(0,25),random(0,35),random(1,2),random(1,3),1);
		bekle(1);
		uzay1.dikdortgenUret(8,8,3,1,5);
		bekle(1);
		uzay1.dikdortgenUret(4,4,2,1,1);
		bekle(1);
		uzay1.dikdortgenUret(4,4,2,1,8);
		bekle(1);
		uzay1.dikdortgenUret(20,24,3,1,1);
		bekle(1);
		uzay1.dikdortgenUret(28,29,4,2,1);
		bekle(1);
	*/
	
	uzay1.agirlikMerkeziYazdir();
	uzay1.koordinatlariDosyayaYazdir();
	uzay1.agirlikMerkeziEkranaYazdir();
	uzay1.koordinatlariEkranaYazdir();
	
}

