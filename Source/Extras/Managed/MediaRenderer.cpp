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

/*----------------------------------------------------------------------
|   includes
+---------------------------------------------------------------------*/
#include "StdAfx.h"
#include "PltMimeType.h"
#include "MediaRenderer.h"
#include "DeviceHost.h"
#include "MediaRendererEventBridge.h"

Platinum::MediaRenderer::MediaRenderer(PLT_MediaRenderer* server) : 
    DeviceHost(*(server))
{
    RegisterEvents();
}

Platinum::MediaRenderer::MediaRenderer(String^ friendlyName) :
	DeviceHost(*(new PLT_MediaRenderer(StringConv(friendlyName))))
{
	RegisterEvents();
}

Platinum::MediaRenderer::MediaRenderer(String^ friendlyName, UInt16 port) :
	DeviceHost(*(new PLT_MediaRenderer(StringConv(friendlyName), false, NULL, port, true)))
{
	RegisterEvents();
}

Platinum::MediaRenderer::MediaRenderer(String^ friendlyName, String^ uuid) :
    DeviceHost(*(new PLT_MediaRenderer(StringConv(friendlyName), false, StringConv(uuid))))
{
    RegisterEvents();
}

Platinum::MediaRenderer::MediaRenderer(String^ friendlyName, String^ uuid, UInt16 port) :
    DeviceHost(*(new PLT_MediaRenderer(StringConv(friendlyName), false, StringConv(uuid), port, true)))
{
    RegisterEvents();
}

void Platinum::MediaRenderer::RegisterEvents()
{
    if (!m_pBridge)
    {
        m_pBridge = new MediaRendererEventBridge(this);
    }

    PLT_MediaRenderer* server = (PLT_MediaRenderer*)(Handle.AsPointer());
    server->SetDelegate(m_pBridge);
}

Platinum::MediaRenderer::!MediaRenderer()
{

}

