#pragma once
void AudioRegister()
{
	AudioAsset::Register(U"BGM_GameScene", Audio::Stream, U"Assets/music/maou_bgm_cyber44.mp3");
	AudioAsset::Register(U"SE_ButtonClicked", U"Assets/sound-effect/button.mp3");
	AudioAsset::Register(U"SE_SpeedUp", U"Assets/sound-effect/speed-up.mp3");
	AudioAsset::Register(U"SE_SpeedDown", U"Assets/sound-effect/slow-down.mp3");

}
