#include"Diesel.h"

#include"TitleScene.h"
#include"GameScene.h"

int main(void)
{
	Engine en("MetaMetabolism", 800,600);

	Resource r;

	r.AddScene(new TitleScene, new GameScene, NULL);

	r.CreateMap("Resource\\Texture\\", "Resource\\", "Texture", ".png");
	r.CreateMap("Resource\\SE\\", "Resource\\", "SE", ".ogg");
	r.CreateMap("Resource\\BGM\\", "Resource\\", "BGM", ".ogg");
	r.CreateMap("Resource\\Font\\", "Resource\\", "Font", ".ttf");

	r.LoadTextureMap("Resource\\Texture.map");
	r.LoadSEMap("Resource\\SE.map");
	r.LoadBGMMap("Resource\\BGM.map");
	r.LoadFontMap("Resource\\Font.map");

	return en.Run();
}