










#include "c3.h"

#include "aui_ui.h"
#include "aui_directui.h"
#include "aui_uniqueid.h"
#include "ns_headerswitch.h"
#include "aui_ldl.h"

#include "ns_header.h"



ns_Header::ns_Header(
	AUI_ERRCODE *retval,
	uint32 id,
	MBCHAR *ldlBlock )
	:
	aui_Header(),
	aui_ImageBase( ldlBlock ),
	aui_TextBase( ldlBlock, (MBCHAR *)NULL )
{
	*retval = aui_Region::InitCommonLdl( id, ldlBlock );
	Assert( AUI_SUCCESS(*retval) );
	if ( !AUI_SUCCESS(*retval) ) return;

	*retval = aui_Control::InitCommonLdl( ldlBlock, NULL, NULL );
	Assert( AUI_SUCCESS(*retval) );
	if ( !AUI_SUCCESS(*retval) ) return;

	*retval = aui_SwitchGroup::InitCommonLdl( ldlBlock );
	Assert( AUI_SUCCESS(*retval) );
	if ( !AUI_SUCCESS(*retval) ) return;

	*retval = aui_Header::InitCommonLdl( ldlBlock );
	Assert( AUI_SUCCESS(*retval) );
	if ( !AUI_SUCCESS(*retval) ) return;

	*retval = InitCommonLdl( ldlBlock );
	Assert( AUI_SUCCESS(*retval) );
	if ( !AUI_SUCCESS(*retval) ) return;

	*retval = CreateSwitches( ldlBlock );
	Assert( AUI_SUCCESS(*retval) );
	if ( !AUI_SUCCESS(*retval) ) return;
}



ns_Header::ns_Header(
	AUI_ERRCODE *retval,
	uint32 id,
	sint32 x,
	sint32 y,
	sint32 width,
	sint32 height )
	:
	aui_Header(),
	aui_ImageBase( (sint32)0 ),
	aui_TextBase( NULL )
{
	*retval = aui_Region::InitCommon( id, x, y, width, height );
	Assert( AUI_SUCCESS(*retval) );
	if ( !AUI_SUCCESS(*retval) ) return;

	*retval = aui_Control::InitCommon( NULL, NULL );
	Assert( AUI_SUCCESS(*retval) );
	if ( !AUI_SUCCESS(*retval) ) return;

	*retval = aui_SwitchGroup::InitCommon();
	Assert( AUI_SUCCESS(*retval) );
	if ( !AUI_SUCCESS(*retval) ) return;

	*retval = aui_Header::InitCommon();
	Assert( AUI_SUCCESS(*retval) );
	if ( !AUI_SUCCESS(*retval) ) return;

	*retval = InitCommon();
	Assert( AUI_SUCCESS(*retval) );
	if ( !AUI_SUCCESS(*retval) ) return;

	*retval = CreateSwitches();
	Assert( AUI_SUCCESS(*retval) );
	if ( !AUI_SUCCESS(*retval) ) return;
}



AUI_ERRCODE ns_Header::InitCommonLdl( MBCHAR *ldlBlock )
{
	return InitCommon();
}



AUI_ERRCODE ns_Header::InitCommon( void )
{
	return AUI_ERRCODE_OK;
}



AUI_ERRCODE ns_Header::CreateSwitches( MBCHAR *ldlBlock )
{
	AUI_ERRCODE errcode;

	
	aui_Ldl *theLdl = g_ui->GetLdl();
	static MBCHAR block[ k_AUI_LDL_MAXBLOCK + 1 ];

	if ( ldlBlock )
	{
		sint32 i = 0;
		do
		{
			sprintf( block, "%s.%s%d", ldlBlock, k_AUI_HEADER_LDL_SWITCH, i );

			if ( !theLdl->GetLdl()->FindDataBlock( block ) )
				break;

			aui_Switch *theSwitch = new ns_HeaderSwitch(
				&errcode,
				aui_UniqueId(),
				block );
			Assert( AUI_NEWOK(theSwitch,errcode) );
			if ( !AUI_NEWOK(theSwitch,errcode) )
				return AUI_ERRCODE_MEMALLOCFAILED;

			aui_Action *action = new aui_HeaderSwitchAction( i );
			Assert( action != NULL );
			if ( !action ) return AUI_ERRCODE_MEMALLOCFAILED;

			theSwitch->SetAction( action );

			AddChild( theSwitch );

			i++;

		} while ( 1 );
	}

	return AUI_ERRCODE_OK;
}