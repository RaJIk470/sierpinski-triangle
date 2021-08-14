#include<SFML/Graphics.hpp>
#include<iostream>

sf::Vector2f calculatePosition(sf::Vector2f a, sf::Vector2f b)
{
  sf::Vector2f position((a.x + b.x) / 2, (a.y + b.y) / 2); 
  return position;
}

sf::VertexArray getPoints(sf::VertexArray points, int numberOfPoints)
{
  sf::VertexArray newPoints(sf::Points, numberOfPoints);
  sf::Vector2f startPosition = points[0].position;
  for (int i = 0; i < numberOfPoints; ++i)
  {
    int pointnumber = rand() % 3;      
    newPoints[i].position = calculatePosition(startPosition, points[pointnumber].position); 
    startPosition = newPoints[i].position;
  }
  return newPoints;
}

int main()
{
  srand(time(0));
  sf::RenderWindow window(sf::VideoMode(500, 500), "fractal");
 
  int numberOfPoints;
  std::cin >> numberOfPoints;

  sf::VertexArray startPoints(sf::Points, 3);
  startPoints[0].position = sf::Vector2f(10.f, 240.f);
  startPoints[1].position = sf::Vector2f(240.f, 10.f);
  startPoints[2].position = sf::Vector2f(480.f, 240.f);

  sf::CircleShape shape(2.f);
  shape.setFillColor(sf::Color::Red);
//  window.draw(shape, point1);
//  window.draw(shape, point2);
//  window.draw(shape, point3);
  window.clear(sf::Color::Black);
  window.draw(startPoints);
  sf::VertexArray points(sf::Points, numberOfPoints);
  points = getPoints(startPoints, numberOfPoints);
  window.draw(points);
  window.display();

  while (window.isOpen())
  {
    sf::Event event;
    while (window.pollEvent(event))
    {
      if (event.type == sf::Event::Closed)
        window.close();
    }
  }
  return 0;
}

