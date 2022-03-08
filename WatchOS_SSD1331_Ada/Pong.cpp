#include "Pong.h"
extern void print3(byte );
extern bool lastLeft;
Pong::Pong() {

  directionx = random(2);
  player.x = display.width() - 1;
  player.y = 0;
  player.w = 1;
  player.h = 19;
  player.score = 0;
  ai.x = 0;
  ai.y = 0;
  ai.w = player.w;
  ai.h = player.h;
  ai.score = 0;
  ball.x = 48;
  ball.y = 32;
  ball.r = 2;
  Countdown();
}
void Pong::Up() {
  if (player.y != 0 && !pause) {
    player.y -= 1;
  }
}
void Pong::Down() {
  if (player.y + 20 != 64 && !pause) {
    player.y += 1;
  }
}
void Pong::Left() {
  if (!lastLeft) {
    pause = !pause;
  }
}
void Pong::Right() {

}
void Pong::Special() {

}
void Pong::Specialholdoff() {

}
void Pong::displayAll() {

  if (ball.y > ai.y && ai.y != 63) {
    ai.y += 1;
  }
  if (ball.y < ai.y + ai.w-random(4)+1 && ai.y != 0) {
    ai.y -= 1;
  }
  ai.draw(RED);
  player.draw(BLUE);
  /*
    display.fillRect(0, ai_y, 5, 20, WHITE);
    display.fillRect(123, player_y, 5, 20,WHITE);
  */
  byte d_w = display.width();
  //display.fillRect(d_w/2-1,0,2,63,WHITE);
  display.setTextColor(RED);
  display.setCursor(20, 0);
  print3(ai.score);
  display.setTextColor(BLUE);
  display.setCursor(67, 0);
  print3(player.score);
  display.fillCircle(ball.x, ball.y, ball.r, BLACK);
  if (!pause) {
    checkCollision(true);
    checkCollision(false);
    if ( (ball.x != 0 && !(ball.x > 200)) && ball.x != display.width() - 1) {
      if (directionx == 0) {
        ball.x -= 1;
      }
      else {
        ball.x += 1;
      }
    }
    else {
      directionx = random(2);
      if (ball.x == display.width() - 1) {
        ai.score++;
      }
      if (ball.x == 0 || (ball.x > 200)) {
        player.score ++;
      }

      ball.x = 48;
      ball.y = 32;
      directiony = 1;
      display.setTextSize(2);
      display.fillScreen(BLACK);
      display.setCursor(0, 23);
      display.setTextColor(RED);
      print3(ai.score);
      display.setCursor(50, 23);
      display.setTextColor(BLUE);
      print3(player.score);
      delay(2500);
      display.fillScreen(BLACK);
      display.setTextSize(1);
    }
    if ((!(ball.y >= 200)) && (ball.y <= 63)) {
      if (directiony == 0) {
        ball.y += 1;
      }
      if (directiony == 1) {

      }
      if (directiony == 2) {
        ball.y -= 1;
      }
    }
    else {
      if ( ball.y >= 200) {
        ball.y = 2;
        directiony = 0;
      }
      else {
        directiony = 2;
        ball.y -= 1;
      }
    }
  }

  //Clear display
  display.fillRect(display.width() - 1, 0, 1, 64, BLACK);
  display.fillRect(0, 0, 1, 64, BLACK);
  display.fillCircle(ball.x, ball.y, ball.r, YELLOW);


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
  if (rect == true) {
    if (player.intersects(ball)) {
      directionx = 0;
      directiony = random(3);
    }
  }
  else {
    if (ai.intersects(ball)) {
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
void Pong::Countdown() {
  display.setTextSize(3);
  display.setCursor(40, 21);
  display.fillScreen(BLACK);
  display.print("3");
  delay(1000);
  display.setCursor(40, 21);
  display.fillScreen(BLACK);
  display.print("2");
  delay(1000);
  display.setCursor(40, 21);
  display.fillScreen(BLACK);
  display.print("1");
  delay(1000);
  display.fillScreen(BLACK);
  display.setTextSize(1);
  display.fillScreen(BLACK);

}
