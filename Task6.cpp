#include  <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <cmath> 
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS
using namespace sf; 
int n = 3;
void podder(int fract,int kol, float x1, float y1, float x2, float y2, float x3, float y3);
RenderWindow window(VideoMode(1200, 650), "lesson-6");
VertexArray tri(Triangles, 30000);
class window
{
public:
    sf::RenderWindow window;
};
void task6() {
	float x1 = 100, y1 = 550, x2 = 1000, y2 = 550, x3 = 550, y3 = 50;
	int fract;
	printf("Введите кол-во итераций");
	scanf_s("%d", &fract);
	window.clear();

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

	podder(fract, 3, (x1 + x2) / 2, (y1 + y2) / 2, (x1 + x3) / 2, (y1 + y3) / 2, (x2 + x3) / 2, (y2 + y3) / 2);

	while (window.isOpen()) {

		Event event;
		while (window.isOpen()) {

			Event event;
			while (window.pollEvent(event)) {
				if (event.type == Event::Closed)
					window.close();
			}

			//window.clear();
			window.draw(tri);
			window.display();
		}
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
		case 6: {
			task6();//таск 6
			break;
		}

		}
	}
    return 0;
}



void podder(int fract,int kol, float x1, float y1, float x2, float y2, float x3, float y3) {

   
    tri[n].position = Vector2f(x1, y1);
    tri[n].color = Color::Blue;
	n++;
    tri[n].position = Vector2f(x2, y2);
    tri[n].color = Color::Green;
	n++;
    tri[n].position = Vector2f(x3, y3);
    tri[n].color = Color::Red;
	n++;
    
	printf("%d ",n);

 
   
    
    if (kol < fract*3) {
        
        podder(
			
			fract,
            kol + 3,
            (x1 + x2) / 2 + (x1 - x3) / 2,
            (y1 + y2) / 2 + (y1 - y3) / 2,
            (x1 + x2) / 2 + (x2 - x3) / 2,
            (y1 + y2) / 2 + (y2 - y3) / 2,
            (x1 + x2) / 2,
            (y1 + y2) / 2);


        podder(
			
			fract,
            kol + 3,
            (x3 + x2) / 2 + (x3 - x1) / 2,
            (y3 + y2) / 2 + (y3 - y1) / 2,
            (x3 + x2) / 2 + (x2 - x1) / 2,
            (y3 + y2) / 2 + (y2 - y1) / 2,
            (x3 + x2) / 2,
            (y3 + y2) / 2);

        podder(
			
			fract,
            kol + 3,
            (x1 + x3) / 2 + (x1 - x2) / 2,
            (y1 + y3) / 2 + (y1 - y2) / 2,
            (x1 + x3) / 2 + (x3 - x2) / 2,
            (y1 + y3) / 2 + (y3 - y2) / 2,
            (x1 + x3) / 2,
            (y1 + y3) / 2);

    }
	
	//window.draw(tri);
}

