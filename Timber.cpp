#include <SFML/Graphics.hpp>

using namespace sf;

int main()
{
	//Create a video mode object
	VideoMode vm(1920, 1080);

	//Create and open a window for the game (Timber is the window's name)
	RenderWindow window(vm, "Timber!!!", Style::Fullscreen);

	//Create a texture to hold a graphic on the GPU (Class object)
	Texture textureBackground;

	//Load a graphic into the texture
	textureBackground.loadFromFile("graphics/background.png");

	//Create a sprite (Class object)
	Sprite spriteBackground;

	//Attach the texture to the sprite (assoc. Texture object with Sprite object)
	spriteBackground.setTexture(textureBackground);

	//Set the spriteBackground to cover the screen
	spriteBackground.setPosition(0, 0);

	while (window.isOpen())
	{
		/*
		*******
		Handle player's input
		*******
		*/
		if (Keyboard::isKeyPressed(Keyboard::Escape))
		{
			window.close();
		}

		/*
		*******
		Update the scene
		*******
		*/

		/*
		*******
		Draw the scene
		*******
		*/


		// Clear everything from the last frame
		window.clear();

		// Draw game scene here (uses the window obj to draw the spriteBackground object, in between clearing the display and showing the newly drawn scene
		window.draw(spriteBackground);

		// Show everything we just drew
		window.display();
	}

	return 0;
}
