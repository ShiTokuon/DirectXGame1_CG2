#include<Windows.h>

LRESULT WindowProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam) {
	//���b�Z�[�W�ɉ����ăQ�[���ŗL�̏������s��
	switch (msg) {
		//�E�B���h�E���j�����ꂽ
	case WM_DESTROY:
		//OS�ɑ΂��āA�A�v���̏I����`����
		PostQuitMessage(0);
		return 0;
	}
	//�W���̃��b�Z�[�W�������s��
	return DefWindowProc(hwnd, msg, wparam, lparam);
}

//Windows�A�v���ł̃G���g���[�|�C���g(main�֐�)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	const int window_width = 1280;
	const int window_height = 720;

	//�E�B���h�E�N���X�̐ݒ�
	WNDCLASSEX w{};
	w.cbSize = sizeof(WNDCLASSEX);
	w.lpfnWndProc = (WNDPROC)WindowProc;
	w.lpszClassName = L"DirectXGame";
	w.hInstance = GetModuleHandle(nullptr);
	w.hCursor = LoadCursor(NULL, IDC_ARROW);
	//�E�B���h�E�N���X��OS�ɓo�^����
	RegisterClassEx(&w);
	//�E�B���h�E�T�C�Y{x���W,y���W,����,�c��}
	RECT wrc = { 0,0,window_width,window_height };
	//�����ŃT�C�Y��␳����
	AdjustWindowRect(&wrc, WS_OVERLAPPEDWINDOW, false);
	//�E�B���h�E�I�u�W�F�N�g�̐���
	HWND hwnd = CreateWindow(w.lpszClassName, L"DirectXGame", WS_OVERLAPPEDWINDOW, CW_USEDEFAULT,
		CW_USEDEFAULT, wrc.right - wrc.left, wrc.bottom - wrc.top, nullptr, nullptr,
		w.hInstance, nullptr);
	//�E�B���h�E��\����Ԃɂ���
	ShowWindow(hwnd, SW_SHOW);
	//���b�Z�[�W
	MSG msg{};
	//-------�@�Q�[���S�̂̏�����--------//

	//DirectX�����������@��������


	//DirectX�����������@�����܂�

	//�Q�[�����[�v
	while (true) {
		//---------�A�Q�[�������s���Ă���ԁA�J��Ԃ��s������--------//
		//���b�Z�[�W������?
		if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE)) {
			//�L�[���̓��b�Z�[�W�̏���
			TranslateMessage(&msg);
			//�v���V�[�W���Ƀ��b�Z�[�W�𑗂�
			DispatchMessage(&msg);
		}

		//�~�{�^���ŏI�����b�Z�[�W��������Q�[�����[�v�𔲂���
		if (msg.message == WM_QUIT) {
			break;
		}
	}

	//----------�B�Q�[���S�̂̏I������-----------//

	//�E�B���h�E�N���X��o�^����
	UnregisterClass(w.lpszClassName, w.hInstance);
	//�R���\�[���ւ̕�������
	//OutputDebugStringA("Hello,DirectX!!\n");

	return 0;
}

