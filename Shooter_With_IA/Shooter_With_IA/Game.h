#pragma once
//#include <SFML/Graphics.hpp>



#include "IComposite.h"

class IPhysicsEngine;
class ResourceManager;
class InputManager;
class IAudioManager;
class IRenderer;
class Window;


class Game : public IComposite
{
private:
	IPhysicsEngine* m_physicsEngine;
	ResourceManager* m_resourceManager;
	InputManager* m_inputManager;
	IAudioManager* m_audioManager;


	IRenderer* m_renderer;
	Window m_Window;
public:
	void Initialize();
	void Run();
	void Update();
	void Draw();
	void Shutdown();


};


