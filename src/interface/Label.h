#ifndef LABEL_H
#define LABEL_H

#include <string>

#include "Component.h"
#include "Misc.h"

namespace ui
{
	class Label : public Component
	{
		std::string text;
		ui::Point textPosition;
		HorizontalAlignment textHAlign;
		VerticalAlignment textVAlign;
	public:
		Label(Window* parent_state, std::string labelText);
		Label(Point position, Point size, std::string labelText);
		Label(std::string labelText);
		virtual ~Label();

		void TextPosition();
		void SetText(std::string text);
		HorizontalAlignment GetHAlignment() { return textHAlign; }
		VerticalAlignment GetVAlignment() { return textVAlign; }
		void SetAlignment(HorizontalAlignment hAlign, VerticalAlignment vAlign) { textHAlign = hAlign; textVAlign = vAlign; TextPosition(); }


		virtual void Draw(const Point& screenPos);
	};
}

#endif // LABEL_H