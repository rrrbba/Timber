#include <SFML/Graphics.hpp>
#include <sstream>

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

	// Make a tree sprite
	Texture textureTree;
	textureTree.loadFromFile("graphics/tree.png");
	Sprite spriteTree;
	spriteTree.setTexture(textureTree); //whenever spriteTree is drawn, it will show the textureTree texture
	spriteTree.setPosition(810, 0);

	// Prepare the bee (since the bee needs to move, need to declare two bee-related variables
	Texture textureBee;
	textureBee.loadFromFile("graphics/bee.png");
	Sprite spriteBee;
	spriteBee.setTexture(textureBee);
	spriteBee.setPosition(0, 800);

	//Is the bee currently moving?
	bool beeActive = false;

	//How fast can the bee fly
	float beeSpeed = 0.0f;

	// Make 3 cloud sprites from 1 texture
	Texture textureCloud;

	//Load 1 new texture
	textureCloud.loadFromFile("graphics/cloud.png");

	// 3 New sprites with the same texture
	Sprite spriteCloud1;
	Sprite spriteCloud2;
	Sprite spriteCloud3;
	spriteCloud1.setTexture(textureCloud);
	spriteCloud2.setTexture(textureCloud);
	spriteCloud3.setTexture(textureCloud);

	//Position the clouds on the left of the screen at different heights
	spriteCloud1.setPosition(0, 0);
	spriteCloud2.setPosition(0, 250);
	spriteCloud3.setPosition(0, 500);

	//Are the clouds currently on the screee?
	bool cloud1Active = false;
	bool cloud2Active = false;
	bool cloud3Active = false;

	//How fast is each cloud?
	float cloud1Speed = 0.0f;
	float cloud2Speed = 0.0f;
	float cloud3Speed = 0.0;

	//Variables to control time itself
	Clock clock;

	//Track whether the game is running
	bool paused = true;
	
	//Draw some text
	int score = 0;

	Text messageText;
	Text scoreText;

	//Choose font
	Font font;
	font.loadFromFile("fonts/KOMIKAP_.tff");

	//Set the font to message
	messageText.setFont(font);
	scoreText.setFont(font);

	//Assign the actual message
	messageText.setString("Press Enter to start!");
	scoreText.setString("Score = 0");

	//Font size
	messageText.setCharacterSize(75);
	scoreText.setCharacterSize(100);

	//Choose color
	messageText.setFillColor(Color::White);
	scoreText.setFillColor(Color::White);

	//Position the text
	FloatRect textRect = messageText.getLocalBounds();

	messageText.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);

	messageText.setPosition(1920 / 2.0f, 1080 / 2.0f);

	scoreText.setPosition(20, 20);
	

	while (window.isOpen())
	{
		/*
		**********************
		Handle player's input
		**********************
		*/
		if (Keyboard::isKeyPressed(Keyboard::Escape))
		{
			window.close();
		}

		//Start the game
		if (Keyboard::isKeyPressed(Keyboard::Return))
		{
			//if Enter key is being pressed, it sets paused to false
			paused = false;
		}

		/*
		*****************
		Update the scene
		*****************
		*/
		if (!paused) {
			// Measure time
			Time dt = clock.restart();

			// Setup the bee
			if (!beeActive)
			{
				// How fast is the bee
				srand((int)time(0)); //seed the random number generator
				beeSpeed = (rand() % 200) + 200; //assign var to a # b/w 200 & 399

				//How high is the bee
				srand((int)time(0) * 10); //seed the random number generator
				float height = (rand() % 500) + 500; //assign var to a # b/w 500 & 999
				spriteBee.setPosition(2000, height);
				beeActive = true;

			}
			else
			{
				// Move the bee
				spriteBee.setPosition(spriteBee.getPosition().x - (beeSpeed * dt.asSeconds()), spriteBee.getPosition().y);

				// Has the bee reached the left-hand edge of the screen?
				if (spriteBee.getPosition().x < -100)
				{
					// Set it up ready to be a whole new bee next frame
					beeActive = false;
				}

			}

			// Manage the clouds
			//Cloud 1
			if (!cloud1Active)
			{
				//How fast is the cloud
				srand((int)time(0) * 10); //*10 so that always get a diff seed for each of the clouds
				cloud1Speed = (rand() % 200);

				//How high is the cloud
				srand((int)time(0) * 10);
				float height = (rand() % 150);
				spriteCloud1.setPosition(-200, height);
				cloud1Active = true;

			}
			else
			{
				//Move the cloud
				spriteCloud1.setPosition(spriteCloud1.getPosition().x + (cloud1Speed * dt.asSeconds()), spriteCloud1.getPosition().y);

				//Has the cloud reached the right hand edge of the screen?
				if (spriteCloud1.getPosition().x > 1920)
				{
					//Set it up to be a whole new cloud next frame
					cloud1Active = false;
				}
			}

			//Cloud 2
			if (!cloud2Active)
			{
				//How fast is the cloud
				srand((int)time(0) * 20); //*10 so that always get a diff seed for each of the clouds
				cloud2Speed = (rand() % 200);

				//How high is the cloud
				srand((int)time(0) * 20);
				float height = (rand() % 300) - 150;
				spriteCloud2.setPosition(-200, height);
				cloud2Active = true;

			}
			else
			{
				//Move the cloud
				spriteCloud2.setPosition(spriteCloud2.getPosition().x + (cloud2Speed * dt.asSeconds()), spriteCloud2.getPosition().y);

				//Has the cloud reached the right hand edge of the screen?
				if (spriteCloud2.getPosition().x > 1920)
				{
					//Set it up to be a whole new cloud next frame
					cloud2Active = false;
				}
			}

			//Cloud 1
			if (!cloud3Active)
			{
				//How fast is the cloud
				srand((int)time(0) * 30); //*10 so that always get a diff seed for each of the clouds
				cloud3Speed = (rand() % 200);

				//How high is the cloud
				srand((int)time(0) * 30);
				float height = (rand() % 450) - 150;
				spriteCloud3.setPosition(-200, height);
				cloud3Active = true;

			}
			else
			{
				//Move the cloud
				spriteCloud3.setPosition(spriteCloud3.getPosition().x + (cloud3Speed * dt.asSeconds()), spriteCloud3.getPosition().y);

				//Has the cloud reached the right hand edge of the screen?
				if (spriteCloud3.getPosition().x > 1920)
				{
					//Set it up to be a whole new cloud next frame
					cloud3Active = false;
				}
			}
		}

		/*
		***************
		Draw the scene
		***************
		*/


		// Clear everything from the last frame
		window.clear();

		// Draw game scene here (uses the window obj to draw the spriteBackground object, in between clearing the display and showing the newly drawn scene
		window.draw(spriteBackground);

		// Draw the clouds
		window.draw(spriteCloud1);
		window.draw(spriteCloud2);
		window.draw(spriteCloud3);

		// Draw the tree
		window.draw(spriteTree);

		// Draw the bee
		window.draw(spriteBee);

		// Show everything we just drew
		window.display();
	}

	return 0;
}
