#pragma once

#define SCREEN_WIDTH 768
#define SCREEN_HEIGHT 1024

#define SPLASH_STATE_SHOW_TIME 0.0


#define SPLASH_SCENE_BACKGROUND_FILEPATH "C:/Users/Gonzalo/Desktop/Flappy Bird/Flappy Bird/Debug/Resources/res/Splash Background.png"
#define MAIN_MENU_BACKGROUND_FILEPATH "C:/Users/Gonzalo/Desktop/Flappy Bird/Flappy Bird/Debug/Resources/res/background2.png"
#define GAME_BACKGROUND_FILEPATH "C:/Users/Gonzalo/Desktop/Flappy Bird/Flappy Bird/Debug/Resources/res/background2.png"
#define GAME_OVER_BACKGROUND_FILEPATH "C:/Users/Gonzalo/Desktop/Flappy Bird/Flappy Bird/Debug/Resources/res/background2.png"
#define PIPE_UP_FILEPATH "C:/Users/Gonzalo/Desktop/Flappy Bird/Flappy Bird/Debug/Resources/res/PipeUp.png"
#define PIPE_DOWN_FILEPATH "C:/Users/Gonzalo/Desktop/Flappy Bird/Flappy Bird/Debug/Resources/res/PipeDown.png"
#define SCORING_PIPE_FILEPATH "C:/Users/Gonzalo/Desktop/Flappy Bird/Flappy Bird/Debug/Resources/res/InvisibleScoringPipe.png"


#define FLAPPY_FONT_FILEPATH "C:/Users/Gonzalo/Desktop/Flappy Bird/Flappy Bird/Debug/Resources/fonts/FlappyFont.ttf"
#define PIPE_MOVEMENT_SPEED 300.0f
#define ENEMY_MOVEMENT_SPEED 400.0f

#define PIPE_SPAWN_FREQUENCY 2.0f
#define ENEMY_SPAWN_FREQUENCY 2.5f
#define GAME_TITLE_FILEPATH "C:/Users/Gonzalo/Desktop/Flappy Bird/Flappy Bird/Debug/Resources/res/logo.png"
#define PLAY_BUTTON_FILEPATH "C:/Users/Gonzalo/Desktop/Flappy Bird/Flappy Bird/Debug/Resources/res/PlayButton2.png"
#define LAND_FILEPATH "C:/Users/Gonzalo/Desktop/Flappy Bird/Flappy Bird/Debug/Resources/res/land.png"
#define GAME_OVER_TITLE_FILEPATH "C:/Users/Gonzalo/Desktop/Flappy Bird/Flappy Bird/Debug/Resources/res/Game-Over-Title.png"
#define GAME_OVER_BODY_FILEPATH "C:/Users/Gonzalo/Desktop/Flappy Bird/Flappy Bird/Debug/Resources/res/Game-Over-Body.png"

#define BIRD_ANIMATION_DURATION 0.4f

#define ENEMY_ANIMATION_DURATION 0.4f

#define BIRD_STATE_STILL 1
#define BIRD_STATE_FALLING 2
#define BIRD_STATE_FLYING 3

#define GRAVITY 700.0f
#define FLYING_SPEED 500.0f

#define FLYING_DURATION 0.25f

#define BIRD_FRAME_1_FILEPATH "C:/Users/Gonzalo/Desktop/Flappy Bird/Flappy Bird/Debug/Resources/res/bird 1.png"
#define BIRD_FRAME_2_FILEPATH "C:/Users/Gonzalo/Desktop/Flappy Bird/Flappy Bird/Debug/Resources/res/bird 2.png"
#define BIRD_FRAME_3_FILEPATH "C:/Users/Gonzalo/Desktop/Flappy Bird/Flappy Bird/Debug/Resources/res/bird 3.png"
#define BIRD_FRAME_4_FILEPATH "C:/Users/Gonzalo/Desktop/Flappy Bird/Flappy Bird/Debug/Resources/res/bird 4.png"

#define ENEMY_FRAME_1_FILEPATH "C:/Users/Gonzalo/Desktop/Flappy Bird/Flappy Bird/Debug/Resources/res/enemy 1.png"
#define ENEMY_FRAME_2_FILEPATH "C:/Users/Gonzalo/Desktop/Flappy Bird/Flappy Bird/Debug/Resources/res/enemy 2.png"
#define ENEMY_FRAME_3_FILEPATH "C:/Users/Gonzalo/Desktop/Flappy Bird/Flappy Bird/Debug/Resources/res/enemy 3.png"
#define ENEMY_FRAME_4_FILEPATH "C:/Users/Gonzalo/Desktop/Flappy Bird/Flappy Bird/Debug/Resources/res/enemy-4.png"

#define ROTATION_SPEED 400.0f
#define BRONZE_MEDAL_FILEPATH "C:/Users/Gonzalo/Desktop/Flappy Bird/Flappy Bird/Debug/Resources/res/Bronze-Medal.png"
#define SILVER_MEDAL_FILEPATH "C:/Users/Gonzalo/Desktop/Flappy Bird/Flappy Bird/Debug/Resources/res/Silver-Medal.png"
#define GOLD_MEDAL_FILEPATH "C:/Users/Gonzalo/Desktop/Flappy Bird/Flappy Bird/Debug/Resources/res/Gold-Medal.png"
#define PLATINUM_MEDAL_FILEPATH "C:/Users/Gonzalo/Desktop/Flappy Bird/Flappy Bird/Debug/Resources/res/Platinum-Medal.png"

#define HIT_SOUND_FILEPATH "C:/Users/Gonzalo/Desktop/Flappy Bird/Flappy Bird/Debug/Resources/audio/Hit.wav"
#define POINT_SOUND_FILEPATH "C:/Users/Gonzalo/Desktop/Flappy Bird/Flappy Bird/Debug/Resources/audio/Point.wav"
#define WING_SOUND_FILEPATH "C:/Users/Gonzalo/Desktop/Flappy Bird/Flappy Bird/Debug/Resources/audio/Wing.wav"
#define BACKGROUND_MUSIC_FILEPATH "C:/Users/Gonzalo/Desktop/Flappy Bird/Flappy Bird/Debug/Resources/audio/bensound-retrosoul.wav"

enum GameStates
{
	eReady, ePlaying, eGameOver
};



#define FLASH_SPEED 1500.0f
#define TIME_BEFORE_GAME_OVER_APPEARS 1.5f


#define BRONZE_MEDAL_SCORE 0
#define SILVER_MEDAL_SCORE 5
#define GOLD_MEDAL_SCORE 25
#define PLATINUM_MEDAL_SCORE 100
