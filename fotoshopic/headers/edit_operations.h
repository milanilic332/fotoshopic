#pragma once


#include "abstract_operation.h"
#include "image.h"


namespace fs::ops
{

	/*
	* @breif Enum class representing color operations.
	*/
	enum class basic_edits
	{
		brightness,
		contrast,
		shadows,
		highlights,
		whites,
		blacks,
		vignette,
		saturation,
		luminance,
		temperature,
	};


	/*
	* @brief Class representing basic edit operations.
	*/
	class BasicEditOperation : public AbstractOperation
	{
		public:
			explicit BasicEditOperation(float from, float to);
			virtual void apply(Image &img) override;
			virtual void invert(Image &img) override;

			inline int from() const { return m_from; }
			inline int to() const { return m_to; }
		private:
			float m_from, m_to;
	};


	/*
	* @brief Class representing advanced edit operations.
	*/
	class AdvancedEditOperation : public BasicEditOperation
	{
		public:
			explicit AdvancedEditOperation(float from, float to);
			virtual void apply(Image &img) override;
			virtual void invert(Image &img) override;
		private:
			Image m_old;
	};

} // namespace fs::ops