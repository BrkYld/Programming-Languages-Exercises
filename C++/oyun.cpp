// Proje.cpp : Bu dosya 'main' işlevi içeriyor. Program yürütme orada başlayıp biter.
//
//c++ konsol oyunu örneği
#include "pch.h"
#include <iostream>
#include <Windows.h>
#include <time.h>
using namespace std;
const int height = 20; // Sütun , yükseklik
const int widht = 100; // Satir , genislik
char keys[256];


void readKeys(char keys[]) //Tuşları okuma
{
	for (int i = 0; i < 256; i++) 
	{
		keys[i] = (char)(GetAsyncKeyState(i) >> 8);
	}
}
void setCursorPosition(int x, int y) //Konsol konumunu ayarlama
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void hiddenCursor() //Konsol işaretçisini gizleme
{
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursorInfo;
	GetConsoleCursorInfo(out, &cursorInfo);
	cursorInfo.bVisible = false;
	SetConsoleCursorInfo(out, &cursorInfo);
}

class Game
{
private:
	char gamingArea[widht][height];
	char planeChar;
	char bulletChar;
	char enemyChar;
	int planeY;
	int bulletY[150];
	int bulletX[150];
	int bulletCounter;
	int enemyX[10];
	int enemyY[10];
	int enemyCounter;
public:
	Game() 
	{
		planeChar = 219;
		bulletChar = 205;
		enemyChar = 178;
		for (int i = 0; i < 10; i++)
		{
			enemyX[i] = 0;
			enemyY[i] = 0;
		}
		for (int i = 0 ;i < 150; i++) 
		{
			bulletX[i] = 0;
			bulletY[i] = 0;
		}
		
		Create();
	}
	void Create() 
	{
		refreshGamingArea();
		bulletCounter = 0;
		enemyCounter = 0;
		planeY = 3;
	}
	void playerControl() //Oyuncunun bastıgı tuşlara göre hareket etme
	{
		
		if (keys['W'] != 0) 
		{
			planeY--;
			if (planeY == height) planeY = 3;
			else if (planeY == 1) planeY = height-3;
		}
		else if (keys['S'] != 0) 
		{
			planeY++;
			if (planeY == height) planeY = 3;
			else if (planeY == 1) planeY = height - 3;
		}
		else if (keys['X'] != 0) 
		{
			for (int i = 0; i < 2; i++)
			{

				if (bulletCounter == 149)
				{
					bulletCounter = 0;
					bulletX[bulletCounter] = 3;
					bulletY[bulletCounter] = planeY;
					bulletCounter++;
				}
				else
				{
					bulletX[bulletCounter] = 3;
					bulletY[bulletCounter] = planeY;
					bulletCounter++;
				}


			}
			
		}

		
	}
	void printPlane(int y) //Uçagı oyun alanına yerleştirme
	{
		if (planeY < 0) 
		{
			y = planeY;
		}
		gamingArea[1][y-2] = planeChar;
		gamingArea[2][y-1] = planeChar;
		gamingArea[3][y] = planeChar;
		gamingArea[2][y+1] = planeChar;
		gamingArea[1][y+2] = planeChar;

		planeY = y;
	}
	void printEnemy() //Düşmanı oyun alanına yerleştirme
	{
		int x;
		int y;
		for (int i = 0; i < 10; i++)
		{
			 x = enemyX[i];
			 y = enemyY[i];
			if (enemyX[i] == 0 && enemyY[i] == 0)
			{
				continue;
			}
			else
			{
				if ( enemyY[i] < 0 || enemyX[i] < 0)
				{
					enemyX[i] = 0;
					enemyY[i] = 0;
					
					enemyCounter = i;
					continue;
				}
				for (int x = 0; x < 150;x++) //Çarpışma kontrolu yapan döngü
				{
					if (bulletY[x] == enemyY[i] || bulletY[x] == enemyY[i]+1 || bulletY[x] == enemyY[i]+2  )
					{
						if (bulletX[x] == enemyX[i] || bulletX[x] == enemyX[i] + 1 || bulletX[x] == enemyX[i] + 2) 
						{
							enemyX[i] = 0;
							enemyY[i] = 0;
							enemyCounter = i;
							bulletX[x] = 0;
							bulletY[x] = 0;
							bulletCounter = x;
							continue;
						}
					}
				}
				
				gamingArea[x][y] = enemyChar;
				gamingArea[x + 1][y] = enemyChar;
				gamingArea[x + 2][y] = enemyChar;
				gamingArea[x][y + 1] = enemyChar;
				gamingArea[x + 2][y + 1] = enemyChar;
				gamingArea[x][y + 2] = enemyChar;
				gamingArea[x + 1][y + 2] = enemyChar;
				gamingArea[x + 2][y + 2] = enemyChar;
				enemyX[i] = enemyX[i] - 1;
				
			}

		}
		
		
		


	}
	void printBullet()//Mermileri oyun alanına yerleştirme
	{
		for (int i = 0; i < 150; i++) 
		{
			if (bulletX[i] == 0 && bulletY[i] == 0)
			{
				continue;
			}
			else 
			{
				if (bulletY[i] > height || bulletY[i] < 0) 
				{
					bulletY[i] = 0;
					continue;
				}
				if (bulletX[i] > widht - 1) 
				{
					bulletX[i] = 0;
					bulletY[i] = 0;
				    bulletCounter = i;
					continue;
				}
				gamingArea[bulletX[i]][bulletY[i]] = bulletChar;
				bulletX[i]++;
			}
			
		}
		
	}
	void newEnemy() //Rastgele konumlarda düşman oluşturur
	{
		
		enemyX[enemyCounter] = widht;
		enemyY[enemyCounter] = rand() % 15 + 1;
		enemyCounter++;
		if (enemyCounter == 10) enemyCounter = 0;
		
	}
	void refreshGamingArea() // oyun alanını sıfırlar
	{
		for (int i = 0; i < height; i++)
		{
			for (int j = 0; j < widht; j++)
			{
				gamingArea[j][i] = ' ';
			}
		}
	}
	void Render() //Oyunun ana fonksiyonu. Burada oyun alanı sürekli silinip yeniden yazılarak oyun ortamı oluşur
	{
		int i = 0;
		int planeTemp = 0;
		while (true) 
		{
			srand(time(NULL));
			if (bulletChar != 205) bulletChar = 205;
			if (planeChar != 219) planeChar = 219;
			refreshGamingArea();
			readKeys(keys);
			playerControl();
			hiddenCursor();
			if (planeY < 0 || planeY > 100) 
			{
				planeY = planeTemp;
			}
			printPlane(planeY);
			planeTemp = planeY;

			if (i == 20) 
			{
				newEnemy();
				i = 0;
			}
			printEnemy();
			printBullet();
			printGamingArea();
			i++;
			
			
			
			
		}
	}
	void printGamingArea() // oyun alanının çizilmesi
	{
		for (int i = 0; i < widht; i++)
		{
			gamingArea[i][0] = 219;
			gamingArea[i][height - 1] = 219;
		}
		for (int i = 0; i < height; i++) 
		{
			gamingArea[0][i] = 219;
			gamingArea[widht-1][i] = 219 ;
		}
		for (int i = 0; i < height; i++)
		{
			for (int j = 0; j < widht; j++)
			{
				cout << gamingArea[j][i];
			}
			cout << endl;
		}
		setCursorPosition(0, 0);
	}
};


int main()
{
	Game game;
	game.Render();
}

// Programı çalıştır: Ctrl + F5 veya Hata Ayıkla > Hata Ayıklamadan Başlat menüsü
// Programda hata ayıkla: F5 veya Hata Ayıkla > Hata Ayıklamayı Başlat menüsü

// Kullanmaya Başlama İpuçları: 
//   1. Dosyaları eklemek/yönetmek için Çözüm Gezgini penceresini kullanın
//   2. Kaynak denetimine bağlanmak için Takım Gezgini penceresini kullanın
//   3. Derleme çıktısını ve diğer iletileri görmek için Çıktı penceresini kullanın
//   4. Hataları görüntülemek için Hata Listesi penceresini kullanın
//   5. Yeni kod dosyaları oluşturmak için Projeye Git > Yeni Öğe ekle veya varolan kod dosyalarını projeye eklemek için Proje > Var Olan Öğeyi Ekle adımlarını izleyin
//   6. Bu projeyi daha sonra yeniden açmak için Dosya > Aç > Proje'ye gidip .sln uzantılı dosyayı seçin
