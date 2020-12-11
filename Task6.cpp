#include  <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <cmath> 
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS
using namespace sf; 

void podder(int n, float x1, float y1, float x2, float y2, float x3, float y3);
RenderWindow window(VideoMode(1200, 650), "lesson-6");
VertexArray tri(Triangles, 30000);
class window
{
public:
    sf::RenderWindow window;
};
void zadanie2() {
	int n, m;
	printf("Task9. 2\n");
	printf("Введите размер через пробел");
	scanf_s("%d %d", &n, &m);

	int** mas;
	mas = (int**)malloc(n * sizeof(int*));
	for (int q = 0; q < n; q++) {
		mas[q] = (int*)malloc(m * sizeof(int));
	}
	if (m > n) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {

				mas[i][j] = j + 1 - i;
				if (mas[i][j] <= 0) {
					mas[i][j] = 2 - mas[i][j];
				}
			}
		}
	}
	else {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {

				mas[i][j] = j + 1 - i;
				if (mas[i][j] <= 0) {
					mas[i][j] = 2 - mas[i][j];
				}
			}
		}
	}


	for (int i = 0; i < n; i++) {  //вывод
		printf("\n");
		for (int j = 0; j < m; j++) {
			printf("\t%d", mas[i][j]);
			mas[i][j] = 0;
		}
	}
	printf("\n\n");


	int sum = 1;

	if (n % 2 == 1 && m % 2 == 1) {
		mas[n / 2][m / 2] = n * m;

	}

	int krugov;
	if (n > m) {
		krugov = m / 2 + m % 2;
	}
	else {
		krugov = n / 2 + m % 2;
	}

	for (int i = 0; i < krugov; i++) {
		if ((krugov == i + 1 && n % 2 == 1) || (n % 2 == 0) || (krugov != i + 1 && n % 2 == 1)) {
			for (int j = i; j < (m - i); j++) {
				mas[i][j] = sum;
				sum++;
			}
		}
		if ((krugov == i + 1 && m % 2 == 1) || (m % 2 == 0) || (krugov != i + 1 && m % 2 == 1)) {
			for (int j = 1; j < (n - i - i); j++) {
				mas[(j + i)][m - i - 1] = sum;
				sum++;
			}
		}
		if (krugov != i + 1 && (m % 2 == 1 || n % 2 == 1)) {
			for (int j = m - 2 - i; j >= i; j--) {
				mas[n - i - 1][(j)] = sum;
				sum++;
			}
			for (int j = ((n - i) - 2); j > i; j--) {
				mas[j][i] = sum;
				sum++;
			}
		}
	}


	for (int i = 0; i < n; i++) {  //вывод
		printf("\n");
		for (int j = 0; j < m; j++) {
			printf("\t%d", mas[i][j]);
		}
	}



}
void task6() {
	float x1 = 100, y1 = 550, x2 = 1000, y2 = 550, x3 = 550, y3 = 50;

	VertexArray tri(Triangles, 3);
	tri[0].position = Vector2f(x1, y1);
	tri[1].position = Vector2f(x2, y2);
	tri[2].position = Vector2f(x3, y3);
	float ax, ay, bx, by, cx, cy;
	ax = (x1 + x2) / 2;
	ay = (y1 + y2) / 2;
	bx = (x1 + x3) / 2;
	by = (y1 + y3) / 2;
	cx = (x2 + x3) / 2;
	cy = (y2 + y3) / 2;

	podder(3, (x1 + x2) / 2, (y1 + y2) / 2, (x1 + x3) / 2, (y1 + y3) / 2, (x2 + x3) / 2, (y2 + y3) / 2);

	while (window.isOpen()) {

		Event event;
		while (window.pollEvent(event)) {
			if (event.type == Event::Closed)
				window.close();
		}

		//window.clear();
		//window.draw(tri2);
		window.display();
	}
}
int main() {
	int q = -1;
	setlocale(LC_ALL, "Russian");
	printf("\n\n2) (2) Заполнить двумерный массив размером n x m так, как представлено в таблице для 5х5 (Таск 8)");
	printf("\n\n6) Фрактал");
	printf("\n\n0)Выйти");
	while (q != 0) {
		printf("\n\nВведите номер нужного задания : ");
		scanf_s("%d", &q);
		switch (q) {
		case 2: {
			zadanie2();//Задание 2  таск 8 
			break;
		}
		case 6: {
			task6();//таск 6
			break;
		}

		}
	}
    return 0;
}



void podder(int kol, float x1, float y1, float x2, float y2, float x3, float y3) {

   
    tri[kol + 0].position = Vector2f(x1, y1);
    tri[kol + 0].color = Color::Blue;
    tri[kol + 1].position = Vector2f(x2, y2);
    tri[kol + 1].color = Color::Green;
    tri[kol + 2].position = Vector2f(x3, y3);
    tri[kol + 2].color = Color::Red;

    
   

 
   
    
    if (kol < 18) {
        
        podder(
            kol + 3,
            (x1 + x2) / 2 + (x1 - x3) / 2,
            (y1 + y2) / 2 + (y1 - y3) / 2,
            (x1 + x2) / 2 + (x2 - x3) / 2,
            (y1 + y2) / 2 + (y2 - y3) / 2,
            (x1 + x2) / 2,
            (y1 + y2) / 2);


        podder(
            kol + 3,
            (x3 + x2) / 2 + (x3 - x1) / 2,
            (y3 + y2) / 2 + (y3 - y1) / 2,
            (x3 + x2) / 2 + (x2 - x1) / 2,
            (y3 + y2) / 2 + (y2 - y1) / 2,
            (x3 + x2) / 2,
            (y3 + y2) / 2);

        podder(
            kol + 3,
            (x1 + x3) / 2 + (x1 - x2) / 2,
            (y1 + y3) / 2 + (y1 - y2) / 2,
            (x1 + x3) / 2 + (x3 - x2) / 2,
            (y1 + y3) / 2 + (y3 - y2) / 2,
            (x1 + x3) / 2,
            (y1 + y3) / 2);

    }
    else {
        window.draw(tri);
    }
  
}
