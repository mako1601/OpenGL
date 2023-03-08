#ifndef SHADERPROGRAM_H
#define SHADERPROGRAM_H

#include <glad/glad.h>
#include <string>

namespace Renderer {
	class ShaderProgram {
	private:
		bool m_isCompilied = false;
		GLuint m_ID = 0;

		bool createShader(const std::string& source, const GLenum shaderType, GLuint& shaderID);
		
		ShaderProgram() = delete;
		ShaderProgram(ShaderProgram&) = delete;
		ShaderProgram& operator=(const ShaderProgram&) = delete;
		ShaderProgram& operator=(ShaderProgram&& shaderProgram) noexcept;
		ShaderProgram(ShaderProgram&& shaderProgram) noexcept;

	public:
		ShaderProgram(const std::string& vertexShader, const std::string& fragmentShader);
		~ShaderProgram();

		bool isCompilied() const { return m_isCompilied; }
		void use() const;
	};
}

#endif SHADERPROGRAM_H