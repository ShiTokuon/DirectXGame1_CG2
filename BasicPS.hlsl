#include "Basic.hlsli"

float4 main(VSOutput input) : SV_TARGET
{
    return float4(input.uv, 0, 1);
}

//cbuffer ConstBufferDataMaterial : register(b0)
//{
//	float4 color; // �F(RGBA)
//};

//float4 main(float4 pos:SV_POSITION) : SV_TARGET
//{
//	return color;
//	//float4(1.0f,1.0f,1.0f,1.0f);
//}