#pragma once
#include <SDL.h>

// Compilation + rapide, si pas d'appel de constructeur
class Window;
struct Rectangle;

class Renderer
{
public:
	Renderer() = default;
	Renderer(const Renderer&) = delete;
	Renderer& operator = (const Renderer&) = delete;

	bool initialize(Window& window);
	void beginDraw();
	void drawRect(const Rectangle& rect);
	void endDraw();

	inline SDL_Renderer* toSDLRenderer() const { return SDLRenderer; }
	void close();

private:
	SDL_Renderer* SDLRenderer{ nullptr };
};