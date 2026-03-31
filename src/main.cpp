#include <iostream>
#include <game/game.h>

int main() {

	try {

		Game game;



		game.Run();
	}
	catch (const char* e){
		std::cout << e << std::endl;
		return -1;
	}

	return 0;
}
