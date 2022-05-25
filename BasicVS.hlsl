#include "Basic.hlsli"

VSOutput main(float4 pos:POSITION, float2 uv : TEXCORD)
{
	VSOutput output; //ピクセルシェーダーに渡す値
	output.svpos = pos;
	output.uv = uv;
	return output;
}

//float4 main(float4 pos : POSITION) : SV_POSITION
//{
//	float4 a;
//float4 b = { 1,1,0,0 };
//float4 pos2 = pos;
//const float PI = 3.14159;
//float angle = PI * 0.0;
//pos2.x = pos.x * cos(angle) - pos.y * sin(angle);
//pos2.y = pos.x * sin(angle) + pos.y * cos(angle);
//return pos;
//}