//libreiraswddddwadwdwadwadw
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "mundo_main.h"

//yo uso esto por que no me gusta el escribir eso todo largo XD
using namespace std;
using namespace sf;

int main()
{
    RenderWindow window(VideoMode(540, 476), "Proyect glaiding");
    window.setFramerateLimit(60);//limitamos los fames

    //creamos el eventos 
    Event event;
    //para controlas el tienpo de los frames
    Clock clock;

    //variables de salto
    bool boolSpace = false;
    bool boolAir = false;

    //varables de movimiento
    bool stay = true;
    bool walckD = false;
    bool walckA = false;

    //variables para correr
    bool run = false;


    //cargamos los fondos
    Texture txt_fondo_1;
    Sprite spr_fondo_1;
    Texture txt_fondo_2;
    Sprite spr_fondo_2;


    //cargamos el piso
    Texture txt_floor;
    Sprite spr_floor;

    //cargamos el personaje
    Texture txt_player;
    Sprite spr_player;

    //declaramos para el fondo 
    if (!txt_fondo_1.loadFromFile("Assets/fondos/fondo_1.png")) {
        cout << " fondo_1 no se encuentra" << endl;
    }
    if (!txt_fondo_2.loadFromFile("Assets/fondos/fondo_2.png")) {
        cout << " fondo_2 no se encuentra" << endl;
    }
    if (!txt_floor.loadFromFile("Assets/platform/plataforma.png")) {
        cout << " la plataforma no se encuentra" << endl;
    }
    if (!txt_player.loadFromFile("Assets/player/idle.png")) {
        cout << "el player no se encuntra" << endl;
    }

    //ahora lo seteamos en los sprites
    spr_fondo_1.setTexture(txt_fondo_1);
    spr_fondo_2.setTexture(txt_fondo_2);
    spr_player.setTexture(txt_player);
    spr_floor.setTexture(txt_floor);


    //le setamos el tamaño
    spr_fondo_1.setScale(Vector2f(2.3f, 2.7f));
    spr_fondo_2.setScale(Vector2f(2.0f, 2.7f));
    spr_player.setScale(Vector2f(2.0f, 2.0f));
    spr_floor.setScale(Vector2f(7.0f, 5.0f));

    //configuramos el cuerpo 
    world player;
    player.instansgravity(vect_2(0.0f, 550.0f));//gavedad del objeto
    //lo setea en el origen de la ventana
    cuerpo _player; 
    _player.mass = 2.0f;
    _player.invmass = 1 / _player.mass;
    _player.position = vect_2(400.0f, 430.0f);
    _player.velocity = vect_2(0.0f, 0.0f);

    player.addbody(&_player);

    //seteamos el centro del perosonaje
    Rect<float> size = spr_player.getGlobalBounds();
    spr_floor.setOrigin(Vector2f(9.0f, -30.9f)); 
    spr_player.setOrigin(Vector2f(size.width / 2, size.height / 2));

    spr_player.setPosition(Vector2f(_player.position.x, _player.position.y));

 
    //pocicion de los objetos
    
    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
            if (event.type == Event::KeyPressed)
            {
                //salto 
                if (event.key.code == Keyboard::Space)
                {
                    boolSpace = true;
                    cout << "Space pressed!" << endl;
                }

                //caminar
                if (event.key.code == Keyboard::D) {
                    walckD = true;
                    cout << "D pressed!" << endl;
                }
                if (event.key.code == Keyboard::A) {
                    walckA = true;
                    cout << "A pressed!" << endl;
                }

                //correr
                if (event.key.code == Keyboard::LShift) {
                    run = true;
                    cout << "run" << endl;
                }
            }
            //mientra no este presionada 
            if (event.type == Event::KeyReleased)
            {
                //salto
                if (event.key.code == Keyboard::Space)
                { 
                    boolSpace = false;
                }
                //caminar
                if (event.key.code == Keyboard::D) {
                    walckD = false;
                }
                if (event.key.code == Keyboard::A) {
                    walckA = false;
                }

                //corrrer
                if (event.key.code == Keyboard::LShift) {
                    run = false;
                }

            }

        }
        
       //mientra esta en el arie 
        if (!boolAir)
        {
            if (boolSpace ) 
            {
                _player.velocity.y =-400.0f;
                boolAir = true;
            }
        }
        
        //caminar hacia la derecha
        if (walckD) {
            _player.velocity.x = 100.0f;
        }

        //caminar hacia la izquierda
        if (walckA) {
            _player.velocity.x = -100.0f;
        }

        //correr
        if (walckA && run) {
            _player.velocity.x = -400.0f;
        }

        if (walckD && run) {
            _player.velocity.x = 400.0f;
        }

        sf::Time elapsed = clock.restart();
        float dt = elapsed.asSeconds();

        //uso el tiempo calculado para la funcion step() 
        player.step(dt);

        if (_player.position.y >= 430.0f){
            _player.position.y = 430.0f;
            boolAir = false;
        }

        _player.velocity.x = 0.0f;


        //yo lo intente con las coordenadas que le puse primeramente al personaje, pero  no se si es como lo copio o como lo implemente  no funciono
        spr_player.setPosition(Vector2f(_player.position.x, _player.position.y));

        window.clear(Color::Transparent);
        window.draw(spr_fondo_1);
        window.draw(spr_fondo_2);
        window.draw(spr_floor);
        window.draw(spr_player);
        window.display();
    }

    return 0;
}
