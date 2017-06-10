class Music : public Item{
	public:
		void loadMusic(std :: string path);
		void stop();
		void playMusic();
	private:
		int singTime;
		//std ::string musicPath;
		sf :: SoundBuffer buffer;
		sf :: Sound sound;
		//sf :: Music music;
};

void Music :: loadMusic(std :: string path){
	buffer.loadFromFile(path);
	sound.setBuffer(buffer);
	//music.openFromFile(path);
}

void Music :: playMusic(){
	sound.play();
	//music.play();
}

void Music :: stop(){
	sound.stop();
	//music.play();
}
