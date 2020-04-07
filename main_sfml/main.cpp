//librerias
#include <SFML/Graphics.hpp>
#include "mundo_main.h"

using namespace std;

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600),"LLUVIA DE CAJETAS"); //Creamos una ventana con dimensiones 800x600. 
	window.setFramerateLimit(60);

	sf::Event event; //Creamos un objeto tipo evento, llamado event. 
	sf::Clock clock; //Para llevar el tiempo que toma hacer un frame en el ciclo de window. 

	//Cargando sprites. 
	sf::Texture boxTex1;
	sf::Sprite boxSprite1;

	if (!boxTex1.loadFromFile("Assets/Sprites/box1.png"))
	{
		cout << "Could not load texture. . ." << endl;
		system("pause");
	}

	//Configuramos nuestro mundo. 
	world w1;
	w1.instansgravity(vect_2(0.0f, 900.0f));

	cuerpo b1;
	b1.massvalue(1.0f);
	b1.intanspos(vect_2(100.0f, 0.0f));
	b1.intansvel(vect_2(350.0f, 0.0f));

	w1.addbody(&b1);

	//Configurando sprites.

	boxSprite1.setTexture(boxTex1);
	boxSprite1.setScale(sf::Vector2f(0.35f, 0.35f));

	//Colocamos el origen del sprite en el centro del sprite. 
	sf::Rect<float> size = boxSprite1.getGlobalBounds();
	boxSprite1.setOrigin(sf::Vector2f(size.width / 2, size.height / 2));

	//Para ilustrar lo que queremos... colocaremos la cajita en el centro de la pantalla.
	//El sprite usa la misma posición inicial que se le da al cuerpo en la configuración de cuerpo.
	boxSprite1.setPosition(sf::Vector2f(b1.getpos().getX(), b1.getpos().getY()));


	//Lo que sucede en la pantalla...
	while (window.isOpen()) //Se mantiene el ciclo while mientras la ventana esté abierta. 
	{
		while (window.pollEvent(event)) //Lee si hubo alguna señal de entrada (mouse, teclado, joystick...) 
		{
			if (event.type == sf::Event::Closed) //Si el usuario presiona X (para salir de la ventana)...
			{
				window.close(); //... Cierra la ventana
			}
		}

		//Calculo el tiempo que toma hacer un frame.
		sf::Time elapsed = clock.restart();
		float dt = elapsed.asSeconds();

		//Uso el tiempo calculado para usar la función Step() de World w1.
		w1.step(dt);

		boxSprite1.setPosition(sf::Vector2f(b1.getpos().getX(), b1.getpos().getY()));

		window.clear(sf::Color::Black);
		window.draw(boxSprite1);
		window.display();
	}

	return 0;
}