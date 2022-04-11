#include<Windows.h>

LRESULT WindowProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam) {
	//メッセージに応じてゲーム固有の処理を行う
	switch (msg) {
		//ウィンドウが破棄された
	case WM_DESTROY:
		//OSに対して、アプリの終了を伝える
		PostQuitMessage(0);
		return 0;
	}
	//標準のメッセージ処理を行う
	return DefWindowProc(hwnd, msg, wparam, lparam);
}

//Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	const int window_width = 1280;
	const int window_height = 720;

	//ウィンドウクラスの設定
	WNDCLASSEX w{};
	w.cbSize = sizeof(WNDCLASSEX);
	w.lpfnWndProc = (WNDPROC)WindowProc;
	w.lpszClassName = L"DirectXGame";
	w.hInstance = GetModuleHandle(nullptr);
	w.hCursor = LoadCursor(NULL, IDC_ARROW);
	//ウィンドウクラスをOSに登録する
	RegisterClassEx(&w);
	//ウィンドウサイズ{x座標,y座標,横幅,縦幅}
	RECT wrc = { 0,0,window_width,window_height };
	//自動でサイズを補正する
	AdjustWindowRect(&wrc, WS_OVERLAPPEDWINDOW, false);
	//ウィンドウオブジェクトの生成
	HWND hwnd = CreateWindow(w.lpszClassName, L"DirectXGame", WS_OVERLAPPEDWINDOW, CW_USEDEFAULT,
		CW_USEDEFAULT, wrc.right - wrc.left, wrc.bottom - wrc.top, nullptr, nullptr,
		w.hInstance, nullptr);
	//ウィンドウを表示状態にする
	ShowWindow(hwnd, SW_SHOW);
	//メッセージ
	MSG msg{};
	//-------①ゲーム全体の初期化--------//

	//DirectX初期化処理　ここから


	//DirectX初期化処理　ここまで

	//ゲームループ
	while (true) {
		//---------②ゲームを実行している間、繰り返し行う処理--------//
		//メッセージがある?
		if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE)) {
			//キー入力メッセージの処理
			TranslateMessage(&msg);
			//プロシージャにメッセージを送る
			DispatchMessage(&msg);
		}

		//×ボタンで終了メッセージが来たらゲームループを抜ける
		if (msg.message == WM_QUIT) {
			break;
		}
	}

	//----------③ゲーム全体の終了処理-----------//

	//ウィンドウクラスを登録解除
	UnregisterClass(w.lpszClassName, w.hInstance);
	//コンソールへの文字入力
	//OutputDebugStringA("Hello,DirectX!!\n");

	return 0;
}

