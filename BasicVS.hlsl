float4 main(float4 pos : POSITION) : SV_POSITION
{
	float4 a;
float4 b = { 1,1,1,1 };
float4 pos2 = pos;
const float PI = 3.14159;
float angle = PI * 0.25;
pos2.x = pos.x * cos(angle) - pos.y * sin(angle);
pos2.y = pos.x * sin(angle) + pos.y * cos(angle);
return pos2;
}