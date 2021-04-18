/* xoreos - A reimplementation of BioWare's Aurora engine
 *
 * xoreos is the legal property of its developers, whose names
 * can be found in the AUTHORS file distributed with this source
 * distribution.
 *
 * xoreos is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 3
 * of the License, or (at your option) any later version.
 *
 * xoreos is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with xoreos. If not, see <http://www.gnu.org/licenses/>.
 */

/** @file
 *  The menu for modifying the skills of the character.
 */

#ifndef ENGINES_KOTOR_GUI_CHARGEN_CHARGENSKILLS_H
#define ENGINES_KOTOR_GUI_CHARGEN_CHARGENSKILLS_H

#include <string>

#include "src/engines/kotorbase/gui/gui.h"

#include "src/engines/kotor/gui/chargen/chargenbase.h"

namespace Engines {

namespace KotOR {

class GenSkill {
public:
	GenSkill();
	GenSkill(
			const char* lbl,
			Odyssey::WidgetLabel *label,
			Odyssey::WidgetButton *button,
			Odyssey::WidgetButton *plusButton,
			Odyssey::WidgetButton *minusButton,
			KotORBase::Class kClass);
	bool isHovered();
	void setHighlight(bool highlight);
	KotORBase::CreatureInfo::CrossClassSkill getCrossClass();
	uint8_t getCost();
	Common::UString _desc; ///< Description text of Computer Use TODO getter function
	decrease();
	increase();
private:
	uint8_t _points; ///< Current points spent on Computer Use
	uint8_t _max;
	Odyssey::WidgetLabel *_label; ///< Label displaying "Computer Use"
	Odyssey::WidgetButton *_button; ///< Label displaying Computer Use points
	Odyssey::WidgetButton *_plusButton; ///< Button increasing Computer Use
	Odyssey::WidgetButton *_minusButton; ///< Button decreasing Computer Use
	enum KotORBase::CreatureInfo::CrossClassSkill _crossClassSkill; // FIXME type ???
};


class CharacterGenerationSkillsMenu : public CharacterGenerationBaseMenu {
public:
	CharacterGenerationSkillsMenu(KotORBase::CharacterGenerationInfo &info,
	                            ::Engines::Console *console = 0);

private:
	uint8_t _remainingSections; ///< Remaining points to spend

	GenSkill _com; ///< TODO Current points spent on Computer Use
	GenSkill _dem; ///< TODO Current points spent on Demolitions
	GenSkill _ste; ///< TODO Current points spent on Stealth
	GenSkill _awa; ///< TODO Current points spent on Awareness
	GenSkill _per; ///< TODO Current points spent on Persuade
	GenSkill _rep; ///< TODO Current points spent on Repair
	GenSkill _sec; ///< TODO Current points spent on Security
	GenSkill _tre; ///< TODO Current points spent on Treat Injury

	Odyssey::WidgetLabel *_remainingSectionsLabel; ///< Label displaying remaining points to spend
	Odyssey::WidgetLabel *_costPointsLabel; ///< Label displaying the cost of increasing the skill
	Odyssey::WidgetLabel *_classSkillLabel; ///< Label displaying (cross-) class
	GenSkill *_hoveredSkill; ///< TODO Pointer to the currently hovered button/skill
	Odyssey::WidgetListBox *_descListBox; ///< List box containing the description of the skill

	/**
	 * @brief Callback called on button press
	 *
	 * @param widget Widged representing pressed button
	 */
	void callbackActive(Widget &widget);

	/**
	 * @brief Callback used to react to hovering Skills
	 *
	 * Updates the cost for increasing the skill,
	 * the display for (cross-)class skill
	 * and the description for the skill
	 */
	void callbackRun();
	void hoverSkill(GenSkill skill);
};

} // End of namespace KotOR

} // End of namespace Engines

#endif // ENGINES_KOTOR_GUI_CHARGEN_CHARGENSKILLS_H
