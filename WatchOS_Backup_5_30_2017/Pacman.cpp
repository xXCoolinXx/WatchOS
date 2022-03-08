/*
 * Pacman.cpp
 *
 * Created: 4/30/2017 4:12:13 PM
 *  Author: A cool dude
 */ 
 #include "Pacman.h"
 extern void print3(byte);
const byte aghost[]  PROGMEM  = {
 0x1f, 0x80,
 0x7f, 0xe0,
 0xc6, 0x30,
 0xc6, 0x30,
 0xc6, 0x30,
 0xff, 0xf0,
 0xff, 0xf0,
 0xff, 0xf0,
 0xff, 0xf0,
 0xff, 0xf0,
 0xd9, 0xb0,
 0x89, 0x10
 };
 
 const byte pac_right[] PROGMEM = {
0x1f, 0xc0,
0x7f, 0xf0,
0x7f, 0xf8,
0xff, 0xf8,
0xff, 0xf0,
0xff, 0x00,
0xfc, 0x00,
0xff, 0x00,
0xff, 0xf0,
0xff, 0xf8,
0x7f, 0xf8,
0x7f, 0xf0,
0x1f, 0xc0
 };
 const byte pac_left[] PROGMEM {
0x1f, 0xc0,
0x7f, 0xf0,
0xff, 0xf0,
0xff, 0xf8,
0x7f, 0xf8,
0x07, 0xf8,
0x01, 0xf8,
0x07, 0xf8,
0x7f, 0xf8,
0xff, 0xf8,
0xff, 0xf0,
0x7f, 0xf0,
0x1f, 0xc0
};

const byte pac_up[] PROGMEM {
0x30, 0x60,
0x78, 0xf0,
0x78, 0xf0,
0xf8, 0xf8,
0xf8, 0xf8,
0xfd, 0xf8,
0xfd, 0xf8,
0xff, 0xf8,
0xff, 0xf8,
0xff, 0xf8,
0x7f, 0xf0,
0x7f, 0xf0,
0x1f, 0xc0
};

const byte pac_down[] PROGMEM  {
0x1f, 0xc0,
0x7f, 0xf0,
0x7f, 0xf0,
0xff, 0xf8,
0xff, 0xf8,
0xff, 0xf8,
0xfd, 0xf8,
0xfd, 0xf8,
0xf8, 0xf8,
0xf8, 0xf8,
0x78, 0xf0,
0x78, 0xf0,
0x30, 0x60

};
Pacman::Pacman()
{

}

 void Pacman::Up() {
	direction = 3;
}

void Pacman::Down() {
	direction = 0;
}

void Pacman::Left()
{
	direction = 1;
}

void Pacman::Right()
{
	direction = 2;
}

void Pacman::Special()
{

}

void Pacman::Specialholdoff()
{

}

void Pacman::displayAll()
{
display.drawRect(38,27,52,22, WHITE);
display.drawLine(53,27, 73, 27, BLACK);
display.fillRect(55,26,16,3,WHITE);
	if(direction == 2) {
		pacman.x++;
		display.drawBitmap(pacman.x, pacman.y, pac_right, pacman.w, pacman.h, WHITE);
	}
	else if(direction == 1) {
		display.drawBitmap(pacman.x, pacman.y, pac_left, pacman.w, pacman.h, WHITE);
		pacman.x--;
	}
	if(direction == 0) {
		display.drawBitmap(pacman.x, pacman.y, pac_down, pacman.w, pacman.h, WHITE);
		pacman.y++;
	}
	else if(direction == 3) {
		display.drawBitmap(pacman.x, pacman.y, pac_up, pacman.w, pacman.h, WHITE);
		pacman.y--;
	}
	if(direction == 255) {
		display.drawBitmap(pacman.x, pacman.y, pac_right, pacman.w, pacman.h, WHITE);
	}
  display.setCursor(0, 54);
	display.print(F("Score: "));
  print3(score);
  display.print(F(" Lives: "));
  print3(lives);
	for(int i = 0; i < 4; i++) {
		display.drawBitmap(ghosts[i].x, ghosts[i].y, aghost, ghosts[i].w, ghosts[i].h, WHITE);
		if(pacman.intersects(ghosts[i])) {
			if(eat) {
				score +=1;
			}
			else {
				lives--;
				pacman.x = 57;
				pacman.y = 50;
				pacman.w = 13;
				pacman.h = 13;
				pacman = {57, 50, 13,13};
				ghosts[0] = Rect{57,10,12,12};
				ghosts[1] = Rect{43,32,12,12};
				ghosts[2] = Rect{58,32,12,12};
				ghosts[3] = Rect{73,32,12,12};
        direction = 255;
			}
			
		}
	}
	if(lives == 0) {
		display.clearDisplay();
		display.setTextSize(4);
		display.print(F("FAIL"));
    display.display();
    delay(1000);
    lives = 3;
    eat =false;
	}
	
}

