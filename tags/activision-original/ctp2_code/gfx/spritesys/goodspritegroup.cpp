










 


#include "c3.h"
#include "c3errors.h"

#include "tiffutils.h"
#include "pixelutils.h"

#include "aui_directsurface.h"
#include "primitives.h"

#include "GoodSpriteGroup.h"
#include "FacedSprite.h"
#include "Sprite.h"
#include "ScreenManager.h"

#include "CivPaths.h"
#include "c3files.h"

#include "SpriteFile.h"
#include "Anim.h"

#include "Token.h"

extern CivPaths *g_civPaths;
extern ScreenManager *g_screenManager;

GoodSpriteGroup::GoodSpriteGroup(GROUPTYPE type)
:
SpriteGroup(type)
{
	POINT		thePoint = {0,0};
	sint32		i;

	for (i = GOODACTION_IDLE; i<GOODACTION_MAX; i++) {
		m_sprites[i] = NULL;
		m_anims[i] = NULL;

	}

	m_width = 0;
	m_height = 0;

	m_hasDeath = FALSE;

}

GoodSpriteGroup::~GoodSpriteGroup()
{
	int i;

	for ( i = GOODACTION_IDLE; i<GOODACTION_MAX; i++) {
		if (m_sprites[i]) {
			delete m_sprites[i];
			m_sprites[i] = NULL;
		}
	}

	for (i = GOODACTION_IDLE; i<GOODACTION_MAX; i++) {
		if (m_anims[i]) {
			delete m_anims[i];
			m_anims[i] = NULL;
		}
	}
}

void GoodSpriteGroup::Draw(GOODACTION action, sint32 frame, sint32 drawX, sint32 drawY, 
						   sint32 facing, double scale, uint16 transparency, Pixel16 outlineColor, uint16 flags)
{
	Assert(action > GOODACTION_NONE &&
			action < GOODACTION_MAX);

	if (m_sprites[action] == NULL) return;

	if (frame >= m_sprites[action]->GetNumFrames())
		frame = 0;

	m_sprites[action]->SetCurrentFrame((uint16)frame);

	if (m_sprites[action] != NULL)
		m_sprites[action]->Draw(drawX, drawY, facing, scale, transparency, outlineColor, flags);
}

void GoodSpriteGroup::DrawDirect(aui_Surface *surf, GOODACTION action, sint32 frame, sint32 drawX, sint32 drawY, 
						   sint32 facing, double scale, uint16 transparency, Pixel16 outlineColor, uint16 flags)
{
	Assert(action > GOODACTION_NONE &&
			action < GOODACTION_MAX);

	if (m_sprites[action] == NULL) return;

	m_sprites[action]->SetCurrentFrame((uint16)frame);

	if (m_sprites[action] != NULL)
		m_sprites[action]->DrawDirect(surf, drawX, drawY, facing, scale, transparency, outlineColor, flags);
}

POINT GoodSpriteGroup::GetHotPoint(GOODACTION action)
{
	POINT nullPoint = {0,0};

	if (m_sprites[action] != NULL) {
			return m_sprites[action]->GetHotPoint();
	}

	return nullPoint;	
}


#define kBenchIterations		10000

void GoodSpriteGroup::RunBenchmark(aui_Surface *surf)
{

































































































	exit(0);
}


void GoodSpriteGroup::LoadBasic(MBCHAR *filename)
{
	SpriteFile		*file = new SpriteFile(filename);
	SPRITEFILETYPE	type;

	file->Open(&type);
	file->ReadBasic(this);
	file->CloseRead();

	m_loadType = LOADTYPE_BASIC;

	delete file;
}

void GoodSpriteGroup::LoadFull(MBCHAR *filename)
{
	SpriteFile		*file = new SpriteFile(filename);
	SPRITEFILETYPE	type;

	file->Open(&type);
	file->ReadFull(this);
	file->CloseRead();

	m_loadType = LOADTYPE_FULL;

	delete file;
}

void GoodSpriteGroup::Save(MBCHAR *filename,unsigned version_id,unsigned compression_mode)
{
	SpriteFile *file = new SpriteFile(filename);

	file->Create(SPRITEFILETYPE_GOOD,version_id,compression_mode);
	file->Write(this);
	file->CloseWrite();

	delete file;
}












