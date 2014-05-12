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
    win.drawLine(m.x, 0.99f,m.x, 1.0f, 0,0,0);

    //Test roter Punkt reagiert auf Mausposition
    if (m.y<0.5f && m.x<0.5f)
    {
        win.drawPoint(0.3f,0.3f,255,0,0);
    }else{
      win.drawPoint(0.3f,0.3f,0,255,0);
    }

    //Begrenzungsrahmen (beim Mac unteres linkes Viertel)
    win.drawLine(1.0f,0.0f, 1.0f,1.0f, 0,0,0);
    win.drawLine(0.0,1.0f,1.0f,1.0f,0,0,0);

    //Zeichnen eines Rechtecks mit Anpassung der Linienfarbe bei Mouseover ohne draw-Methode (weil Fehler)
    Rectangle rectangle = Rectangle(Point2d(0.2,0.2), 0.3, 0.4, ColorRGB(153,45,2));

    if (rectangle.is_inside(Point2d(m.x,m.y)))
    {
      rectangle.draw(win);
    }else{
      rectangle.draw(win, ColorRGB(255,0,0));
    }
    //Test der translate-Funktion an einem Punkt (funktioniert)
    Point2d x4 = Point2d(0.1,0.2);
    win.drawPoint(x4.x(), x4.y(), 0,0,0);

    x4.translate(0.1,0.2);
    win.drawPoint(x4.x(), x4.y(), 0,0,0);

    //Test der translate-Funktion an einem Viereck-Punkt (funktioniert nicht)
    auto rectangle1(rectangle);
    rectangle1.lowerleft().translate(0.4,0.5);
    win.drawPoint(rectangle1.lowerleft().x(), rectangle1.lowerleft().y(),0,255,0);  


    //Zeichnen eines Kreises
    Circle circle = Circle(Point2d(0.5,0.5),0.1,ColorRGB(0));
    Point2d ziel = Point2d(circle.center().x(),circle.center().y()+circle.radius());

    
    if (circle.is_inside(Point2d(m.x,m.y))) 
    {
      circle.draw(win);
    }else{
      circle.draw(win, ColorRGB(0,255,0));
    }
    
    
    win.update();
  }

  return 0;
}
