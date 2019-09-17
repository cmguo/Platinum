/*****************************************************************
|
|   Platinum - Managed MediaRendererEventBridge
|
| Copyright (c) 2004-2010, Plutinosoft, LLC.
| All rights reserved.
| http://www.plutinosoft.com
|
| This program is free software; you can redistribute it and/or
| modify it under the terms of the GNU General Public License
| as published by the Free Software Foundation; either version 2
| of the License, or (at your option) any later version.
|
| OEMs, ISVs, VARs and other distributors that combine and 
| distribute commercially licensed software with Platinum software
| and do not wish to distribute the source code for the commercially
| licensed software under version 2, or (at your option) any later
| version, of the GNU General Public License (the "GPL") must enter
| into a commercial license agreement with Plutinosoft, LLC.
| 
| This program is distributed in the hope that it will be useful,
| but WITHOUT ANY WARRANTY; without even the implied warranty of
| MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
| GNU General Public License for more details.
|
| You should have received a copy of the GNU General Public License
| along with this program; see the file LICENSE.txt. If not, write to
| the Free Software Foundation, Inc., 
| 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
| http://www.gnu.org/licenses/gpl-2.0.html
|
****************************************************************/

#pragma once

/*----------------------------------------------------------------------
|   includes
+---------------------------------------------------------------------*/
#include "PltMediaRenderer.h"

namespace Platinum
{

ref class MediaRenderer;

/*----------------------------------------------------------------------
|   MediaRendererEventBridge
+---------------------------------------------------------------------*/
private class MediaRendererEventBridge : public PLT_MediaRendererDelegate
{
private:

    gcroot<MediaRenderer^> m_pMediaRenderer;

public:

    // PLT_MediaRendererDelegate methods
	// ConnectionManager
	virtual NPT_Result OnGetCurrentConnectionInfo(PLT_ActionReference& action);

	// AVTransport
	virtual NPT_Result OnNext(PLT_ActionReference& action);
	virtual NPT_Result OnPause(PLT_ActionReference& action);
	virtual NPT_Result OnPlay(PLT_ActionReference& action);
	virtual NPT_Result OnPrevious(PLT_ActionReference& action);
	virtual NPT_Result OnSeek(PLT_ActionReference& action);
	virtual NPT_Result OnStop(PLT_ActionReference& action);
	virtual NPT_Result OnSetAVTransportURI(PLT_ActionReference& action);
	virtual NPT_Result OnSetPlayMode(PLT_ActionReference& action);

	// RenderingControl
	virtual NPT_Result OnSetVolume(PLT_ActionReference& action);
	virtual NPT_Result OnSetVolumeDB(PLT_ActionReference& action);
	virtual NPT_Result OnGetVolumeDBRange(PLT_ActionReference& action);
	virtual NPT_Result OnSetMute(PLT_ActionReference& action);


public:

    MediaRendererEventBridge(gcroot<MediaRenderer^> server)
    {
        m_pMediaRenderer = server;
    }

    virtual ~MediaRendererEventBridge()
    {}

};


}
