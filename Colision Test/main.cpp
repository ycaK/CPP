#include <SFML/Graphics.hpp>

bool colisionCheck(int borderY, int boxY, int boxHeight)
{
    int colision = (borderY - boxY) - boxHeight;
    int minusBoxHeight = boxHeight * -1;
    if(colision < 0 && colision > minusBoxHeight)
    {
        return false;
    }
    else
    {
        return true;
    }
}

bool colisionCheckDown(int boxY, int boxY2, int boxHeight2)
{
    int colision = (boxY - boxY2) - boxHeight2;
    int minusBoxHeight2 = boxHeight2 * -1;
    if(colision < 0 && colision > minusBoxHeight2)
    {
        return false;
    }
    else
    {
        return true;
    }
}

bool nearUp(int boxX, int boxX2, int boxWidth, int boxWidth2)
{
    if(boxX2 > boxX + boxWidth || boxX2 < boxX - boxWidth2)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool nearDown(int boxX2, int boxX, int boxWidth2, int boxWidth)
{
    if(boxX > boxX2 + boxWidth2 || boxX < boxX2 - boxWidth)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    sf::RenderWindow window(sf::VideoMode(400, 400), "Game");

    int boxWidth = 40;
    int boxHeight = 40;
    int boxX = 100;
    int boxY = 310;

    int boxWidth2 = 100;
    int boxHeight2 = 40;
    int boxX2 = 100;
    int boxY2 = 200;

    int borderWidth = 400;
    int borderHeight = 40;
    int borderX = 0;
    int borderY = 360;

    sf::RectangleShape box2;
    box2.setSize(sf::Vector2f(boxWidth2, boxHeight2));
    box2.setPosition(boxX2, boxY2);
    box2.setFillColor(sf::Color::Green);

    sf::RectangleShape box;
    box.setSize(sf::Vector2f(boxWidth, boxHeight));
    box.setPosition(boxX, boxY);
    box.setFillColor(sf::Color::Black);

    sf::RectangleShape bgax;
    bgax.setSize(sf::Vector2f(400, 400));
    bgax.setFillColor(sf::Color::Blue);
    bgax.setPosition(0,0);

    sf::RectangleShape ptax;
    ptax.setSize(sf::Vector2f(400, 40));
    ptax.setPosition(0, 360);
    ptax.setFillColor(sf::Color::Green);

    while(window.isOpen())
    {
        int colision = (borderY - boxY) - boxHeight;
        sf::Event event;
        while(window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
                window.close();
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
            {
                if(nearUp(boxX, boxX2, boxWidth, boxWidth2))
                {
                    boxY += 1;
                    box.setPosition(boxX, boxY);
                }
                else
                    if(colisionCheck(borderY, boxY, boxHeight) && colisionCheck(boxY2, boxY, boxHeight))
                    {
                        boxY += 1;
                        box.setPosition(boxX, boxY);
                    }
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
                if(nearUp(boxY, boxY2, boxHeight, boxHeight2))
                {
                    boxX += 1;
                    box.setPosition(boxX, boxY);
                }
                else
                    if(colisionCheck(boxX2, boxX, boxWidth))
                    {
                        boxX += 1;
                        box.setPosition(boxX, boxY);
                    }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
                if(nearUp(boxY2, boxY, boxHeight2, boxHeight))
                {
                    boxX -= 1;
                    box.setPosition(boxX, boxY);
                }
                else
                    if(colisionCheck(boxX, boxX2, boxWidth2))
                    {
                        boxX -= 1;
                        box.setPosition(boxX, boxY);
                    }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
                if(nearDown(boxX2, boxX, boxWidth2, boxWidth))
                {
                    boxY -= 1;
                    box.setPosition(boxX, boxY);
                }
                else
                    if(colisionCheckDown(boxY, boxY2, boxHeight2))
                        boxY -= 1;
                        box.setPosition(boxX, boxY);
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
                //if(colisionCheckDown(boxY, boxY2, boxHeight2))
                    boxY -= 25;
                    box.setPosition(boxX, boxY);
            if(sf::Event::KeyReleased && event.key.code == sf::Keyboard::Space)
                //if(colisionCheckDown(boxY, boxY2, boxHeight2))
                    boxY += 25;
                    box.setPosition(boxX, boxY);
        }
        window.clear();
        window.draw(bgax);
        window.draw(ptax);
        window.draw(box2);
        window.draw(box);
        window.display();

    }
}
