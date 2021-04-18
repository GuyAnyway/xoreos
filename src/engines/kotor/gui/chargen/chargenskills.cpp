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

#include "src/common/strutil.h"

#include "src/aurora/talkman.h"
#include "src/aurora/2dareg.h"
#include "src/aurora/2dafile.h"

#include "src/engines/odyssey/button.h"
#include "src/engines/odyssey/label.h"
#include "src/engines/odyssey/listbox.h"

#include "src/engines/kotorbase/gui/chargeninfo.h"

#include "src/engines/kotor/gui/chargen/chargenskills.h"

#define REMAIN_POINTS 16 // TODO how to compute correct value? read from files? intelligence dependent

/*
#define INIT_SKILL (skill)          \
	do {                        \
		_ ## skill = 0;     \
	} while (0)                 \
*/

namespace Engines {

namespace KotOR {

GenSkill::GenSkill() {
	_points = 0;
}

GenSkill::GenSkill(
		const char* lbl,
		Odyssey::WidgetLabel *label,
		Odyssey::WidgetButton *button,
		Odyssey::WidgetButton *plusButton,
		Odyssey::WidgetButton *minusButton,
		KotORBase::Class kClass) {
	_points = 0;
	_label = label;
	_button = button;
	_plusButton = plusButton;
	_minusButton = minusButton;
	_button->setText(Common::composeString(_points));
	_minusButton->setInvisible(true);

	std::string cls_lbl;
	switch (kClass) {
		case KotORBase::kClassSoldier:
			cls_lbl = "sol_class";
			break;
		case KotORBase::kClassScout:
			cls_lbl = "sct_class";
			break;
		case KotORBase::kClassScoundrel:
			cls_lbl = "scd_class";
		break;
		default:
			;
		//	return -1; // FIXME proper error handling
	}

	const Aurora::TwoDAFile &skills = TwoDAReg.get2DA("skills");
	const Aurora::TwoDARow &row = skills.getRow("label", lbl);
	if (row.getInt(cls_lbl) == 1) {
		_crossClassSkill = KotORBase::CreatureInfo::CrossClassSkill::classSkill;
		_max = 4; // TODO is this in the 2da files?
	} else {
		_crossClassSkill = KotORBase::CreatureInfo::CrossClassSkill::crossClassSkill;
		_max = 2; // TODO is this in the 2da files?
	}

	const Aurora::TwoDAFile &_skills = TwoDAReg.get2DA("skills");
	_desc = TalkMan.getString(_skills.getRow("label", lbl).getInt("description"));
}

bool GenSkill::isHovered() {
	return (_button->isHovered()
			|| _label->isHovered()
			|| _plusButton->isHovered()
			|| _minusButton->isHovered()
	    );
}

void GenSkill::setHighlight(bool highlight) {
	_label->setHighlight(highlight);
}

KotORBase::CreatureInfo::CrossClassSkill GenSkill::getCrossClass() {
	return _crossClassSkill;
}

uint8_t GenSkill::getCost() {
	switch (_crossClassSkill) {
		case CreatureInfo::crossClassSkill:
			return 2;
		case CreatureInfo::classSkill:
			return 1;
	}
}

void	GenSkill::decrease() {
		// TODO assert preconditions
		if (_points > 0) {
			return; // Button should not be clickable in this case
			        // TODO fail!
		}
		_points--;
		_button.setText(Common::composeString(_points));
		// TODO compute max

		if (0 == _points) {
			_strengthMinusButton->setInvisible(true);
			_strengthPlusButton->hide();
		}
		if (_points >= _max) {
			_strengthPlusButton->setInvisible(true);
			_strengthPlusButton->hide();
		}
}

void	GenSkill::increase() {
}

CharacterGenerationSkillsMenu::CharacterGenerationSkillsMenu(KotORBase::CharacterGenerationInfo &info,
                                                                 Console *console) :
		CharacterGenerationBaseMenu(info, console) {

	load("skchrgen");

	addBackground(KotORBase::kBackgroundTypeMenu);

	_remainingSections = REMAIN_POINTS;

	_com = GenSkill("ComputerUse",
			getLabel("COMPUTER_USE_LBL"),
			getButton("COMPUTER_USE_POINTS_BTN"),
			getButton("COM_PLUS_BTN"),
			getButton("COM_MINUS_BTN"),
			_info.getClass());
	_dem = GenSkill("Demolitions",
			getLabel("DEMOLITIONS_LBL"),
			getButton("DEMOLITIONS_POINTS_BTN"),
			getButton("DEM_PLUS_BTN"),
			getButton("DEM_MINUS_BTN"),
			_info.getClass());
	_ste = GenSkill("Stealth",
			getLabel("DEMOLITIONS_LBL"),
			getButton("STEALTH_POINTS_BTN"),
			getButton("STE_PLUS_BTN"),
			getButton("STE_MINUS_BTN"),
			_info.getClass());
	_awa = GenSkill("Awareness",
			getLabel("STEALTH_LBL"),
			getButton("AWARENESS_POINTS_BTN"),
			getButton("AWA_PLUS_BTN"),
			getButton("AWA_MINUS_BTN"),
			_info.getClass());
	_per = GenSkill("Persuade",
			getLabel("PERSUADE_LBL"),
			getButton("PERSUADE_POINTS_BTN"),
			getButton("PER_PLUS_BTN"),
			getButton("PER_MINUS_BTN"),
			_info.getClass());
	_rep = GenSkill("Repair",
			getLabel("REPAIR_LBL"),
			getButton("REPAIR_POINTS_BTN"),
			getButton("REP_PLUS_BTN"),
			getButton("REP_MINUS_BTN"),
			_info.getClass());
	_sec = GenSkill("Security",
			getLabel("SECURITY_LBL"),
			getButton("SECURITY_POINTS_BTN"),
			getButton("SEC_PLUS_BTN"),
			getButton("SEC_MINUS_BTN"),
			_info.getClass());
	_tre = GenSkill("TreatInjury",
			getLabel("TREAT_INJURY_LBL"),
			getButton("TREAT_INJURY_POINTS_BTN"),
			getButton("TRE_PLUS_BTN"),
			getButton("TRE_MINUS_BTN"),
			_info.getClass());


	_remainingSectionsLabel = getLabel("REMAINING_SELECTIONS_LBL");
	_remainingSectionsLabel->setText(Common::composeString(_remainingSections));
	_costPointsLabel = getLabel("COST_POINTS_LBL");
	_classSkillLabel = getLabel("CLASSSKL_LBL");
	_hoveredSkill = NULL;

	_descListBox = getListBox("LB_DESC", true);
	if (!_descListBox)
		throw Common::Exception("CharGenMenu: No description listbox");
	_descListBox->setItemSelectionEnabled(false);
	_descListBox->createItemWidgets(1); // useful (see below)
	_descListBox->removeAllItems(); // useful (see above)
	//_descListBox->setPadding(3);
	_descListBox->setAdjustHeight(true);
	_descListBox->refreshItemWidgets();
	// TODO is the appearance allright?
	// TODO stop highliting on hovering description (how?)
	// TODO stop weird indentation of description text
}

void CharacterGenerationSkillsMenu::callbackRun() {
	// Check if a specific button is hovered and set cost, description and (cross-)class skill
	if (_com.isHovered() && _hoveredSkill != &_com) {
		hoverSkill(_com);
	} else if (_dem.isHovered() && _hoveredSkill != &_dem) {
		hoverSkill(_dem);
	} else if (_ste.isHovered() && _hoveredSkill != &_ste) {
		hoverSkill(_ste);
	} else if (_awa.isHovered() && _hoveredSkill != &_awa) {
		hoverSkill(_awa);
	} else if (_per.isHovered() && _hoveredSkill != &_per) {
		hoverSkill(_per);
	} else if (_rep.isHovered() && _hoveredSkill != &_rep) {
		hoverSkill(_rep);
	} else if (_sec.isHovered() && _hoveredSkill != &_sec) {
		hoverSkill(_sec);
	} else if (_tre.isHovered() && _hoveredSkill != &_tre) {
		hoverSkill(_tre);
	}
}

void CharacterGenerationSkillsMenu::hoverSkill(GenSkill skill) {
	if (NULL != _hoveredSkill) _hoveredSkill->setHighlight(false);
	skill.setHighlight(true);

	switch (skill.getCrossClass()) {
		case KotORBase::CreatureInfo::classSkill :
			_classSkillLabel->setText("Class Skill");
			break;
		case KotORBase::CreatureInfo::crossClassSkill:
			_classSkillLabel->setText("Cross-Class Skill");
			break;
	}
	// TODO rewrite above to look like below?
	_costPointsLabel->setText(Common::composeString(skill.getCost()));

	// FIXME this only displays the text of treat injury
	//       I guess it doesn't display longer texts.
	//       Figure a way to make that work!
	_descListBox->removeAllItems();
	_descListBox->addItem(skill._desc);
	_descListBox->refreshItemWidgets();

	_hoveredSkill = &skill;
}

void CharacterGenerationSkillsMenu::callbackActive(Widget &widget) {
	if (widget.getTag() == "BTN_BACK") {
		_returnCode = 1;
		return;
	}
	if (widget.getTag() == "BTN_ACCEPT") {
		if (0 != _remainingSections) {
			// TODO display warning
			return;
		}
		// TODO save skills to character info
		accept();
		_returnCode = 1;
		return;
	}
	if (widget.getTag() == "BTN_RECOMMENDED") {
		// TODO
		accept();
		_returnCode = 1;
		return;
	}

	if (widget.getTag() == "COM_MINUS_BTN") {
		if (_remainingSections <= 0) {
			return; // Button should not be clickable in this case
			        // TODO fail!
		}
		_com.decrease();
		_remainingSections = _remainingSections + _com.getCost();
		_remainingSectionsLabel->setText(Common::composeString(_remainingSections));
		if (0 < _remainingSections) {
			enablePlusButtons();
		}
	}

	if (widget.getTag() == "COM_MINUS_BTN") {
	}

	// TODO implement buttons
	//       - mod (+-) comp use, ...
	//       - recommended
}

} // End of namespace KotOR

} // End of namespace Engines
