#ifndef WINDOW_H
#define WINDOW_H

#include "Core/Event.h"
#include <string>
#include <functional>

struct GLFWwindow;

namespace Engine {

	class Window {
	public: using EventCallbackFn = std::function<void(BaseEvent&)>;
	private:
		struct WindowData {
			std::string title;
			unsigned int width;
			unsigned int height;
			EventCallbackFn eventCallbackFn;
		};

		GLFWwindow* m_pWindow = nullptr;
		WindowData m_data;
		float m_background_color[4] = { 0.0902f, 0.047f, 0.0902f, 1.0f };

		int init();
		void shutdown();

	public:
		Window(std::string title, const unsigned int width, const unsigned int height);
		~Window();

		Window(const Window&) = delete;
		Window(Window&&) = delete;
		Window& operator=(const Window&) = delete;
		Window& operator=(Window&&) = delete;

		void on_update();
		void set_event_callback(const EventCallbackFn& callback) { m_data.eventCallbackFn = callback; }
		unsigned int get_width() const { return m_data.width; }
		unsigned int get_height() const { return m_data.height; }
	};
}

#endif