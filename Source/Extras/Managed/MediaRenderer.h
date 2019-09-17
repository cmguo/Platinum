/*****************************************************************
|
|   Platinum - Managed MediaRenderer
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
#include "DeviceHost.h"
#include "Http.h"

class PLT_MediaRenderer;

namespace Platinum
{

ref class DeviceHost;
ref class Action;
class MediaRendererEventBridge;

/*----------------------------------------------------------------------
|   MediaRenderer
+---------------------------------------------------------------------*/
public ref class MediaRenderer : public DeviceHost
{
public:

	delegate Int32 GetCurrentConnectionInfoDelegate(Action^ action);
	delegate Int32 PrepareForConnectionDelegate(Action^ action);
	delegate Int32 ConnectionCompleteDelegate(Action^ action);
	delegate Int32 NextDelegate(Action^ action);
	delegate Int32 PauseDelegate(Action^ action);
	delegate Int32 PlayDelegate(Action^ action);
	delegate Int32 PreviousDelegate(Action^ action);
	delegate Int32 SeekDelegate(Action^ action);
	delegate Int32 StopDelegate(Action^ action);
	delegate Int32 SetAVTransportURIDelegate(Action^ action);
	delegate Int32 SetPlayModeDelegate(Action^ action);
	delegate Int32 SetVolumeDelegate(Action^ action);
	delegate Int32 SetVolumeDBDelegate(Action^ action);
	delegate Int32 GetVolumeDBRangeDelegate(Action^ action);
	delegate Int32 SetMuteDelegate(Action^ action);

private:

    MediaRendererEventBridge* m_pBridge;

public:

    // properties

private:

    void RegisterEvents();

public:

	event GetCurrentConnectionInfoDelegate^ GetCurrentConnectionInfo;
	event PrepareForConnectionDelegate^ PrepareForConnection;
	event ConnectionCompleteDelegate^ ConnectionComplete;
	event NextDelegate^ Next;
	event PauseDelegate^ Pause;
	event PlayDelegate^ Play;
	event PreviousDelegate^ Previous;
	event SeekDelegate^ Seek;
	event StopDelegate^ Stop;
	event SetAVTransportURIDelegate^ SetAVTransportURI;
	event SetPlayModeDelegate^ SetPlayMode;
	event SetVolumeDelegate^ SetVolume;
	event SetVolumeDBDelegate^ SetVolumeDB;
	event GetVolumeDBRangeDelegate^ GetVolumeDBRange;
	event SetMuteDelegate^ SetMute;

internal:

	Int32 OnGetCurrentConnectionInfo(Action^ action)
	{
		// handle events
		return this->GetCurrentConnectionInfo(action);
	}

	Int32 OnPrepareForConnection(Action^ action)
	{
		// handle events
		return this->PrepareForConnection(action);
	}

	Int32 OnConnectionComplete(Action^ action)
	{
		// handle events
		return this->ConnectionComplete(action);
	}

	Int32 OnNext(Action^ action)
	{
		// handle events
		return this->Next(action);
	}

	Int32 OnPause(Action^ action)
	{
		// handle events
		return this->Pause(action);
	}

	Int32 OnPlay(Action^ action)
	{
		// handle events
		return this->Play(action);
	}

	Int32 OnPrevious(Action^ action)
	{
		// handle events
		return this->Previous(action);
	}

	Int32 OnSeek(Action^ action)
	{
		// handle events
		return this->Seek(action);
	}

	Int32 OnStop(Action^ action)
	{
		// handle events
		return this->Stop(action);
	}

	Int32 OnSetAVTransportURI(Action^ action)
	{
		// handle events
		return this->SetAVTransportURI(action);
	}

	Int32 OnSetPlayMode(Action^ action)
	{
		// handle events
		return this->SetPlayMode(action);
	}

	Int32 OnSetVolume(Action^ action)
	{
		// handle events
		return this->SetVolume(action);
	}

	Int32 OnSetVolumeDB(Action^ action)
	{
		// handle events
		return this->SetVolumeDB(action);
	}

	Int32 OnGetVolumeDBRange(Action^ action)
	{
		// handle events
		return this->GetVolumeDBRange(action);
	}

	Int32 OnSetMute(Action^ action)
	{
		// handle events
		return this->SetMute(action);
	}

public:

    MediaRenderer(String^ friendlyName);
	MediaRenderer(String^ friendlyName, UInt16 port);
	MediaRenderer(String^ friendlyName, String^ uuid);
	MediaRenderer(String^ friendlyName, String^ uuid, UInt16 port);
	MediaRenderer(PLT_MediaRenderer* server);
    
    ~MediaRenderer()
    {
        // clean-up managed

        // clean-up unmanaged
        this->!MediaRenderer();
    }

    !MediaRenderer();

};

}