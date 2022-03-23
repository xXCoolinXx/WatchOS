#include "Pong.h"
#include "Kernel.h"

Pong::Pong(Kernel* kernel) : App(kernel) {
  reset_ball();  
}

String Pong::get_name() {
  return String("Pong");
}

void Pong::run_code(double x, double y, bool special, Kernel* kernel) {
  RectDouble user_last = user_move(x, y, kernel);
  RectDouble comp_last = comp_move(kernel);
  RectDouble ball_last = ball_move(kernel);

  kernel->display.fillRect(comp_last.x, comp_last.y, comp_last.width, comp_last.height, BLACK);
  kernel->display.fillRect(comp_pad .x, comp_pad .y, comp_pad .width, comp_pad .height, WHITE);

  kernel->display.fillRect(user_last.x, user_last.y, user_last.width, user_last.height, BLACK);
  kernel->display.fillRect(user_pad .x, user_pad .y, user_pad .width, user_pad .height, WHITE);

  kernel->display.fillCircle(ball_last.x, ball_last.y, ball_last.width / 2, BLACK);
  kernel->display.fillCircle(ball     .x, ball     .y, ball     .width / 2, WHITE);

  kernel->display.fillRect((SCREEN_WIDTH - 2) / 2, 0, 2, SCREEN_HEIGHT, WHITE); //Center line
}

RectDouble Pong::user_move(double x, double y, Kernel* kernel) {
  RectDouble last = user_pad;
  
  double fps_ratio = 80.00 / kernel->get_fps(); 
  user_pad.y = min(double(kernel->display.height() - user_pad.height), max(0.00, user_pad.y + fps_ratio * y));

  return last;
}

RectDouble Pong::comp_move(Kernel* kernel) {
  RectDouble last = comp_pad;

  double dif = (ball.y - ball.height / 2) - (comp_pad.y - comp_pad.height / 2);
  double mov = abs(dif) / dif;
  double fps_ratio = 80.00 / kernel->get_fps(); 

  comp_pad.y = min(double(kernel->display.height() - comp_pad.height), max(0.00, comp_pad.y + fps_ratio * mov));

  return last;
}

RectDouble Pong::ball_move(Kernel* kernel) {
  RectDouble last = ball;
  
  double fps_ratio = 80.00 / kernel->get_fps(); 
  
  //Move forward
  ball.x += ball_speed * fps_ratio * cos(ball_angle);
  ball.y += ball_speed * fps_ratio * sin(ball_angle); 
  ball.x  = min(max(ball.x, 0.00), double(SCREEN_WIDTH  - BALL_DIAMETER));
  ball.y  = min(max(ball.y, 0.00), double(SCREEN_HEIGHT - BALL_DIAMETER));

  //Bounce off walls
  if(ball.y == 0) {
    ball_angle += (ball_angle > pi/2) ? pi/4 : 3*pi/2;
  } else if (ball.y == SCREEN_HEIGHT - BALL_DIAMETER) {
    ball_angle += (ball_angle < 3*pi/2) ? -1 * pi/4 : -3*pi/2;
  }
  
  //Check paddles
  if(not check_collisions()) 
  {
    if(ball.x == 0) {
      user_score++;
      reset_ball();
    } else if (ball.x == SCREEN_WIDTH - BALL_DIAMETER) {
      comp_score++;
      reset_ball();
    }
  }
  
  return last;
}

void Pong::reset_ball() {
  ball.x = (SCREEN_WIDTH  - BALL_DIAMETER) / 2;
  ball.y = (SCREEN_HEIGHT - BALL_DIAMETER) / 2;

  ball_angle = random(360) * pi / 180;
}

bool Pong::check_collisions() {
  if(ball.intersect(user_pad)) {
    double dif = (ball.y - ball.height / 2) - (user_pad.y - user_pad.height / 2);
    ball_angle += (ball_angle < pi / 2) ? pi/4 : -3*pi / 2;
    return true;
  } else if (ball.intersect(comp_pad)) {
    ball_angle += (ball_angle > pi) ? pi/4 : -pi/4;
    return true;
  } else {
    return false;
  }
}
