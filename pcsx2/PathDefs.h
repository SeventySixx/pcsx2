/*  PCSX2 - PS2 Emulator for PCs
 *  Copyright (C) 2002-2009  PCSX2 Dev Team
 *
 *  PCSX2 is free software: you can redistribute it and/or modify it under the terms
 *  of the GNU Lesser General Public License as published by the Free Software Found-
 *  ation, either version 3 of the License, or (at your option) any later version.
 *
 *  PCSX2 is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY;
 *  without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
 *  PURPOSE.  See the GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License along with PCSX2.
 *  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include "PrecompiledHeader.h"

enum FoldersEnum_t
{
	// FIXME : Settings folders are no longer part of the user-local
	// ini storage.  They have been moved to an app-local ini storage class (which is currently
	// handled lazily via global variables)
	FolderId_Settings = 0,
	
	FolderId_Bios,
	FolderId_Savestates,
	FolderId_MemoryCards,

	FolderId_Documents,

	FolderId_Cheats,
	FolderId_CheatsWS,

	FolderId_COUNT
};

// --------------------------------------------------------------------------------------
//  PathDefs  (namespace)
// --------------------------------------------------------------------------------------
// Contains default values for various pcsx2 path names and locations.
//
// Note: The members of this namespace are intended for default value initialization only.
// Everything else should use the path folder assignments in g_Conf instead, since those
// are user-configurable.
//
namespace PathDefs
{
	// complete pathnames are returned by these functions (may or may not be absolute)

	extern wxDirName GetBios();
	extern wxDirName GetSavestates();
	extern wxDirName GetMemoryCards();
	extern wxDirName GetSettings();
	extern wxDirName GetCheats();
	extern wxDirName GetCheatsWS();

	extern wxDirName Get( FoldersEnum_t folderidx );

	// Base folder names used to extend out the documents/approot folder base into a complete
	// path.  These are typically for internal AppConfig use only, barring a few special cases.
	namespace Base
	{
		extern const wxDirName& Savestates();
		extern const wxDirName& MemoryCards();
		extern const wxDirName& Settings();
		extern const wxDirName& Cheats();
		extern const wxDirName& CheatsWS();
	}
}

namespace FilenameDefs
{
	extern wxFileName GetUiConfig();
	extern wxFileName GetVmConfig();
	extern const wxFileName& Memcard( uint port, uint slot );
};

