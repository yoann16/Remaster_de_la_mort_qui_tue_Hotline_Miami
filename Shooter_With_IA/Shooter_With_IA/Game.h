#pragma once
#include <SFML/Graphics.hpp>



#include "IComposite.h"

class IPhysicsEngine;
class ResourceManager;
class InputManager;
class IAudioManager;
class IRenderer;
class Window;


//class Game : public IComposite
//{
//private:
//	IPhysicsEngine* m_physicsEngine;
//	ResourceManager* m_resourceManager;
//	InputManager* m_inputManager;
//	IAudioManager* m_audioManager;
//
//
//	IRenderer* m_renderer;
//	Window m_Window;
//public:
//	void Initialize();
//	void Run();
//	void Update();
//	void Draw();
//	void Shutdown();
//
//
//};


#include <functional>

class SFMLRenderer;  
class OptionsMenuScene;
class Game;

class Window 
{
	friend class SFMLRenderer;
	friend class OptionsMenuScene;
	friend class Game;

private:
	sf::RenderWindow m_Window;
	unsigned int m_width;
	unsigned int m_height;
	std::string m_title;
	bool m_isFullscreen;
	sf::VideoMode m_videoMode;
	sf::Uint32 m_style;
	bool m_isVsyncEnabled;
	sf::Vector2i m_position;
	bool m_isFocused;
	sf::Color m_clearColor;
	bool m_isResizable;
	sf::Image m_icon;
	//TODO voir pour la VSync
	
public:
	Window() {}
	~Window() = default;

	void create(unsigned int width, unsigned int height, const std::string& title, bool fullscreen = false)
	{
		m_width = width;
		m_height = height;
		m_title = title;
		m_isFullscreen = fullscreen;
		m_videoMode = sf::VideoMode(m_width, m_height);

		if (m_isFullscreen)
			m_style = sf::Style::Fullscreen;
		else
			m_style = sf::Style::Titlebar | sf::Style::Close | sf::Style::Resize;

		m_Window.create(m_videoMode, m_title, m_style);


		//setting optionnal
		m_Window.setVerticalSyncEnabled(m_isVsyncEnabled=true);

		m_clearColor = sf::Color(0, 0, 0);

		m_Window.setMouseCursorVisible(true);

		if (m_icon.loadFromFile("\\Remaster_de_la_mort_qui_tue_Hotline_Miami\\Shooter_With_IA\\Ressources\\icon.jpg"))
		{
			m_Window.setIcon(m_icon.getSize().x, m_icon.getSize().y, m_icon.getPixelsPtr());
		}// TODO revenir desssus quand on implémentera le système de Ressource

	}
	bool isOpen() const { return m_Window.isOpen(); }
	void close() { m_Window.close(); }

	
	sf::RenderWindow& getWindow() { return m_Window; }
	void clear() { m_Window.clear(m_clearColor); }
	void display() { m_Window.display(); }

	
	void setSize(unsigned int width, unsigned int height)
	{
		m_width = width;
		m_height = height;
		if(m_isFullscreen)
			create(m_width, m_height, m_title);
		else
		{
			m_Window.setSize(sf::Vector2u(m_width, m_height));
			sf::View view = m_Window.getDefaultView();
			view.setSize(sf::Vector2f(m_width, m_height));
			view.setCenter(sf::Vector2f(m_width / 2.f, m_height / 2.f));
			m_Window.setView(view);
		}
	}
	void setTitle(const std::string& title);
	void setFullscreen(bool fullscreen);
	sf::Vector2u getSize() const;
	sf::Vector2i getPosition() const;

	
	void handleEvents();
	void setEventCallback(const std::function<void(sf::Event)>& callback);

	
	bool pollEvent(sf::Event& event) { return m_Window.pollEvent(event); }
};