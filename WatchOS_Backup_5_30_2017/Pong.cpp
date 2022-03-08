#include "Pong.h"
extern void print3(byte );

Pong::Pong() {

	directionx = random(2);
  player.x = display.width()-5;
  player.y = 0;
  player.w = 5;
  player.h = 20;
  player.score = 0;
  ai.x = 0;
  ai.y = 0;
  ai.w = 5;
  ai.h = 20;
  ai.score = 0;
  ball.r=4;
}
void Pong::Up() {
	if(player.y != 0){ 
		player.y-=2;
	}
}
void Pong::Down() {
	if(player.y+20 != 64) {
		player.y+=2;
	}
}
void Pong::Left() {

}
void Pong::Right() {

}
void Pong::Special() {

}
void Pong::Specialholdoff() {

}
void Pong::displayAll() {
	if(ball.y > ai.y && ai.y != 63) {
		ai.y+= 1;
	}
	if(ball.y < ai.y+20 && ai.y !=0) {
		ai.y-= 1;
	}
	ai.draw();
  player.draw();
	/*
	display.fillRect(0, ai_y, 5, 20, WHITE);
	display.fillRect(123, player_y, 5, 20,WHITE);
	*/
	byte d_w = display.width();
	display.fillRect(d_w/2-1,0,2,63,WHITE);
	display.setCursor(35, 28);
	print3(ai.score);
	display.setCursor(75,28);
	print3(player.score);
	display.fillCircle(ball.x, ball.y, ball.r,WHITE);
	checkCollision(true);
	checkCollision(false);
	if((ball.x != 0 && !(ball.x > 200)) && ball.x != d_w) {
		if(directionx == 0) {
			ball.x-=2;
		}
		else {
			ball.x+=2;
		}
	}
	else {
		directionx = random(2);
		if(ball.x == d_w) {
			ai.score++;
		}
		else {
			player.score ++;
		}

		ball.x = 63;
		ball.y = 31;
		directiony = 1;
	}
	if((!(ball.y >= 200)) && (ball.y <= 63)) {
		if(directiony == 0) {
			ball.y += 2;
		}
		if(directiony == 1) {

		}
		if(directiony == 2) {
			ball.y -= 2;
		}
	}
	else {
		if( ball.y >= 200) {
			ball.y = 2;
			directiony = 0;
		}
		else{
			directiony = 2;
			ball.y-=1;
		}
	}
}
void Pong::checkCollision(bool rect) {
	byte cx;
	if (rect)
	{
		cx = ball.x + 4;
	}
	else 
	{
		cx = ball.x - 4;
	}
  if(rect == true) {
    if(player.intersects(ball)) {
      directionx = 0;
      directiony = random(3);
    }
  }
  else{
    if(ai.intersects(ball)) {
      directionx = 1;
      directiony = random(3);
    }
  }
	/*if( (cx > 0 && cx <= 5) ||  (cx < 127 && cx >=  123) ) {
		if((ball.y >= y && ball.y <= y+20) || (ball.y+4 >= y && ball.y+4 <= y+20) || (ball.y-4 >= y && ball.y-4<= y+20)) {
			if(rect == true) {
				directionx = 0;
			}
			else {
				directionx = 1;
			}
			directiony = random(3);
		}
	}
	*/
}

