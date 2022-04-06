#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Deniz's window");
    sf::CircleShape circle(120.0);
    circle.setPosition(200.0, 0.0);
    circle.setFillColor(sf::Color(250, 200, 50));

    sf::RectangleShape rectangle(sf::Vector2f(120.0, 60.0));
    rectangle.setPosition(500.0, 400.0);
    rectangle.setFillColor(sf::Color(100, 50, 250));

    sf::ConvexShape triangle;
    triangle.setPointCount(3);
    triangle.setPoint(0, sf::Vector2f(0.0, 0.0));
    triangle.setPoint(1, sf::Vector2f(0.0, 100.0));
    triangle.setPoint(2, sf::Vector2f(140.0, 40.0));
    triangle.setOutlineColor(sf::Color::Red);
    triangle.setOutlineThickness(5);
    triangle.setPosition(600.0, 100.0);
    sf::Clock clock;



    while (window.isOpen()) {
        sf::Time elapsed = clock.restart();


        rectangle.move(+100.0*elapsed.asSeconds(),60.0*elapsed.asSeconds());

        sf::Event event;
        while (window.pollEvent(event)) {

            if (event.type == sf::Event::Closed)
                window.close();
        }


        window.clear(sf::Color::Black);
        window.draw(circle);
        window.draw(rectangle);
        window.draw(triangle);
        window.display();
    }

    return 0;

}
