#include "kmpch.h"
#include "GameWindow.h"

namespace KMCore
{

	Window* Window::Create(const WindowData& data)
	{
		return new GameWindow(data);
	}

	GameWindow::GameWindow(const WindowData& data)
	{
		Init(data);
	}

	GameWindow::~GameWindow()
	{
		Shutdown();
	}

	void GameWindow::Init(const WindowData& data)
	{
		m_Data.Title = data.Title;
		m_Data.VideoMode = data.VideoMode;
		m_Data.Style = data.Style;
		m_Data.ContextSettings = data.ContextSettings;

		m_Window = new sf::RenderWindow(data.VideoMode, data.Title, data.Style, data.ContextSettings);

		SetVSync(data.VSync);
		m_Window->setActive();
	}

	void GameWindow::OnUpdate()
	{
	}

	void GameWindow::SetVSync(bool enabled)
	{
		m_Data.VSync = enabled;
		m_Window->setVerticalSyncEnabled(enabled);
	}

	bool GameWindow::IsVSyncEnabled() const
	{
		return m_Data.VSync;
	}

	void GameWindow::Shutdown()
	{
		m_Window->close();
	}
}