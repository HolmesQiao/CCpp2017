/*************************************************************************
*	item --> music ---------------------> character---Fighting                  *
*          |-->scene                         friend      <----|           *
*          |-->text                           enemy      <----|           *
*                                                                        *
*************************************************************************/
/******************************************************************************************************************************/
 C */	Item:{position, sprite, isMoving, status, dir} //update(){change isMoving & move}, move(), handleInput(key, isPressed);*
 L */	Music:{singTime, musicPath, buffer, sound} //pause(); loadMusic(path) playMusic(){sound.play()};                                   * 
 A */	Character:{texture, maxLive, live, characterPath, vecter<sprite>} //loadCharacter(); change();                         *
 S */	 /*loadCharacter :"data": store num of run fight, the image num is from 1 ~ 9                                          * 
 S */	Scene:{position, texture, edgeData} //loadScene();                                                                                 * 
/*****************************************************************************************************************************/
/*****************************************************************************************************************************/
datar.h : //friendFile enemyFile sceneFile dataFile
	numFriend, numEnemy, numScene;
	*friendFile, *enemyFile, *sceneFile, *dataFile;
	queue <string>: allFriendPath, allEnemyPath, allScenePath
	Sprite : allFriendSprite, allE, allS;
	Texture : allFriendTexture, allE, allS;
	//characterFriend, cE, sS//

	/*first line: n means the num of item
	  next n line: path 
	*/
/****************************************************************************************************************************/
现在需要一个控制剧本流程的类/函数script:具体功能如下
控制character，scene，text出场顺序及个数，控制动画，音效
需要给character加一个fight & talk & 背包，属性的功能，加入text类
需要判断scene边界，对对象的move做一些调整
需要加一个菜单类
/***************************************************************************************************************************/
Script:
eachline include
command s : scene  numScene m p
                              s
			    s d 
command f : friend numFriend p
                             d
command e : enemy  numEnemy  p
                             d
command m : music  numMusic  p
                             d
command v : video  numVideo  p
                             d
