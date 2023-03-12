#ifndef SHADERPROGRAM_H
#define SHADERPROGRAM_H

#include <glm/mat4x4.hpp>

namespace Engine {
	class ShaderProgram {
	private:
		bool m_isCompiled = false;
		unsigned int m_id = 0;

	public:
		ShaderProgram(const char* vertex_shader_src, const char* fragment_shader_src);
		~ShaderProgram();
		ShaderProgram& operator=(ShaderProgram&& shaderProgram) noexcept;
		ShaderProgram(ShaderProgram&& shaderProgram) noexcept;

		ShaderProgram() = delete;
		ShaderProgram(ShaderProgram&) = delete;
		ShaderProgram& operator=(const ShaderProgram&) = delete;


		bool isCompiled() const { return m_isCompiled; }
		void bind() const;
		static void unbind();
		void setMatrix4(const char* name, const glm::mat4& matrix) const;
	};
}

#endif