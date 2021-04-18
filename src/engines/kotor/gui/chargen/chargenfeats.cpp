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
 *  The menu for modifying the feats of the character.
 */

#include "src/engines/odyssey/button.h"
#include "src/engines/odyssey/label.h"

#include "src/engines/kotorbase/gui/chargeninfo.h"

#include "src/engines/kotor/gui/chargen/chargenfeats.h"

namespace Engines {

namespace KotOR {

CharacterGenerationFeatsMenu::CharacterGenerationFeatsMenu(KotORBase::CharacterGenerationInfo &info,
                                                                 Console *console) :
		CharacterGenerationBaseMenu(info, console) {

	load("ftchrgen");

	addBackground(KotORBase::kBackgroundTypeMenu);

	// TODO set lables and fields
	//       - description
	//       - remaining feats
	//       - description
}

void CharacterGenerationFeatsMenu::callbackActive(Widget &widget) {
	if (widget.getTag() == "BTN_BACK") {
		_returnCode = 1;
		return;
	}
	if (widget.getTag() == "BTN_ACCEPT") {
		accept();
		_returnCode = 1;
		return;
	}

	// TODO implement buttons
	//       - add
	//       - recommended
}

} // End of namespace KotOR

} // End of namespace Engines