void GoodSpriteGroup::DrawText(sint32 x, sint32 y, char *s)
{
	primitives_DrawText((aui_DirectSurface *)g_screenManager->GetSurface(), x, y, (MBCHAR *)s, 0, 0);
}




sint32 GoodSpriteGroup::Parse(uint16 id,GROUPTYPE group)
{
	Token			*theToken=NULL; 
	MBCHAR			name[k_MAX_NAME_LENGTH];
	MBCHAR			scriptName[k_MAX_NAME_LENGTH];

	MBCHAR			*imageNames[k_MAX_NAMES];
	MBCHAR			*shadowNames[k_MAX_NAMES];

	sint32			i;

	char			prefixStr[80];

	sprintf(prefixStr, ".\\%d\\", id);
	sprintf(scriptName, "GG%#.2d.txt", id);


	theToken = new Token(scriptName, C3DIR_SPRITES); 
	Assert(theToken); 
	
	if (!theToken) return FALSE; 
	
	sint32 tmp;

	if (!token_ParseKeywordNext(theToken, TOKEN_GOOD_SPRITE)) {

		
		delete theToken;
		return k_NOT_GOOD; 
	}

	printf("Good Processing '%s'\n", scriptName);

	for (i=0; i<k_MAX_NAMES; i++) {
		imageNames[i] = (char *)malloc(k_MAX_NAME_LENGTH);
		shadowNames[i] = (char *)malloc(k_MAX_NAME_LENGTH);
	}

	if (!token_ParseAnOpenBraceNext(theToken)) return FALSE;

	if (!token_ParseValNext(theToken, TOKEN_GOOD_SPRITE_IDLE, tmp)) return FALSE;
	if (tmp) {
		Sprite *idleSprite = new Sprite;
		Assert(idleSprite);
		if(!idleSprite) return FALSE;
		idleSprite->ParseFromTokens(theToken);

		printf(" [Idle");
		for(i=0; i<idleSprite->GetNumFrames(); i++) {

			sprintf(name, "%sGG%#.2dS.%d.tif", prefixStr, id, i+idleSprite->GetFirstFrame());
			strcpy(shadowNames[i], name);

			sprintf(name, "%sGG%#.2dA.%d.tif", prefixStr, id, i+idleSprite->GetFirstFrame());
			strcpy(imageNames[i], name);
		}

		idleSprite->Import(idleSprite->GetNumFrames(), imageNames, shadowNames);
		m_sprites[GOODACTION_IDLE] = idleSprite;
		printf("]\n");

		Anim *idleAnim = new Anim;

		idleAnim->ParseFromTokens(theToken);
		m_anims[GOODACTION_IDLE] = idleAnim;
	}

	

	delete theToken;

	for (i=0; i<k_MAX_NAMES; i++) {
		free(imageNames[i]);
		free(shadowNames[i]);
	}

	return TRUE;
}

void GoodSpriteGroup::ExportScript(MBCHAR *name)
{
	FILE				*file;
	extern TokenData	g_allTokens[];

	file = fopen(name, "w");
	if (!file) {
		c3errors_ErrorDialog("Sprite Export", "Could not open '%s' for writing.", name);
		return;
	}

	char timebuf[100];
	time_t ltime;
	struct tm *now;

	time(&ltime);
	now = localtime(&ltime);
	strftime(timebuf, 100, "%I:%M%p %m/%d/%Y", now);

	fprintf(file, "#\n");
	fprintf(file, "# This file was automatically generated by Sprite-Test\n");
	fprintf(file, "#\n");
	fprintf(file, "# %s\n", timebuf);
	fprintf(file, "#\n\n");


	fprintf(file, "%d # %s\n\n", 0, name);
	fprintf(file, "%s\n", g_allTokens[TOKEN_GOOD_SPRITE].keyword);
	fprintf(file, "{\n");

	ExportSpriteGroup(file,(GAME_ACTION)GOODACTION_IDLE,TOKEN_UNIT_SPRITE_IDLE,TOKEN_MAX);
  









	fprintf(file, "}\n");

	fclose(file);
}