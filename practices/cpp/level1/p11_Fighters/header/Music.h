class Music : public Item{
	public:
		void loadMusic(std :: string path);
		void stop();
		void playMusic();
	private:
		int singTime;
		std ::string musicPath;
		sf :: SoundBuffer buffer;
		sf :: Sound sound;
};

void Music :: loadMusic(std :: string path){
	buffer.loadFromFile(path);
	sound.setBuffer(buffer);
}

void Music :: playMusic(){
	sound.play();
}

void Music :: stop(){
	sound.stop();
}
