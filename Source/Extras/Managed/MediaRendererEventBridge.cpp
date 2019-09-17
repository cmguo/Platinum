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

/*----------------------------------------------------------------------
|   includes
+---------------------------------------------------------------------*/
#include "StdAfx.h"
#include "MediaRendererEventBridge.h"
#include "MediaRenderer.h"
#include "Action.h"

// ConnectionManager
NPT_Result Platinum::MediaRendererEventBridge::OnGetCurrentConnectionInfo(PLT_ActionReference& action)
{
	return m_pMediaRenderer->OnGetCurrentConnectionInfo(marshal_as<Action^>(action));
}

NPT_Result Platinum::MediaRendererEventBridge::OnPrepareForConnection(PLT_ActionReference& action)
{
	return m_pMediaRenderer->OnPrepareForConnection(marshal_as<Action^>(action));
}

NPT_Result Platinum::MediaRendererEventBridge::OnConnectionComplete(PLT_ActionReference& action)
{
	return m_pMediaRenderer->OnConnectionComplete(marshal_as<Action^>(action));
}

// AVTransport
NPT_Result Platinum::MediaRendererEventBridge::OnNext(PLT_ActionReference& action)
{
	return m_pMediaRenderer->OnNext(marshal_as<Action^>(action));
}

NPT_Result Platinum::MediaRendererEventBridge::OnPause(PLT_ActionReference& action)
{
	return m_pMediaRenderer->OnPause(marshal_as<Action^>(action));
}

NPT_Result Platinum::MediaRendererEventBridge::OnPlay(PLT_ActionReference& action)
{
	return m_pMediaRenderer->OnPlay(marshal_as<Action^>(action));
}

NPT_Result Platinum::MediaRendererEventBridge::OnPrevious(PLT_ActionReference& action)
{
	return m_pMediaRenderer->OnPrevious(marshal_as<Action^>(action));
}

NPT_Result Platinum::MediaRendererEventBridge::OnSeek(PLT_ActionReference& action)
{
	return m_pMediaRenderer->OnSeek(marshal_as<Action^>(action));
}

NPT_Result Platinum::MediaRendererEventBridge::OnStop(PLT_ActionReference& action)
{
	return m_pMediaRenderer->OnStop(marshal_as<Action^>(action));
}

NPT_Result Platinum::MediaRendererEventBridge::OnSetAVTransportURI(PLT_ActionReference& action)
{
	return m_pMediaRenderer->OnSetAVTransportURI(marshal_as<Action^>(action));
}

NPT_Result Platinum::MediaRendererEventBridge::OnSetPlayMode(PLT_ActionReference& action)
{
	return m_pMediaRenderer->OnSetPlayMode(marshal_as<Action^>(action));
}

// RenderingControl
NPT_Result Platinum::MediaRendererEventBridge::OnSetVolume(PLT_ActionReference& action)
{
	return m_pMediaRenderer->OnSetVolume(marshal_as<Action^>(action));
}

NPT_Result Platinum::MediaRendererEventBridge::OnSetVolumeDB(PLT_ActionReference& action)
{
	return m_pMediaRenderer->OnSetVolumeDB(marshal_as<Action^>(action));
}

NPT_Result Platinum::MediaRendererEventBridge::OnGetVolumeDBRange(PLT_ActionReference& action)
{
	return m_pMediaRenderer->OnGetVolumeDBRange(marshal_as<Action^>(action));
}

NPT_Result Platinum::MediaRendererEventBridge::OnSetMute(PLT_ActionReference& action)
{
	return m_pMediaRenderer->OnSetMute(marshal_as<Action^>(action));
}

