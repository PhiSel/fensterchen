#include "fensterchen.hpp"
#include "rectangle.hpp"
#include "circle.hpp"
#include <cmath>

int main(int argc, char* argv[])
{
  Window win(glm::ivec2(600,600));

  while (!win.shouldClose()) {
    if (win.isKeyPressed(GLFW_KEY_ESCAPE)) {
      win.stop();
    }

    auto t = win.getTime();
    float x1(0.5 + 0.5 * std::sin(t)); float y1(0.5 + 0.5 * std::cos(t));
    float x2(0.5 + 0.5 * std::sin(2.0*t)); float y2(0.5 + 0.5 * std::cos(2.0*t));
    float x3(0.5 + 0.5 * std::sin(t-10.f)); float y3(0.5 + 0.5 * std::cos(t-10.f));

    win.drawPoint(x1, y1, 255, 0, 0);
    win.drawPoint(x2, y2, 0, 255, 0);
    win.drawPoint(x3, y3, 0, 0, 255);

    auto m = win.mousePosition();
    win.drawLine(0.1f,0.1f, 0.8f,0.1f, 255,0,0);

    win.drawLine(0.0f, m.y, 0.01f, m.y, 0,0,0);
    win.drawLine(0.99f, m.y,1.0f, m.y, 0,0,0);

    win.drawLine(m.x, 0.0f, m.x, 0.01f, 0,0,0);
    win.drawLine(m.x, 0.99f, m.x, 1.0f, 0,0,0);

    //Begrenzungsrahmen (beim Mac unteres linkes Viertel)
    win.drawLine(1.0f, 0.0f, 1.0f, 1.0f, 0, 0, 0);
    win.drawLine(0.0, 1.0f, 1.0f, 1.0f, 0, 0, 0);

    //Zeichnen eines Rechtecks mit Anpassung der Linienfarbe bei Mouseover
    Rectangle rectangle{{0.35, 0.2}, 0.3, 0.4, {0, 255, 0}};

    if (rectangle.is_inside({m.x,m.y}))
    {
      rectangle.draw(win, {0, 0, 255});
    }else{
      rectangle.draw(win);
    }

    //Test der translate-Funktion an einem Viereck-Punkt (funktioniert nicht)
    auto rectangle1(rectangle);
    auto rectangle2(rectangle);
    rectangle1.color({206, 19, 182});
    rectangle1.translate(0.2, 0.3);
    rectangle2.color({206, 19, 182});
    rectangle2.translate(-0.2, 0.3);
    
    //rectangle1.draw(win);  

    if (rectangle1.is_inside({m.x,m.y}))
    {
      rectangle1.draw(win, {0, 0, 255});
    }else{
      rectangle1.draw(win);
    }

    if (rectangle2.is_inside({m.x,m.y}))
    {
      rectangle2.draw(win, {0, 0, 255});
    }else{
      rectangle2.draw(win);
    }

    //Zeichnen eines Kreises
    Circle circle{{0.5, 0.32}, 0.1, {255, 0, 0}};
    Circle circle1{{0.23,0.75}, 0.05, {0}};
    Circle circle2{{0.65,0.75}, 0.05, {0}};
    circle1.draw(win);
    circle2.draw(win);
    
    if (circle.is_inside(Point2d(m.x,m.y))) 
    {
      circle.draw(win, {0, 0, 255});
    }else{
      circle.draw(win);
    }
    
    
    win.update();
  }

  return 0;
}
