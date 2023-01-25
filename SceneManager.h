#pragma once

class SceneManager final{
private:
	//コンストラクタをprivateにする
	SceneManager();
	//デストラクタをprivateにする
	~SceneManager();

public:
	// コピーコンストラクタを無効にする
	SceneManager(const SceneManager&) = delete;
	//代入演算子を無効にする
	SceneManager& operator=(const SceneManager&) = delete;
	// インスタンス
	static SceneManager* GetInstance();

	void ChangeScene(int sceneNo);

};