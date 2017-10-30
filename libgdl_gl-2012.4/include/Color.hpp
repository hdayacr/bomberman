#ifndef __GDL__COLOR__HPP__
#define __GDL__COLOR__HPP__

namespace gdl
{
	////////////////////////////////////////////////////////////
	/// The color class provides an simple container to manage
	/// colors.
	////////////////////////////////////////////////////////////
	struct Color
	{
		////////////////////////////////////////////////////////////
		/// Type redefinition.
		////////////////////////////////////////////////////////////
		typedef unsigned char	uchar;

		////////////////////////////////////////////////////////////
		/// Default constructor.
		////////////////////////////////////////////////////////////
		Color();

		////////////////////////////////////////////////////////////
		/// Constructor.
		///
		/// \param[in] r Byte for red component.
		/// \param[in] g Byte for green component.
		/// \param[in] b Byte for blue component.
		/// \param[in] a Byte for alpha component.
		////////////////////////////////////////////////////////////
		Color(uchar r, uchar g, uchar b, uchar a = 255);

		////////////////////////////////////////////////////////////
		/// Copy constructor.
		///
		/// \param[in] color Instance to copy.
		////////////////////////////////////////////////////////////
		Color(const Color &);

		////////////////////////////////////////////////////////////
		/// Default destructor.
		////////////////////////////////////////////////////////////
		~Color(void)
		{
		}

		////////////////////////////////////////////////////////////
		/// Overloading of the assignment operator.
		///
		/// \return An reference on the Color instance.
		////////////////////////////////////////////////////////////
		Color&		operator=(Color const &);

		////////////////////////////////////////////////////////////
		/// Overloading of the comparison operator.
		///
		/// \return If the test succeed, true is returned.
		/// Otherwise, false is returned.
		////////////////////////////////////////////////////////////
		bool operator==(Color const &) const;

		////////////////////////////////////////////////////////////
		/// Overloading of the comparison operator.
		///
		/// \return If the test succeed, true is returned.
		/// Otherwise, false is returned.
		////////////////////////////////////////////////////////////
		bool operator!=(Color const &) const;

		////////////////////////////////////////////////////////////
		/// Red component.
		////////////////////////////////////////////////////////////
		uchar r;
		////////////////////////////////////////////////////////////
		/// Green component.
		////////////////////////////////////////////////////////////
		uchar g;
		////////////////////////////////////////////////////////////
		/// Blue component.
		////////////////////////////////////////////////////////////
		uchar b;
		////////////////////////////////////////////////////////////
		/// Alpha component.
		////////////////////////////////////////////////////////////
		uchar a;
	};
}

#endif /* __GDL__COLOR__HPP__ */
