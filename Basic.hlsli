cbuffer ConstBufferDataMaterial : register(b0)
{
	float4 color; // �F(RGBA)
};

// ���_�V�F�[�_�[�̏o�͍\����
// �i���_�V�F�[�_�[����s�N�Z���V�F�[�_�[�ւ̂����Ɏg�p����j
struct VSOutput
{
    // �V�X�e���p���_���W
    float4 svpos : SV_POSITION;
    // uv�l
    float2 uv  :TEXCOORD;
};