#include "pch.h"
#include <iostream>
#include <cstdlib> 
#include <ctime> 
#include "SFML\Graphics.hpp"
#define WIDTH 600
#define HEIGHT 600
#define triangle 1
#define diamond 2
#define circle 0
#define poly 3
using namespace std;
using namespace sf;



		
	class shape 
	{
		CircleShape _shapes[4];
		Color shapeColor[4];

	public:
		shape()
		{
			_shapes[0] = CircleShape(70, 360); //circle
			_shapes[1] = CircleShape(80, 3); //triangle
			_shapes[2] = CircleShape(70,4);//diamond
			_shapes[3] = CircleShape(70, 5);//poly
			shapeColor[0] = { Color::Red };
			shapeColor[1] = { Color::Cyan };
			shapeColor[2] = { Color::Blue };
			shapeColor[3] = { Color::Magenta };
		}
		CircleShape getShape(int num,int num2)
		{
		CircleShape	shapeOut = _shapes[num];
		shapeOut.setFillColor(shapeColor[num2]);
		return shapeOut;
		}
	};
	

	
	CircleShape spawnShape(int sShape,int sColor);
	void draw(void);

	
	
int main()
{
	
	draw();
	
}
void draw(void)
{
	int sColor1 = 0;
	int sShape1 = 1;
	int sColor2 = 1;
	int sShape2 = 0;
	int sColor3 = 2;
	int sShape3 = 3;
	int sColor4 = 0;
	int sShape4 = 2;
	int score = 0;
	int lifes = 10;
	int colors1 = 0;
	int shapes1 = 0;
	int colors2 = 1;
	int shapes2 = 1;
	int colors3 = 2;
	int shapes3 = 2;
	int colors4 = 3;
	int shapes4 = 3;
	float yPos = 0;
	
	shape c;
	auto first = c.getShape(shapes1,colors1);
	first.setPosition(0, 455);
	auto second = c.getShape(shapes2,colors2);
	second.setPosition(150, 455);
	auto third = c.getShape(shapes3,colors3);
	third.setPosition(290, 455);
	auto fourth = c.getShape(shapes4,colors4);
	fourth.setPosition(460, 455);
	auto sFirst = c.getShape(sShape1,sColor1);
	sFirst.setPosition(0,0);
	auto sSecond = c.getShape(sShape2,sColor2);
	sSecond.setPosition(150, 0);
	auto sThird = c.getShape(sShape3,sColor3);
	sThird.setPosition(290,0);
	auto sFourth = c.getShape(sShape4,sColor4);
	sFourth.setPosition(460,0);
	Event e;
	RenderWindow window(VideoMode(HEIGHT, WIDTH), "SFML works!");
	window.setFramerateLimit(60);
	while (window.isOpen())
	{
		window.pollEvent(e);
		switch (e.type)
		{
		case Event::KeyPressed:
			if (Keyboard::isKeyPressed(Keyboard::A)) //change shape
			{
				while (shapes1 < 4)
				{
					if (shapes1!=3)
					{
						shapes1++;
						break;
					}
					else
					{
						shapes1 = 0;
						break;
					}
					
				}
				
			} 
         if (Keyboard::isKeyPressed(Keyboard::S)) //change shape
			{
				while (shapes2 < 4)
				{
					if (shapes2 != 3)
					{
						shapes2++;
						break;
					}
					else
					{
						shapes2 = 0;
						break;
					}
				}
			}
		
			if (Keyboard::isKeyPressed(Keyboard::D))
			{
				while (shapes3 < 4)
				{
					if (shapes3 != 3)
					{
						shapes3++;
						break;
					}
					else
					{
						shapes3 = 0;
						break;
					}
				}
			}
		 if (Keyboard::isKeyPressed(Keyboard::F))
			{
				while (shapes4 < 4)
				{
					if (shapes4 != 3)
					{
						shapes4++;
						break;
					}
					else
					{
						shapes4 = 0;
						break;
					}
				}
			}
		 if (Keyboard::isKeyPressed(Keyboard::H))
			{
				while (colors1 < 4)
				{
					if (colors1 != 3)
					{
						colors1++;
						break;
					}
					else
					{
						colors1 = 0;
						break;
					}
				}
			}
		if (Keyboard::isKeyPressed(Keyboard::J))
			{
				while (colors2 < 4)
				{
					if (colors2 != 3)
					{
						colors2++;
						break;
					}
					else
					{
						colors2 = 0;
						break;
					}
				}
			}
		 if (Keyboard::isKeyPressed(Keyboard::K))
			{
				while (colors3 < 4)
				{
					if (colors3 != 3)
					{
						colors3++;
						break;
					}
					else
					{
						colors3 = 0;
						break;
					}

				}
			}
		 if (Keyboard::isKeyPressed(Keyboard::L))
			{
			 while (colors4 < 4)
			    {
				if (colors4 != 3)
				{
					colors4++;
					break;
				}
				else
				{
					colors4 = 0;
					break;
				}
			   }
			}
		default:
			break;
		}
			first = c.getShape(shapes1, colors1);
			first.setPosition(0, 455);
			second = c.getShape(shapes2, colors2);
			second.setPosition(150, 455);
			third = c.getShape(shapes3, colors3);
			third.setPosition(290, 455);
			fourth = c.getShape(shapes4, colors4);
			fourth.setPosition(460, 455);
		window.clear();
		
		if (lifes >= 0)
		{
			if (yPos < 455)
			{
				window.draw(sFirst);
				sFirst.move(0, 1);

				window.draw(sSecond);
				sSecond.move(0, 1);

				window.draw(sThird);
				sThird.move(0, 1);

				window.draw(sFourth);
				sFourth.move(0, 1);
				
				yPos = yPos + 1;
			}
			else
			{
				if ((sColor1 == colors1) && (sShape1 == shapes1))
				{
					score++;
					printf("match\n");
				}
				else
				{
					lifes--;
					printf("not match\n");
				}

				if ((sColor2 == colors2) && (sShape2 == shapes2))
				{
					score++;
					printf("match\n");
				}
				else
				{
					lifes--;
					printf("not match\n");
				}

				if ((sColor3 == colors3) && (sShape3 == shapes3))
				{
					score++;
					printf("match\n");
				}
				else
				{
					lifes--;
					printf("not match\n");
				}


				if ((sColor4 == colors4) && (sShape4 == shapes4))
				{
					score++;
					printf("match\n");
				}
				else
				{
					lifes--;
					printf("not match\n");
				}
				if (sShape1 < 3)
				{  
					if (sColor1 < 3)
					{
						sColor1++;
					}
					else
					{
						
						sColor1 = 0;
					}
						sShape1++;
				}
				else
				{
					
						if (sColor1 < 3)
						{
							sColor1++;
						}
						else
						{
							sColor1 = 0;
						}
						sShape1 = 0;
				}
				//shape 2
				if (sShape2 < 3)
				{
					if (sColor2 < 3)
					{
						sColor2++;
					}
					else
					{

						sColor2 = 0;
					}
					sShape2++;
				}
				else
				{

					if (sColor2 < 3)
					{
						sColor2++;
					}
					else
					{
						sColor2 = 0;
					}
					sShape2 = 0;
				}
				//shape 3 
				if (sShape3 < 3)
				{
					if (sColor3 < 3)
					{
						sColor3++;
					}
					else
					{

						sColor3 = 0;
					}
					sShape3++;
				}
				else
				{

					if (sColor3 < 3)
					{
						sColor3++;
					}
					else
					{
						sColor3 = 0;
					}
					sShape3 = 0;
				}
				if (sShape4 < 3)
				{
					if (sColor4 < 3)
					{
						sColor4++;
					}
					else
					{

						sColor4 = 0;
					}
					sShape4++;
				}
				else
				{

					if (sColor4 < 3)
					{
						sColor4++;
					}
					else
					{
						sColor4 = 0;
					}
					sShape4 = 0;
				}			    
				sFirst = c.getShape(sShape1, sColor1);
				sFirst.setPosition(0, 0);
				window.draw(sFirst);
				sSecond = c.getShape(sShape2, sColor2);
				sSecond.setPosition(150, 0);
				window.draw(sSecond);
				sThird = c.getShape(sShape3, sColor3);
				sThird.setPosition(290, 0);
				window.draw(sThird);
				sFourth = c.getShape(sShape4, sColor4);
				sFourth.setPosition(460, 0);
				window.draw(sFourth);
				yPos = 0;
			}
		window.draw(first);
		window.draw(second);
		window.draw(third);
		window.draw(fourth);
		window.display();
		}
			
		
		
	}
}

CircleShape spawnShape(int sShape,int sColor)
{
	shape sh;
	CircleShape spawnned = sh.getShape(sShape, sColor);

	return spawnned;
}
