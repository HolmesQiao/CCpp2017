#ifndef windowX
#define windowX 1000.f
#endif 
#ifndef windowY
#define windowY 700.f
#endif

class Scene : public Music{
	public:
		Scene() {position.x = -450.f; position.y = -380.f;}
		void loadScene(std :: string path);
	private:
		sf :: Texture texture;
		std :: string scenePath;
};

void Scene :: loadScene(std :: string path){
	FILE *edgeData = fopen((path + "edgeData").c_str(), "r");
	fscanf(edgeData, "%f%f", &edgeX, &edgeY);
	edgeX -= windowX;
	edgeY -= windowY;
	//std :: cout << edgeX << std :: endl;
	//std :: cout << edgeY << std :: endl;
	//std :: cout << "load " << path << std :: endl;
	std :: string ScenePath = path + "scene.png";
	//std :: cout << ScenePath << std :: endl;
	std :: string MusicPath = path + "music.wav";
	//std :: cout << MusicPath << std :: endl;
	texture.loadFromFile(ScenePath);
	//texture.setSmooth(true);
	sprite.setTexture(texture);
	loadMusic(MusicPath);
}
