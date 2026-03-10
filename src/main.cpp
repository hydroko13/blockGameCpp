#include <iostream>
#include <raylib.h>

int main() {

	SetConfigFlags(FLAG_WINDOW_RESIZABLE);
	InitWindow(800, 450, "window name");

	Color c;

	c.r = 255;
	c.g = 0;
	c.b = 0;
	c.a = 255;


	while (!WindowShouldClose())
	{
		BeginDrawing();
		ClearBackground(RAYWHITE);

		

		DrawText("Congrats!", 190, 200, 54, c);

		EndDrawing();
	}

	CloseWindow();

	return 0;
}