#ifndef INDEXBUFFER_H
#define INDEXBUFFER_H

#include "VertexBuffer.h"

namespace Engine {
	class IndexBuffer {
	private:
		unsigned int m_id = 0;
		size_t m_count;

	public:
		IndexBuffer(const void* data, const size_t count,
			const VertexBuffer::EUsage usage = VertexBuffer::EUsage::Static);
		~IndexBuffer();
		IndexBuffer(IndexBuffer&& index_buffer) noexcept;
		IndexBuffer& operator=(IndexBuffer&& index_buffer) noexcept;

		IndexBuffer(const IndexBuffer&) = delete;
		IndexBuffer& operator=(IndexBuffer&) = delete;

		void bind() const;
		static void unbind();
		size_t get_count() const { return m_count; }
	};
}

#endif
