#pragma once
#include<Windows.h>
#include<d3d11.h>
class imguiWrapper
{
public:
    imguiWrapper(HWND,ID3D11Device*,ID3D11DeviceContext*);
    void newframe();
    void endframe();
    void shutdown();
};

