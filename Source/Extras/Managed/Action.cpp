/*****************************************************************
|
|   Platinum - Managed Action
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
#include "Action.h"
#include "ActionDescription.h"
#include "Service.h"
#include "ActionArgumentDescription.h"
#include "EnumerableNptArray.h"

Platinum::Service^ Platinum::Action::ParentService::get()
{
    return marshal_as<Service^>(*(*m_pHandle)->GetActionDesc().GetService());
}

Platinum::ActionDescription^ Platinum::Action::Description::get()
{
    return marshal_as<ActionDescription^>((*m_pHandle)->GetActionDesc());
}

IEnumerable<Platinum::ActionArgumentDescription^>^ Platinum::Action::Arguments::get()
{
    return gcnew Enumerables::EnumerableNptArray<ActionArgumentDescription^, PLT_ArgumentDesc*>(
        (*m_pHandle)->GetActionDesc().GetArgumentDescs()
        );
}

Platinum::ActionArgumentDescription^ Platinum::Action::GetArgument( String^ name )
{
    if (String::IsNullOrEmpty(name))
        throw gcnew ArgumentException("null or empty", "name");

    marshal_context c;

    PLT_ArgumentDesc* arg = (*m_pHandle)->GetActionDesc().GetArgumentDesc(c.marshal_as<const char*>(name));

    if (!arg)
        return nullptr;

    return marshal_as<ActionArgumentDescription^>(*arg);
}

Int32 Platinum::Action::SetArgumentValue( String^ name, String^ value )
{
    if (String::IsNullOrEmpty(name))
        throw gcnew ArgumentException("null or empty", "name");

    marshal_context c;
    return (*m_pHandle)->SetArgumentValue(c.marshal_as<const char*>(name), c.marshal_as<const char*>(value));
}

String^ Platinum::Action::GetArgumentValue( String^ name )
{
	if (String::IsNullOrEmpty(name))
		throw gcnew ArgumentException("null or empty", "name");

	marshal_context c;
	NPT_String value;
	int result = (*m_pHandle)->GetArgumentValue(c.marshal_as<const char*>(name), value);
	if (result != NPT_SUCCESS)
		return nullptr;
	return gcnew String(value);
}

void Platinum::Action::HandleActionResponse( NeptuneException^ error, Action^ action )
{
    if (action->m_pHandle == m_pHandle)
    {
        this->ActionResponse(error);
    }
}

